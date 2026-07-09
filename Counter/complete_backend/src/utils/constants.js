export const UserRolesEnum = {
    ADMIN: "admin",
    PROJECT_ADMIN: "project_admin",
    MEMBER: "member"
}

export const AvailableUserRole = Object.values(UserRolesEnum)

export const TaskStatusEnum = {
    TODO: "todo",
    IN_PROGRESS: "in_progress",
    DONE: "done"
}
export const AvailableTaskStatuses = Object.values(TaskStatusEnum)

// ADD THIS LINE HERE:
export const DB_NAME = "project_manager" // Or whatever you want to name your database!