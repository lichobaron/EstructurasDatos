#include <iostream>
#include "ArbolBinarioOrd.h"

using namespace std;
int main()
{
  int a=6, b=8, c=1, d=3, e=10, f=11, g=9;
  ArbolBinarioOrd<int> arbol = ArbolBinarioOrd<int>();
  arbol.insertar(arbol.obtenerRaiz(),a);
  arbol.insertar(arbol.obtenerRaiz(),b);
  arbol.insertar(arbol.obtenerRaiz(),c);
  arbol.insertar(arbol.obtenerRaiz(),d);
  arbol.insertar(arbol.obtenerRaiz(),e);
  arbol.insertar(arbol.obtenerRaiz(),f);
  arbol.insertar(arbol.obtenerRaiz(),g);
  arbol.inOrden(arbol.obtenerRaiz());
  cout<<endl<<"Altura: "<<arbol.altura(arbol.obtenerRaiz())<<endl;
  //arbol.nivelOrden(arbol.obtenerRaiz());
  //cout<<endl;
  cout<<"Minimo: "<<arbol.minimo(arbol.obtenerRaiz())<<endl;
  cout<<"Maximo: "<<arbol.maximo(arbol.obtenerRaiz())<<endl;
  arbol.eliminar(nullptr,arbol.obtenerRaiz(),b);
  cout<<endl<<"Altura: "<<arbol.altura(arbol.obtenerRaiz())<<endl;
  arbol.inOrden(arbol.obtenerRaiz());
  cout<<endl;
  return 0;
}
