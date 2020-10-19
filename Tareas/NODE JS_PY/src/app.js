//EXPRESS
const express = require('express');
const app = express();

//MORGAN y CODIGO
//const servicio = require("./Servicio");
const morgan = require('morgan');
app.use(morgan('dev'));

//CORS
var cors = require("cors");
app.use(cors());

//BODY-PARSER
var body_Parser = require("body-parser");
app.use(body_Parser.urlencoded({ extended: true }));
app.use(body_Parser.json());

/*
function prueba1(Entrada) {
    return Entrada+="\n JAVIER FUNCIONA EL ENVIO!!";
}*/

//var resultado="FFFFF";

function solicitudM1Goolang(cadena){
    try{

        var parser = require('../lexico');//aqui uso lexico.js q esta en la raiz
        var cosas = parser.parse(cadena.toString());
       // console.log("_____________________________________________\n"+cosas.resultado);

        return cosas;
    }
    catch(e){
        return " && NO REGRESO" + e.toString();
    }
}


app.post('/JavaScript/', function (req, res) {
    var solicitud = req.body.text;
    var remit = solicitudM1Goolang(solicitud);
    res.send(remit);
    });



module.exports = app;// exportar a index