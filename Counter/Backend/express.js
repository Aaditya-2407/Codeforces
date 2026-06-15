import express from 'express';
import fs from 'fs';
const app = express();
const port = 3000;

app.use((req, res, next) => {
    const log = `${new Date().toLocaleString()} - ${req.method} ${req.url}\n`;
    fs.appendFile('text.txt', log, (err) => {
        if (err) console.error(err);
    });
    next(); 
});

app.get('/', (req, res) => {
    res.send('helloworld');
});

app.get('/about', (req, res) => {
    res.send('helloworld');
});

app.get('/not', (req, res) => {
    res.send('helloworld');
});
app.get('/log', (req, res) => {
    fs.readFile('text.txt', 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            res.status(500).send('Error reading log file');
            return;
        }
        res.send(data);
    });
});

app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});