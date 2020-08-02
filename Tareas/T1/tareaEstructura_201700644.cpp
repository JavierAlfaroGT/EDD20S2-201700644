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

        string obtenerNodoInIndex(int pos) {

            Nodo *Mold = Primi;

            //cambiar a for
            for (int i = 0; i < pos; i++) {

                Mold = Mold->siguiente;//encontrar objeto

            }
            return Mold->alumno->toString();//retorno usuario
        }//fin funcion

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
                        Primi = Primi->siguiente;
                        tam--;
                        break;
                    }
                    else if(aux->alumno->carnet == Primi->alumno->carnet && Primi->siguiente == NULL) {
                        Primi = NULL;
                        //cout << "?????????????????????????? se borro la cabeza " << endl;
                    }

                    // si esta en medio o al final
                    if (aux->siguiente != NULL) {
                        //cout << "?????????????????????????? se borro! intermedio " << aux->alumno->toString() << endl;
                        anterior->siguiente = aux->siguiente;
                        //cout << "?????????????????????????? se borro! intermediozz "<< anterior->alumno->toString()<<"->" << anterior->siguiente->alumno->toString() << endl;
                        tam--;
                        break;
                    }
                    else {
                       // cout << "?????????????????????????? se borro! el ultimo " << aux->alumno->toString() << endl;
                        anterior->siguiente = NULL;
                        tam--;
                        break;
                    }

                }
            }//fin de for
        }        
};



int main()
{
    Estudiante *javier = new Estudiante("javier", "2017");
    Estudiante* javier1 = new Estudiante("javier1", "2018");
    Estudiante* javier2 = new Estudiante("javier2", "2019");
 
    ListaSimple listal;
    cout <<"lista vacia? (1) si / (0) no |" <<listal.ListaEmpy() << endl;
    cout << "tam:" << listal.tam << endl;

    listal.AgregarEstudiante(javier);  
    cout << "-------------------se agrego 1 alumno------------------------" << endl;
    cout << "tam alpha:" << listal.tam << endl;

    cout << "------------------busqueda-------------------------" << endl;
    string auc4 = listal.BusquedaEstudiante("2017");
    cout << "busqueda: " << auc4 << endl;


    listal.AgregarEstudiante(javier1);
    listal.AgregarEstudiante(javier2);
    cout << "-------------------se agregaron 2 alumnos mas------------------------" << endl;
    cout << "tam beta:"<<listal.tam << endl;
    
    cout << "------------------busqueda 2-------------------------" << endl;
    string auc = listal.BusquedaEstudiante("2019");
    cout <<"busqueda: " <<auc << endl;
    
    cout << "&&&&&&&&&&&&&&&&&&& eliminar &&&&&&&&&&&&&&&&&&&&&7" << endl;
    listal.EliminarEstudiante("2018");
    cout << "tam despues de eliminar:" << listal.tam << endl;

    listal.AgregarEstudiante(javier1);
    cout << "-------------------se agrego 1 alumno------------------------" << endl;
    cout << "tam alpha:" << listal.tam << endl;
    
    cout << "&&&&&&&&&&&&&&&& busqueda post eliminar &&&&&&&&&&&&&&&&&&" << endl;
    string auc1 = listal.BusquedaEstudiante("2018");
    cout << "busqueda: " << auc1 << endl;

    return 0;
}
