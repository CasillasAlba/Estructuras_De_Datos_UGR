#include <iostream>
#include <string>
#include "termino.h"

using namespace std;

//Constructor por defecto

Termino::Termino(){
	palabra = " ";
	definicion = 0;
}

//Constructor por parametros

Termino::Termino(string pal, Vector_Dinamico<string> v){
	palabra = pal;
	definicion = v;
}

//Constructor de copia

Termino::Termino(const Termino & ter){
	palabra = ter.palabra;
	definicion = ter.definicion;
}

//Operadores de consulta
//Obtener la palabra

string Termino::GetPalabra() const{
	return palabra;
}

//Obtener las definiciones asociadas a la palabra

Vector_Dinamico<string> Termino::GetDefiniciones() const{
	return definicion;
}

//Obtener las definiciones en una posicion del vector de definiciones

const string & Termino::GetDefinicion(int & pos) const{
	return definicion[pos];
}

//Obtener el numero de definiciones asociadas a la palabra

int Termino::GetNumDefiniciones() const{
	return definicion.size();
}


//Operadores de modificacion
//Establecer la palabra

void Termino::SetPalabra(string palabra){
	(*this).palabra = palabra;
}

//Añadir nuevas definiciones

void Termino::AniadirDefinicion(string def){
	if (!contieneDefinicion(def))
 		definicion.push_back(def); //He definido el metodo push_back en la 
					   //clase Vector Dinamico
}


bool Termino::contieneDefinicion (string def){
	bool contiene_definicion = false;
	int num_def = GetNumDefiniciones();
	for (int i=0; i<num_def && !contiene_definicion; i++){
		if (definicion[i] == def)
			contiene_definicion = true;
	}
	return contiene_definicion;
}

//Sobrecarga de operadores
//Operador =

Termino & Termino::operator= (const Termino & term){

	if(this != &term){
	  palabra = term.palabra;
	  definicion = term.definicion;
	}
	
	return(*this);
}

//Operador ==

bool Termino::operator== (const Termino & term){
	bool iguales = false;	
	if(palabra == term.palabra){
	 if(definicion == term.definicion){
		iguales = true;	
	 }
	}

	return iguales;
}


//Operador <<

ostream & operator<< (ostream & os, const Termino & term){
	os << term.GetPalabra() << endl;
	os << term.GetNumDefiniciones() << endl;

	for(int i= 0; i < term.GetNumDefiniciones(); i++){
		os << term.GetDefinicion(i) << endl;
	}

	return os;
}


