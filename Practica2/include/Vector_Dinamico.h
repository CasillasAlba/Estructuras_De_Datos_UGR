#ifndef VectorDinamico_h
#define VectorDinamico_h

template <class T>
class Vector_Dinamico{
private:

  T * datos;
  int nelementos;
  int ocupadas ;

public:

  Vector_Dinamico<T>(int n=0);
  Vector_Dinamico<T>(const Vector_Dinamico & original);
  ~Vector_Dinamico<T>();
  int size() const;
  void resize( int n);
  int GetOcupadas() const;
  void push_back( const T & elemento);
  T & operator[](const int i);
  const T & operator[](const int i) const;
  Vector_Dinamico <T>& operator=(const Vector_Dinamico<T> & original);
  bool operator == (const Vector_Dinamico<T> & otro);
  bool operator != (const Vector_Dinamico<T> & otro);
  
};

#include "Vector_Dinamico.tpp"

#endif // VectorDinamico_h
