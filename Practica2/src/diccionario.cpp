#include <iostream>
#include <string>
#include "Vector_Dinamico.h"
#include "diccionario.h"

using namespace std;

//Constructor por defecto

Diccionario::Diccionario(){
  terminos = 0;
}

//Constructor por parametros

Diccionario::Diccionario(Vector_Dinamico<Termino> & term){
  for (int i=0; i<term.GetOcupadas();i++){
    terminos.push_back(term[i]);
  }
}

//Constructor de copia

Diccionario::Diccionario (const Diccionario& otro_diccionario){
	
  for (int i=0; i<otro_diccionario.getNumTerminos();i++){
    terminos.push_back(otro_diccionario[i]);
  }
	
}

//Consultor de definición

Vector_Dinamico<string> Diccionario::getDefinicion(string palabra) const{
  bool encontrada=false;
  Vector_Dinamico<string> definiciones;
  for (int i=0; i<terminos.size() && !encontrada; i++){
    string pal=terminos[i].GetPalabra();
    if (pal==palabra){
      definiciones =terminos[i].GetDefiniciones();
      encontrada=true;
    }
  }
  return definiciones;
}

Vector_Dinamico<string> Diccionario::GetDefinicion(int pos) const{
	//if (pos < terminos.size())
		return terminos[pos].GetDefiniciones();
}

//Consultor de terminos

Vector_Dinamico<Termino> Diccionario::getTerminos() const{
  return terminos;
}

//Consultor de numero de terminos

int Diccionario::getNumTerminos() const{
  return terminos.GetOcupadas();
}

//Operadores de modificación
//Añadir un nuevo termino

bool Diccionario::aniadirTermino(Termino nuevo){ 
  int num_ter = getNumTerminos();
  bool aniadido = false;
  bool pertenece = false;

  for (int i=0; i<num_ter && !pertenece; i++){
    if (nuevo.GetPalabra() == terminos[i].GetPalabra()) {
      pertenece=true;
      Vector_Dinamico<string> def = nuevo.GetDefiniciones();
      int num_def = nuevo.GetNumDefiniciones();
      for (int j=0; j<num_def; j++){
        terminos[i].AniadirDefinicion(def[j]);
        aniadido=true;
      }
    }
  }

  if (!pertenece){
    terminos.push_back(nuevo);
    aniadido=true;
  }


  ordenar();

  return aniadido;
}



//Borrar un termino

bool Diccionario::borrarTermino(Termino aborrar){
  int num_ter=terminos.size();
  bool borrado=false;
  bool encontrado=false;
  int i;

  for (i=0; i<num_ter && !encontrado; i++){ 
    if (terminos[i]==aborrar)
      encontrado=true;
  }

  if (encontrado){
    for (int k=i; k<num_ter;k++){
      terminos[k]=terminos[k+1];
    }
    terminos.resize(num_ter-1);
  }

  return borrado;
}

//Sobrecarga de operadores
//Operador =

Diccionario & Diccionario::operator= (const Diccionario & d){
	if(this != &d){
			terminos.resize(0);
	    for (int i=0; i<d.getNumTerminos();i++){
				cout << "A";
		    terminos.push_back(d.terminos[i]);
			}

	}
	
	return(*this);
}

//Operador []

const Termino & Diccionario::operator[](const int pos)const{
	return(terminos[pos]);
}

Termino & Diccionario::operator[](const int i){
	return(terminos[i]);
}

//Sobrecarga de <<

ostream & operator<< (ostream & os, const Diccionario & diccionario){
	Vector_Dinamico<Termino> term = diccionario.getTerminos();	
	
	for(int i = 0; i < diccionario.getNumTerminos(); i++){
	   os << term[i] << endl ;
	}
  

  return os; 
}

//Sobrecarga de >>

istream & operator>> (istream & is, Diccionario & diccionario){
	unsigned long long cnt=0;	
	if(is){
	  while(!is.eof()){
		Termino aux;
		string palabra;
		string def;
		
		getline(is, palabra, ';');
		getline(is, def);
		aux.SetPalabra(palabra);
		aux.AniadirDefinicion(def);
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

  Vector_Dinamico<Termino> filtrados;

  for (int i=0; i<getNumTerminos(); i++){
    string palabra= terminos[i].GetPalabra();
		if (palabra[0]>=caracter_inicio && palabra[0]<=caracter_final){
			filtrados.push_back(terminos[i]);
		}
  }
	
  Diccionario nuevo(filtrados);
	cout << "DICCIONARIO " << nuevo.getNumTerminos() << "/" << filtrados.GetOcupadas() << endl;
  return nuevo;
}

//Filtro por palabra clave

Diccionario Diccionario::filtroPalabraClave (string palabra_clave){
  Vector_Dinamico<Termino> filtrados;

  for (int i=0; i<terminos.size(); i++){
    Vector_Dinamico<string> definicion= terminos[i].GetDefiniciones();
      for (int k=0; k<definicion.size();k++){
        if (definicion[k].find(palabra_clave)!=-1)
          filtrados.push_back(terminos[i]);
      }
  }
 
  Diccionario nuevo(filtrados);
  cout << "DICCIONARIO " << nuevo.getNumTerminos() << "/" << filtrados.GetOcupadas() << endl;

  return nuevo;
}

//Recuento de definiciones

int Diccionario::recuentoDefiniciones (){
  int recuento=0;
  for (int i=0; i<terminos.size(); i++){
    Vector_Dinamico<string> definicion= terminos[i].GetDefiniciones();
    recuento+=definicion.size();
  }
  return recuento;
}

//Maximo de definiciones por palabra

int Diccionario::maximoDefiniciones (){
  int max_definiciones=0;

  for (int i=0; i<terminos.size(); i++){
    Vector_Dinamico<string> definicion= terminos[i].GetDefiniciones();
    if (definicion.size()>=max_definiciones)
      max_definiciones=definicion.size();
  }

  return max_definiciones;
}

//Promedio de definiciones

int Diccionario::promedioDefiniciones (){
   int promedio=0;
   promedio=this->recuentoDefiniciones() / terminos.size();
   return promedio;
}

//Ordenación

void Diccionario::ordenar(){
   for (int i = 0; i<terminos.size()-1; i++){
      for (int j = 0; j<terminos.size()-i-1; j++){
         if(terminos[j].GetPalabra() > terminos[j+1].GetPalabra()){
	    Termino aux = terminos[j];
	    terminos[j] = terminos[j+1];
	    terminos[j+1] = aux;
 
         }
      }
   }
}
