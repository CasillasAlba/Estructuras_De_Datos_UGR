//Programa de prueba para comprobar el correcto funcionamiento del TDA Diccionario

#include "diccionario.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
  	cout<<"Dime el nombre del fichero con el diccionario"<<endl;
    return 0;
  }

  ifstream f (argv[1]);

	if (!f){
  	cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
   
  
  Diccionario mi_diccionario;

  cout << "Cargando..." << endl;
  f>>mi_diccionario; //Cargamos en memoria el diccionario
  cout << "Cargado" << endl;


  const_iteratord it;

  for(it = mi_diccionario.begin() ; it != mi_diccionario.end(); ++it){
		cout << (*it) << endl;
  }


  int longitud;

  cout << "Dime una longitud de las palabras que quieres ver ";
  cin >> longitud;

  vector<string> conjunto = mi_diccionario.palabrasLongitud(longitud);

  cout << "Palabras de Longitud " << longitud << endl;

  vector<string>::const_iterator c_ite;

  for(c_ite = conjunto.cbegin(); c_ite != conjunto.cend(); c_ite++){
		cout << (*c_ite) << endl;
  }

  string p;

  cout << "Dime una palabra: ";
  cin >> p;

  if(mi_diccionario.esta(p)){
		cout << "La palabra existe" << endl;
  }else{
		cout << "La palabra no existe" << endl;
  }

}
