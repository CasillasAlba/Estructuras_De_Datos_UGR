//Programa principal del juego

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include "bolsaLetras.h"
#include "diccionario.h"

using namespace std;





//---------------------------------
//  ¡¡Funciones del programa!!
//---------------------------------


//Función que inicializa la semilla usada para crear una bolsa de letras aleatorias

void inicializarSemilla(){
	srand(time(0));
}

//Función que calcula la puntuación de una palabra

int calculaPuntuacion(string pal, BolsaLetras bolsa){
	int puntuacion = 0;

  for (unsigned int i = 0; i < pal.size(); i++){

		bool encontrada = false;
		iteratorb it;

    for ( it = bolsa.begin(); it != bolsa.end() && !encontrada; ++it){

			if(toupper(pal[i]) == (*it).getLetra()){

        puntuacion += (*it).getPuntuacion();
        encontrada = true;

      }
    } 
  }

  return puntuacion;

}

//Función que calcula la mejor opción

string mejorOpcion (vector<pair<string,int> > res){
		int maximo = res[0].second;
    string mejor_palabra = res[0].first;

		for (unsigned int i = 1; i < res.size(); i++){

				if (res[i].second > maximo){

          maximo = res[i].second;
					mejor_palabra = res[i].first;

				}
		}

	return mejor_palabra;

}


//Función que calcula las mejores soluciones según la longitud

/*

	Igualamos una variable contador al tamaño de la bolsa, para buscar palabras válidas de tamaño
	menor o igual que a bolsa y mayor o igual que la puntuación de la solución dada (ya que no nos interesa
	las de puntuación menor). Si la palabra puede formarse con las letras de la bolsa, la añadimos a un vector
	de parejas(la palabra y su longitud)

*/

vector<pair<string,int> > victoriasLongitud(Diccionario dic, BolsaLetras bolsa, int punt){
	vector<pair<string, int> > res;
  int contador = bolsa.getTamanio();
	vector<string> longitudes;

  while(contador >= punt && res.empty()){

		longitudes = dic.palabrasLongitud(contador);
    iteratorb it;
    bool esta;
 
    for(unsigned int i = 0; i < longitudes.size(); i++){

      BolsaLetras baux(bolsa);
		  string palabra = longitudes[i];
      esta = baux.palabraEnBolsa(palabra);

      if(esta){

					res.push_back(make_pair(palabra,palabra.size()));

      }
    }
   
    contador--;
  }

	return res;
}


//Función que calcula las mejores soluciones según la puntuación

/*
  Recorremos las palabras en la bolsa, y comprobamos que se pueden formar. Si se puede formar, 
	calculamos su puntuación.
  Como hay que quedarse con las palabras que acumulen una mayor puntuación, metemos en un vector de
	parejas las que superen (o igualen) la puntuación máxima encontrada hasta el moento, eliminando
	las de menor puntuación.

*/

vector<pair<string,int> > victoriasPuntuacion(Diccionario dic, BolsaLetras bolsa, int punt){
	vector<pair<string, int> > res;
	iteratord it;
  iteratorb itb;
  bool esta;


  for ( it = dic.begin(); it != dic.end() ; ++it){

		BolsaLetras baux(bolsa);
    esta = baux.palabraEnBolsa(*it);

    if(esta){

      int puntuacion = 0;
      string palabra = *it;

      puntuacion = calculaPuntuacion(palabra, bolsa);

      if (puntuacion > punt){

        res.clear();
				res.push_back(make_pair((*it),puntuacion));
        punt = puntuacion;

      }else if (puntuacion == punt){

				res.push_back(make_pair((*it),puntuacion));

      }
    }
  }

return res;

}





//---------------------------------
//  ¡¡Programa principal!!
//---------------------------------


int main(int argc, char * argv[]){
  inicializarSemilla();

  if (argc!=5){
    cout << "Numero de parámetros incorrecto." << endl;
    return 0;
   }

  ifstream f (argv[1]);

  if (!f){
    cout << "No puedo abrir el fichero. " << argv[1] << endl;
    return 0;
  }

  ifstream fi (argv[2]);

  if (!fi){
    cout << "No puedo abrir el fichero. " << argv[2] << endl;
    return 0;
  }

  int total_bolsita = (atoi(argv[3]));
   
  if(total_bolsita <= 0 || total_bolsita > 24){
  	cerr << "No se puede crear una bolsita con este numero de letras." << endl;
		exit(1);
  }

  string modalidad = argv[4];

  if(modalidad[0] != 'L' && modalidad[0] != 'P'){
    cerr << "Modalidad de juego incorrecta. ('L' para jugar por longitud y 'P' para jugar por puntuacion)." << endl;
		exit(1);
  }

  Diccionario mi_diccionario;

  cout << "Cargando..." << endl;
  f>>mi_diccionario; //Cargamos en memoria el diccionario
  cout << "Diccionario cargado" << endl;


  ConjuntoLetras mi_conjunto;

  cout << "Cargando..." << endl;
  fi >>mi_conjunto; //Cargamos en memoria el conjunto de letras
  cout << "Conjunto de letras cargado" << endl;

 char otra_vez;

 do{
  
  BolsaLetras b(atoi(argv[3]), mi_conjunto);  //atoi(argv[3]); convierte el char en un entero
	BolsaLetras baux(b);

  cout << "Mostrando bolsa de letras: " << endl;

  iteratorb itbol;
  for (itbol = b.begin(); itbol != b.end(); ++itbol){
		cout << "Letra:\t" << (*itbol).getLetra() << "\tPuntuacion\t" << (*itbol).getPuntuacion() << endl;
  }

  string solucion;
  bool esta_en_bolsa;
	



   
  //Comprobamos que la solución dada se puede formar con las letras que tenemos.

  do{

    cout << "Dime tu solución: " ;
		cin >> solucion;

    BolsaLetras baux(b);
    esta_en_bolsa = baux.palabraEnBolsa(solucion);
   
    if(!esta_en_bolsa){
			cout << "Esta palabra no se puede formar con las letras que tienes..."  << endl;
    }else if(!mi_diccionario.esta(solucion)){
			cout << "La palabra se puede formar pero no se encuentra en el diccionario. ¡¡Lo siento!!" << endl;
    }
 
  }while(!esta_en_bolsa || !mi_diccionario.esta(solucion));


  int puntuacion = 0;
	int maximo;
	string mejor_palabra;
  vector<pair<string,int> > resultados;

	//Actuamos en base a la opción que hemos elegido

  if(modalidad[0] == 'L'){
   
		puntuacion = solucion.size();

		cout << solucion << "\tPuntuacion:   " << puntuacion << endl;
 
		resultados = victoriasLongitud(mi_diccionario, b, puntuacion);


  }if (modalidad[0] == 'P'){

		puntuacion = calculaPuntuacion(solucion,b);

   	cout << solucion << "\tPuntuacion:\t" << puntuacion << endl;

		resultados = victoriasPuntuacion(mi_diccionario, b, puntuacion);

  }

	//Mostramos las soluciones

  cout << "Mis soluciones son: " << endl;
  for (unsigned int i = 0; i < resultados.size(); i++){
		cout << resultados[i].first << "\tPuntuacion:\t" << resultados[i].second << endl;
  }

	//Mostramos la mejor solución

   mejor_palabra = 	mejorOpcion(resultados);		
	 cout << "Mejor solucion: " << mejor_palabra << endl;



   cout << "¿Quieres seguir jugando[S/N]?" << endl;
   cin >> otra_vez;

 }while ( otra_vez != 'N');
    

}
