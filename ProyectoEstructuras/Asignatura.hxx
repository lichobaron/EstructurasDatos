#ifndef __Asignatura__HXX__
#define __Asignatura__HXX__

#include "Asignatura.h"

Asignatura::Asignatura(int grado, int IDCurso, std::string nombre, std::string desc, int credit, std::string, int IDcatalogo){
  this->grado=grado;
  this->IDCurso=IDCurso;
  this->nombre=nombre;
  this->descrip=desc;
  this->creditos= credit;
  this->sistemaCal=sistemaCal;
  this->IDcatalogo=IDcatalogo;
}

Asignatura::Asignatura(int grado, int IDCurso, std::string nombre, std::string desc, int IDcatalogo){
  this->grado=grado;
  this->IDCurso=IDCurso;
  this->nombre=nombre;
  this->descrip=desc;
  this->IDcatalogo=IDcatalogo;
}

Asignatura::Asignatura(int IDCurso, std::string nombre, int credit, std::string sistemaCal){
  this->IDCurso= IDCurso;
  this->nombre= nombre;
  this-> creditos= credit;
  this->sistemaCal= sistemaCal;
}

int Asignatura::obtenerIDCurso(){
  return this->IDCurso;
}

std::string Asignatura::obtenerNombre(){
  return this->nombre;
}

std::vector<Clase*> Asignatura::obtenerClases(){
  return this->clases;
}

std::vector<Asignatura *> Asignatura::obtenerPrerrequisitos(){
  return this->prerrequisitos;
}

Clase* Asignatura::buscarClase(int IDClase){
  for(int i=0;i<this->clases.size();i++){
    if(this->clases[i]->obtenerIDClase()==IDClase){
      return this->clases[i];
    }
  }
  return nullptr;
}

void Asignatura::insertarClase(Clase *clase){
  this->clases.push_back(clase);
}

void Asignatura::insertarPrerreq(Asignatura *prerreq){
  this->prerrequisitos.push_back(prerreq);
}

int Asignatura::totalInscritos(int ccloElect){
  int x=0;
  for(int i=0;i<this->clases.size();i++){
    if(this->clases[i]->obtenerCcloElect()==ccloElect){
      x=x+this->clases[i]->obtenerTotalIns();
    }
  }
  return x;
}

#endif
