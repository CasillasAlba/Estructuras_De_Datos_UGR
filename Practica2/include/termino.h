/**
  * @file  Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */


#include <iostream>
#include <string>
#include "Vector_Dinamico.h"


#ifndef _TERMINO_H_
#define _TERMINO_H_

using namespace std;

/** 
  * @brief  T.D.A Termino
  *
  * Una instancia @e del TDA Termino es un objeto compuesto por un 
  * string que representa una palabra y un vector de string que  
  * representa las definiciones de dicha palabra-
  *
  * @author Alba Casillas Rodríguez
  * @author Paula Cumbreras Torrente
  * @date   Octubre 2018.
  */

class Termino{

 private:
/**
  * @page    Rep del TDA Termino
  * @section Invariante de la representacion
  *
  * EL invariante es que no exista la palabra, o que esté formada por caracteres/numeros
  * externos al albafeto.
  *
  */

	string palabra;
	Vector_Dinamico<string> definicion;

 public:
/**
  * @brief Constructor por defecto. Crea un termino con una palabra
  *        vacia y un string de definiciones inicializado a 0.
  */
	Termino();

/**
  * @brief  Constructor de la clase
  * @param  pal correspondiente al string palabra
  * @param  v correspondiente al vector de definiciones
  * @return crea el Termino formado por palabra;definicion
  */

	Termino(string pal, Vector_Dinamico<string> v);

/**
  * @brief Constructor de Copia de la clase
  * @param ter.palabra para crear el string palabra
  * @param ter.definicion para crear el vector de definiciones
  */

	Termino(const Termino & ter);
/**
  * @brief  Palabra
  * @return Devuelve una palabra del termino
  */

	string GetPalabra() const;

/**
  * @brief  Definiciones
  * @return Devuelve las definiciones asociadas a una palabra
  */

	Vector_Dinamico<string> GetDefiniciones() const;

/**
  * @brief  Definicion de una posicion
  * @return Devuelve las definiciones asociadas a una posicion
  * @param  pos posicion int a consultar
  */

        const string & GetDefinicion(int & pos)const;

/**
  * @brief  Cantidad de definiciones
  * @return Devuelve el numero de definiciones que tiene una palabra
  */

	int GetNumDefiniciones() const;

/**
  * @brief Modificar palabra
  * @param palabra string que dara valor al dato miembro palabra del termino
  */

	void SetPalabra(string palabra);
/**
  * @brief Añadir definición nueva
  * @param def string que se aniadira a las definiciones del termino
  */
	void AniadirDefinicion(string def);

/**
  * @brief  Operador de asignacion
  * @param  term un término para realizar la asignación
  * @return El término con los valores asignados
  */

	Termino & operator= (const Termino & term);

/**
  * @brief  operador de igualdad
  * @param  term un término para comprobar la igualdad
  * @return variable booleana que inidica si los terminos son iguales o no
  */


	bool operator== (const Termino & term);

/**
  * @brief  Comprueba si una definicion forma parte de un termino
  * @param  def string a comprobar
  * @return variable booleana que inidica si la definicion pasada como argumento
  * 	    aparece en el termino
  */
	bool contieneDefinicion (string def);

/**
  * @brief Salida de un termino a ostream
  * @param os stream de salida
  * @param term Termino a escribir
  * @post  Se obtiene en "os" la cadena (palabra;definicion) con los valores
  * 	   de la palabra y sus definiciones de "term"
  */
	friend ostream & operator<< (ostream & os, const Termino & term);

};

#endif
