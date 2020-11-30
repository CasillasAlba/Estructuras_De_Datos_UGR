#include <iostream>
#include <string>
#include <vector>
#include "diccionario.h"

using namespace std;



// ----------------------------------
//  ¡¡Constructores y Destructor!!
// ----------------------------------



//Constructor por defecto

Diccionario::Diccionario(){

}

//Constructor por parametros

Diccionario::Diccionario(set<string> & d){
  const_iteratord it;

	for(it = d.begin(); it != d.end(); ++it){
    datos.insert(*it);
  }

}

//Constructor de copia

Diccionario::Diccionario (const Diccionario & otro_diccionario){
	*this = otro_diccionario; 

}

//Destructor

Diccionario::~Diccionario(){}





// ----------------------------------
//  ¡¡Métodos de consulta!!
// ----------------------------------



//Consultor de palabras

set<string> Diccionario::getPalabras(){
  return datos;
}

const set<string> & Diccionario::getPalabras() const{
  return datos;
}

//Consultor del número de palabras

int Diccionario::size() const{
  return datos.size();
}

//Palabras en el diccionario de una longitud dada

vector<string> Diccionario::palabrasLongitud(unsigned int longitud){
  vector<string> res;
	const_iteratord it;

	for(it = datos.begin(); it != datos.end(); ++it){
   if ((*it).size() == longitud){
		res.push_back(*it);
   }
  }

  return res;
}

//Está o no una palabra en el diccionario

bool Diccionario::esta(string palabra){
	bool esta_palabra = false;

  if(datos.find(palabra) != datos.end()){
		esta_palabra = true;
  }    

  return esta_palabra;
}





// ----------------------------------
//  ¡¡Métodos de modificación!!
// ----------------------------------



//Añadir una nueva palabra

/*
	NO comprobamos si la palabra está ya o no, 
	puesto que al usar un "set", este solo almacena valores sin repetir.
*/

void Diccionario::aniadirPalabra(const string & pal){
	datos.insert(pal);
}

//Borrar un termino

void Diccionario::borrarPalabra(string a_borrar){
	iteratord pos_a_borrar;
	pos_a_borrar = datos.find(a_borrar); //find devuelve un iterador de la posicion donde esta el elemeto que buscas
																			 //si no existe el elemento, devuelve un iterador a end

  if(pos_a_borrar != datos.end()){ //Si existe el elemento que queremos borrar
		datos.erase(a_borrar);
  }
}





// ----------------------------------
//  ¡¡Métodos de iteradores!!
// ----------------------------------



iteratord Diccionario::begin(){
  return datos.begin();
}

iteratord Diccionario::end(){
  return datos.end();
}

const_iteratord Diccionario::cbegin() const{
  return datos.cbegin();
 }

const_iteratord Diccionario::cend() const{
  return datos.cend();
 }





// ----------------------------------
//  ¡¡Sobrecarga de operadores!!
// ----------------------------------



//Operador =

Diccionario & Diccionario::operator= (const Diccionario & d){
	if(this != &d){
      set<string> palabras = d.getPalabras();
      const_iteratord it;
      for (it = palabras.begin(); it != palabras.end(); ++it){
		    datos.insert(*it);
			}

	}

	return(*this);
}

//Operador []

const string & Diccionario::operator[](const int & pos) const{
	const_iteratord it = datos.begin();

	for(int i = 0; i < pos; i++){
		++it;
  }

	return(*it);
}

string Diccionario::operator[](const int & pos){
		const_iteratord it = datos.begin();

	for(int i = 0; i < pos; i++){
		++it;
  }

	return(*it);
}





// ----------------------------------
//  ¡¡Flujos de entrada/salida!!
// ----------------------------------



//Sobrecarga de >>

istream & operator>> (istream & is, Diccionario & diccionario){
	if(is){
	  while(!is.eof()){
		string aux;
		getline(is, aux); // getline ya que el diccionario va por lineas
		diccionario.aniadirPalabra(aux);
	  }
	}

	return(is);

}

//Sobrecarga de <<

ostream & operator<< (ostream & os, const Diccionario & diccionario){
	set<string> palabras = diccionario.getPalabras();
  const_iteratord it;
  for (it = diccionario.cbegin(); it != diccionario.cend(); ++it){
	   os << (*it) << endl ;
	}

  return os;
}
