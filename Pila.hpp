/**
 * \file Pila.hpp
 * \brief Archivo que contiene la definici&oacute;n de la plantilla de clase Pila con un arreglo redimensionable.
 *
 * Este archivo declara la clase gen&eacute;rica Pila, que implementa una estructura de datos tipo pila
 * capaz de almacenar elementos de cualquier tipo y ajustar su capacidad de forma din&aacute;mica.
 *
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
            Portugal Arreola, Marian Bethsab&eacute;
 * \date 23/02/2026
 *
 * \code{.cpp}

#include <iostream>

#include "Pila.hpp"

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
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241" : "No") << endl;
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
        cout << "\250La pila esta vac\241a?: " << (A.EstaVacia() ? "S\241" : "No") << endl;


        cout << "\n-> 9. Forzando la excepci\242n PilaVacia()..." << endl;
        cout << "Tope: " << A.ObtenerTope() << endl; // Esto hara que salte al catch

    }catch(Pila<int>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    system("pause");
    return 0;
}
 * \endcode
 */

#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <exception>

/**
 * \brief Plantilla de clase que implementa una pila con arreglo redimensionable.
 *
 * Esta clase define una pila gen&eacute;rica que permite almacenar datos de cualquier tipo.
 * Utiliza un arreglo din&aacute;mico que puede duplicar su capacidad cuando es necesario.
 *
 * \tparam T Tipo de dato que almacenar&aacute; la pila.
 */
template <typename T = int>
class Pila {
    /** \brief Funci&oacute;n friend que permite imprimir el contenido de la pila usando el operador '<<'.
     *
     * \tparam TT Tipo de dato de la pila que se imprimir&aacute;.
     * \param salida Flujo de salida donde se mostrar&aacute;n los elementos.
     * \param pila Referencia constante a la pila que se imprimir&aacute;.
     * \return Referencia al flujo de salida (std::ostream).
     */
    template <typename TT>
    friend std::ostream &operator<<(std::ostream &salida, const Pila<TT> &pila);

public:
    /** \brief Constructor por defecto de la clase Pila.
     *
     * Inicializa la pila con una capacidad base y asigna memoria din&aacute;mica
     * para almacenar los elementos.
     *
     * \throw std::bad_alloc Si no hay memoria disponible para crear el arreglo.
     */
    Pila();

    /** \brief Constructor de copias de la clase Pila.
     *
     * Crea una nueva pila copiando los datos de otra existente.
     *
     * \param pila Referencia constante a la pila que se va a copiar.
     */
    Pila(const Pila<T> &pila);

    /** \brief Destructor de la clase Pila.
     *
     * Libera la memoria asignada din&aacute;micamente al destruir el objeto.
     */
    ~Pila();

    /** \brief Sobrecarga del operador de asignaci&oacute;n.
     *
     * Permite copiar el contenido de una pila a otra asegurando que ambas
     * mantengan independencia en memoria.
     *
     * \param pila Referencia constante a la pila origen.
     * \return Referencia a la pila actual despu&eacute;s de la asignaci&oacute;n.
     * \throw std::bad_alloc Si ocurre un error de memoria durante la copia.
     */
    Pila &operator=(const Pila<T> &pila);

    /** \brief Funci&oacute;n que agrega un nuevo elemento al tope de la pila.
     *
     * Si la pila est&aacute; llena, se redimensiona autom&aacute;ticamente antes de insertar
     * el nuevo valor.
     *
     * \param valor Elemento que se insertar&aacute; en el tope de la pila.
     */
    void Agregar(T valor);

    /** \brief Funci&oacute;n que elimina el elemento del tope de la pila.
     *
     * \pre La pila no debe estar vac&iacute;a para eliminar un elemento.
     * \throw PilaVacia Si se intenta eliminar un elemento de una pila vac&iacute;a.
     */
    void Eliminar();

    /** \brief Funci&oacute;n que obtiene el elemento actual en el tope de la pila.
     *
     * \return Valor almacenado en el tope.
     * \pre La pila no debe estar vac&iacute;a para acceder al tope.
     * \throw PilaVacia Si la pila se encuentra vac&iacute;a.
     */
    T ObtenerTope() const;

    /** \brief Funci&oacute;n que determina si la pila est&aacute; vac&iacute;a.
     *
     * \return true si no hay elementos en la pila, false en caso contrario.
     */
    bool EstaVacia() const;

    /** \brief Funci&oacute;n que vac&iacute;a por completo la pila.
     *
     * Establece el &iacute;ndice del tope a -1, eliminando l&oacute;gicamente los elementos.
     */
    void Vaciar();

    /** \brief Funci&oacute;n que devuelve la cantidad de elementos actuales en la pila.
     *
     * \return N&uacute;mero de elementos almacenados actualmente.
     */
    int ObtenerTam() const;

    /** \brief Funci&oacute;n que devuelve la capacidad total del arreglo din&aacute;mico.
     *
     * \return Capacidad m&aacute;xima actual de la pila.
     */
    int ObtenerCapacidad() const;

    /** \brief Funci&oacute;n que imprime los elementos de la pila (solo para pruebas).
     *
     * Muestra los elementos desde el tope hasta la base.
     */
    void Imprimir() const;

    /**
     * \brief Clase interna que representa una excepci&oacute;n lanzada cuando se intenta operar con una pila vac&iacute;a.
     */
    class PilaVacia : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n PilaVacia.
         */
        PilaVacia() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una pila vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:
    int capacidad;      /// Capacidad actual del arreglo que almacena los elementos.
    int tope;           /// Índice del elemento en el tope de la pila (-1 indica que está vacía).
    T *elemento;        /// Puntero al arreglo dinámico que contiene los elementos.

    /** \brief Funci&oacute;n que determina si la pila est&aacute; llena.
     *
     * \return true si la pila ha alcanzado su capacidad m&aacute;xima, false en caso contrario.
     */
    bool EstaLlena() const;

    /** \brief Funci&oacute;n que duplica la capacidad del arreglo din&aacute;mico.
     *
     * Se utiliza internamente cuando la pila necesita m&aacute;s espacio.
     *
     * \warning Esta operaci&oacute;n puede consumir m&aacute;s memoria y requiere copiar los elementos existentes.
     * \throw std::bad_alloc Si falla la asignaci&oacute;n de nueva memoria.
     */
    void Redimensionar();
};

#include "Pila.tpp"

#endif // PILA_HPP
