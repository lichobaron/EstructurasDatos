#ifndef __NodoAsignatura__HXX__
#define __NodoAsignatura__HXX__

#include "NodoAsignatura.h"

NodoAsignatura::NodoAsignatura(){

}

NodoAsignatura::NodoAsignatura(Asignatura *asignatura){
  this->asignatura= asignatura;
}

int NodoAsignatura::obtenerIDCurso(){
  return this->asignatura->obtenerIDCurso();
}

std::string NodoAsignatura::obtenerNombre(){
  return this->asignatura->obtenerNombre();
}

int NodoAsignatura::obtenerInscritos(){
  return this->inscritos;
}

Asignatura* NodoAsignatura::obtenerAsignatura(){
  return this->asignatura;
}

std::vector<NodoAsignatura*> NodoAsignatura::obtenerHijos(){
  return this->hijos;
}

void NodoAsignatura::agregarHijo(Asignatura* hijo){
  NodoAsignatura *nodo= new NodoAsignatura(hijo);
  this->hijos.push_back(nodo);
}

void NodoAsignatura::agregarHijoAux(NodoAsignatura * nodoAsign){
  this->hijos.push_back(nodoAsign);
}

NodoAsignatura* NodoAsignatura::obtenerNodo(Asignatura* a){
  if(!this->hijos.empty()){
    bool e=false;
    for(int i=0;i<this->hijos.size();i++){
      if(this->hijos[i]->obtenerAsignatura()==a){
        e=true;
        return this->hijos[i];
      }
    }
    if(!e){
      for(int i=0;i<this->hijos.size();i++){
        return this->hijos[i]->obtenerNodo(a);
      }
    }
    else{
      return nullptr;
    }
  }
  return nullptr;
}

bool NodoAsignatura::crearArbol(Asignatura *asignatura, Sistema *sistema, int semestre){
  std::vector<int> inscritos= sistema->obtenerInscritos(asignatura->obtenerIDCurso());
  this->asignatura=asignatura;
  this->inscritos= inscritos[semestre];
  bool retorno= false;
  for(int i=0; i<asignatura->obtenerPrerrequisitos().size();i++){
    Asignatura *aux=asignatura->obtenerPrerrequisitos()[i];
    this->agregarHijo(aux);
    this->hijos[i]->crearArbol(aux, sistema, semestre);
    retorno= true;
  }
  return retorno;
}

#endif
