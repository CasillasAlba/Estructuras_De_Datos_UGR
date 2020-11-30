#include <iostream>
#include <string>
#include "termino.h"

using namespace std;

//Constructor por defecto

Termino::Termino(){}

//Constructor por parametros

Termino::Termino(string pal, vector<string> v){
	termino.first = pal;
	termino.second = v;
}

//Constructor de copia

Termino::Termino(const Termino & ter){
	termino.first = ter.termino.first;
	termino.second = ter.termino.second;
}

Termino::~Termino(){}

//Operadores de consulta
//Obtener la palabra

const string& Termino::GetPalabra() const{
	return termino.first;
}

//Obtener las definiciones asociadas a la palabra

vector<string> Termino::GetDefiniciones() const{
	return termino.second;
}

//Obtener las definiciones en una posicion del vector de definiciones

string Termino::GetDefinicion(int pos) const{
	return termino.second[pos];
}

//Obtener el numero de definiciones asociadas a la palabra

int Termino::GetNumDefiniciones() const{
	return termino.second.size();
}


//Operadores de modificacion
//Establecer la palabra

void Termino::SetPalabra(string palabra){
	(*this).termino.first = palabra;
}

//Añadir nuevas definiciones

void Termino::AniadirDefinicion(string def){
 	termino.second.push_back(def);
}

iteratort Termino::begin(){
    return termino.second.begin();
}

iteratort Termino::end(){
 	return termino.second.end();
}

const_iteratort Termino::cbegin() const{
	return termino.second.cbegin();
}

const_iteratort Termino::cend() const{
	return termino.second.cend();
}

//Sobrecarga de operadores
//Operador =

Termino & Termino::operator= (const Termino & term){

	if(this != &term){
	  termino.first = term.termino.first;
	  termino.second = term.termino.second;
	}

	return(*this);
}

//Operador !=
bool Termino::operator != (const Termino & term) const{
		if(*this == term) {
    return false;
  }
  return true;
}

//Operador ==

bool Termino::operator== (const Termino & term) const{
	if(termino.first == term.GetPalabra() && termino.second == term.GetDefiniciones()) {
    return true;
  }else{
    return false;
  }
}

bool Termino::operator>(const Termino & term) const{
	bool es_mayor;
    if(*this > term){
      es_mayor = true;
    }else{
      es_mayor = false;
    }

	return es_mayor;

}


bool Termino::operator<(const Termino & term) const {
	bool es_menor = true;
  string aux = term.GetPalabra();

  if(termino.first != aux){


      if( termino.first < aux ){
        es_menor = true;
      }else{
        es_menor = false;
			}

  }

  return es_menor;

}

//Operador <<

ostream & operator<< (ostream & os, const Termino & term){
	const_iteratort it;

	for(it= term.cbegin(); it != term.cend(); ++it){
		os << term.termino.first << "-->" << (*it) << endl;
	}

	return os;
}

//Operador >>

istream & operator>> (istream & is, Termino & term){
  /* CODIGO USADO EN LA PRACTICA 2
  if(is){
	bool primera_palabra = true; //El primer caso es especial ya que el diccionario esta vacío

	string cadena = " ";

	while(is.peek() != '\n' && !is.eof()){
	   if(is.peek() == ';' && !primera_palabra){
		is.ignore();
		term.AniadirDefinicion(cadena);
		cadena = '\0';
	    }else{
		if(is.peek() != ';'){
		  cadena.push_back(is.get());
		  primera_palabra = false;
	        }else{
		is.ignore();
	        }
	      }

	term.AniadirDefinicion(cadena);
	}
     }
	*/

  if(is) {
		string linea, palabra, def;
    bool diferente = false;

		getline(is, linea);
		//Busco un texto dentro de la cadena y obtengo la posicion
		int separador = linea.find(";");

		//Obtengo una subcadena a partir del caracter 0 hasta el separador
		palabra = linea.substr(0,separador);

		//Obtengo una subcadena a partir del separador, y para eliminarlo, sumo 1
		def = linea.substr (separador+1);

		term.SetPalabra(palabra);
		term.AniadirDefinicion(def);

    //Almacena por donde va leyendo
    int posicionRetorno = is.tellg();

    while( !is.eof() && !diferente){
      getline(is, linea);

			//Obtengo una subcadena a partir del caracter 0 hasta el separador
			palabra = linea.substr(0,separador);

      if(term.GetPalabra() != palabra){
				diferente = true;
				//Si no la añade, hay que volver hacia atras el fichero
				//Viene a decir que lea tantas posiciones, desde el principio
				is.seekg(posicionRetorno, is.beg);

      }else{
				//Obtengo una subcadena a partir del separador, y para eliminarlo, sumo 1
				def = linea.substr (separador+1);
				
				term.AniadirDefinicion(def);
				//Si la añade, debe de darse por leida
				posicionRetorno = is.tellg();
      }

		}

  }

	return is;
}
