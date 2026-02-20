/**
    * \file Vector.hpp
    * Archivo de definición de la clase
    * \author Jesús Axel Sanchez Montoy
    * \date 23/01/2026
    \ code{.cpp}

    #include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
    try{

        int dim;

        cout << "Porgrama que hace operaciones con vectores en R^n" << endl;

        cout << "Ingresa la dimension: ";
        cin >> dim;

        cout << "\nconst Vector t = ";

        Vector u(dim), v(dim);


        //Vector v; // Aqui se usa el constructor por default
        //Vector v(5); // Aqui se usa el segundo constructor, el cual se dice que esta sobre cargado, lo que pasa aqui es que se esta declarando un vector con dimension 5
        //Vector v(4, 3.14); //Aqui es el tercer constructor

        const Vector t(dim, 2.5); // Un const Vector es un dato de tipo Vector que es constante, osea que sus parametros nunca va a cambiar
        t.Imprimir();


        //INVESTIGAR QUE OPERADORES EN C++ NO SE PUEDEN SOBRECARGAR

        cout << "\n\n-> Capturando las " << u.ObtenerDim() << " entradas del primer:\n";
        cin >> u;
        cout << "\nU = " << u;

        cout << "\n\n-> Capturando las " << v.ObtenerDim() << " entradas del segundo:\n";
        cin >> v;
        cout << "\nV = " << v;

        cout << "\n\n";
        system("pause");
        system("CLS");

        cout << "===== OPERACIONES CON METODOS DE CLASE =====" << endl;;

        cout << "\nU = " << u;

        cout << "\nV = " << v;

        cout << "\n\n=====\nSUMANDO LOS VECTORES\n=====\n" << endl;

        //Vector v3 = u.SumaVectores(v);

        cout << "U = " << u;

        cout << "\nV = " << v;
        cout << " \nU + V = ";
        u.SumaVectores(v).Imprimir();
        //v3.Imprimir();

        cout << "\n\n=====\nRESTANDO LOS VECTORES\n=====\n" << endl;

        cout << "U = " << u;

        cout << "\nV = " << v;
        cout << " \nU - V = ";
        u.RestaVectores(v).Imprimir();
        //v3.Imprimir();

        cout << "\n\n=====\nPRODUCTO PUNTO\n=====\n" << endl;

        cout << "U = " << u;

        cout << "\nV = " << v;

        cout << "\nU\372V = " << u.ProductoPunto(v);

        cout << "\n\n=====\nESCALAR\n=====\n" << endl;

        float escalar;

        cout << "Ingresa tu escalar: ";
        cin >> escalar;

        cout << "\n" << escalar << " * " << u << " = ";
        u.MultiplicarEscalar(escalar).Imprimir();

        cout << "\n" << escalar << " * " << v << " = ";
        v.MultiplicarEscalar(escalar).Imprimir();

        cout << "\n\n=====\nMAGNITUD\n=====\n" << endl;

        cout << "|U| = " << u.ObtenerMagnitud();
        cout << "\n|V| = " << v.ObtenerMagnitud();

        cout << "\n\n";
        system("pause");
        system("CLS");

        //Clase 21/Ene/2026
        // Estaria bien chido poder sumar vectores de la forma s = u + v; no?

        // Operadores binarios:
        // x - y
        // x = y
        // x > y
        // x * y
        // x & y // Esto es una conjuncion en binario

        //Operadores monario:
        // -x
        // +x
        // *x // "A lo que apunta x (puntero)
        // &x // "Referencia"
        // new TipoDeDato

        cout << "===== OPERACIONES CON OPERADORES SOBRECARGADOS =====" << endl;;

        cout << "\nU = " << u;

        cout << "\nV = " << v;

        cout << "\n\n=====\nSUMANDO CON SOBRECARGA DE OPERADORES\n=====\n" << endl;

        Vector s;

        s = u + v;

        cout << "U = "<< u;

        cout << "\nV = " << v;
        cout << " \nU + V = " << s;

        cout << "\n\n=====\nRESTANDO CON SOBRECARGA DE OPERADORES\n=====\n" << endl;

        s = u - v;

        cout << "U = " << u;

        cout << "\nV = " << v;
        cout << " \nU - V = " << s;

        cout << "\n\n=====\nPRODUCTO PUNTO\n=====\n" << endl;

        cout << "U = " << u;

        cout << "\nV = " << v;

        cout << "\nU\372V = " << u*v;

        cout << "\n\n=====\nESCALAR (Simple)\n=====\n" << endl;

        cout << u << " * " << escalar << " = ";
        s = u*escalar;
        cout << s;

        s = v*escalar;
        cout << "\n" << v << " * " << escalar << " = " << s;

        cout << "\n\n=====\nESCALAR (Friend y comnutativo)\n=====\n" << endl;

        s = escalar*u;
        cout << u << " * " << escalar << " = " << s;

        s = escalar*v;
        cout << "\n" << v << " * " << escalar << " = " << s;

        cout << endl;

        cout << "\n\n";
        system("pause");
        system("CLS");

        s = u + v;

        Vector h;

        h = s = v;

        cout << s << endl << h << endl;

    }catch(const char *mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(bad_alloc &){
        cerr << "Error en la asignaci242n de memoria" << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado\n";
    }

    return 0;
}

    \endcode
*/


