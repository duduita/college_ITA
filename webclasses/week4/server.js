const express = require("express"),
  app = express(),
  path = require("path"),
  multer = require("multer"),
  fs = require('fs');


const storage = multer.diskStorage({
  destination: function (req, file, cb) {
    cb(null, "uploads/");
  },
  filename: function (req, file, cb) {
    cb(null, file.originalname);
  },
});

const upload = multer({ storage });

app.use(express.static("public"));

app.get('/', function(req, res){
    res.sendFile(__dirname + '/public/' + 'index.html');
});
app.get("/process_get", function (req, res) {
  // Prepare output in JSON format
  response = {
    first_name: req.query.first_name,
    last_name: req.query.last_name,
  };
  console.log(response);
  res.end(JSON.stringify(response));
});
app.get('/list_users', function(req, res){
    fs.readFile(__dirname + '/public/' + 'data.json', 'utf8', function(err, data){
        if (err) return console.log(err);
        res.end(data);
    });
});

app.post('/file_upload', upload.single('file'), function(req, res){
    response = {
        filename: res.req.file.originalname,
        size: res.req.file.size/1000 + 'kb'
    };
    console.log(response);
    res.send('<h2>Upload realizado com sucesso</h2>');
});

var server = app.listen(8081, function () {
  var host = server.address().address;
  var port = server.address().port;
  console.log("Example app listening at http://%s:%s", host, port);
});
