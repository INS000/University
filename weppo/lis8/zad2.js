const express = require('express');
const app = express();
const ejs = require('ejs');

app.set('view engine', 'ejs');

app.get('/', (req, res) => {
    const checkbox  = {
        name: 'checkbox',
        options : [
            {id: 'option1', value: '1', text: 'Option 1'},
            {id: 'option2', value: '2', text: 'Option 2'},
            {id: 'option3', value: '3', text: 'Option 3'},
        ]
    }

    const checkbox2  = {
        name: 'checkbox',
        options : [
            {id: 'option4', value: '4', text: 'Option 7'},
            {id: 'option2', value: '2', text: 'Option 2'},
            {id: 'option3', value: '3', text: 'Option 3'},
        ]
    }
    res.render('zad2' , {checkbox, checkbox2});
});

app.listen(3000);
