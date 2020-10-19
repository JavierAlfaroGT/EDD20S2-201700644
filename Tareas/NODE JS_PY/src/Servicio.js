class Jison {
    
    constructor(resultado,tokens,arbol,traduccion) {
        this.resultado=resultado;
        this.tokens=tokens;
        this.arbol = arbol;
        this.traduccion = traduccion;
    }
    
    /*prueba1(Entrada) {
        var parser = require('./lexico');
        return "form jison:"+parser.parse(Entrada);
    }*/
}
module.exports = Jison;
