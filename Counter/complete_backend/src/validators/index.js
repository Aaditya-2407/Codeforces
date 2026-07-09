import {body} from "express-validator";

const userRegistrationValidator = () =>
{
    return [
        body("email")
        .trim()
        .isEmail
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
export {userRegistrationValidator}