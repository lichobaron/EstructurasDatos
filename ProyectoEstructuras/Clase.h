#ifndef __Clase__HH__
#define __Clase__HH__

#include <vector>
#include "Sesion.h"

class Clase{

protected:
  int ccloElect;
  int IDCurso;
  int IDClase;
  int seccion;
  std::string estado;
  std::string estadoIns;
  std::string fechaInicio;
  std::string fechaFinal;
  std::string nombreAsig;
  int capInsc;
  int totalIns;
  std::vector<Sesion*> sesiones;

public:
  Clase(int ccloElect, int IDCurso, int IDClase, int seccion, std::string estado,
  std::string estadoIns, std::string fechaInicio, std::string fechaFinal,
  int capInsc, int totalIns, std::string nombreAsig);
  int obtenerIDClase();
  int obtenerIDCurso();
  int obtenerCcloElect();
  std::string obtenerNombre();
  int obtenerTotalIns();
  std::vector<Sesion*> obtenerSesiones();
  void insertarSesion(Sesion *sesion);
  void imprimirSesiones();
};

#include "Clase.hxx"
#endif
