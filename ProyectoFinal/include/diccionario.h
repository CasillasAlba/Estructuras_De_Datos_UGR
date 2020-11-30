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
#include <vector>

using namespace std;

typedef set<string>::iterator iteratord;
typedef set<string>::const_iterator const_iteratord;

/**
  *  @brief   T.D.A. Diccionario
  *
  *  Una instancia @e de T.D.A. Diccionario es una colección de strings
  *  ordenados por un set
  *
  *
  *  @author  Paula Cumbreras Torrente
  *  @author  Alba Casillas Rodriguez
  *  @date    Diciembre 2018-Enero 2019
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

  set<string> datos;


  public:

/**
  *  @brief Constructor por defecto de la clase. Crea un diccionario vacio
  */

  Diccionario();

/**
  *  @brief  Constructor de la clase
  *  @param  set(conjunto) de strings
  *  @return Devuelve un diccionario de strings
  */

  Diccionario(set<string> & d);

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
  *  @return Devuelve todos las palabras del diccionario constante
  */

  const set<string> & getPalabras() const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve todos las palabras del diccionario constante
  */

  set<string> getPalabras();


/**
  * @brief Devuelve el número de palabras en el diccionario
  * return un entero con el número de palabras
  */

  int size() const;

/**
  * @brief Obtiene todas las palabras en el diccionario de una longitud dada
  * @param longitud: la logitud de las palabras de salida
  * @return un vector con palabras de longitud específica en el parametro de entrada
  */

  vector<string> palabrasLongitud(unsigned int longitud);

/**
  * @brief Indica si una palabra está en el diccionario o no
  * @param palabra: la palabra que se quiere buscar
  * @return true si la palabra esta en el diccionario, false si no.
  */
  
  bool esta(string palabra);

/**
  * @brief  Operador de modificacion
  * @param  palabra: nueva palabra a añadir
  * @pre    nuevo no debe coincidir con ningun otro termino del diccionario
  */

  void aniadirPalabra(const string & pal);

/**
  * @brief  Operador de modificacion
  * @param  aborrar termino a borrar
  * @pre    aborrar debe existir en el diccionario
  */

  void borrarPalabra(string a_borrar);


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


  const string & operator[](const int& pos)const;

/**
  * @brief  Acceso a un elemento del vector
  * @param  pos es la posicion del vector donde esta el elemento. 0<=pos<terminos.size()
  * @return Devuelve la referencia al elemento. Por tanto, puede usarse para almacenar un
  * 	    valor en esa posición
  */

  string operator[](const int& i) ;

/**
  * @brief  Sobrecarga de operador de entrada
  * @param  is stream de entrada
  * @param  diccionario diccionario sobre el que se escribe
  * @return Devuelve el diccionario con los valores pasados como argumentos
  * @pre    is debe contener datos para escribir sobre diccionario
  */

  friend istream & operator>> (istream & is, Diccionario & diccionario);

/**
  * @brief Sobrecarga de operador de salida
  * @param os stream de salida
  * @param diccionario diccionario a escribir
  * @post  los datos de diccionario se escribiran en el stream os
  */

  friend ostream & operator<< (ostream & os, const Diccionario & diccionario);


};

#endif
