#ifndef __ClaseEst__HH__
#define __ClaseEst__HH__

#include <vector>
#include "Clase.h"

class ClaseEst{

protected:
  Clase* clase;
  int calAsig;
  std::string estadoIns;
  std::string fechaIns;
  std::string fechaBaja;

public:
  ClaseEst(Clase *clase, int calAsig, std::string estadoIns, std::string fechaInicio, std::string fechaFinal);
  Clase* obtenerClase();
};

#include "ClaseEst.hxx"
#endif
