import mongoose, { Schema } from "mongoose";
import { ProjectMember } from "./projectMember.models";
import {ProjectSchema} from "./project.models";
import { User } from "./user.models";
import { AvailableTaskStatuses, TaskStatusEnum } from "../utils/constants";

const TaskSchema = new Schema(
    {title : {
        type: String,
        required: true,

    },
    project: {
        type: Schema.Types.ObjectId,
        ref : "Project",
        required : true,

    },
    description : {
            type: String,
    },
    assignedTo: {
            type: Schema.Types.ObjectId,
            ref: "User",
            required: true,

    },

    assignedBy: {
            type : Schema.Types.ObjectId,
            ref: "User",
            required: true,
    },

    status: {
        type : String,
        enum : AvailableTaskStatuses,
        default: TaskStatusEnum.TODO,


    },

   attachment: [
        {
            url: String,
            mimeType: String,
            size: Number
        }
    ]
},{timestamps: true})
export const Task = mongoose.model("Task", taskSchema);