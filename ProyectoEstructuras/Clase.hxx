#ifndef __Clase__HXX__
#define __Clase__HXX__

#include "Clase.h"

Clase::Clase(int ccloElect, int IDCurso, int IDClase, int seccion, std::string estado,
  std::string estadoIns, std::string fechaInicio, std::string fechaFinal,
  int capInsc, int totalIns, std::string nombreAsig){
  this->ccloElect= ccloElect;
  this->IDCurso=IDCurso;
  this->IDClase=IDClase;
  this->seccion=seccion;
  this->estado=estado;
  this->estadoIns=estadoIns;
  this->fechaInicio=fechaInicio;
  this->fechaFinal=fechaFinal;
  this->capInsc=capInsc;
  this->totalIns=totalIns;
  this->nombreAsig=nombreAsig;
}

int Clase::obtenerIDClase(){
  return this->IDClase;
}

int Clase::obtenerIDCurso(){
  return this->IDCurso;
}

int Clase::obtenerCcloElect(){
  return this->ccloElect;
}


std::string Clase::obtenerNombre(){
    return this->nombreAsig;
}

int Clase::obtenerTotalIns(){
  return this->totalIns;
}

std::vector<Sesion*> Clase::obtenerSesiones(){
  return this->sesiones;
}

void Clase::insertarSesion(Sesion *sesion){
    this->sesiones.push_back(sesion);
}

void Clase::imprimirSesiones(){
    for(int i=0;i<this->sesiones.size();i++){
       std::cout<<"-"<<this->sesiones[i]->obtenerDia()<<"-"<<this->sesiones[i]->obtenerTipo()<<std::endl;
    }
}

#endif
