var http = require('http')
var express = require('express')
var app = express()


app.use((req, res) => {
    const data = 'To jest test'
    res.setHeader('Content-Disposition', 'attachment; filename=data.txt')
    res.end(data)
});


http.createServer(app).listen(3000)