#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
using std::ostream;

#define MAX_DIM 100

//const int MAX_DIM = 100;

/**
 *
 */
class Vector{
    //friend void operator<<(ostream & salida, Vector v);
    friend std::ostream & operator <<(std::ostream & salida, const Vector &v);
    friend std::istream & operator>>(std::istream & entrada, Vector &v);

public:
    friend Vector operator*(float escalar, Vector v);

    // Los constructores deben llamarse igual que la clase, No tienen tipo de valor de vuelto, el constructor sirve mas que nada para que desde un inicio...
    // ya tenga valores asignados
    // Un constructor que no recibe parametros es el constructor por default
    // Sirve apra establecer un estado valido desde un objeto desde un inicio

    //Vector(); // Este es el constructor por default
    //explicit Vector(int dim); // Este es otro constructor que va a tener de caracteriztica que va a solicitar la dimension //Constructor Operador de conversion implicita
    explicit Vector(int dim=3, float valor=0);

    Vector(const Vector &v);

    ~Vector(); // Destructor

    Vector & operator =(const Vector &v);

    // El constructor de copias se ejetuta cuando una funcion devuelve un objeto de esa clase

    // Si te fijas hay algunos metodos que tienen "const" al final, pero esto que quiere decir?
    // Esto se hace con metodos qe¿ue NO MODIFICAN AL OBJETO
    // Por ejemplo, metodos como "Captruar" pues modifica las entradas del arreglo, pero metodos como imprimir pues no modifica nada, solamente imprime y listo xd
    // Pero bueno, esto sirve por que en main se pueden definir vectores constantes, osea vectores que no se modifican
    // Entonces, si estos metodos no tuvieran la palabra const, los vectores en main definidos como const NO VAN A PODER utilizar ni siqueira metoods como imprimir
    // Entonces, ahora con metodos constantes, los vectores definidos como constantes en main van a poder acceder a estos metodos constantes que no modifican el vector constante.
    // const es parte de la firma del metodo

    Vector SumaVectores(const Vector &v2) const;
    Vector RestaVectores(const Vector &v2) const;
    float ProductoPunto(const Vector &v) const;
    Vector MultiplicarEscalar(float escalar) const;
    float ObtenerMagnitud() const;

    int ObtenerDim() const;

    /** \brief
     *
     * \param i int
     * \param valor float
     * \return void
     *
     */
    void EstablecerEntrada(int i, float valor); //índice de la entrada, valor por cual cambiar
    float & operator[](int i); //devuelve una referencia, no debe ser constante
    float ObtenerEntrada(int i);
    float operator[](int i) const; //devuelve valor, debe ser constante

    void Capturar();
    void Imprimir() const;


    // SOBRECARGA DE OPERADORES

    /** \brief Operador para sumar dos vectores
     *
     * \param v2 const Vector&: segundo operando para la suma
     * \return Vector resultante de la suma
     *
     * \pre Los vectores a sumar deben tener la misma dimensión
     * \throw const char * Cuando los operandos sean de distina dimensi&oacuten; o cuando el vector resultante no pueda ser creado
     */
    Vector operator+(const Vector &v2) const; // Suma de vectores U+V

    Vector operator-(const Vector &v2) const; // Resta de vectores U-V
    float operator*(const Vector &v2) const; // Producto punto U*V
    Vector operator*(float escalar) const; // Multiplicar por escalar U*a

    Vector & operator++();
    Vector operator++(int);

    void Redimensionar(int dim);

private:
    void EstablecerDim(int dim);    // Método de utileria
    int dim;
    float *entrada;

};

//inline funcionCualquiera();
//#include nombre_ejemplo.ipp

// template <typename T> // Aqui estamos definiendo T como un parametro de tipo, es decir, T va a poder ser un int, float, double o cualquier tipo de dato
// T ValorAbs(T a); // Mientras tanto, a es el parametro de valor, asi que a puede ser un parametro de tipo T, asi como si fuera int num, solo que ahora es T a

// cout << ValorAbs(-5); // Aqui recibiría un int 5
// cout << ValorAbs(-3.14); // Aqui recibiría un float 3.14
// Este tipo de funciones se van a incluir al final del archivo .hpp de la forma: #include "nombreTypename.tpp" al igual que los inline


#endif // VECTOR_HPP_INCLUDED
