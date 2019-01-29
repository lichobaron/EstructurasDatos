#ifndef __Departamento__HXX__
#define __Departamento__HXX__

#include "Departamento.h"

Departamento::Departamento(std::string orgAcad,std::string descFmal){
  this->orgAcad=orgAcad;
  this->descFmal=descFmal;
}

std::string Departamento::obtenerOrgAcad(){
  return this->orgAcad;
}

std::string Departamento::obtenerDescFmal(){
  return this->descFmal;
}

std::vector<Asignatura*> Departamento::obtenerAsignaturas(){
  return this->asignaturas;
}

Asignatura* Departamento::buscarAsignatura(int IDCurso){
  for(int i=0;i<this->asignaturas.size();i++){
    if(this->asignaturas[i]->obtenerIDCurso()==IDCurso){
      return this->asignaturas[i];
    }
  }
  return nullptr;
}

void Departamento::insertarAsignatura(Asignatura *asignatura){
  this->asignaturas.push_back(asignatura);
}

#endif
