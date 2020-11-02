// Definições gerais
let express = require("express");
let app = express();
let port = 3000;
var formidable = require("formidable");
var fs = require("fs");
const { Component } = require("react");

// Definindo conteúdo estático
app.use(express.static("public"));

// Enviando dados
app.post("/sendData", (req, res) => {
  var form = new formidable.IncomingForm();
  form.parse(req, function (err, fields, files) {
    fs.readFile("data.json", "utf8", function (err, data) {
      var obj = JSON.parse(data);
      obj["database"].push(fields);
      fs.writeFileSync("data.json", JSON.stringify(obj));
    });
  });
});

// Consultado os dados
app.get("/getData", (req, res) => {
  fs.readFile("data.json", "utf8", function (err, data) {
    res.end(data);
  });
});

// Escutando a porta
app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});
