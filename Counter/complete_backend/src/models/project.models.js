import mongoose, { Schema } from "mongoose";
import { ProjectMember } from "./projectMember.models";

import { User } from "./user.models";
import { AvailableTaskStatuses, TaskStatusEnum } from "../utils/constants";


const projectSchema = new Schema(
    {
        name : {type: String,
            required : true,
            unique: true,
            trim: true


        },

        description : {
            type: String,
            
        },
        createdBy: {
        type: Schema.Types.ObjectId,
        ref: "User",
        required: true,
    }
        
    
    
    },{timestamps: true}

)
export const project = mongoose.model("Project",projectSchema)