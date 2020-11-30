#include <iostream>
#include "Vector_Dinamico.h"

using namespace std;

template <class T>
void cargar_indices(Vector_Dinamico<T> & v){
  for(int i=0; i<v.size(); i++){
	v.push_back(i);
  }

}

template <class T>
T maximo(const Vector_Dinamico<T> &v){
  T max;
  if (v.size()==0){
    cerr << "Máximo de 0 elementos!! Asignamos 0 "<< endl;
    max = 0;
  }
  else{
    max = v[0];
    for(int i=1; i<v.size(); i++)
      if (max < v[i])
        max = v[i];
  }
  return max;
}

int main() {
  Vector_Dinamico<float> vector;
  cargar_indices(vector);
  cout << "Máximo de " << vector.size() << " elementos: "
  << maximo(vector) << endl;
  
  vector.resize(10);
  cargar_indices(vector);
  cout << "Máximo de " << vector.size() << " elementos: "
  << maximo(vector) << endl;
  
  vector.push_back(1);
  
  for(int i= 0; i < vector.GetOcupadas(); i++){
  	cout << "Vector habiendo hecho push_back" << vector[i] << endl;
  }

  cout << endl;
  cout << "Usamos el contructor de copia para crear otro vector" << endl;
  Vector_Dinamico<float> v2 (vector);

  cout << "Comparamos vectores." << endl;
  if(vector == v2){
	cout << "Ambos vectores son iguales" << endl;
  }else{
	cout << "Los vectores no son iguales" << endl ;
  }
  
  return 0;
}
