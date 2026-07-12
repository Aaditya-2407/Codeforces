import {body} from "express-validator";

const userRegistrationValidator = () =>
{
    return [
        body("email")
        .trim()
        .isEmail()
        .withMessage("not a valid email")
        .notEmpty()
        .withMessage("email field cant be empty"),
        body("username")
        .trim()
        .notEmpty()
        .withMessage("username cannot be empty")
        .isLowercase()
        .withMessage("username must be lowercase")
        .isLength({min: 3, max: 21})
        .withMessage("username must me atleast 3 characters"),
        body("password")
        .trim()
        .notEmpty()
        .withMessage("password is required")
        .isLength({min : 7})
        .withMessage("must be atleat 7 characters (thala for a reason)"),
        body("fullName")
        .optional()
        .trim()
        .notEmpty()




    ]
}
const loginValidator = () => {
    return [
        body("email")
        .optional()
        .isEmail()
        .withMessage("Email invalid"),
        body("password")
        .notEmpty()
        .withMessage("Password is required")


    ]
}
import { body } from "express-validator";

// 1. Validator for Changing Current Password
export const userChangeCurrentPasswordValidator = () => {
    return [
        body("oldPassword").notEmpty().withMessage("Old password is required"),
        body("newPassword").notEmpty().withMessage("New password is required")
    ];
};

// 2. Validator for Forgot Password Request
export const userForgotPasswordValidator = () => {
    return [
        body("email")
            .notEmpty().withMessage("Email is required")
            .isEmail().withMessage("Email is invalid")
    ];
};

// 3. Validator for Reset Password
export const userResetPasswordValidator = () => {
    return [
        body("newPassword").notEmpty().withMessage("Password is required")
    ];
};
export {userRegistrationValidator , loginValidator}