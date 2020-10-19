class Nodo_arbol {
    constructor(valor,tipo) {
        this.valor=valor;
        this.tipo=tipo;
        this.hijos=[];
        this.id=0;
        this.txt="";//F
        this.cadena=[];//F
    }//fin de constructor
    
    agregarHijo(hijo){
        this.hijos.push(hijo);      
    }

    insertarTXT(txt1){//F
        this.txt+= txt1 ;
    }

    translate(cadena){
        this.cadena.push(cadena);//F  
    }


    recorrer_arbol(nodo){
        var concatena;
        if(nodo.tipo!="" && nodo.valor!=undefined){
            concatena= "" + nodo.valor + "";
        }else{
            concatena= /*""  + nodo.valor + */"";
        }
        if(nodo.hijos!=undefined){
        nodo.hijos.forEach(element => {
            concatena += this.recorrer_arbol(element);
        });
    }
        //concatena+="</li></ul>" +"\n";
        return concatena;
    }
    recorrer_arbol2(nodo){
        var concatena;
        if(nodo.tipo!="" && nodo.valor!=undefined &&nodo.valor!="epsilon"){
            concatena= "" + nodo.valor + "";
        }else{
            concatena= /*""  + nodo.valor + */"";
        }
        if(nodo.hijos!=undefined){
        nodo.hijos.forEach(element => {
            concatena += this.recorrer_arbol2(element);
        });
    }
        //concatena+="</li></ul>" +"\n";
        return concatena;
    }

    recorrer_arbolPRINTS(nodo){
        var concatena;
        if(nodo.tipo!="" && nodo.valor!=undefined &&nodo.valor!="epsilon" && nodo.tipo!="System"&&nodo.tipo!="punto"&&nodo.tipo!="out"&&nodo.tipo!="print"&&nodo.tipo!="pa"&&nodo.tipo!="pc"&&nodo.tipo!="pyc" ){
            concatena= "" + nodo.valor + "";
        }else{
            concatena= /*""  + nodo.valor + */"";
        }
        if(nodo.hijos!=undefined){
        nodo.hijos.forEach(element => {
            
            concatena += this.recorrer_arbolPRINTS(element);
            

        });
    }
        //concatena+="</li></ul>" +"\n";
        
        return concatena;
    }

    recorrer_arbolM(nodo){
        var concatena;
        if(nodo.tipo!="" && nodo.valor!=undefined &&nodo.valor!="epsilon"){
            if(nodo.valor=="}" || nodo.valor=="{"){concatena= "\n" + nodo.valor + "\n";}else{
          
                switch(nodo.valor) {
                    case "int":
                    case "String":
                    case "boolean":
                    case "char":
                    case "double":
                      concatena= "var " + nodo.valor + "";
                      break;
                    default:
                       concatena= "" + nodo.valor + "";
                    }
        
        }
        }else{
            concatena= /*""  + nodo.valor + */"";
        }

        /*if(nodo.hijos!=undefined && nodo.valor=="LISTAPARAMETROS_FOR"){
            nodo.hijos.forEach(element => {
                concatena += ""+this.recorrer_arbolM2(element);
            });
        }*/

        if(nodo.hijos!=undefined && nodo.valor!="LCUERPOMETODO2"){
        nodo.hijos.forEach(element => {
            concatena += this.recorrer_arbolM(element);
        });
    }

        if(nodo.hijos!=undefined && nodo.valor=="LCUERPOMETODO2"){
            nodo.hijos.forEach(element => {
                concatena += ""+this.recorrer_arbolM2(element);
            });
        }

        


        //concatena+="</li></ul>" +"\n";
        return concatena;
    }

    recorrer_arbolM2(nodo){
        var concatena;
        if(nodo.tipo!="" && nodo.valor!=undefined &&nodo.valor!="epsilon"){

            switch(nodo.valor) {
                case "{":
                case "}":
                  concatena= "\n" + nodo.valor + "\n";
                  break;
                case "int":
                case "String":
                case "boolean":
                case "char":
                case "double":
                  concatena= "var " + nodo.valor + "";
                  break;
                case ";":
                  concatena= "" + nodo.valor + "\n";
                  break;
                case "":
                  concatena= "" + nodo.valor + "\n";
                  break;
                case "System":
                case "out":
                case ".":
                    concatena= "";
                    break;
                case "println":
                case "print":
                    concatena= "console.log";
                    break;
                default:
                  // code block
                  concatena= "" + nodo.valor + "";
              }

        }else{
            concatena= /*""  + nodo.valor + */"";
        }
        if(nodo.hijos!=undefined){
        nodo.hijos.forEach(element => {
            concatena += this.recorrer_arbolM2(element);
        });
    }
        concatena+="";
        return concatena;
    }

     
}//fin de clase
module.exports = Nodo_arbol;