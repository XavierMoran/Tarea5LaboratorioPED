# Tarea5LaboratorioPED

#include <iostream>
#include <string>
using namespace std;

struct Nodo{

    int id;
    int edad;
    int peso;
    string owner;
    string raza;
    
    Nodo *sig; 

};
class ListaCircularSimple
{

private:
    
    Nodo *pInicio;

public:

    ListaCircularSimple();
    ~ListaCircularSimple();
    void insertNodo();
    void insInicio(int, int, int, string, string);
    void mostrarListaID(int);
    void eliminarListaCirRec(Nodo *);

};
ListaCircularSimple::ListaCircularSimple(void)
{
    pInicio = NULL; 
                    
}
ListaCircularSimple::~ListaCircularSimple(){

    cout << "...DESTRUCTOR EJECUTANDOSE..." << endl;
    if(pInicio)
        eliminarListaCirRec(pInicio);
    
    pInicio = NULL;
}
void ListaCircularSimple::eliminarListaCirRec(Nodo *p){

    if(p->sig != pInicio)
        eliminarListaCirRec(p->sig);
    delete p;
}
void ListaCircularSimple::insInicio(int id, int edad, int peso, string owner, string raza)
{
    Nodo *nuevo, *saltarin;

    nuevo = new Nodo; 
    nuevo -> id = id; 
    nuevo -> edad = edad;
    nuevo -> peso = peso;
    nuevo -> owner = owner; 
    nuevo -> raza = raza;

    if(!pInicio){
        pInicio = nuevo;
        pInicio -> sig = pInicio;

    } else {
        nuevo -> sig = pInicio;
        Nodo *saltarin = pInicio;

        while (saltarin->sig != pInicio)
        {
            saltarin = saltarin->sig;

        }
        saltarin -> sig = nuevo;
        pInicio = nuevo;
    } 
}

void ListaCircularSimple::mostrarListaID(int id)
{
    cout << "Buscando..." << endl << endl;
    Nodo *saltarin;
    saltarin = pInicio;
    
    if(pInicio){
        do
        {
            
            if(saltarin -> id == id){
                cout << "DUEÑO: " <<saltarin ->owner << endl;
                cout << "RAZA: " << saltarin ->raza << endl;
                cout << "PESO(lb): "<< saltarin -> peso << endl;
                cout << "EDAD: "<<saltarin -> edad << endl;
            } else {
                saltarin = saltarin -> sig;
            }
        } while (saltarin != pInicio);
    }

}
int menu(){

    int opcion = 0;
    cout << endl;
    cout << "1) AGREGAR MASCOTA." << endl;
    cout << "2) MOSTRAR SU MASCOTA." << endl;
    cout << "3) ELIMINAR." << endl;
    cout << "OPCION: ";
    cin >> opcion; cin.ignore();

    cout << endl;
    return opcion;
}

int main(void)
{
    
    ListaCircularSimple objListaCircular;
    cout << endl;
    cout << "ADMINISTRACION DE VETERINARIA" << endl;

    string nombre = "", owner = "", raza = "";
    int edad = 0, peso = 0, id = 0;
    bool opcion = true;
    int p = 0;

    do {
        switch (menu())
        {
            
        case 1:
            cout << "ID: ";
            cin >> id; cin.ignore();

            cout << "NOMBRE DEL DUEÑO: ";
            getline(cin, owner);

            cout << "RAZA: ";
            getline(cin, raza);

            cout << "PESO(lb): ";
            cin >> peso;

            cout << "EDAD: ";
            cin >> edad; cin.ignore();
            objListaCircular.insInicio(id, edad, peso, owner, raza);
            break;
            
        case 2:
            cout << "INGRESAR ID DE LA MASCOTA PARA BUSCAR: ";
            cin >> p;

            objListaCircular.mostrarListaID(p);
            break;
        
        case 3:
            opcion = false;
            break;

        default:
        
            break;
        }

    }while(opcion);

    
    cout << endl;
    return 0;
}
