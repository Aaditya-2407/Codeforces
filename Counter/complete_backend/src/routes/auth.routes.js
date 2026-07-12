import { Router } from "express";
import { validate } from "../middlewares/validator.middleware.js";
import { verifyJWT } from "../middlewares/auth.middleware.js";

// Import all Controllers
import {
    registerUser,
    loginUser,
    logoutUser,
    getCurrentUser,
    verifyEmail,
    resendEmailVerification,
    refreshAccessToken,
    forgotPasswordRequest,
    resetPassword,
    changeCurrentPassword
} from "../controllers/auth.controllers.js";

// Import all Validators
import {
    userRegisterValidator,
    userLoginValidator,
    userChangeCurrentPasswordValidator,
    userForgotPasswordValidator,
    userResetPasswordValidator
} from "../validators/index.js";

const router = Router();

// ==========================================
// 🔓 UNSECURED ROUTES (No Token Required)
// ==========================================

router.route("/register").post(userRegisterValidator(), validate, registerUser);
router.route("/login").post(userLoginValidator(), validate, loginUser);

// Refresh token route (Uses refresh token from cookies, not access token)
router.route("/refresh-token").post(refreshAccessToken);

// Forgot Password Flow
router.route("/forgot-password").post(userForgotPasswordValidator(), validate, forgotPasswordRequest);

// Note the /:resetToken - This captures the dynamic value from the URL into req.params!
router.route("/reset-password/:resetToken").post(userResetPasswordValidator(), validate, resetPassword);

// Verify Email Route (Captures token from URL)
router.route("/verify-email/:verificationToken").get(verifyEmail);


// ==========================================
// 🔒 SECURED ROUTES (Token Required!)
// ==========================================

// Every route below MUST have the `verifyJWT` middleware injected first.

router.route("/logout").post(verifyJWT, logoutUser);
router.route("/current-user").get(verifyJWT, getCurrentUser); 
router.route("/resend-email-verification").post(verifyJWT, resendEmailVerification);

// Change Password Flow
router.route("/change-password").post(
    verifyJWT, 
    userChangeCurrentPasswordValidator(), 
    validate, 
    changeCurrentPassword
);

export default router;