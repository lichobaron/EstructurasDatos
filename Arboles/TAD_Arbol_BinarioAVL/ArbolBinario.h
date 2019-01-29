
#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "NodoBinario.h"
#include <iostream>
#include <queue>

template< class T >

class ArbolBinarioAVL{
protected:
  NodoBinario<T> *raiz ;
public:
  ArbolBinarioAVL();
  ArbolBinarioAVL(T& val);
  ~ArbolBinarioAVL() = default;
  bool esVacio() ;
  T& datoRaiz();
  void preOrden() ;
  void inOrden() ;
  void posOrden();
  void nivelOrder();
  int altura();
  int tamano();
  bool buscar(T& val) ;
  bool insertar(T& val);
  bool eliminar(T& val);
  T& minimo();
  T& maximo();

};

#include "ArbolBinario.hxx"
#endif
