#include <iostream>
#include <string>
#include <vector>
#include "diccionario.h"

using namespace std;

//Constructor por defecto

Diccionario::Diccionario(){

}

//Constructor por parametros

Diccionario::Diccionario(set<Termino> & term){
  const_iteratord i;
	for(i= term.begin(); i != term.end(); ++i){
    terminos.insert(*i);
  }
}

//Constructor de copia

Diccionario::Diccionario (const Diccionario & otro_diccionario){
	*this = otro_diccionario; 

}

Diccionario::~Diccionario(){

}

//Consultor de definición

vector<string> Diccionario::getDefinicion(string palabra) const{
  vector<string> definiciones;
  const_iteratord i;
  for (i = terminos.begin(); i!= terminos.end(); ++i){
    Termino term = (*i);
    string pal = term.GetPalabra();
    if (pal == palabra){
      definiciones = term.GetDefiniciones();
    }
  }

  return definiciones;
}

vector<string> Diccionario::GetDefinicion(int pos) const{
  const_iteratord it = terminos.begin();

	for(int i = 0; i < pos; i++){
		++it;
  }

	Termino aux = (*it);
  
	return aux.GetDefiniciones();
}

//Consultor de terminos

set<Termino> Diccionario::getTerminos() const{
  return terminos;
}

//Consultor de numero de terminos

int Diccionario::getNumTerminos() const{
  return terminos.size();
}

//Operadores de modificación
//Añadir un nuevo termino
//NO se comprueba si la palabra está ya o no, puesto que al usar un "set", este solo almacena valores sin repetir.
void Diccionario::aniadirTermino(const Termino& nuevo){
	terminos.insert(nuevo);
}

//Borrar un termino

void Diccionario::borrarTermino(Termino a_borrar){
	iteratord pos_a_borrar;
	pos_a_borrar = terminos.find(a_borrar); //find devuelve un iterador de la posicion donde esta el elemeto que buscas
																					//si no existe el elemento, devuelve un iterador a end

  if(pos_a_borrar != terminos.end()){ //Si existe el elemento que queremos borrar
		terminos.erase(a_borrar);
  }
}

iteratord Diccionario::begin(){
  return terminos.begin();
}

iteratord Diccionario::end(){
  return terminos.end();
}

const_iteratord Diccionario::cbegin() const{
  return terminos.cbegin();
 }

const_iteratord Diccionario::cend() const{
  return terminos.cend();
 }

//Sobrecarga de operadores
//Operador =

Diccionario & Diccionario::operator= (const Diccionario & d){
	if(this != &d){
      set<Termino> otro_term = d.getTerminos();
      const_iteratord i;
      for (i = otro_term.begin(); i != otro_term.end(); ++i){
		    terminos.insert(*i);
			}

	}

	return(*this);
}

//Operador []

const Termino & Diccionario::operator[](const int & pos) const{
	const_iteratord it = terminos.begin();

	for(int i = 0; i < pos; i++){
		++it;
  }

	return(*it);
}

Termino Diccionario::operator[](const int & pos){
		const_iteratord it = terminos.begin();

	for(int i = 0; i < pos; i++){
		++it;
  }

	return(*it);
}

//Sobrecarga de <<

ostream & operator<< (ostream & os, const Diccionario & diccionario){
	set<Termino> term = diccionario.getTerminos();
  const_iteratord i;
  for (i = term.begin(); i != term.end(); ++i){
	   os << (*i) << endl ;
	}


  return os;
}

//Sobrecarga de >>

istream & operator>> (istream & is, Diccionario & diccionario){
	if(is){
	  while(!is.eof()){
		Termino aux;
		is >> aux;
		diccionario.aniadirTermino(aux);
	  }
	}

	return(is);

}


//Filtro por intervalo

Diccionario Diccionario::filtroIntervalo (char caracter_inicio, char caracter_final){
  if (caracter_inicio>='A' && caracter_inicio<='Z')
    caracter_inicio+='a'-'A';

  if (caracter_final>='A' && caracter_final<='Z')
    caracter_final+='a'-'A';

  set<Termino> filtrados;

  iteratord i;
  for (i = terminos.begin(); i != terminos.end(); ++i){
    Termino term = (*i);
    string palabra= term.GetPalabra();
		if (palabra[0]>=caracter_inicio && palabra[0]<=caracter_final){
			filtrados.insert(term);
		}
  }

  Diccionario nuevo(filtrados);

  return nuevo;
}

//Filtro por palabra clave

Diccionario Diccionario::filtroPalabraClave (string palabra_clave){
  set<Termino> filtrados;
  iteratord i;
  for (i = terminos.begin(); i != terminos.end(); ++i){
    Termino term = (*i);
    vector<string> definicion = term.GetDefiniciones();
    for (unsigned int k = 0; k < definicion.size(); k++){
      if (definicion[k].find(palabra_clave)!= string::npos) //string::npos = posicion no valida
        filtrados.insert(term);
    }
  }

  Diccionario nuevo(filtrados);

  return nuevo;
}

//Recuento de definiciones

int Diccionario::recuentoDefiniciones (){
  int recuento=0;
  iteratord i;
  for (i = terminos.begin(); i != terminos.end(); ++i){
    Termino term = (*i);
    vector<string> definicion = term.GetDefiniciones();
    recuento += definicion.size();
  }
  return recuento;
}

//Maximo de definiciones por palabra

int Diccionario::maximoDefiniciones (){
  unsigned int max_definiciones=0;
  iteratord i;
  for (i = terminos.begin(); i != terminos.end(); ++i){
    Termino term = (*i);
    vector<string> definicion= term.GetDefiniciones();
    if (definicion.size()>=max_definiciones)
      max_definiciones=definicion.size();
  }

  return max_definiciones;
}

//Promedio de definiciones

float Diccionario::promedioDefiniciones (){
   float promedio=0;
   promedio=this->recuentoDefiniciones() / terminos.size();
   return promedio;
}


/*
Comentamos este metodo realizado para la practica 2 ya que al usar un "set" no es necesario
void Diccionario::ordenar(){
  Diccionario::iteratord i, j, next;

  for (i.it = terminos.begin(); i.it != terminos.end(); i++){
      j.it=terminos.begin(); next=++j;
      for (j.it = terminos.begin(); next.it != terminos.end(); ++j, ++next){
        Termino term = (*j);
        Termino term_sig = (*next);
        if(term.GetPalabra() > term_sig.GetPalabra()){
      	    Termino aux = term;
      	    term = term_sig;
      	    term_sig = aux;
         }
      }
   }
}
*/
