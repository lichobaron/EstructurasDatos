#ifndef __Estudiante__HXX__
#define __Estudiante__HXX__

#include "Estudiante.h"

Estudiante::Estudiante(std::string gradoAcademico, std::string indBaja, int IDEstudiante, std::string nombre,
  int grado, std::string indAcadBase, std::string indAcad, std::string nombreProgAcad){
  this->gradoAcademico=gradoAcademico;
  this->indBaja= indBaja;
  this->IDEstudiante= IDEstudiante;
  this->nombre= nombre;
  this->grado= grado;
  this->indAcadBase=indAcadBase;
  this->indAcad= indAcad;
  this->nombreProgAcad=nombreProgAcad;
}

int Estudiante::obtenerIDEstudiante(){
  return this->IDEstudiante;
}

std::string Estudiante::obtenerNombre(){
  return this->nombre;
}

std::vector<ClaseEst*> Estudiante::obtenerClasesInsc(){
  return this->clasesInsc;
}
void Estudiante::insertarClaseEst(ClaseEst *claseEst){
  this->clasesInsc.push_back(claseEst);
}

bool Estudiante::buscarClase(int IDClase){
  for(int i=0;i<this->clasesInsc.size();i++){
    if(clasesInsc[i]->obtenerClase()->obtenerIDClase()==IDClase){
      return true;
    }
  }
  return false;
}

bool operator == (const Estudiante &v1, const Estudiante &v2){
  return v1.IDEstudiante==v2.IDEstudiante;
}

bool operator != (const Estudiante &v1, const Estudiante &v2){
  return v1.IDEstudiante!=v2.IDEstudiante;
}

bool operator <= (const Estudiante &v1, const Estudiante &v2){
  return v1.IDEstudiante<=v2.IDEstudiante;
}

bool operator >= (const Estudiante &v1, const Estudiante &v2){
  return v1.IDEstudiante>=v2.IDEstudiante;
}

bool operator < (const Estudiante &v1, const Estudiante &v2){
  return v1.IDEstudiante<v2.IDEstudiante;
}

bool operator > (const Estudiante &v1, const Estudiante &v2){
  return v1.IDEstudiante>v2.IDEstudiante;
}

std::ostream& operator <<(std::ostream &o, const Estudiante *v1){
  o<<v1->nombre;
  return o;
}

#endif
