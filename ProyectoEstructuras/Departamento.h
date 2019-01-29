#ifndef __Departamento__HH__
#define __Departamento__HH__

#include "Asignatura.h"

class Departamento{

protected:
  std::string orgAcad;
  std::string descFmal;
  std::vector<Asignatura*> asignaturas;

public:
  Departamento(std::string orgAcad,std::string descFmal);
  std::string obtenerOrgAcad();
  std::string obtenerDescFmal();
  std::vector<Asignatura*> obtenerAsignaturas();
  Asignatura* buscarAsignatura(int IDCurso);
  void insertarAsignatura(Asignatura *asignatura);
};

#include "Departamento.hxx"
#endif
