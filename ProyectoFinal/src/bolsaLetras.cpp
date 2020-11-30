#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include "bolsaLetras.h"

using namespace std;




// ----------------------------------
//  ¡¡Constructores y Destructor!!
// ----------------------------------



//Constructor por defecto

BolsaLetras::BolsaLetras(){}

//Constructor por parámetros

BolsaLetras::BolsaLetras(list<Letra> & b){

  iteratorb it;

	for(it = b.begin(); it != b.end(); ++it){
    bolsita.push_back(*it);
  }

}

//Constrcutor con argumentos. En base al número de elementos que tiene la bolsa

/*

	Si creamos un número aleatorio según el número de letras que hay en el abecedario, las posibilidades
	de que aparezca "x" letra es equiprobable; por consecuencia podemos tener bolsas de letras poco favorables
	(como en el caso de que solo aparecen consonantes). Por eso creamos un número aleatorio en base al número de apariciones
	de cada letra, de forma que las letras con mayor número de apariciones tendrán mas posibilidades de ser elegidas. 

*/

BolsaLetras::BolsaLetras(int tamanio_bolsa, ConjuntoLetras conj){
  int num_aleatorio;
  int absolutas = 0;
 
  for (iteratorcl it = conj.begin(); it != conj.end(); ++it){
		absolutas += (*it).getNumApariciones();
  }

  
  for(int i = 0; i < tamanio_bolsa; i++){
		num_aleatorio = generarAleatorio(1, absolutas);

    int contador = 0;
		int sig_letra = -1;


   
    while(contador < num_aleatorio){
      sig_letra++;
			contador += conj.infoLetraPosicion(sig_letra).getNumApariciones();

    }
   
    bolsita.push_back(conj.infoLetraPosicion(sig_letra));
    conj.decrementaApariciones(sig_letra);
		absolutas--;
  
  }
   
}

//Destructor

BolsaLetras::~BolsaLetras(){}





// ----------------------------------
//  ¡¡Métodos de consulta!!
// ----------------------------------


//Consultor de la bolsa de letras

const list<Letra> BolsaLetras::getBolsa() const{
	return bolsita;
}

//Consultor del tamaño de la bolsa

const int BolsaLetras::getTamanio() const{
	return bolsita.size();
}

//Consultor de las letras de la bolsa

char BolsaLetras::getLetras(){
	iteratorb it;
  char letra;

  for (it = begin(); it != end(); ++it){
		letra = (*it).getLetra();
  }

  return letra;
}

//Consultor de la puntuación de las letras de la bolsa

int BolsaLetras::getPuntuacionLetra(){
	iteratorb it;
  int punt;

  for (it = begin(); it != end(); ++it){
		punt = (*it).getPuntuacion();
  }

  return punt;
}	

//Comprueba si una palabra puede formarse con las letras de la bolsa

/*

	Para no probar con todas las combinaciones posibles, el objetivo de este
	método es ir descartando las palabras que NO pueden formarse con las letras
	disponibles

*/

bool BolsaLetras::palabraEnBolsa(string solucion){
    bool esta = true;
	  iteratorb it;

		for (unsigned int i = 0; i < solucion.size() && esta; i++){
			  bool encontrada = false;

			for (it = begin(); it != end() && !encontrada; ++it){
				if( toupper(solucion[i]) == (*it).getLetra()){
						borraLetra(it);
					  encontrada = true;
				}
      }

      if (!encontrada){ //Si ha enrado tantas veces al if como letras hay en la bolsa, es que esa letra NO está
					esta = false;
      }
    }

    return esta;

}




// ----------------------------------
//  ¡¡Métodos de modificación!!
// ----------------------------------

//Borramos una letra de la bolsa

void BolsaLetras::borraLetra(iteratorb it){

	bolsita.erase(it);

}


//Borramos la bolsa de letras

void BolsaLetras::limpiar(){

	bolsita.clear();

}




// ----------------------------------
//  ¡¡Métodos auxiliares!!
// ----------------------------------



//Generar un número aleatorio

int BolsaLetras::generarAleatorio(int min, int max){
	int tam = max - min + 1;
  return ((rand()%tam)+min);
}





// ----------------------------------
//  ¡¡Métodos de iteradores!!
// ----------------------------------



iteratorb BolsaLetras::begin(){
  return bolsita.begin();
}

iteratorb BolsaLetras::end(){
  return bolsita.end();
}

const_iteratorb BolsaLetras::cbegin() const{
  return bolsita.cbegin();
}

const_iteratorb BolsaLetras::cend() const{
  return bolsita.cend();
}





// ----------------------------------
//  ¡¡Flujo de salida!!
// ----------------------------------



ostream & operator << (ostream & os, const BolsaLetras & b){
  const_iteratorb it;

  for ( it = b.cbegin(); it != b.cend(); ++it){
		os << (*it) << endl;
  }

 return os;
}

