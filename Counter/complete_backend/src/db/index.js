import mongoose from "mongoose";
import { DB_NAME } from "../utils/constants.js"; // <-- This is the magic line!

const connectDB = async () => {
    try {
        const connectionInstance = await mongoose.connect(`${process.env.MONGO_URI}/${DB_NAME}`);
        console.log(`\n MongoDB Connected !! DB Host: ${connectionInstance.connection.host}`);
    } catch (error) {
        console.error("MongoDB connection Error", error);
        process.exit(1);
    }
}

export default connectDB;