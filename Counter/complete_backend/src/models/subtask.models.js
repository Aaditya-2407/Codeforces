import mongoose, { Schema } from "mongoose";
import { ProjectMember } from "./projectMember.models";
import {ProjectSchema} from "./project.models";
import { User } from "./user.models";
import { AvailableTaskStatuses, TaskStatusEnum } from "../utils/constants";
import { TaskSchema } from "./task.models";

const subTaskSchema = new Schema (
    {
        title: {
            type : String,
            required : true,
        },
        task : 
        {
            type : Schema.Types.ObjectId,
            ref: "Tasks",
            required: true,
        },
        isCompleted: {
            type : Boolean,
            default: false,
        },
        creadtedBy: {
            type : Schema.ObjectId,
            ref : "User",
            required : true,
        },

    },{timestamps: true}
)
export const SubTask = mongoose.model("SubTask", subTaskSchema);