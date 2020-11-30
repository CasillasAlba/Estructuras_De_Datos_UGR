/**
  * @file  diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef _DICCIONARIO_
#define _DICCIONARIO_

#include <string>
#include <iostream>
#include <set>
#include "termino.h"

using namespace std;

typedef set<Termino>::iterator iteratord;
typedef set<Termino>::const_iterator const_iteratord;

/**
  *  @brief   T.D.A. Diccionario
  *
  *  Una instancia @e de T.D.A. Diccionario es una colección de términos
  *  ordenados alfabéticamente.
  *
  *  @include pruebadiccionario.cpp
  *  @include termino.cpp
  *
  *  @author  Paula Cumbreras Torrente
  *  @author  Alba Casillas Rodriguez
  *  @date    Diciembre 2018
  */

class Diccionario {

  private:
/**
  *  @page    Rep del T.D.A. Diccionario
  *  @section Invariante de la representacion
  *
  *  El invariante es que el diccionario no esté vacio.
  *
  */

  set<Termino> terminos;


  public:

/**
  *  @brief Constructor por defecto de la clase. Crea un diccionario con 0 terminos
  */

  Diccionario();

/**
  *  @brief  Constructor de la clase
  *  @param  terminos set(conjunto) de objetos T.D.A. Termino
  *  @return Devuelve un diccionario de terminos
  */

  Diccionario(set<Termino> & terminos);

/**
  *  @brief Constructor de copias de la clase
  *  @param otro_diccionario objeto T.D.A. diccionario que se desea copiar
  */

  Diccionario (const Diccionario& otro_diccionario);

/**
  * @brief Destructor de la clase
  */

  ~Diccionario();

/**
  *  @brief  Operador de consulta
  *  @param  palabra string a consultar
  *  @return Devuelve la definicion de dicha palabra
  */

  vector<string> getDefinicion(string palabra) const;


/**
  *  @brief  Operador de consulta
  *  @param  posicion int a consultar
  *  @return Devuelve la definicion en dicha posición
  */

  vector<string> GetDefinicion(int pos) const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve todos los terminos del diccionario
  */

  set<Termino> getTerminos() const;

/**
  * @brief  Operador de consulta
  * @return Devuelve el numero de terminos del diccionario
  */

  int getNumTerminos() const;

/**
  * @brief  Operador de modificacion
  * @param  nuevo termino a añadir
  * @pre    nuevo no debe coincidir con ningun otro termino del diccionario
  */

  void aniadirTermino(const Termino& nuevo);

/**
  * @brief  Operador de modificacion
  * @param  aborrar termino a borrar
  * @pre    aborrar debe existir en el diccionario
  */

  void borrarTermino(Termino a_borrar);

/**
  * @brief Operador de asignacion
  * @param un diccionario para realizar la asignación
  * @return El diccionario con los valores asignados
  */

   Diccionario & operator= (const Diccionario & d);

/**
  * @brief  Acceso a un elemento de un vector constante
  * @param  pos es la posicion del vector donde esta el elemento. 0<=pos<terminos.size()
  * @return Devuelve la referencia al elemento. Se supone que el vector no se puede
  *	    modificar y por tanto es acceso de solo lectura
  */


  const Termino & operator[](const int& pos)const;

/**
  * @brief  Acceso a un elemento del vector
  * @param  pos es la posicion del vector donde esta el elemento. 0<=pos<terminos.size()
  * @return Devuelve la referencia al elemento. Por tanto, puede sarse para almacenar un
  * 	    valor en esa posición
  */

  Termino operator[](const int& i) ;

/**
  * @brief Sobrecarga de operador de salida
  * @param os stream de salida
  * @param diccionario diccionario a escribir
  * @post  los datos de diccionario se escribiran en el stream os
  */

  friend ostream & operator<< (ostream & os, const Diccionario & diccionario);

/**
  * @brief  Sobrecarga de operador de entrada
  * @param  is stream de entrada
  * @param  diccionario diccionario sobre el que se escribe
  * @return Devuelve el diccionario con los valores pasados como argumentos
  * @pre    is debe contener datos para escribir sobre diccionario
  */

  friend istream & operator>> (istream & is, Diccionario & diccionario);

/**
  * @brief  Filtra el diccionario por intervalo
  * @param  caracter_inicio char inicial del intervalo
  * @param  caracter_fin char final del intervalo
  * @return Devuelve un subdiccionario cuyas palabras asociadas
  *	    esten comprendidas entre el intervalo pasado como argumento
  */

  Diccionario filtroIntervalo (char caracter_inicio, char caracter_final);

/**
  * @brief  Filtra el diccionario por palabra clave
  * @param  palabra_clave string a buscar en el diccionario
  * @return Devuelve un diccionario en cuyas definiciones
  *	    aparezca la palabra clave
  */

  Diccionario filtroPalabraClave (string palabra_clave);

/**
  * @brief  Recuento de definiciones
  * @return Devuelve el numero total de definiciones del diccionario
  */

  int recuentoDefiniciones ();

/**
  * @brief  Maximo de definiciones por palabra
  * @return Devuelve el numero maximo de definiciones para una misma palabra
  */

  int maximoDefiniciones ();

/**
  * @brief  Promedio de definiciones
  * @return Devuelve el promedio de definiciones por palabra
  */

  float promedioDefiniciones ();


/*
   @brief Ordena el diccionario alfabeticamente
  

  void ordenar();
*/

/**
  * @brief  Iterador begin
  * @return Devuelve el iterador begin
  */

	iteratord begin();

/**
  * @brief  Iterador end
  * @return Devuelve el iterador end
  */

	iteratord end();

/**
  * @brief  Iterador constante begin
  * @return Devuelve el iterador constante cbegin
  */


	const_iteratord cbegin() const;

/**
  * @brief  Iterador constante end
  * @return Devuelve el iterador constante cend
  */

	const_iteratord cend() const;
};

#endif
