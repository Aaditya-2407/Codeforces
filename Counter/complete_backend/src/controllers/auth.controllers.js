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
        $or: [{ username }, { email }] // FIX 2: Changed userName to username
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

    // FIX 3: Removed the spaces after the minus signs in the select string
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

export { registerUser, login };