#ifndef __ClaseAux__HXX__
#define __ClaseAux__HXX__

#include "ClaseAux.h"

ClaseAux::ClaseAux(Clase *clase){
  this->clase=clase;
}

Clase* ClaseAux::obtenerClase(){
  return this->clase;
}

std::vector<Estudiante*> ClaseAux::obtenerEstudiantes(){
  return this->estudiantes;
}

void ClaseAux::insertarEstudiante(Estudiante *estudiante){
    this->estudiantes.push_back(estudiante);
}

#endif
