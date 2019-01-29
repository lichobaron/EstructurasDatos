#ifndef __NodoAsignatura__HH__
#define __NodoAsignatura__HH__

#include "Sistema.h"
#include "Asignatura.h"
#include <vector>

class NodoAsignatura{

protected:
  Asignatura *asignatura;
  int inscritos;
  std::vector<NodoAsignatura*> hijos;

public:
  NodoAsignatura();
  NodoAsignatura(Asignatura *asignatura);
  int obtenerIDCurso();
  std::string obtenerNombre();
  int obtenerInscritos();
  Asignatura* obtenerAsignatura();
  std::vector<NodoAsignatura*> obtenerHijos();
  void agregarHijoAux(NodoAsignatura* nodoAsign);
  void agregarHijo(Asignatura *hijo);
  NodoAsignatura* obtenerNodo(Asignatura* a);
  bool crearArbol(Asignatura *asignatura, Sistema *sistema, int semestre);
};

#include "NodoAsignatura.hxx"
#endif
