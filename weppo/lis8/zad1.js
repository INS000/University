const express = require('express');
const app = express();
const path = require('path');

const multer = require('multer');
const storage = multer.diskStorage({
    destination: function(req, file, cb) {
        cb(null, 'images');
    },
    filename: function(req, file, cb){
        cb(null, Date.now() + path.extname(file.originalname));
    }
    });

const upload = multer({storage: storage});

app.set('view engine', 'ejs');

app.get('/', (req, res) => {
    res.render('zad1');
});

app.post('/', upload.single('image'), (req, res) => {
    res.send('File uploaded');
});


app.listen(3000);
console.log('started');
