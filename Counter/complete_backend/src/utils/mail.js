import Mailgen from "mailgen";
import nodemailer from "nodemailer";


const sendEmail = async (options) => {
    const mailGenerator = new Mailgen({
        theme: "default",
        product: {
            name: "Task Manager",
            link:"https://taskmanagelink.com"
        }
    })

    const emailTextual = mailGenerator.generatePlaintext(options.mailgenContent)
    const emailHtml = mailGenerator.generate(options.mailgenContent)


    const transporter = nodemailer.createTransport({
        host: process.env.MAILTRAP_SMTP_HOST,
        port: process.env.MAILTRAP_SMTP_PORT,
        auth: {
            user: process.env.MAILTRAP_SMTP_USER,
            pass: process.env.MAILTRAP_SMTP_PASS,
        }
    })

    const mail = {
        from : "mail.taskmanager@example.com",
        to: options.email,
        subject:options.subject,
        text:emailTextual,
        html: emailHtml
    }

    try {
        await transporter.sendMail(mail)
        
    } catch (error) {
        throw new Error(`Failed to send email: ${error.message}`)
        
    }
}



const emailVerificationMailgenContent = (username, verificationUrl) => {
    return {
        body: {
            name: username,
            intro: "Welcome to our App! we are excited to have you onboard",
            action: {
                intructions: "To Verify your email Please click on the following button",
                button:{
                    color: "#22BC66",
                    text: "Verify Your Email",
                    link: verificationUrl

                },
            },
            outro: "Need help , pr have questions? Just reply to this email , we'd like to help "

        },
    };
}

const forgotPasswordMailgenContent = (username, passwordResetUrl) => {
    return {
        body: {
            name: username,
            intro: "We got a request to reset your password ",
            action: {
                intructions: "To Reset your password Please click on the following button",
                button:{
                    color: "#22BC66",
                    text: "Reset Your Password",
                    link: passwordResetUrl,

                },
            },
            outro: "Need help , pr have questions? Just reply to this email , we'd like to help "
            
        },
    };
}

export {
    emailVerificationMailgenContent,
    forgotPasswordMailgenContent,
    sendEmail,
}