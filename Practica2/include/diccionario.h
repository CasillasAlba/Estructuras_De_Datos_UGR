/**
  * @file  diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef _DICCIONARIO_
#define _DICCIONARIO_

#include <string>
#include <iostream>
#include "Vector_Dinamico.h"
#include "termino.h"

using namespace std;

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
  *  @date    Octubre 2018
  */

class Diccionario {

  private:
/**
  *  @page    Rep del T.D.A. Diccionario
  *  @section Invariante de la representacion
  *
  *  El invariante es que el diccionario esté vacio.
  *
  */

  Vector_Dinamico<Termino> terminos;

  public:
    
/**
  *  @brief Constructor por defecto de la clase. Crea un diccionario con 0 terminos
  */

  Diccionario();

/**
  *  @brief  Constructor de la clase
  *  @param  terminos vector de objetos T.D.A. Termino
  *  @return Devuelve un diccionario de terminos
  */

  Diccionario(Vector_Dinamico<Termino> & terminos);  

/**
  *  @brief Constructor de copias de la clase
  *  @param otro_diccionario objeto T.D.A. diccionario que se desea copiar
  */

  Diccionario (const Diccionario& otro_diccionario);  

/**
  *  @brief  Operador de consulta
  *  @param  palabra string a consultar
  *  @return Devuelve la definicion de dicha palabra
  */ 

  Vector_Dinamico<string> getDefinicion(string palabra) const;


/**
  *  @brief  Operador de consulta
  *  @param  posicion int a consultar
  *  @return Devuelve la definicion en dicha posición
  */ 

  Vector_Dinamico<string> GetDefinicion(int pos) const;

/**
  *  @brief  Operador de consulta
  *  @return Devuelve todos los terminos del diccionario
  */
 
  Vector_Dinamico<Termino> getTerminos() const;

/**
  * @brief  Operador de consulta
  * @return Devuelve el numero de terminos del diccionario
  */

  int getNumTerminos() const;

/**
  * @brief  Operador de modificacion
  * @param  nuevo termino a añadir
  * @return Devuelve un valor booleano, que tomara el valor true si 
  * 	    ha sido añadido correctamente
  * @pre    nuevo no debe coincidir con ningun otro termino del diccionario
  */   

  bool aniadirTermino(Termino nuevo);

/**
  * @brief  Operador de modificacion
  * @param  aborrar termino a borrar
  * @return Devuelve un valor booleano, que tomara el valor true si 
  * 	    ha sido borrado correctamente
  * @pre    aborrar debe existir en el diccionario
  */ 
  
  bool borrarTermino(Termino aborrar);

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


  const Termino & operator[](const int pos)const;

/**
  * @brief  Acceso a un elemento del vector
  * @param  pos es la posicion del vector donde esta el elemento. 0<=pos<terminos.size()
  * @return Devuelve la referencia al elemento. Por tanto, puede sarse para almacenar un
  * 	    valor en esa posición
  */

  Termino & operator[](const int i) ;

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

  int promedioDefiniciones ();

/**
  *@brief Ordena el diccionario alfabeticamente
  */

  void ordenar();

};

#endif
