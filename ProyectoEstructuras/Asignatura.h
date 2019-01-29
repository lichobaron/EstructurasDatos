#ifndef __Asignatura__HH__
#define __Asignatura__HH__

#include <vector>
#include "Clase.h"

class Asignatura{

protected:
  int IDCurso;
  int grado;
  std::string nombre;
  std::string descrip;
  int creditos;
  std::string sistemaCal;
  int IDcatalogo;
  std::vector<Clase*> clases;
  std::vector<Asignatura *> prerrequisitos;

public:
  Asignatura(int grado, int IDCurso, std::string nombre, std::string desc, int credit, std::string sistemaCal, int IDcatalogo);
  Asignatura(int grado, int IDCurso, std::string nombre, std::string desc, int IDcatalogo);
  Asignatura(int IDCurso, std::string nombre, int credit, std::string sistemaCal);
  int obtenerIDCurso();
  std::string obtenerNombre();
  std::vector<Clase*> obtenerClases();
  std::vector<Asignatura*> obtenerPrerrequisitos();
  Clase* buscarClase(int IDClase);
  void insertarClase(Clase *clase);
  void insertarPrerreq(Asignatura *prerreq);
  int totalInscritos(int ccloElect);
};

#include "Asignatura.hxx"
#endif
