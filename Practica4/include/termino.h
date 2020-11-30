/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */


#include <iostream>
#include <string>
#include <vector>
#include <utility>


#ifndef _TERMINO_H_
#define _TERMINO_H_

using namespace std;

typedef vector<string>::iterator iteratort;
typedef vector<string>::const_iterator const_iteratort;

/**
  * @brief T.D.A Termino
  * Una instancia @e del TDA Termino es un objeto compuesto por un
  * string que representa una palabra y un vector de string que
  * representa las definiciones de dicha palabra-
  *
  * @author Alba Casillas Rodríguez
  * @author Paula Cumbreras Torrente
  * @date Diciembre 2018.
  */

class Termino{

 private:
/**
  * @page Rep del TDA Termino
  * @section Invariante de la representacion
  *
  * EL invariante es que todo los terminos tengan definición(es)
  *
  */

        pair<string, vector<string> > termino;


 public:
/**
  * @brief Constructor por defecto. Crea un termino con una palabra
  * vacia y un string de definiciones inicializado a 0.
  */

	Termino();

/**
  * @brief Constructor de la clase
  * @param pal correspondiente al string palabra
  * @param v correspondiente al vector de definiciones
  * @return crea el Termino formado por palabra;definicion
  */

	Termino(string pal, vector<string> v);

/**
  * @brief Constructor de Copia de la clase
  * @param ter.first para crear el string palabra
  * @param ter.second para crear el vector de definiciones
  */

	Termino(const Termino & ter);

/**
  * @brief Destructor de la clase
  */

  	~Termino();

/**
  * @brief Palabra
  * @return Devuelve una palabra del termino
  */

	const string& GetPalabra() const;

/**
  * @brief Definiciones
  * @return Devuelve las definiciones asociadas a una palabra
  */

	vector<string> GetDefiniciones() const;

/**
  * @brief Definicion de una posicion
  * @return Devuelve las definiciones asociadas a una posicion
  */

  	string GetDefinicion(int pos)const;

/**
  * @brief Cantidad de definiciones
  * @return Devuelve el numero de definiciones que tiene una palabra
  */

	int GetNumDefiniciones() const;

/**
  * @brief Modificar palabra
  */

	void SetPalabra(string palabra);

/**
  * @brief Añadir definición nueva
  */

	void AniadirDefinicion(string def);

/**
  * @brief Operador de asignacion
  * @param un término para realizar la asignación
  * @return El término con los valores asignados
  */

	Termino & operator= (const Termino & term);

/**
  * @brief Operador no igual
  * @return Devuelve un booleano indicando si los terminos son diferentes
  */

	bool operator != (const Termino & term) const;

/**
  * @brief operador de igualdad
  * @param un término para comprobar la igualdad
  * @return variable booleana que inidica si los terminos son iguales o no
  */

	bool operator== (const Termino & term) const;

/**
  * @brief Comprueba si una Termino es alfabéticamente mayor
  * @param term Termino a comparar
  * @return true si es mayor, false si no
  */

  	bool operator> (const Termino & term) const;

/**
  * @brief Comprueba si un Termino es alfabéticamente menor. Si el char es menor, va antes alfabéticamente
  * @param term Termino a comparar
  * @return true si es menor, false si no
  */

	bool operator< (const Termino & term) const;

/**
  * @brief Salida de un termino a ostream
  * @param os: stream de salida
  * @param term Termino a escribir
  * @post Se obtiene en "os" la cadena (palabra;definicion) con los valores
  * de la palabra y sus definiciones de "term"
  */

	friend ostream & operator<< (ostream & os, const Termino & term);


/**
  * @brief  Sobrecarga de operador de entrada
  * @param  is stream de entrada
  * @param  term Término sobre el que se escribe (palabra;definiciones)
  * @return Devuelve el término con los valores pasados como argumentos
  * @pre    is debe contener datos para escribir sobre término
  */

	friend istream & operator>> (istream & is, Termino & term);
  
/**
  * @brief  Iterador begin
  * @return Devuelve el iterador begin
  */

	iteratort begin();

/**
  * @brief  Iterador end
  * @return Devuelve el iterador end
  */

	iteratort end();

/**
  * @brief  Iterador constante begin
  * @return Devuelve el iterador constante cbegin
  */


	const_iteratort cbegin() const;

/**
  * @brief  Iterador constante end
  * @return Devuelve el iterador constante cend
  */

	const_iteratort cend() const;

};

#endif
