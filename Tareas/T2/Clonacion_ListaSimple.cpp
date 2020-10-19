#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using namespace std;

class Estudiante{
    public:
        string nombre;
        string carnet;

        Estudiante() {}//constructor empy

        Estudiante(string nombre1, string carnet1) {
            nombre = nombre1;
            carnet = carnet1;
        }//constructor 

        string toString() {
            stringstream s;
            s << "Carnet: " << carnet << " | Nombre: " << nombre << endl;
            return s.str();
        }//toString
};//clase estudiante basica

class Nodo {
    public:
        Estudiante* alumno;
        Nodo* siguiente = NULL ;

        //constructor vacio del nodo
        Nodo() {}

        //constructor del nodo
        Nodo(Estudiante* alumnoPrimi) {
            alumno = alumnoPrimi;
        }

        //agregar un siguiente nodo
        void Agregar_Nodo(Nodo* nodoNew) {
            siguiente = nodoNew;
        }


};


class ListaSimple {
    public:
            int tam=0;
            Nodo* Primi;

            ListaSimple() {
                Primi = NULL;
            }// fin constructor

            bool ListaEmpy() {
                return Primi == NULL;// 1 es true 0 es false
            }//fin de si esta vacio

 //*******************************************************************************  TAREA 2  ********************************************************************************************
            Estudiante* obtenerNodoInIndex(int pos) {
                Nodo* Mold = Primi;	//constante =1

                //cambiar a for
                for (int i = 0; i < pos; i++) {		//bucle hasta pos=n

                    Mold = Mold->siguiente;//encontrar objeto	constante=1
                }
                return Mold->alumno;//retorno usuario	//constante=1
            }//fin funcion
    //1+n+1   == 2+n
 //***************************************************************************************************************************************************************************************         


            ListaSimple* ClonarLista(ListaSimple* l) {

                Nodo* Mold = Primi;	//constante =1

                if (tam>0) { 
                    //cambiar a for
                    for (int i = 0; i < tam; i++) {		//bucle hasta tam=n 

                        l->AgregarEstudiante(Mold->alumno); //tam=n -> (5+n cuando es exitosa la operacion y hay elementos)/si esta vacia es igual a constante = 2
                        Mold = Mold->siguiente;         //encontrar objeto	constante=1

                    }
                    return l;//retorno usuario	//constante=1
                
                }
                return l;// esto en el caso de q la lista este vacia
            }//fin funcion:   2+n(5+n) = n^2+5n+2 procesos solucion: O(n^2)


            void AgregarEstudiante(Estudiante* a) {
           
                //si la cabeza es null
              if (Primi == NULL) {
                   Primi = new Nodo(a);
                   tam++;              
               }
               else {
                   //hay elementos en la lista
                   if (Primi->alumno->carnet!=a->carnet) {
                       Nodo *aux = Primi;
                       bool crear = true;
                       while (aux->siguiente != NULL) {
                           aux = aux->siguiente;
                           if (aux->alumno->carnet==a->carnet) {
                               crear = false;//para evitar q se repitan
                           }
                       }//fin de while
                       if (crear == true) {                      
                           Nodo *alumn = new Nodo(a);//creo el nodo con el producto q me envian
                           aux->Agregar_Nodo(alumn);
                           tam++;                      
                       }
                   }
               }

            }//fin metodo agregar

            string BusquedaEstudiante(string carnet) {

                Nodo* aux3 = Primi;
                //cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$" << aux3->alumno->toString() << endl;
                while (aux3->siguiente != NULL && aux3->alumno->carnet != carnet) {
               
                    aux3 = aux3->siguiente;
                    //cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$"<< aux3 ->alumno->toString()<< endl;
                }

                if (aux3->alumno->carnet == carnet) {
                    return aux3->alumno->toString();
                }
                else {
                    return "no existe el valor";
                }




            }// fin metodo buscar

