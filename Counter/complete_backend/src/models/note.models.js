import mongoose, { Schema } from "mongoose";
import { ProjectMember } from "./projectMember.models";
import {ProjectSchema} from "./project.models";
import { User } from "./user.models";
import { AvailableTaskStatuses, TaskStatusEnum } from "../utils/constants";
import { TaskSchema } from "./task.models";
import { subTaskSchema } from "./subtask.models";
import { NotBeforeError } from "jsonwebtoken";

const PrjectNoteSchema = new Schema(
    {
        project: {
                type : Schema.Types.ObjectId,
                ref:"Project",
                required: true,
        },
        createdBy: {
                type:Schema.Types.ObjectId,
                ref : "User",
                required:true,
        },
        content: {
            type : String,
            required: true,
        }
    },{timestamps: true}
)

export const Note = mongoose.model("Note", ProjectNoteSchema); // Typo: PrjectNoteSchema