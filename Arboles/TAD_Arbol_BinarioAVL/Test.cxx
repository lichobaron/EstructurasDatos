#include <iostream>
#include "ArbolBinario.h"

int main(int argc, char const *argv[]) {
  ArbolBinarioAVL<int> arbol;
  int var = 7 ;
  int var1 = 3 ;
  int var2 = 20 ;
  int var3 = 0 ;
  int var4 = 5 ;
  int var5 = -3 ;
  int var6 = 1 ;
  int var7 = 4 ;
  int var8 = 6 ;
  int var9 = 15 ;
  int var10 = 25 ;
  int var11 = 30;
  int var12 = 35;
  int var13 = 8;
  int var14 = 16;
  int var15 = 14 ;
  int var16 = 9 ;
  int var17 = 40 ;
  int var18 = 2 ;
  int var19 = 10 ;
  int var20 = 18 ;


  arbol.insertar(var4);


  arbol.insertar(var14);
  arbol.insertar(var6);
  arbol.insertar(var13);
  arbol.insertar(var7);
  arbol.insertar(var10);
  arbol.insertar(var1);
  arbol.insertar(var8);
  arbol.insertar(var12);
  arbol.insertar(var9);
  arbol.insertar(var2);


  arbol.insertar(var5);
  arbol.insertar(var11);
  arbol.insertar(var);
  arbol.insertar(var3);


  std::cout<<std::endl ;
  arbol.preOrden();
  std::cout<<std::endl<<"ALTURA : "<<arbol.altura() ;
  std::cout<<std::endl<<"TAMAÑO : "<<arbol.tamano() ;
  std::cout<<std::endl<<"MINIMO : "<<arbol.minimo() ;
  std::cout<<std::endl<<"MAXIMO : "<<arbol.maximo() ;
  std::cout<<std::endl ;
  /*
  arbol.eliminar(var10);
  arbol.eliminar(var13);
  arbol.eliminar(var1);
  arbol.eliminar(var14);
  arbol.eliminar(var6);
  arbol.eliminar(var3);
  arbol.eliminar(var7);
  arbol.eliminar(var11);
  arbol.insertar(var14);
  arbol.insertar(var15);
  arbol.insertar(var13);
  arbol.insertar(var16);
  */
  arbol.insertar(var16);
  arbol.insertar(var15);

  arbol.insertar(var17);
  arbol.insertar(var18);
  arbol.insertar(var19);
  arbol.insertar(var20);
  arbol.eliminar(var13);
  arbol.preOrden();
  std::cout<<std::endl ;


  return 0;
}