            void EliminarEstudiante(string carnet) {
                Nodo* aux = Primi;
                Nodo* anterior = NULL;

                for (int i = 0; i < tam; i++) {
                    if (aux->alumno->carnet != carnet && aux->siguiente!=NULL) {// no se encontro alumno
                        anterior = aux;
                        aux = aux->siguiente;//

                    }
                    else {//encontro alumno
                        //ahora vienen los casos

                        //si es la cabeza
                        if (aux->alumno->carnet == Primi->alumno->carnet && Primi->siguiente != NULL) {
                           // cout << "?????????????????????????? se borro! la cabeza pero habia otro despues" << Primi->alumno->toString() << endl;
                            Nodo* aux2 = Primi;
                            Primi = Primi->siguiente;
                            delete aux2;
                            tam--;

                        
                            break;
                        }
                        else if(aux->alumno->carnet == Primi->alumno->carnet && Primi->siguiente == NULL) {
                            //Primi = NULL;
                            delete Primi;
                        
                            //cout << "?????????????????????????? se borro la cabeza " << endl;
                        }

                        // si esta en medio o al final
                        if (aux->siguiente != NULL) {
                            //cout << "?????????????????????????? se borro! intermedio " << aux->alumno->toString() << endl;
                            anterior->siguiente = aux->siguiente;
                            delete aux;
                            //cout << "?????????????????????????? se borro! intermediozz "<< anterior->alumno->toString()<<"->" << anterior->siguiente->alumno->toString() << endl;
                            tam--;
                            break;
                        }
                        else {
                           // cout << "?????????????????????????? se borro! el ultimo " << aux->alumno->toString() << endl;
                            anterior->siguiente = NULL;
                            delete aux;
                            tam--;
                            break;
                        }

                    }
                }//fin de for
            }        
};
//*******************************************************************************  TAREA 2  ********************************************************************************************
ListaSimple* ClonarLista(ListaSimple* l) {
    //clonar lista Tarea 2 EDD y calcular complejidad

    ListaSimple* listaClon = new ListaSimple();				//Constante = 1

    if (l->tam == 0) { return 0; }					//Constante = 1
    else {
        for (int i = 0; i < l->tam; i++) {				//Bucle hasta tam donde tam= n / para i++ : constante=1
            listaClon->AgregarEstudiante(l->obtenerNodoInIndex(i));	//hace 2+n procesos (ver funcion hasta arriba!)
        }//fin for
        return listaClon;     						//Constante = 1 
    }
}// fin funcion clonar


// si entra al if hace 2 procesos
// de lo contrario hace 2+n(2+n) == n^2 +2n+2 procesos solucion: O(n^2)

//***************************************************************************************************************************************************************************************         


int main()
{
    Estudiante *javier = new Estudiante("javier", "2017");
    Estudiante* javier1 = new Estudiante("javier1", "2018");
    Estudiante* javier2 = new Estudiante("javier2", "2019");
 
    ListaSimple *listal= new ListaSimple();

    listal->AgregarEstudiante(javier);
    listal->AgregarEstudiante(javier1);
    listal->AgregarEstudiante(javier2);


    /*  cout <<"lista vacia? (1) si / (0) no |" <<listal->ListaEmpy() << endl;
    cout << "tam:" << listal->tam << endl;

    listal->AgregarEstudiante(javier);  

    cout << "-------------------se agrego 1 alumno------------------------" << endl;
    cout << "tam alpha:" << listal->tam << endl;

    cout << "------------------busqueda-------------------------" << endl;
    string auc4 = listal->BusquedaEstudiante("2017");
    cout << "busqueda: " << auc4 << endl;


    listal->AgregarEstudiante(javier1);
    listal->AgregarEstudiante(javier2);
    cout << "-------------------se agregaron 2 alumnos mas------------------------" << endl;
    cout << "tam beta:"<<listal->tam << endl;
    
    cout << "------------------busqueda 2-------------------------" << endl;
    string auc = listal->BusquedaEstudiante("2019");
    cout <<"busqueda: " <<auc << endl;
    
    cout << "&&&&&&&&&&&&&&&&&&& eliminar &&&&&&&&&&&&&&&&&&&&&7" << endl;
    listal->EliminarEstudiante("2018");
    cout << "tam despues de eliminar:" << listal->tam << endl;

    listal->AgregarEstudiante(javier1);
    cout << "-------------------se agrego 1 alumno------------------------" << endl;
    cout << "tam alpha:" << listal->tam << endl;
    
    cout << "&&&&&&&&&&&&&&&& busqueda post eliminar &&&&&&&&&&&&&&&&&&" << endl;
    string auc1 = listal->BusquedaEstudiante("2018");
    cout << "busqueda: " << auc1 << endl;


    FFFFFFFFFFFFFFFFFFFFFFF
    ListaSimple* xd = new ListaSimple();

    xd = listal->ClonarLista(xd);
    cout << "tam:" << xd->tam << endl;  //comprobamos si el tamanyo es el mismo

    string auc4 = xd->BusquedaEstudiante("2017");//verificamos si el objeto estudiante esta!
    cout << "busqueda: " << auc4 << endl;// imprimimos la busqueda del estudiante

    */



//------------------------------------------- TAREA 2------------------------------------------------
   ListaSimple *xd = ClonarLista(listal);//lista clon devuelta por el metodo ClonarLista
    cout << "tam:" << xd->tam << endl;  //comprobamos si el tamanyo es el mismo

    string auc4 = xd->BusquedaEstudiante("2017");//verificamos si el objeto estudiante esta!
    cout << "busqueda: " << auc4 << endl;// imprimimos la busqueda del estudiante


    // en total se realizan: 2+n(2+n) == n^2+2n+2 procesos solucion: O(n^2)

//-----------------------------------------------------------------------------------------------------------------------------




    delete listal;
    delete xd;
    delete javier;
    delete javier1;
    delete javier2;

    return 0;
}
