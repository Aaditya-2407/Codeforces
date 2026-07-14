// ==========================================
// 4. GET ALL PROJECTS (FOR CURRENT USER)
// ==========================================
const getProjects = asyncHandler(async (req, res) => {
    const projects = await ProjectMember.aggregate([
        {
            // TODO: Match ProjectMember where user is req.user._id
            $match:"req.user._id", as:"memeber"
        },
        {
            // TODO: $lookup from 'projects' collection
            // localField is 'project', foreignField is '_id'
            $lookup:{
                projectMember:"$member",
                localField:"$_id",
                foreignField: "proejectId",
                as: "ProjectsByIdOfMember",

            }
        },
        {
            $unwind: "$ProjectsByIdOfMember"

        },
        {
            // TODO: $project to return the joined project details
            $ProjectsByIdOfMember
        }
    ]);

    return res.status(200).json(new ApiResponse(200, projects, "Projects fetched successfully"));
});