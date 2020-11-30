#include <iostream>
#include "Pila_max.hpp"

using namespace std;

int main(){

	
  Pila_max<int> p;

  p.poner(2);
  cout << "Se introduce el valor 2. El maximo es " << p.valor_maximo() << endl;
  p.poner(5);
  cout << "Se introduce el valor 5. El maximo es " << p.valor_maximo() << endl;
  p.poner(4);
  cout << "Se introduce el valor 4. El maximo es " << p.valor_maximo() << endl;
  p.poner(9);
  cout << "Se introduce el valor 9. El maximo es " << p.valor_maximo() << endl;
  p.poner(7);
  cout << "Se introduce el valor 7. El maximo es " << p.valor_maximo() << endl;
  p.poner(8);
  cout << "Se introduce el valor 8. El maximo es " << p.valor_maximo() << endl;
   
  

  cout << "La cola tiene " << p.numElementos() << " elementos. ";
  cout << "El maximo es " << p.valor_maximo() << endl;


  while(!p.vacia()){
    cout << p.tope();
    p.quitar();
    cout << "Se quita este valor" << endl;
  }

}
 
