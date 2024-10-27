const express = require('express');
const path = require('path'); 
const app = express();
const PORT = process.env.PORT || 3000; 

class AppError extends Error {
    constructor(message, statusCode) {
        super(message);
        this.statusCode = statusCode;
        this.isOperational = true;
        Error.captureStackTrace(this, this.constructor);
    }
}

app.use(express.json({ limit: '10mb' }));

app.use(express.static(path.join(__dirname)));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
}); 

app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
