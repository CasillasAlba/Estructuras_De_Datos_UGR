//Programa de prueba que calcula las frecuencias absolutas y relativas según las veces que aparece cada letra en el diccionario.
//El resultado es guardado en un fichero de texto

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "diccionario.h"
#include "conjuntoLetras.h"

using namespace std;


//Función que calcula la frecuencia relativa.

double frecuenciaRelativa (int num_apariciones, int suma){
	double frec_relat;

	frec_relat = ((double)num_apariciones/suma) * 100;

  return frec_relat;
}





int main(int argc, char * argv[]){

  if (argc!=4){
  	cout<<"Numero de parámetros incorrecto"<<endl;
    return 0;
  }

  ifstream f (argv[1]);

  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  ifstream fi (argv[2]);

  if (!fi){
   cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
   return 0;
  }

  ofstream fo (argv[3]);

  if (!fo){
		cout << "No se ha podido crear el fichero" << argv[3] << endl;
    return 0;
  }

  //Completamos la cabecera del fichero de escritura
  fo << "#Letra\tFabs.\tFrel." << endl;

  Diccionario mi_diccionario;

  cout << "Cargando..." << endl;
  f>>mi_diccionario; //Cargamos en memoria el diccionario
  cout << "Diccionario cargado" << endl;


  ConjuntoLetras mi_conjunto;

  cout << "Cargamos el conjunto de letras" << endl;
  fi >>mi_conjunto; //Cargamos en memoria el conjunto de letras
  cout << "Conjunto de letras cargado" << endl;

 
  iteratorcl it;
	iteratord itd;

  vector< pair<char, int> > info_fabs;
  double frel = 0.0;
  int suma_fabs = 0;
	
  for(it = mi_conjunto.begin() ; it != mi_conjunto.end(); ++it){
		int fabs = 0;
		for (itd = mi_diccionario.begin() ; itd != mi_diccionario.end(); ++itd){
			for(unsigned int i = 0; i < (*itd).size() ; i++){
				if (tolower((*it).getLetra()) == (*itd)[i]){
       		fabs++;
				}
			}
		}

   info_fabs.push_back(make_pair((*it).getLetra(), fabs));
   suma_fabs += fabs;

  }


	for (unsigned int i = 0; i < info_fabs.size(); i++){
   	frel = frecuenciaRelativa(info_fabs[i].second, suma_fabs);
    fo << info_fabs[i].first << "\t" << info_fabs[i].second << "\t" << frel << endl;
  }

  cout << "¡¡Ya puede consultar su fichero de frecuencias!!" << endl;
}



   
