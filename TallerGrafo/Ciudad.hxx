#ifndef __Ciudad__HXX__
#define __Ciudad__HXX__
#include "Ciudad.h"

Ciudad::Ciudad(std::string nombre){
  this->nombre=nombre;
  this->visited=false;
}

std::string Ciudad::obtenerNombre(){
  return this->nombre;
}

void Ciudad::agregarConexionTren(Ciudad* destino,Edge* ed){
  this->tren.insert(std::pair<Ciudad*,Edge*>(destino,ed));
}

int Ciudad::cantRedTren(){
  return this->tren.size();
}

void Ciudad::agregarConexionAvion(Ciudad* destino,Edge* ed){
  this->avion.insert(std::pair<Ciudad*,Edge*>(destino,ed));
}

int Ciudad::cantRedAvion(){
  return this->avion.size();
}

void Ciudad::agregarConexionBarco(Ciudad* destino,Edge* ed){
  this->barco.insert(std::pair<Ciudad*,Edge*>(destino,ed));
}

int Ciudad::cantRedBarco(){
  return this->barco.size();
}

void Ciudad::setValue(int value){
  this->value=value;
}

int Ciudad::getValue(){
  return this->value;
}

std::multimap<Ciudad*, Edge*> Ciudad::obtenerRutas(){
  std::multimap<Ciudad*, Edge*> r;
  std::map<Ciudad*,Edge*>::iterator it;
  for(it=this->tren.begin();it!=this->tren.end();it++){
    r.insert(std::pair<Ciudad*,Edge*>(it->first,it->second));
  }
  for(it=this->avion.begin();it!=this->avion.end();it++){
    r.insert(std::pair<Ciudad*,Edge*>(it->first,it->second));
  }
  for(it=this->barco.begin();it!=this->barco.end();it++){
    r.insert(std::pair<Ciudad*,Edge*>(it->first,it->second));
  }
  return r;
}

void Ciudad::resetVisited(){
  std::map<Ciudad* ,Edge*>::iterator it ;
  for(it=this->tren.begin();it!=this->tren.end();it++){
    (it->second)->visited = false ;
  }
  for(it=this->avion.begin();it!=this->avion.end();it++){
    (it->second)->visited = false ;
  }
  for(it=this->barco.begin();it!=this->barco.end();it++){
    (it->second)->visited = false ;
  }
}

bool Ciudad::getVisited(){
  return this->visited;
}

void Ciudad::setVisited(bool v){
  this->visited=v;
}

#endif
