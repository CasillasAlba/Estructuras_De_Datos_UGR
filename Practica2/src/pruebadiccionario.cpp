#include "diccionario.h"
#include <fstream>
#include <iostream>

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
    f>>mi_diccionario; //Cargamos en memoria el diccionario

    mi_diccionario.ordenar();
	

    cout << "Terminos leidos, hay un total de: ";
    cout << mi_diccionario.getNumTerminos() << endl;

    cout << "Vamos a obtener las definiciones asociadas a una palabra" << endl;
    string p;
    getline(cin, p);
    Vector_Dinamico<string> t = mi_diccionario.getDefinicion(p);
    cout << "Las definiciones de " << p << " son:" << endl;
    for (int i = 0; i<t.size(); i++){
	cout << t[i] << endl;
    }
    cout << endl << endl;

    char c_i, c_f ;
    cout << "Creamos un sub-diccionario de terminos comprendidos entre dos caracteres: " << endl;
    cout << "Introduzca el caracter inicial: " ;
    cin >> c_i;
    cout << "Introduzca el caracter final: " ;
    cin >> c_f ;
    Diccionario dic_peque=mi_diccionario.filtroIntervalo(c_i,c_f);
		
    cout << dic_peque << endl << endl;
   
    string clave;
    cout << "Creamos un sub-diccionario de terminos asociados a una clave: " << endl;
    cout << "Introduzca la clave: " ;
    cin >> clave ;
    Diccionario dic_clave = mi_diccionario.filtroPalabraClave(clave);
    cout << dic_clave << endl << endl;

    int recuento = mi_diccionario.recuentoDefiniciones();
    int maximo = mi_diccionario.maximoDefiniciones();
    int promedio = mi_diccionario.promedioDefiniciones();

    cout << "Este diccionario tiene un total de " << recuento << " definiciones, con un maximo de " << maximo << " definiciones "
	  << "asociadas a una misma palabra y con un promedio de " << promedio << " definiciones por palabra" << endl << endl;

   

}
