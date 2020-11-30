#include <cassert>
#include "Cola_max_vd.hpp"

template <class T>
Cola_max<T>::Cola_max(){
  datos = new Element<T>[1];
  reservados = 1;
  anterior = posterior = 0;
  nelem = 0;
}

template <class T>
Cola_max<T>::Cola_max(const Cola_max<T>& c){
  copiar(c);
}

template <class T>
Cola_max<T>& Cola_max<T>::operator=(const Cola_max<T>& c){
  if(this!=&c){
    liberar();
    copiar(c);
  }
 return(*this);
}

template <class T>
Cola_max<T>::~Cola_max(){
 liberar();
}

template <class T>
void Cola_max<T>::poner(const T valor){
  if(nelem==reservados)
    resize(2*reservados);
  datos[posterior].valor = valor;
  datos[posterior].maximo = valor;
  this->editarMaximos();
  posterior=(posterior+1)%reservados;
  nelem++;
}

template <class T>
void Cola_max<T>::quitar(){
  assert(nelem!=0);
  anterior = (anterior+1)%reservados;
  nelem--;
  if (nelem< reservados/4)
    resize(reservados/2);
}

template <class T>
T Cola_max<T>::frente() const{
  assert(nelem!=0);
  return datos[anterior].valor;
}

template <class T>
bool Cola_max<T>::vacia() const{
  return (nelem == 0);
}

template <class T>
void Cola_max<T>::copiar(const Cola_max &c){
  reservados = c.reservados;
  datos = new Element<T>[reservados];
  for (int i= anterior; i!=posterior; i= (i+1)%reservados)
    datos[i] = c.datos[reservados];
  anterior = c.anterior;
  posterior = c.posterior;
  nelem = c.nelem;
}

template <class T>
void Cola_max<T>::liberar(){
  delete[] datos;
  anterior = posterior = nelem = reservados = 0;
}

template <class T>
void Cola_max<T>::resize(const int n){
  assert(n>0 && n>nelem);
  Element<T>* aux = new Element<T>[n];
  for(int i=0; i<nelem; i++)
    aux[i] = datos[(anterior+i)%reservados];
  anterior = 0;
  posterior = nelem;
  delete[] datos;
  datos = aux;
  reservados = n;
}

template <class T>
T Cola_max<T>::maximo(){
  return datos[anterior].maximo;
}

template <class T>
void Cola_max<T>::editarMaximos(){
  T max = datos[posterior].maximo;
  for (int i=0; i<nelem; i++){
    if(datos[posterior-i-1].maximo > max)
      max = datos[posterior-i-1].maximo;
    else
      datos[posterior-i-1].maximo = max;
  }
}

template <class T>
int Cola_max<T>::num_elementos(){
  return nelem;
}
