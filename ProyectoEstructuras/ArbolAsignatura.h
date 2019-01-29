#ifndef __ArbolAsignatura__HH__
#define __ArbolAsignatura__HH__

#include "NodoAsignatura.h"
#include "Sistema.h"
#include <queue>
#include <iostream>
#include <vector>

class ArbolAsignatura{

protected:
 NodoAsignatura *raiz;

public:
  ArbolAsignatura();
  ArbolAsignatura(NodoAsignatura *r);
  NodoAsignatura* obtenerRaiz();
  bool llenarArbol(Asignatura* asignatura, Sistema *sistema, int it);
  void imprimirArbol(NodoAsignatura *raiz);
  bool calcularDemanda(Semestre *semestre);
  void nivelOrden(int sem);
  void agregarHijo(NodoAsignatura* asig);
  bool nodoRepetido(NodoAsignatura* nodo);
  NodoAsignatura* obtenerNodo(Asignatura* a);
  void arbolIndividual(Sistema *sistema,std::vector<Asignatura*> v,Asignatura * a);
  ArbolAsignatura* arbolFut(Semestre* sem, std::vector<Asignatura*> &v,Asignatura * a,std::vector<Asignatura*> fut);
};

#include "ArbolAsignatura.hxx"
#endif
