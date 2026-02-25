/**
 * \file main.cpp
 * \brief Cliente que prueba la plantilla de clase Pila con distintos tipos de datos.
 *
 * En este archivo se encuentra el c&oacute;digo principal que sirve como cliente de la plantilla
 * de clase Pila. Aqu&iacute; se prueban los diferentes recursos que la clase ofrece utilizando
 * varios tipos de datos como int, string y Vector.
 *
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
            Portugal Arreola, Marian Bethsab&eacute;

 * \date 23/02/2026
 */

#include <iostream>

#include "Pila.hpp"
#include "Vector.hpp"

using namespace std;

int main()
{

    // PILA DE ENTEROS
    try{
        cout << "========================================" << endl;
        cout << "-----> COMPROBANDO M\220TODOS (int) <-----" << endl;
        cout << "========================================" << endl << endl;

        Pila<int> A, B;

        cout << "-> 1. Verificando par\240metros del constructor por default..." << endl;
        cout << "Capacidad: " << A.ObtenerCapacidad() << endl;
        cout << "Elementos en la pila: " << A.ObtenerTam() << endl;
        cout << endl;


        cout << "-> 2. Agregando elementos a la pila A (0,1, ..., 12)" << endl;
        for(int i = 0 ; i < 13 ; ++i){
            A.Agregar(i);
        }

        cout << "Pila A: ";
        A.Imprimir();
        cout << endl;


        cout << "\n-> 3. Verificando el operador de asignaci\242n..." << endl;
        cout << "B = A..." << endl;
        B = A;

        cout << "Pila B:";
        B.Imprimir();
        cout << endl;


        cout << "\n-> 4. Verificando el Constructor de Copias ( Pila<int> C(A) )..." << endl;
        Pila<int> C(A);
        cout << "Pila C: ";
        C.Imprimir();
        cout << endl;


        cout << "\n-> 5. Comprobando algunos m\202todos..." << endl;
        cout << "Obtener el elemento en el tope de la pila: " << A.ObtenerTope() << endl;
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241." : "No.") << endl;
        cout << "Conocer el n\243mero de elementos que tiene la pila: " << A.ObtenerTam() << endl;
        cout << "Conocer la capacidad de la pila: " << A.ObtenerCapacidad() << endl;


        cout << "\n-> 6. Probando el m\202todo Eliminar()..." << endl;
        cout << "Eliminando el elemento del tope [" << A.ObtenerTope() << "]..." << endl;
        A.Eliminar();
        cout << "Pila A despu\202s de eliminar: ";
        A.Imprimir();
        cout << "\nNuevo tope: " << A.ObtenerTope() << endl;


        cout << "\n-> 7. Probando Redimensionar()" << endl;

        for(int i = A.ObtenerTam() ; i < 17 ; ++i){
            A.Agregar(i);
            cout << "A = ";
            A.Imprimir();
            cout << "\nCapacidad: " << A.ObtenerCapacidad() << " | Elementos: " << A.ObtenerTam() << endl;
            cout << endl;
        }


        cout << "-> 8. Vaciando la pila..." << endl;
        A.Vaciar();
        cout << "Pila A: ";
        A.Imprimir();
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241." : "No.") << endl;


        cout << "\n-> 9. Forzando la excepci\242n PilaVacia()..." << endl;
        cout << "Tope: " << A.ObtenerTope() << endl; // Esto hara que salte al catch

    }catch(Pila<int>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }
    cout << endl;

    system("pause");
    system("CLS");

    // PILA DE CADENA DE CARACTERES
    try{
        cout << "========================================" << endl;
        cout << "-----> COMPROBANDO M\220TODOS (string) <-----" << endl;
        cout << "========================================" << endl << endl;

        Pila<string> A, B;

        cout << "-> 1. Verificando par\240metros del constructor por default..." << endl;
        cout << "Capacidad: " << A.ObtenerCapacidad() << endl;
        cout << "Elementos en la pila: " << A.ObtenerTam() << endl;
        cout << endl;


        cout << "-> 2. Agregando elementos a la pila A" << endl;
        A.Agregar("Hola"); // Elemento 1
        A.Agregar("Mundo"); // Elemento 2
        A.Agregar("Cruel"); // Elemento 3
        A.Agregar("Programa"); // Elemento 4
        A.Agregar("Creado"); // Elemento 5
        A.Agregar("Por"); // Elemento 6
        A.Agregar("Axel"); // Elemento 7
        A.Agregar("y por"); // Elemento 8
        A.Agregar("Marian"); // Elemento 9
        A.Agregar("Los mas papu pros"); // Elemento 10
        A.Agregar("e11"); // Elemento 11
        A.Agregar("e12"); // Elemento 12
        A.Agregar("e13"); // Elemento 13
        A.Agregar("e14"); // Elemento 14

        cout << "Pila A: ";
        A.Imprimir();
        cout << endl;


        cout << "\n-> 3. Verificando el operador de asignaci\242n..." << endl;
        cout << "B = A..." << endl;
        B = A;

        cout << "Pila B:";
        B.Imprimir();
        cout << endl;


        cout << "\n-> 4. Verificando el Constructor de Copias ( Pila<int> C(A) )..." << endl;
        Pila<string> C(A);
        cout << "Pila C: ";
        C.Imprimir();
        cout << endl;


        cout << "\n-> 5. Comprobando algunos m\202todos..." << endl;
        cout << "Obtener el elemento en el tope de la pila: " << A.ObtenerTope() << endl;
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241." : "No.") << endl;
        cout << "Conocer el n\243mero de elementos que tiene la pila: " << A.ObtenerTam() << endl;
        cout << "Conocer la capacidad de la pila: " << A.ObtenerCapacidad() << endl;


        cout << "\n-> 6. Probando el m\202todo Eliminar()..." << endl;
        cout << "Eliminando el elemento del tope [" << A.ObtenerTope() << "]..." << endl;
        A.Eliminar();
        cout << "Pila A despu\202s de eliminar: ";
        A.Imprimir();
        cout << "\nNuevo tope: " << A.ObtenerTope() << endl;


        cout << "\n-> 7. Probando Redimensionar()" << endl;

        A.Agregar("Ya casi"); // Elemento 15
        cout << "A = ";
        A.Imprimir();
        cout << "\nCapacidad: " << A.ObtenerCapacidad() << " | Elementos: " << A.ObtenerTam() << endl;
        cout << endl;

        A.Agregar("Se duplica"); // Elemento 16
        cout << "A = ";
        A.Imprimir();
        cout << "\nCapacidad: " << A.ObtenerCapacidad() << " | Elementos: " << A.ObtenerTam() << endl;
        cout << endl;

        A.Agregar("La capacidad"); // Elemento 17
        cout << "A = ";
        A.Imprimir();
        cout << "\nCapacidad: " << A.ObtenerCapacidad() << " | Elementos: " << A.ObtenerTam() << endl;
        cout << endl;


        cout << "-> 8. Vaciando la pila..." << endl;
        A.Vaciar();
        cout << "Pila A: ";
        A.Imprimir();
        cout << endl;
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241." : "No.") << endl;


        cout << "\n-> 9. Forzando la excepci\242n PilaVacia()..." << endl;
        cout << "Tope: " << A.ObtenerTope() << endl; // Esto hara que salte al catch

    }catch(Pila<string>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }
    cout << endl;

    system("pause");
    system("CLS");

    // PILA DE VECTORES
    try{
        cout << "========================================" << endl;
        cout << "-----> COMPROBANDO M\220TODOS (Vector) <-----" << endl;
        cout << "========================================" << endl << endl;

        Pila<Vector> A, B;

        cout << "-> 1. Verificando par\240metros del constructor por default..." << endl;
        cout << "Capacidad: " << A.ObtenerCapacidad() << endl;
        cout << "Elementos en la pila: " << A.ObtenerTam() << endl;
        cout << endl;


        cout << "-> 2. Agregando elementos a la pila A" << endl;
        for(int i = 0 ; i < 13 ; ++i){
            A.Agregar(Vector(3, i));
        }

        cout << "Pila A: ";
        A.Imprimir();
        cout << endl;


        cout << "\n-> 3. Verificando el operador de asignaci\242n..." << endl;
        cout << "B = A..." << endl;
        B = A;

        cout << "Pila B:";
        B.Imprimir();
        cout << endl;


        cout << "\n-> 4. Verificando el Constructor de Copias ( Pila<int> C(A) )..." << endl;
        Pila<Vector> C(A);
        cout << "Pila C: ";
        C.Imprimir();
        cout << endl;


        cout << "\n-> 5. Comprobando algunos m\202todos..." << endl;
        cout << "Obtener el elemento en el tope de la pila: " << A.ObtenerTope() << endl;
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241." : "No.") << endl;
        cout << "Conocer el n\243mero de elementos que tiene la pila: " << A.ObtenerTam() << endl;
        cout << "Conocer la capacidad de la pila: " << A.ObtenerCapacidad() << endl;


        cout << "\n-> 6. Probando el m\202todo Eliminar()..." << endl;
        cout << "Eliminando el elemento del tope [" << A.ObtenerTope() << "]..." << endl;
        A.Eliminar();
        cout << "Pila A despu\202s de eliminar: ";
        A.Imprimir();
        cout << "\nNuevo tope: " << A.ObtenerTope() << endl;


        cout << "\n-> 7. Probando Redimensionar()" << endl;

        for(int i = A.ObtenerTam() ; i < 17 ; ++i){
            A.Agregar(Vector(3, i));
            cout << "A = ";
            A.Imprimir();
            cout << "\nCapacidad: " << A.ObtenerCapacidad() << " | Elementos: " << A.ObtenerTam() << endl;
            cout << endl;
        }

        cout << "-> 8. Vaciando la pila..." << endl;
        A.Vaciar();
        cout << "Pila A: ";
        A.Imprimir();
        cout << endl;
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241." : "No.") << endl;


        cout << "\n-> 9. Forzando la excepci\242n PilaVacia()..." << endl;
        cout << "Tope: " << A.ObtenerTope() << endl; // Esto hara que salte al catch

    }catch(Pila<Vector>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    cout << endl;

    system("pause");
    return 0;
}
