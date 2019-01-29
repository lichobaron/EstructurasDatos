#ifndef __Estudiante__HH__
#define __Estudiante__HH__

#include <vector>
#include "ClaseEst.h"

class Estudiante{

protected:
  int IDEstudiante;
  std::string gradoAcademico;
  std::string nombre;
  int grado;
  std::string indAcadBase;
  std::string indAcad;
  std::string nombreProgAcad;
  std::string indBaja;
  std::vector<ClaseEst*> clasesInsc;

public:
  Estudiante(std::string gradoAcademico, std::string indBaja, int IDEstudiante, std::string nombre, int grado,
    std::string indAcadBase, std::string indAcad, std::string nombreProgAcad);
  int obtenerIDEstudiante();
  std::string obtenerNombre();
  std::vector<ClaseEst*> obtenerClasesInsc();
  void insertarClaseEst(ClaseEst *claseEst);
  bool buscarClase(int IDClase);
  //friend std::string getData(const Estudiante &e);
  friend bool operator == (const Estudiante &v1, const Estudiante &v2);
  friend bool operator != (const Estudiante &v1, const Estudiante &v2);
  friend bool operator <= (const Estudiante &v1, const Estudiante &v2);
  friend bool operator >= (const Estudiante &v1, const Estudiante &v2);
  friend bool operator < (const Estudiante &v1, const Estudiante &v2);
  friend bool operator > (const Estudiante &v1, const Estudiante &v2);
  friend std::ostream& operator <<(std::ostream &o, const Estudiante *v1);
};

#include "Estudiante.hxx"
#endif
