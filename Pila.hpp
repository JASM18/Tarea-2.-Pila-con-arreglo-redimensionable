#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <exception> // Esto es para poder heredar la clase exception en PilaVacia

template <typename T = std::string> // Ahora la clase es una plantilla de clase
class Pila{
    template <typename TT>
    friend std::ostream & operator<<(std::ostream & salida, const Pila<TT> &pila);

public:
    /** Default constructor */
    Pila();

    /** \brief
     *
     * \param pila const Pila<T>&
     *
     */
    Pila(const Pila<T> &pila); // Constructor de copias

    /** \brief
     *
     *
     */
    ~Pila();

    Pila & operator=(const Pila<T> &pila);


    /** \brief
     *
     * \param valor int
     * \return void
     *
     */
    void Agregar(T valor);

    /** \brief
     *
     * \return void
     *
     */
    void Eliminar();


    /**
     * \return El valor en el tope de la pila
     */
    T ObtenerTope() const;

    /** \brief
     *
     * \return bool
     *
     */
    bool EstaVacia() const;

    /** \brief
     *
     * \return void
     *
     */
    void Vaciar();

    /** \brief
     *
     * \return int
     *
     */
    int ObtenerTam() const;

    /** \brief
     *
     * \return void
     *
     */
    void Imprimir() const;

    class PilaVacia : public std::exception { // Definimos la clase PilaVacia que va a heredar los atributos de la clase exception de forma publica
    public:
        PilaVacia() throw(); // Este indica que tipo de excepciones la funion puede lanzar, si se deja throw() significa que ese metodo no va a lanzar excepciones. ESTO ES CON EL OBJETIVO DE QUE LOS METODOS DE LA CLASE NO LANCEN EXCEPCIONES, SI NO QUE SEA LA CLASE EN SI QUE LANCE LAS EXCEPCIONES
        //virtual const char *QuePaso() const throw();
        virtual const char *what() const throw(); // Aqui estamos sobrecargando el metodo what que se heredó de la clase exception

    //private:
        //const char *mensaje;
    };

    // -> La clase en si van a ser objetos que van a ser excepciones, entonces se espera que los metodos de la clase NO LANCEN EXCEPCIONES, para eso se pone throw() en la firma de los metodos, asi forzamos a que los metodos no lancen excepciones.
    // -> Esto se hace por que si no lo hacemos asi, practicamente seria que una expecion nos esta lanzando una excepcion asi que no tendria mucho sentido eso xd

private:
    int capacidad, tope; //!< Member variable "tope"
    T *elemento; //!< Member variable

    bool EstaLlena() const;

    void Redimensionar();
};

#include "Pila.tpp"

#endif // PILA_HPP
