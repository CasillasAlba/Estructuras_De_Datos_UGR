#include "Cola_max_pila.hpp"

using namespace std;

//Constructor por defecto

template <class T>
Cola_max<T>::Cola_max(){}

//Método poner
template <class T>
void Cola_max<T>::poner(const T & a_insertar){
   pila_insercciones.poner(a_insertar);
}


template <class T>
void Cola_max<T>::quitar(){
//Sacar hasta que se vacie y el ultimo que sacas lo devuelves(no return), a medida que sacas vuelcas a otra pila
//vuelves a volcar en la original

   while(!pila_insercciones.vacia()){
 	pila_aux.poner(pila_insercciones.tope().valor);
	pila_insercciones.quitar();
        }



	pila_aux.quitar();


  while(!pila_aux.vacia()){
	pila_insercciones.poner(pila_aux.tope().valor);
       pila_aux.quitar();
    }

}

template <class T>
T & Cola_max<T>::frente (){
	while(!pila_insercciones.vacia()){
 	  pila_aux.poner(pila_insercciones.tope().valor);
	  pila_insercciones.quitar();
        }
	return pila_aux.tope().valor;
}

template <class T>
T & Cola_max<T>::frente () const{
	while(!pila_insercciones.vacia()){
 	  pila_aux.poner(pila_insercciones.tope().valor);
	  pila_insercciones.quitar();
        }
	return pila_aux.tope().valor;
}

template <class T>
const T & Cola_max<T>::maximo () {
    while(!pila_aux.vacia()){
	 pila_insercciones.poner(pila_aux.tope().valor);
         pila_aux.quitar();
     }
	return pila_insercciones.valor_maximo();
}

template <class T>
int Cola_max<T>::num_elementos () const{
	return pila_insercciones.numElementos();
}

template <class T>
bool Cola_max<T>::vacia(){
	return (pila_insercciones.vacia());
}
