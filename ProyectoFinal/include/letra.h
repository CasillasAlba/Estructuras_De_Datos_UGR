/**
  * @file  letra.h
  * @brief Fichero cabecera del TDA Letra
  *
  */

#ifndef _LETRA_
#define _LETRA_

#include <string>
#include <iostream>

using namespace std;

/**
  *  @brief   T.D.A. Letra
  *
  *  Una instancia @e de T.D.A. Letra está formada por
  *  un char (la letra) y dos enteros (el numero de apariciones y la puntuacion de la misma)
  *
  *
  *  @author  Paula Cumbreras Torrente
  *  @author  Alba Casillas Rodriguez
  *  @date    Diciembre 2018-Enero 2019
  */

class Letra {

private:
/**
  *  @page    Rep del T.D.A. Letra
  *  @section Invariante de la representacion
  *
  *  El invariante es que la letra exista.
  *
  */
  
	char letrita;
  int puntuacion;
  int num_apariciones;

public:

/**
  *  @brief Constructor por defecto de la clase. Crea un objeto Letra vacío
  */

  Letra();

/**
  *  @brief  Constructor de la clase
  *  @param  carácter "letra", entero "puntuación", entero "número de apariciones"
  *  @return Devuelve un objeto Letra
  */

  Letra(char let, int punt, int num_ap);

/**
  * @brief Destructor de la clase
  */

  ~Letra();

/**
  *  @brief  Operador de consulta
  *  @return Devuelve la letra (caracter)
  */

	const char & getLetra() const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve la puntuación
  */

  const int & getPuntuacion() const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve el número de apariciones
  */

	const int & getNumApariciones() const;

/**
  * @brief modifica la letra(caracter)
  * @param nuevo valor del caracter
  */

  void setLetra(const char let);

/**
  * @brief modifica la puntuación
  * @param nuevo valor de la puntuación
  */

  void setPuntuacion (const int  punt);

/**
  * @brief modifica el número de apariciones
  * @param nuevo valor del número de apariciones
  */

  void setNumApariciones (const int  num_ap);

/**
  * @brief Operador menor
  * @param objeto de la clase Letra
  * @return true si es menor, false si no es menor
  */

  bool operator < (const Letra & la_letrita) const;

/**
  * @brief  Sobrecarga de operador de entrada
  * @param  is stream de entrada
  * @param  Letra sobre la que se escribe
  * @return Devuelve la letra con los valores pasados como argumentos
  * @pre    is debe contener datos para escribir sobre la letra
  */

  friend istream & operator >> (istream & is, Letra & l);

/**
  * @brief Sobrecarga de operador de salida
  * @param os stream de salida
  * @param Letra a escribir
  * @post  los datos de la letra se escribiran en el stream os
  */

  friend ostream & operator << (ostream & os, const Letra & l);

};
  
  



#endif
