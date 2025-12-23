var fs = require('fs').promises;

fs.readFile("./zad4.txt", 'utf8')
    .then((content) => {
        console.log(content);
    })
    .catch((err) => {
        console.error('error:', err);
    });
