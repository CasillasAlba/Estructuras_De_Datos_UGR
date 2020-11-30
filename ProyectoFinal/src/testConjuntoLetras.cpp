//Programa que comprueba correctamente los TDA Letra y ConjuntoLetras

#include "conjuntoLetras.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
  	cout<<"Dime el nombre del fichero: "<<endl;
    return 0;
  }

  ifstream f (argv[1]);

  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

	ConjuntoLetras mi_conjunto;

	cout << "Cargamos el conjunto de letras" << endl;
	f>>mi_conjunto; //Cargamos en memoria el conjunto de letras
	cout << "Conjunto de letras cargado" << endl;


	const_iteratorcl it;

	for(it = mi_conjunto.begin() ; it != mi_conjunto.end(); ++it){
		cout << (*it) << endl;
	}

}
