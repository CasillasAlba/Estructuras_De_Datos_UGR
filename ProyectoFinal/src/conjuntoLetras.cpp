#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include "conjuntoLetras.h"

using namespace std;




// ----------------------------------
//  ¡¡Constructores y Destructor!!
// ----------------------------------



//Constructor por defecto

ConjuntoLetras::ConjuntoLetras(){}

//Constructor por parámetros

ConjuntoLetras::ConjuntoLetras(set<Letra> & d){
  iteratorcl it;

	for(it = d.begin(); it != d.end(); ++it){
    c_letras.insert(*it);
  }
}

//Destructor

ConjuntoLetras::~ConjuntoLetras(){}





// ----------------------------------
//  ¡¡Métodos de consulta!!
// ----------------------------------


//Consultor del conjunto de letras

const set<Letra> & ConjuntoLetras::getConjunto()const{
	return c_letras;

}

//Consultor del tamaño del conjunto de letras

const int ConjuntoLetras::tamConjunto()const{

return c_letras.size();

}

//Consultor de la información de una letra, a partir de un caracter

Letra ConjuntoLetras::infoLetra(char caracter){
	assert(caracter >= 'A' && caracter <= 'Z'); //'A' Y 'Z' en mayúscula ya que en el fichero pasado en PRADO solo se han usado mayúsculas
	iteratorcl it;

  for (it = c_letras.begin(); it != c_letras.end(); ++it){
		if ((*it).getLetra() == caracter){
      return (*it);
    }
	}

  return (*it); //Por si no entra en el if. En esta situación (*it) vale "c_letras.end()"
}
 
//Consultor de la información de una letra, a partir de ua posición

Letra ConjuntoLetras::infoLetraPosicion(unsigned int pos){
  assert(pos >= 0 && pos <= c_letras.size());
  iteratorcl it;
  unsigned int contador = 0;


    for (it = c_letras.begin(); it != c_letras.end(); ++it, contador++){
			if (contador == pos){
				return *it;
      }
    }

  return *it;
}





// ----------------------------------
//  ¡¡Métodos de modificación!!
// ----------------------------------



//Añadir una nueva letra al conjunto

void ConjuntoLetras::aniadirLetra(Letra la_letrita){

	c_letras.insert(la_letrita);

}

// Decrementar el número de apariciones de una palabra

/*

	Al crear la bolsa de letras, debemos disminuir el número de apariciones
	del caracter elegido, para no obtener el carácter más veces que la cantidad de este.

	Para hacer esto, debemos borrar el caracter y después añadirlo de nuevo, ya que el set
	internamente guarda objetos constantes los cuales no podemos modificar.

*/

void ConjuntoLetras::decrementaApariciones(unsigned int pos){
  iteratorcl it;
  unsigned int contador = 0;
  Letra la_letra ;

    for (it = c_letras.begin(); it != c_letras.end(); ++it, contador++){
			if (contador == pos){
        la_letra = *it;
				c_letras.erase(it);
        c_letras.insert(la_letra);
      }
    }

}  





// ----------------------------------
//  ¡¡Métodos de iteradores!!
// ----------------------------------



iteratorcl ConjuntoLetras::begin(){
  return c_letras.begin();
}

iteratorcl ConjuntoLetras::end(){
  return c_letras.end();
}

const_iteratorcl ConjuntoLetras::cbegin() const{
  return c_letras.cbegin();
}

const_iteratorcl ConjuntoLetras::cend() const{
  return c_letras.cend();
}




// ----------------------------------
//  ¡¡Flujos de entrada/salida!!
// ----------------------------------



//Sobrecarga de >>

istream & operator >> (istream & is, ConjuntoLetras & cl){
  if(is){
   string cadena_inutil;

   getline(is, cadena_inutil); //Porque la primera linea no contiene información útil
   Letra la_letrita;
   is >> la_letrita;

   while(!is.eof()){
    cl.aniadirLetra(la_letrita);
    is >> la_letrita;
   }
  }

  return is;
}

//Sobrecarga de <<

ostream & operator << (ostream & os, const ConjuntoLetras & cl){
 const_iteratorcl it;

 for (it = cl.cbegin(); it != cl.cend(); ++it){
	os << (*it) << endl;
 }

  return os;
}


