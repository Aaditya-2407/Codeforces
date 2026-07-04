const fs = require('fs');
const filepath = './tasks.json';

const loadTasks = () => 
{
    try {
        const dataBuffer = fs.readFileSync(filepath);
        const dataJSON = dataBuffer.toString();
        return JSON.parse(dataJSON);
    }
    catch(e){
        return [];
    }

}

const saveTask = (tasks) =>
{
    const dataJSON = JSON.stringify(tasks);
    fs.writeFileSync(filepath,dataJSON);
    
}

const addTask = (taskName) =>
{
    const tasks = loadTasks();
    tasks.push({task : taskName});
    saveTask(tasks);
    console.log(`Taks Added : ${taskName}`)
}
const listTask = () =>
{
    const tasks = loadTasks();
    tasks.forEach((items , index) => {
        console.log(`${index+1} - ${items.task}`);

    });

};
const removeTask = (taskName) => {
    const tasks = loadTasks();
    
   
    const tasksToKeep = tasks.filter((item) => item.task !== taskName);

    if (tasks.length > tasksToKeep.length) {
        saveTask(tasksToKeep);
        console.log(`Task Removed: ${taskName}`);
    } else {
        console.log(`Task not found: ${taskName}`);
    }
}
const command = process.argv[2];
const argument = process.argv[3];

if(command === "add" || command === "Add"){
    addTask(argument);
}
else if(command === "list")
{
    listTask();
}
else if(command === "remove")
{
    removeTask(argument);

}
else{
    console.log("command not found ");
}