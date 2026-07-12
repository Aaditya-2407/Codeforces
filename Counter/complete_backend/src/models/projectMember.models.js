import mongoose, { Schema } from "mongoose";

import {ProjectSchema} from "./project.models";
import { User } from "./user.models";
import { AvailableTaskStatuses, TaskStatusEnum } from "../utils/constants";


const ProjectMember = new Schema(
    {
        user: {type : Schema.Types.ObjectId,
        ref: "User",
        required: true,},

        project : {type : Schema.Types.ObjectId,
        ref: "Project",
        required: true,},

        role: {
            type : String,
            enum : UserRolesEnum,
            default: UserRolesEnum.MEMBER,


        }
    },{timestamps:true}

)

export const ProjectMember = mongoose.model("ProjectMember", projectMemberSchema);