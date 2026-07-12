import { User } from "../models/user.models.js";
import { ApiResponse } from "../utils/api-response.js";
import { asyncHandler } from "../utils/asyncHandler.js";
import { ApiError } from "../utils/api-error.js";
// FIX 1: Added emailVerificationMailgenContent to the import!
import { sendEmail, emailVerificationMailgenContent } from "../utils/mail.js";

const generateAccessAndRefreshTokens = async (userId) => {
    try {
        const user = await User.findById(userId)
        const refreshToken = user.generateRefreshToken();
        const accessToken = user.generateAccessToken();
        user.refreshToken = refreshToken;
        await user.save({ validateBeforeSave: false });
        return { accessToken, refreshToken }
    }
    catch (error) {
        throw new ApiError(
            500,
            `Something went wrong while generating accessToken: ${error.message}`
        )
    }
}

const registerUser = asyncHandler(async (req, res) => {
    const { email, username, password, role } = req.body

    const existingUser = await User.findOne({
        $or: [{ username }, { email }] 
    })

    if (existingUser) {
        throw new ApiError(409, "email or username already exits", [])
    }

    const user = await User.create({
        email,
        password,
        username,
        isEmailVerified: false,
    })

    const { unHashedToken, hashedToken, tokenExpiry } = await user.generateTemporaryToken();

    user.emailVerificationToken = hashedToken
    user.emailVerificationExpiry = tokenExpiry

    await user.save({ validateBeforeSave: false });

    await sendEmail(
        {
            email: user?.email,
            subject: "Please Verify you Email",
            mailgenContent: emailVerificationMailgenContent(
                user.username,
                `${req.protocol}://${req.get("host")}/api/v1/users/verify-email/${unHashedToken}`
            ),
        }
    );

    const createdUser = await User.findById(user._id).select(
        "-password -refreshToken -emailTokens -emailVerificationToken -emailVerificationExpiry",
    );

    if (!createdUser) {
        throw new ApiError(500, "Something went Wrong While registering a user")
    }

    return res
        .status(201)
        .json(
            new ApiResponse(
                200,
                { user: createdUser }, // FIX 4: Changed createrUser to createdUser
                "user registered succesfully and verification email been sent to your email"
            )
        )
});

const login = asyncHandler(async (req,res,next) => {
    const { email, password } = req.body

    if (!email || !password) {
        throw new ApiError(400, "email and password are required")

    }

    const user = await User.findOne({email});

    if(!user){
        throw new ApiError(400, "User does not exists");

    }
    const isPasswordValid = await user.isPasswordCorrect(password);
    if (!isPasswordValid) {
        throw new ApiError(401, "incorrect password");

    }
    const { accessToken, refreshToken } = await generateAccessAndRefreshTokens(user._id)

    const loggedInUser = await User.findById(user._id).select(
        "-password -refreshToken -emailTokens -emailVerificationToken -emailVerificationExpiry",
    );

    const options = {
        httpOnly : true,
        secure: true,

    }

    return res
            .status(200)
            .cookie("accessToken",accessToken)
            .cookie("refreshToken",refreshToken)
            .json(
                new ApiResponse(
                    200,
                    {
                        user: loggedInUser,
                        accessToken,
                        refreshToken,
                    },
                    "user loggen in succesfully"
                )
            )



});
const logoutUser = asyncHandler(async (req, res) => {
    await User.findByIdAndUpdate(
        req.user._id,
        {
            $set: {
                refreshToken: undefined
            }
        },
        { new: true }
    );

    const options = {
        httpOnly: true,
        secure: true
    };

    return res
        .status(200)
        .clearCookie("accessToken", options)
        .clearCookie("refreshToken", options)
        .json(new ApiResponse(200, {}, "User logged out successfully"));
});
const getCurrentUser = asyncHandler(async (req,res)=>{
    return res 
    .status(200)
    .json(
        new ApiResponse(200,
            req.user,
            "current user fetched succesfully"
        )
    )
});
const verifyEmail = asyncHandler(async (req,res)=>{
    const {verficationToken} = req.params
    if(!emailVerificationToken){
        throw new ApiError(400, "Email verification token is missing")

    }
    let hashedToken = crypto
    .createdHash("sha256")
    .update(verificationToken)
    .digest("hex")

    const user = await User.findOne({
        emailVerificationToken: hashedToken,
        emailVerificationExpiry: {
            $gt: Date.now()
        },

    })
    if(!user){
        throw new ApiError(400, "Token is inValid or expired")
    }
    user.isEmailVerified= true;
    await user.save({validateBeforeSave: false})

    user.emailVerificationToken = undefined;
    user.emailVerificationExpiry = undefined;

    return res
    .status(200)
    json(
        new ApiResponse(200, 
            {
                isEmailVerified: true
            },
            "Email is Verified"
        )
    )
})

