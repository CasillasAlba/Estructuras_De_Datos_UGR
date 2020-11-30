#ifndef _PILA_MAX_H_
#define _PILA_MAX_H_
/**
  * @file  Pila_max.hpp
  * @brief Fichero cabecera del TDA Pila_max
  *
  */

#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct elemento{
	T valor;
	T maximo;
        
};
template <typename T>
ostream & operator<< (ostream & os, const elemento<T> & e);


/**
  * @brief T.D.A Pila_max
  * 
  *La clase abstracta Pila_max está formada por una lista de pares de elementos <T,T>
  *con funcionamiento LIFO (Last In, First Out). En una pila, las operaciones de insercción
  *y borrado de elementos tiene lugar en uno de los extremos denominado tope.
  *
  * Si datos.size() == 0, la pila estará vacia.
  *
  * El espacio requerido para el almacenamiento es 0(n), donde n es el numero de elementos
  * de la Pila_max.
  *
  * @author Alba Casillas Rodríguez
  * @author Paula Cumbreras Torrente
  * @date   Octubre 2018.
  */


template <class T>
class Pila_max{
/**
  * @page Rep del TDA Pila Max
  *
  */
	private:
		list<elemento<T> > datos;
	public:
/**
  * @brief Constructor por defecto. Crea una pila vacía.
  */

		Pila_max();

/**
  * @brief Constructor de copia.
  * @param La pila de la que se hace la copia
  */

	        Pila_max(const Pila_max & otra);

/**
  * @brief Indica si la pila está vacía o no
  */

		bool vacia() const ;

/** 
  * @brief ELiminar un elemento de la pila
  */
		void quitar();


/**
  * @brief Devuelve el elemento tope de la pila
  */
		elemento<T> & tope();

/**
  * @brief Devuelve el elemento tope de la pila contante
  */

		const elemento<T> & tope() const;

/**
  * @brief Añade un elemento "encima" del tope de la pila
  * @param a_insertar El elemento que se va a insertar
  */

		void poner (const T & a_insertar);
/**
  * @brief Devuelve el número de elementos de la pila
  */

		int numElementos()const;

/**
  * @brief Devuelve el valor máximo de la pila
  */

		const T & valor_maximo ();

/**
  * @brief Actualiza los máximos de la pila 
  */

		void actualizaMaximos();

	
};

#include "Pila_max.cpp"
#endif
