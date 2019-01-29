#ifndef __Semestre__HH__
#define __Semestre__HH__

#include <vector>
#include "Estudiante.h"
#include "Asignatura.h"

class Semestre{

protected:
  int ccloElect;
  std::vector<Estudiante*> estudiantes;
  std::vector<Asignatura*> asignaturas;

public:
  Semestre();
  Semestre(int ccloElect);
  int obtenerCcloElect();
  void fijarCcloElect(int ccloElect);
  std::vector<Estudiante*> obtenerEstudiantes();
  std::vector<Asignatura*> obtenerAsignaturas();
  Estudiante* buscarEstudiante(int IDEstudiante);
  Asignatura* buscarAsignatura(int IDCurso);
  void insertarAsignatura(Asignatura *asignatura);
  void insertarEstudiante(Estudiante *estudiante);
  std::vector<Clase*> obtenerClases();
  int obtenerInscritos(int IDCurso);
};

#include "Semestre.hxx"
#endif
