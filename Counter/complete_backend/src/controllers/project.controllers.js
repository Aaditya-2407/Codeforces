import mongoose from "mongoose";
import { Project } from "../models/project.models.js";
import { ProjectMember } from "../models/projectMember.models.js";
import { ApiError } from "../utils/api-error.js";
import { ApiResponse } from "../utils/api-response.js";
import { asyncHandler } from "../utils/asyncHandler.js";
import { UserRolesEnum } from "../utils/constants.js"; // Adjust path if needed

// ==========================================
// 1. CREATE PROJECT
// ==========================================
const createProject = asyncHandler(async (req, res) => {
    
    const { name, description } = req.body;

    
    const project = await Project.create({
        // TODO: Pass name, description, and createdBy (which is req.user._id)
    name,
    description,
    createdBy : new mongoose.Types.ObjectId(req.body._id),
    
    });

    // 3. Create the Project Member (Make the creator an ADMIN)
    await ProjectMember.create({
        // TODO: Pass the project ID, the user ID, and the role (UserRolesEnum.ADMIN)
        user: req.user._id,
        project: project._id,
        role: UserRolesEnum.ADMIN,

    });

    return res.status(201).json(new ApiResponse(201, project, "Project created successfully"));
});

// ==========================================
// 2. UPDATE PROJECT
// ==========================================
const updateProject = asyncHandler(async (req, res) => {
    // 1. Extract projectId from params, and name/description from body
    const { projectId } = req.params;
    const { name, description } = req.body;

    // 2. Find by ID and Update
    const project = await Project.findByIdAndUpdate(
        // TODO: Arg 1: the projectId
       projectId,
       {
        name,
        description
       },
       {new:true}
    );

    // 3. Check if project exists
    if (!project) {
        throw new ApiError(404, "Project not found");
    }

    // 4. Return success
    return res.status(200).json(new ApiResponse(200, project, "Project updated successfully"));
});

// ==========================================
// 3. DELETE PROJECT
// ==========================================
const deleteProject = asyncHandler(async (req, res) => {
    const { projectId } = req.params;

    // 1. Find by ID and Delete
    const project = await Project.findByIdAndDelete(
        projectId
    );
    if (!project) {
        throw new ApiError(404, "Project not found");
    }
    await ProjectMember.deleteMany({ project: projectId });
await Task.deleteMany({ project: projectId });
await Note.deleteMany({ project: projectId });

    

    // Optional: You could also delete all ProjectMembers associated with this project here!

    return res.status(200).json(new ApiResponse(200, {}, "Project deleted successfully"));
});

export { createProject, updateProject, deleteProject };
