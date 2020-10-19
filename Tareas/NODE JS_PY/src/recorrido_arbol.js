//var id_n=1;
class Recorrido_Arbol{
    constructor(){
        this.grafo="";
        this.grafo2="";
        this.id_n=1;
    }
    
    recorrer_arbol(nodo){
        var concatena;
        if(nodo.tipo!=""){
            concatena= "<ul><li data-jstree= '{ \"opened\" : true }'>" + nodo.valor + " (" + nodo.tipo + ")" + "\n";
        }else{
            concatena= "<ul><li data-jstree= '{ \"opened\" : true }'>"  + nodo.valor + "\n";
        }

        nodo.hijos.forEach(element => {
            concatena += this.recorrer_arbol(element);
        });
        concatena+="</li></ul>" +"\n";
        return concatena;
    }

    recorrer_arbol2(nodo){//graphviz
        /*PARA IDS*/
        if(nodo.id==0){
            nodo.id= this.id_n;
            this.id_n++;
        }
        /* id [label= valor fillcolor="#d62728" shape="circle"]; */
        if(nodo.id!=undefined){
        this.grafo+=nodo.id + '[label= "' + nodo.valor + '" fillcolor="#d62728" shape="circle"];\n';//GGGGGGGGGGGGGGGGGGGGG
        /*console.log(nodo.id + '[label= "' + nodo.valor + '" fillcolor="#d62728" shape="circle"];');*/}
        if(nodo.hijos!=undefined){

            nodo.hijos.forEach(element =>{
                /* id -> id; */
                if(nodo.id!=undefined){
                this.grafo2+=nodo.id +'->' + this.id_n + ';\n'
                /*console.log(nodo.id +'->' + this.id_n + ';');*/}
                this.recorrer_arbol2(element);
            });
        }
    }

}

module.exports = Recorrido_Arbol;