#include <cassert>

//#include "Vector_Dinamico.h"

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n){
  assert(n>=0);
  if (n>0){
    datos = new T[n];
  }
  ocupadas = 0;
  nelementos = n;
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico<T> & original){
  nelementos = original.nelementos;
  ocupadas = original.ocupadas;
  
  if(nelementos>0){
    datos = new T[ocupadas];
    for(int i=0; i<ocupadas; i++)
      datos[i] = original.datos[i];
    } else {
    nelementos = 0;
    ocupadas = 0;
    }
}

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico(){
  if (nelementos>0){
    delete []datos;
 }
 
  nelementos = 0;
  ocupadas = 0;
}

template <class T>
int Vector_Dinamico<T>::size() const{
  return nelementos;
}

template <class T>
int Vector_Dinamico<T>::GetOcupadas() const{
	return ocupadas;
}

template <class T>
void Vector_Dinamico<T>::resize(int n){
  assert(n>=0);
  if(n != nelementos){
    if (n!=0){
      T* nuevos_datos = new T[n];
      if (nelementos>0){
        int minimo = n<ocupadas?n:ocupadas; //Por si quieres reducir
        ocupadas = 0;
        for(int i=0; i<minimo; i++){
          nuevos_datos[i] = datos[i];
          ocupadas++;    //Cada vez que añades un datos haces ocupadas++, 
			 //indica que hay una poicion ocupada.
     }
        delete[] datos;
      }
      nelementos = n;
      datos = nuevos_datos;
    }
    else{ //Si n==0
      if(nelementos>0)
        delete[] datos;
      datos = 0;
      nelementos=0;
      ocupadas = 0;
    }
  }
}

template <class T>
void Vector_Dinamico<T>::push_back( const T & elemento){
	if(ocupadas == nelementos){
		resize(nelementos+1);
	}
	
	datos[ocupadas] = elemento;
	ocupadas++;

}

template <class T>
T& Vector_Dinamico<T>::operator[](const int i){
  //assert(i>=0 && i<nelementos);
  return datos[i];
}

template <class T>
const T& Vector_Dinamico<T>::operator[](const int i)const{
 //assert(i>=0 && i<nelementos);
  return datos[i];
}

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico<T> &original){
  if (this != &original)
    if (nelementos>0)
      delete[] datos;
  nelementos = original.nelementos;
  ocupadas = 0;
  if (nelementos>0){
    datos = new T[nelementos]; //elementos de original porque ya los has copiado en
			       //"nelementos = original.nelementos"
    for(int i=0; i<original.ocupadas; i++){
      datos[i] = original.datos[i];
      ocupadas++;
    }
  }
  return *this;
}


template <class T>
bool Vector_Dinamico<T>::operator == (const Vector_Dinamico<T> & otro){
  int nelem_este, nelem_otro, ocup_este, ocup_otro;
  nelem_este = nelementos;
  nelem_otro = otro.nelementos;
  ocup_este = ocupadas;
  ocup_otro = otro.ocupadas;

  bool iguales = (nelem_este == nelem_otro ? true : false);

  if(iguales){
    if(ocup_este == ocup_otro){
      bool sigo = true;
      int i = 0;
      while (sigo && i <= ocupadas){
         if(datos[i] == otro.datos[i]){
		i++;
	 }else{
	   sigo = false;
	   iguales = false ;
         }
        }    
      }
    }

  return (iguales);
}

template <class T>
bool Vector_Dinamico<T>::operator != (const Vector_Dinamico<T> & otro){
  bool no_igual = !(*this == otro);
  return no_igual;
}

      
