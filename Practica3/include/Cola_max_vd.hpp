/**
  * @file  Cola_max_vd.hpp
  * @brief Fichero cabecera del TDA Cola Max con vector dinamico
  *
  */

#ifndef __COLA_MAX_H__
#define __COLA_MAX_H__

/**
  * @brief Estructura con datos tipo int valor y maximo
  *
  */

template <class T>
struct Element{
  T valor;
  T maximo;
};

/**
  * @brief  T.D.A. Cola maximo
  *
  *Una instancia @e del TDA Cola_max es una cola implementada con vector 
  *dinamico que nos permite conocer el valor maximo.
  * 
  *
  * @include pruebacola_max.cpp
  *
  * @author  Paula Cumbreras Torrente
  * @author  Alba Casillas Rodriguez
  * @date    Noviembre 2018
  *
  */

template <class T>
class Cola_max{

  private:
/**
  * @page Rep del T.D.A. Cola Max Vector
  *
  */

  Element<T> * datos;
  int reservados;
  int nelem;
  int anterior, posterior;

/**
  * @brief Redimensiona la cola
  * @param n int nuevo tamaño de la cola
  */

  void resize(const int n);

/**
  * @brief Copia una la cola
  * @param c cola a copiar pasada por referencia
  */

  void copiar(const Cola_max& c);

/**
  * @brief Libera el espacio reservado
  */

  void liberar();

public:

/**
  * @brief Constructor por defecto
  */

  Cola_max();

/**
  * @brief Constructor de copia
  * @param c cola a copiar pasada por referencia
  */

  Cola_max(const Cola_max<T>& c);

/**
  * @brief Destructor
  */

  ~Cola_max();

/**
  * @brief Operador de asignacion
  * @param c cola pasada por referencia
  */

  Cola_max& operator=(const Cola_max<T>& c);

/**
  * @brief Metodo adicional para editar maximos
  */

	void editarMaximos();

/**
  * @brief  Consulta el elemento del frente
  * @return devuelve el elemento del frente
  */

  T frente() const;

/**
  * @brief  Consulta el maximo de la cola
  * @return devuelve el valor int maximo
  */

	T maximo();

/**
  * @brief  Comprueba si la cola esta vacia
  * @return devuelve un valor booleano
  */

  bool vacia() const;

/**
  * @brief Aniade un nuevo elemento a la cola
  * @param valor elemento a aniadir
  */

  void poner(const T valor);

/**
	* @brief Quita un elemento de la cola
	*/

  void quitar();

/**
  * @brief  Consulta el numero de elementos de la cola
  * @return devuelve el numero de elementos
  */

  int num_elementos();

};

#include "Cola_max_vd.cpp"
#endif // __COLA_MAX_H__
