import {Router} from "express";
import { registerUser,login } from "../controllers/auth.controllers.js";
import {User} from "../models/user.models.js"
import { validate } from "../middlewares/validator.middleware.js";
import {userRegistrationValidator} from "../validators/index.js"

const router = Router();

router.route("/register").post(userRegistrationValidator(), validate, registerUser);

router.route("/login").post(login);


 
export default router; 