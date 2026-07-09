import {} from "express-validator";
import { ApiResponse} from "../utils/api-response";
import {ApiError} from "../utils/api-error";


export const validate = (req, res, next) =>{
    const errors = validatorresult(req);
    if(error.isEmpty()){
        return next();
    }
    const extractedErrors = [];
    errors.array().map((err) => extractedErrors.push(
        {
            [err.path]:err.msg
        }
    ));
    throw new ApiError(422, "something went wrong the provided data is not valid",extractedErrors);

    
}