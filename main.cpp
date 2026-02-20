#include <iostream>

#include "Pila.hpp"
#include "Vector.hpp"

using namespace std;

int main()
{

    // PILA DE ENTEROS
    try{
        cout << "-----> PILA DE ENTEROS <-----" << endl;
        Pila<int> A; // La pila es una pila de enteros

        A.Imprimir();

        for(int i = 0 ; i < 5 ; ++i){
            A.Agregar(i);
        }

        A.Agregar(6);

        cout << endl;

        A.Imprimir();

    }catch(Pila<int>::PilaVacia &errorVacio){
        //cerr << "Error: " << errorVacio.QuePaso() << endl;
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }
    cout << endl;

    // PILA DE CARACTERES
    try{
        cout << "-----> PILA DE CARACTERES <-----" << endl;
        Pila<char> A; // La pila es una pila de caracteres

        //cout << A.ObtenerTope() << endl;

        A.Imprimir();
        cout << endl;

        A.Agregar('a');

        A.Imprimir();

        A.Agregar('x');

        A.Imprimir();

    }catch(Pila<char>::PilaVacia &errorVacio){
        //cerr << "Error: " << errorVacio.QuePaso() << endl;
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }
    cout << endl;

    // PILA DE CADENA DE CARACTERES
    try{
        cout << "-----> PILA DE CADENA DE CARACTERES <-----" << endl;
        Pila<string> A; // La pila es una pila de cadena de caracteres

        A.Imprimir();
        cout << endl;

        A.Agregar("hola");

        A.Imprimir();

        A.Agregar("mundo");

        A.Imprimir();

    }catch(Pila<string>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }
    cout << endl;

    // PILA DE VECTORES
    try{
        cout << "-----> PILA DE VECTORES <-----" << endl;
        Pila<Vector> A; // La pila es una pila de vectores

        A.Imprimir();
        cout << endl;

        A.Agregar(Vector(5,1));

        A.Imprimir();

        A.Agregar(Vector(2,1.5));

        A.Imprimir();

    }catch(Pila<Vector>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }
    cout << endl;

    // PILA DE PILAS
    try{
        cout << "-----> PILA DE PILAS DE ENTERO <-----" << endl;
        Pila<Pila<int>> p; // La pila es una pila de pilas de enteros
        Pila<int> pilita;

        p.Imprimir();
        cout << endl;

        p.Agregar(pilita);

        p.Imprimir();

        pilita.Agregar(-4);

        p.Agregar(pilita);

        p.Imprimir();
        cout << endl;

        pilita.Agregar(5);
        pilita.Agregar(0);
        pilita.Agregar(145);

        p.Agregar(pilita);

        p.Imprimir();
        cout << endl;

    }catch(Pila<int>::PilaVacia &errorVacio){
        cerr << "Error en la pilita: " << errorVacio.what() << endl;
    }catch(Pila<Pila<int>>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }

    return 0;
}

