#include "Pila_max.hpp"
#include <list>
#include <cassert>

using namespace std;


//Sobrecarga de <<
template <typename T>
ostream & operator<< (ostream & os, const elemento<T> & e){

  os << "El valor es: " <<  e.valor << " Máximo: " << e.maximo << endl;

  return os; 
}
	

template <class T>
Pila_max<T>::Pila_max(){}


template <class T>
Pila_max<T>::Pila_max(const Pila_max & otra){
	this->datos = otra.datos;

}

template <class T>
bool Pila_max<T>::vacia() const {
	return(datos.empty());
}

template <class T>
void Pila_max<T>::quitar(){
	assert(datos.size()>0);
	datos.pop_back(); //Pop_back ya que al ser una pila, se quitan desde el final
}

template <class T>
elemento<T> & Pila_max<T>::tope(){
	assert(datos.size()>0);
	return datos.back();
}

template <class T>
const elemento<T> & Pila_max<T>::tope() const{
	assert(datos.size()>0);
	datos.back();
}

template <class T>
int Pila_max<T>::numElementos()const{
	return datos.size();
}

template <class T>
void Pila_max<T>::poner (const T & a_insertar){
	elemento<T> ele;
	ele.valor = a_insertar;
	ele.maximo = a_insertar;
	datos.push_back(ele);
	actualizaMaximos();
}


template <class T>
const T & Pila_max<T>::valor_maximo(){
	return datos.front().maximo;
}

template <class T>
void Pila_max<T>::actualizaMaximos(){
	T max = datos.back().maximo;
	typename list<elemento<T> >::reverse_iterator it ;
	it = datos.rbegin();
	while(it != datos.rend() && it->maximo <= max){
		it->maximo = max;
		++it;
	}	

}
	
		

