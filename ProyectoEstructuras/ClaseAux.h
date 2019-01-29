#ifndef __ClaseAux__HH__
#define __ClaseAux__HH__

#include <vector>
#include "Estudiante.h"
#include "Clase.h"

class ClaseAux{

protected:
  Clase *clase;
  std::vector<Estudiante*> estudiantes;

public:
  ClaseAux(Clase* clase);
  Clase* obtenerClase();
  std::vector<Estudiante*> obtenerEstudiantes();
  void insertarEstudiante(Estudiante* estudiante);
};

#include "ClaseAux.hxx"
#endif
