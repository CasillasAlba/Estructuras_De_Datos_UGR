/**
  * @file  bolsaLetras.h
  * @brief Fichero cabecera del TDA bolsaLetras
  *
  */

#ifndef _BOLSALETRAS_
#define _BOLSALETRAS_

#include <string>
#include <iostream>
#include <list>
#include "letra.h"
#include "conjuntoLetras.h"

using namespace std;

typedef list<Letra>::iterator iteratorb;
typedef list<Letra>::const_iterator const_iteratorb;


/**
  *  @brief   T.D.A. Conjunto de Bolsa de Letras
  *
  *  Una instancia @e de T.D.A. BolsaLetras está formada por
  *  una lista formada por objetos de la clase "Letra"
  *
  *
  *  @author  Paula Cumbreras Torrente
  *  @author  Alba Casillas Rodriguez
  *  @date    Diciembre 2018-Enero 2019
  */

class BolsaLetras {

private:
/**
  *  @page    Rep del T.D.A. BolsaLetras
  *  @section Invariante de la representacion
  *
  *  El invariante es que las letras sean existentes y haya un cantida
  *	 disponible para elegirlas
  *
  */

	list<Letra> bolsita;


public:

/**
  *  @brief Constructor por defecto de la clase. Crea una bolsa del letras vacia
  */

	BolsaLetras();

/**
  *  @brief  Constructor de la clase
  *  @param  lista de objetos Letra
  *  @return Devuelve una bolsa de letras
  */

  BolsaLetras(list<Letra> & b);

/**
  *  @brief  Constructor de la clase
  *  @param  Tamaño deseado de la bolsa y un ConjuntoLetras
  *  @return Devuelve una bolsa de letras del tamaño pasado como argumento
  */

  BolsaLetras(int tamanio_bolsa, ConjuntoLetras conj);

/**
  * @brief Destructor de la clase
  */

  ~BolsaLetras();

/**
  *  @brief  Operador de consulta
  *  @return Devuelve la bolsa de letras
  */

  const list<Letra> getBolsa() const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve el tamaño de la bolsa
  */

  const int getTamanio() const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve las letras (unicamente el caracter) de la bolsa
  */

  char getLetras();

/**
  *  @brief  Operador de consulta
  *  @return Devuelve la puntuación de las letras de la bolsa
  */

  int getPuntuacionLetra();

/**
  *  @brief  Generados de números aleatorios
  *  @param  Máximo y mínimo intervalo en el que se debe generar el número aleatorio
  *  @return Devuelve un entero: el número aleatorio
  */

  int generarAleatorio(int min, int max);

/**
  * @brief  Operador de modificacion
  * @param  aborrar termino a borrar
  * @pre    aborrar debe existir en el diccionario
  */

  void borraLetra(iteratorb it);

/**
  * @brief Borra la bolsa
  */

  void limpiar();

/**
	* @brief Operador de consulta
	* @param string: palabra que queremos ver si se puede formas con las letras disponibles
  * @return true si se puede formar, false si no
  */

  bool palabraEnBolsa(string solucion);

/**
  * @brief  Iterador begin
  * @return Devuelve el iterador begin
  */

	iteratorb begin();

/**
  * @brief  Iterador end
  * @return Devuelve el iterador end
  */

	iteratorb end();

/**
  * @brief  Iterador constante begin
  * @return Devuelve el iterador constante cbegin
  */

	const_iteratorb cbegin() const;

/**
  * @brief  Iterador constante end
  * @return Devuelve el iterador constante cend
  */

	const_iteratorb cend() const;

/**
  * @brief Sobrecarga de operador de salida
  * @param os stream de salida
  * @param BolsaLetras a escribir
  * @post  los datos de la bolsa se escribirán en el stream os
  */

  friend ostream & operator << (ostream & os, const BolsaLetras & b);

};

#endif
