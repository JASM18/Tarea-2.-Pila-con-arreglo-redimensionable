#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <exception>

template <typename T = int>
class Pila{
    template <typename TT>
    friend std::ostream & operator<<(std::ostream & salida, const Pila<TT> &pila);

public:
    /** Constructor por default */
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
     * \return int
     *
     */
    int ObtenerCapacidad() const;

    /** \brief
     *
     * \return void
     *
     */
    void Imprimir() const;

    class PilaVacia : public std::exception {
    public:
        PilaVacia() throw();

        virtual const char *what() const throw();
    };

private:
    int capacidad, tope; //!< Member variable "tope"
    T *elemento; //!< Member variable

    bool EstaLlena() const;

    void Redimensionar();
};

#include "Pila.tpp"

#endif // PILA_HPP
