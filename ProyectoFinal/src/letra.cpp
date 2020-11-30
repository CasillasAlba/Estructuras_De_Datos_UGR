#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "letra.h"

using namespace std;




// ----------------------------------
//  ¡¡Constructores y Destructor!!
// ----------------------------------



//Constructor por defecto

Letra::Letra()
	:letrita(' '), puntuacion(0), num_apariciones(0){}

//Constructor con argumentos

Letra::Letra(char let, int punt, int num_ap){
	letrita = let;
  puntuacion = punt;
	num_apariciones = num_ap;
}

//Destrcutor

Letra::~Letra(){}





// ----------------------------------
//  ¡¡Métodos de consulta!!
// ----------------------------------



//Consultor de la letra (carácter)

const char & Letra::getLetra() const{
	return letrita;
}

//Consultor de la puntuación

const int & Letra::getPuntuacion() const{
	return puntuacion;
}

//Consultor del número de apariciones

const int & Letra::getNumApariciones() const{
	return num_apariciones;
}




// ----------------------------------
//  ¡¡Métodos de modificación!!
// ----------------------------------



//Modificador de la letra (carácter)

void Letra::setLetra(const char let){
	letrita = let;
}

//Modificador de la puntuación

void Letra::setPuntuacion (const int punt){
  puntuacion = punt;
}

//Modificador del número de apariciones

void Letra::setNumApariciones (const int  num_ap){
  num_apariciones = num_ap;
}





// ----------------------------------
//  ¡¡Sobrecarga de operadores!!
// ----------------------------------


// Operador <

bool Letra::operator < (const Letra & la_letrita) const{
	return letrita < la_letrita.letrita;
}





// ----------------------------------
//  ¡¡Flujos de entrada/salida!!
// ----------------------------------



//Sobrecarga de >>

/*

	Solo leemos una linea.
	En los dos primeros casos, para la letra y el número de apariciones
	leemos hasta llegar al delimitador(el tabulador). Para la puntuación,
	simplemente se lee hasta el final de la linea.
  
*/

istream & operator >> (istream & is, Letra & l){


  if(!is.eof()){
		char delimitador = '\t';
    string linea1, linea2, linea3;
		linea1 = linea2 = linea3 = " ";

    getline(is, linea1, delimitador);
		l.setLetra(linea1[0]);

		getline(is, linea2, delimitador);
		l.setNumApariciones(atoi(linea2.c_str()));

		getline(is, linea3);
		l.setPuntuacion(atoi(linea3.c_str()));
  }

   return is;
  }
  
  
//Sobrecarga de <<

ostream & operator << (ostream & os, const Letra & l){
	
	os << "	Letra: " << setw(2) << l.getLetra();
  os << "	Número de apariciones: " << setw(2) << l.getNumApariciones();
  os << " Puntuación: " << setw(2) << l.getPuntuacion();

  return os;

}