const resendEmailVerification = asyncHandler(async (req, res) => {
    // 1. Get user (provided by verifyJWT middleware)
    const user = await User.findById(req.user._id);
    if (!user) throw new ApiError(404, "User not found");

    // 2. Check if they even need an email
    if (user.isEmailVerified) {
        throw new ApiError(409, "Email is already verified");
    }

    // 3. Generate new tokens (assuming you have this helper method from Registration)
    const { unHashedToken, hashedToken, tokenExpiry } = await user.generateTemporaryToken();

    user.emailVerificationToken = hashedToken;
    user.emailVerificationExpiry = tokenExpiry;
    await user.save({ validateBeforeSave: false });

    // 4. Send the email (using your mailgen logic from before)
    // await sendEmail(...)

    return res.status(200).json(new ApiResponse(200, {}, "Verification email sent"));
});
const refreshAccessToken = asyncHandler(async (req, res) => {
    const incomingRefreshToken = req.cookies.refreshToken || req.body.refreshToken;
    if (!incomingRefreshToken) throw new ApiError(401, "Unauthorized request");

    try {
        // 1. Decode the token using the REFRESH secret
        const decodedToken = jwt.verify(incomingRefreshToken, process.env.REFRESH_TOKEN_SECRET);

        // 2. Find the user
        const user = await User.findById(decodedToken?._id);
        if (!user) throw new ApiError(401, "Invalid refresh token");

        // 3. CRITICAL: Check if the token sent by the user matches the one in our database!
        if (incomingRefreshToken !== user.refreshToken) {
            throw new ApiError(401, "Refresh token is expired or used");
        }

        // 4. Generate new tokens
        const accessToken = user.generateAccessToken();
        const newRefreshToken = user.generateRefreshToken();

        // 5. Update the DB with the new refresh token
        user.refreshToken = newRefreshToken;
        await user.save({ validateBeforeSave: false });

        // 6. Set secure cookies and send response
        const options = { httpOnly: true, secure: true };

        return res
            .status(200)
            .cookie("accessToken", accessToken, options)
            .cookie("refreshToken", newRefreshToken, options)
            .json(new ApiResponse(200, { accessToken, refreshToken: newRefreshToken }, "Access token refreshed"));

    } catch (error) {
        throw new ApiError(401, error?.message || "Invalid refresh token");
    }
});
const forgotPasswordRequest = asyncHandler(async (req, res) => {
    const { email } = req.body;

    const user = await User.findOne({ email });
    if (!user) {
        throw new ApiError(404, "User does not exist");
    }

    const { unHashedToken, hashedToken, tokenExpiry } = user.generateTemporaryToken();

    user.forgotPasswordToken = hashedToken;
    user.forgotPasswordExpiry = tokenExpiry;
    await user.save({ validateBeforeSave: false });

    
    const resetUrl = `${process.env.FORGOT_PASSWORD_REDIRECT_URL}/${unHashedToken}`;

    

    return res.status(200).json(new ApiResponse(200, {}, "Password reset mail has been sent to your email ID"));
});

import crypto from "crypto";

const resetPassword = asyncHandler(async (req, res) => {
    // 1. Get token from URL and new password from body
    const { resetToken } = req.params;
    const { newPassword } = req.body;

    // 2. Hash the incoming token to match what's in the DB
    const hashedToken = crypto
        .createHash("sha256")
        .update(resetToken)
        .digest("hex");

    // 3. Find user with this token where the expiry is greater than right now
    const user = await User.findOne({
        forgotPasswordToken: hashedToken,
        forgotPasswordExpiry: { $gt: Date.now() }
    });

    if (!user) {
        throw new ApiError(400, "Token is invalid or expired");
    }

    // 4. Update the password (Mongoose pre-save hook will hash it automatically!)
    user.password = newPassword;

    // 5. Clean up the database fields
    user.forgotPasswordToken = undefined;
    user.forgotPasswordExpiry = undefined;

    // 6. Save the user
    await user.save({ validateBeforeSave: false });

    return res.status(200).json(new ApiResponse(200, {}, "Password reset successfully"));
});

const changeCurrentPassword = asyncHandler(async (req, res) => {
    // 1. Get both passwords from the frontend
    const { oldPassword, newPassword } = req.body;

    // 2. Find the logged-in user
    const user = await User.findById(req.user._id);

    // 3. Verify the old password matches the database
    const isPasswordValid = await user.isPasswordCorrect(oldPassword);
    
    if (!isPasswordValid) {
        throw new ApiError(400, "Invalid old password");
    }

    // 4. Set the new password (Mongoose hook hashes it automatically!)
    user.password = newPassword;
    await user.save({ validateBeforeSave: false });

    return res.status(200).json(new ApiResponse(200, {}, "Password changed successfully"));
});



export { registerUser, login, logoutUser };