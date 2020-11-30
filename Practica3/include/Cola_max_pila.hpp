/**
  * @file  Cola_max_pila.hpp
  * @brief Fichero cabecera del TDA Cola_max
  *
  */

#ifndef _COLA_MAX_PILA_H_
#define _COLA_MAX_PILA_H_

#include <iostream>
#include "Pila_max.hpp"

/** 
  * @brief T.D.A Cola_max
  *Una instancia @e del TDA Cola_max es un objeto compuesto por dos
  *pilas, una para las insercciones y otras para las consultas 
  *y borrados.
  *
  * @author Alba Casillas Rodríguez
  * @author Paula Cumbreras Torrente
  * @date   Noviembre 2018.
  */

using namespace std;

template <class T>
class Cola_max{
	private: 
/**
  * @page Rep del T.D.A. Cola Max Pila
  *
  */
		Pila_max<T> pila_insercciones; // Pila para las insercciones
		Pila_max<T> pila_aux; //Pila auxiliar para consultas y borrados
		

	public:
/**
  * @brief Constructor por defecto. Crea una cola vacía.
  */
  
		Cola_max();
/**
  * @brief Añade un elemento a la cola 
  * @param un elemento de tipo T pasado por referencia constante
  */

		void poner (const T & a_insetar);

/** 
  * @brief  Devuelve el frente de la Cola
  * @return un elemento T correspondiente al primero
  */


		T & frente () ;

/** 
  * @brief  Devuelve el frente de la Cola constante
  * @return un elemento T correspondiente al primero
  */


		T & frente () const;

/** 
  * @brief  Devuelve el máximo de la pila
  * @return un elemento T correspondiente al máximo
  */


		const T & maximo ();

/**
  * @brief  Devuelve el número de elementos
  * @return devuelve un entero correspondiente al numero de elementos de la cola
  */

		int num_elementos () const;

/** 
  * @brief ELiminar un elemento de la cola
  */

		void quitar();

/**
  * @brief Indica si la cola está vacía o no
  */

		bool vacia();
};

#include "Cola_max_pila.cpp"
#endif
