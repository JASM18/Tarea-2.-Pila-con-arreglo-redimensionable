/**
 * \file Pila.hpp
 * \brief Archivo que contiene la definición de la plantilla de clase Pila con un arreglo redimensionable.
 *
 * Este archivo declara la clase genérica Pila, que implementa una estructura de datos tipo pila
 * capaz de almacenar elementos de cualquier tipo y ajustar su capacidad de forma dinámica.
 *
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
            Portugal Arreola, Marian Bethsab&eacute;
 * \date 20/02/2026
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
 * Esta clase define una pila genérica que permite almacenar datos de cualquier tipo.
 * Utiliza un arreglo dinámico que puede duplicar su capacidad cuando es necesario.
 *
 * \tparam T Tipo de dato que almacenará la pila.
 */
template <typename T = int>
class Pila {
    /** \brief Función friend que permite imprimir el contenido de la pila usando el operador '<<'.
     *
     * \tparam TT Tipo de dato de la pila que se imprimirá.
     * \param salida Flujo de salida donde se mostrarán los elementos.
     * \param pila Referencia constante a la pila que se imprimirá.
     * \return Referencia al flujo de salida (std::ostream).
     */
    template <typename TT>
    friend std::ostream &operator<<(std::ostream &salida, const Pila<TT> &pila);

public:
    /** \brief Constructor por defecto de la clase Pila.
     *
     * Inicializa la pila con una capacidad base y asigna memoria dinámica
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
     * Libera la memoria asignada dinámicamente al destruir el objeto.
     */
    ~Pila();

    /** \brief Sobrecarga del operador de asignación.
     *
     * Permite copiar el contenido de una pila a otra asegurando que ambas
     * mantengan independencia en memoria.
     *
     * \param pila Referencia constante a la pila origen.
     * \return Referencia a la pila actual después de la asignación.
     * \throw std::bad_alloc Si ocurre un error de memoria durante la copia.
     */
    Pila &operator=(const Pila<T> &pila);

    /** \brief Función que agrega un nuevo elemento al tope de la pila.
     *
     * Si la pila está llena, se redimensiona automáticamente antes de insertar
     * el nuevo valor.
     *
     * \param valor Elemento que se insertará en el tope de la pila.
     */
    void Agregar(T valor);

    /** \brief Función que elimina el elemento del tope de la pila.
     *
     * \pre La pila no debe estar vacía para eliminar un elemento.
     * \throw PilaVacia Si se intenta eliminar un elemento de una pila vacía.
     */
    void Eliminar();

    /** \brief Función que obtiene el elemento actual en el tope de la pila.
     *
     * \return Valor almacenado en el tope.
     * \pre La pila no debe estar vacía para acceder al tope.
     * \throw PilaVacia Si la pila se encuentra vacía.
     */
    T ObtenerTope() const;

    /** \brief Función que determina si la pila está vacía.
     *
     * \return true si no hay elementos en la pila, false en caso contrario.
     */
    bool EstaVacia() const;

    /** \brief Función que vacía por completo la pila.
     *
     * Establece el índice del tope a -1, eliminando lógicamente los elementos.
     */
    void Vaciar();

    /** \brief Función que devuelve la cantidad de elementos actuales en la pila.
     *
     * \return Número de elementos almacenados actualmente.
     */
    int ObtenerTam() const;

    /** \brief Función que devuelve la capacidad total del arreglo dinámico.
     *
     * \return Capacidad máxima actual de la pila.
     */
    int ObtenerCapacidad() const;

    /** \brief Función que imprime los elementos de la pila (solo para pruebas).
     *
     * Muestra los elementos desde el tope hasta la base.
     */
    void Imprimir() const;

    /**
     * \brief Clase interna que representa una excepción lanzada cuando se intenta operar con una pila vacía.
     */
    class PilaVacia : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepción PilaVacia.
         */
        PilaVacia() throw();

        /** \brief Devuelve una descripción del error al intentar operar con una pila vacía.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:
    int capacidad;      /// Capacidad actual del arreglo que almacena los elementos.
    int tope;           /// Índice del elemento en el tope de la pila (-1 indica que está vacía).
    T *elemento;        /// Puntero al arreglo dinámico que contiene los elementos.

    /** \brief Función que determina si la pila está llena.
     *
     * \return true si la pila ha alcanzado su capacidad máxima, false en caso contrario.
     */
    bool EstaLlena() const;

    /** \brief Función que duplica la capacidad del arreglo dinámico.
     *
     * Se utiliza internamente cuando la pila necesita más espacio.
     *
     * \warning Esta operación puede consumir más memoria y requiere copiar los elementos existentes.
     * \throw std::bad_alloc Si falla la asignación de nueva memoria.
     */
    void Redimensionar();
};

#include "Pila.tpp"

#endif // PILA_HPP
