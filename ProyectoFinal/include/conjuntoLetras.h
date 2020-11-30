/**
  * @file  conjuntoLetras.h
  * @brief Fichero cabecera del TDA conjuntoLetras
  *
  */

#ifndef _CONJUNTOLETRAS_
#define _CONJUNTOLETRAS_

#include <string>
#include <iostream>
#include <set>
#include "letra.h"

using namespace std;

typedef set<Letra>::iterator iteratorcl;
typedef set<Letra>::const_iterator const_iteratorcl;

/**
  *  @brief   T.D.A. Conjunto de letras
  *
  *  Una instancia @e de T.D.A. ConjuntoLetras está formada por
  *  un set formado por objetos de la clase "Letra"
  *
  *
  *  @author  Paula Cumbreras Torrente
  *  @author  Alba Casillas Rodriguez
  *  @date    Diciembre 2018-Enero 2019
  */

class ConjuntoLetras {

private:
/**
  *  @page    Rep del T.D.A. ConjuntoLetras
  *  @section Invariante de la representacion
  *
  *  El invariante es que haya letras(existentes) dentro del set.
  *
  */

	set<Letra> c_letras;

public:

/**
  *  @brief Constructor por defecto de la clase. Crea un conjunto de letras vacio
  */

	ConjuntoLetras();

/**
  *  @brief  Constructor de la clase
  *  @param  set de objetos Letra
  *  @return Devuelve un conjunto de letras
  */

  ConjuntoLetras(set<Letra> & d);

/**
  * @brief Destructor de la clase
  */

  ~ConjuntoLetras();

/**
  *  @brief  Operador de consulta
  *  @return Devuelve el conjunto de letras
  */

  const set<Letra> & getConjunto()const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve el tamaño del conjunto
  */

  const int tamConjunto()const;

/**
  * @brief Decrementa el número de apariciones de la letra de una posición dada
  * @param entero con la posición a decrementar
  */

  void decrementaApariciones(unsigned int pos);

/**
  * @brief  Operador de modificacion
  * @param  la_letrita: nueva Letra a añadir
  * @pre    nuevo no debe coincidir con ningun otro termino del diccionario
  */

  void aniadirLetra(Letra la_letrita);

/**
  * @brief Operación de consulta
  * @param carácter del que queremos saber la información
  * @return Letra con la información del caracter
  */

  Letra infoLetra(char caracter);

/**
  * @brief Operación de consulta
  * @param posición del carácter del que queremos saber la información
  * @return Letra con la información del caracter
  */

  Letra infoLetraPosicion(unsigned int pos);

/**
  * @brief  Iterador begin
  * @return Devuelve el iterador begin
  */

	iteratorcl begin();

/**
  * @brief  Iterador end
  * @return Devuelve el iterador end
  */

	iteratorcl end();

/**
  * @brief  Iterador constante begin
  * @return Devuelve el iterador constante cbegin
  */


	const_iteratorcl cbegin() const;

/**
  * @brief  Iterador constante end
  * @return Devuelve el iterador constante cend
  */

	const_iteratorcl cend() const;

/**
  * @brief  Sobrecarga de operador de entrada
  * @param  is stream de entrada
  * @param  ConjuntoLetras sobre el que se escribe
  * @return Devuelve el conjunto con los valores pasados como argumentos
  * @pre    is debe contener datos para escribir sobre el conjunto
  */

  friend istream & operator >> (istream & is, ConjuntoLetras & cl);

/**
  * @brief Sobrecarga de operador de salida
  * @param os stream de salida
  * @param ConjuntoLetras a escribir
  * @post  los datos del conjunto se escribiran en el stream os
  */

  friend ostream & operator << (ostream & os, const ConjuntoLetras & cl);
  
};	

#endif
