var http = require('http');
var express = require('express');
var session = require('express-session');


var FileStore = require('session-file-store')(session);

var app = express();
app.set('view engine', 'ejs');
app.set('views', './views');

app.use(session({
    store: new FileStore,
    secret: 'keyboard cat',
    resave: true,
    saveUninitialized: true
  })
);

app.use('/', (req, res) => {
    var sessionvalue;
   if(!req.session.date){
        sessionvalue = new Date().toString()
        req.session.date = sessionvalue;
   }
   else{
       sessionvalue = req.session.date;
       delete req.session.date;
   }

    res.render('zad5', {sessionvalue: sessionvalue});
});

http.createServer(app).listen(3000);
