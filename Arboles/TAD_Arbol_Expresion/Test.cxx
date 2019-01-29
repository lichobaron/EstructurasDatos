#include <iostream>
#include "ArbolExpresion.h"


int main(int argc, char const *argv[]) {
  /* code */
  ArbolExpresion arbol ;
  std::string a = "5 28 + -8 / 4 2 ^ *" ;
  arbol.llenarDesdePosfija(a);
  std::cout<<"\n \n ---> Prefija Es "<<arbol.obtenerInfija()<<std::endl;
  std::cout<<"\n \n ---> Resltado es  "<<arbol.evaluar()<<std::endl ;
  return 0;
}
