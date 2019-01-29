#ifndef __ClaseEst__HXX__
#define __ClaseEst__HXX__

#include "ClaseEst.h"

ClaseEst::ClaseEst(Clase *clase, int calAsig, std::string estadoIns, std::string fechaIns, std::string fechaBaja){
  this->clase=clase;
  this->calAsig=calAsig;
  this->estadoIns=estadoIns;
  this->fechaIns=fechaIns;
  this->fechaBaja=fechaBaja;
}

Clase* ClaseEst::obtenerClase(){
  return this->clase;
}

#endif
