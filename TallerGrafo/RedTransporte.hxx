#ifndef __RedTransporte__HXX__
#define __RedTransporte__HXX__
#include "RedTransporte.h"

RedTransporte::RedTransporte(){}

void RedTransporte::agregarCiudad(std::string ciudad){
  Ciudad* c= this->encontrarCiudad(ciudad);
  if(c==nullptr){
    c= new Ciudad(ciudad);
    this->ciudades.push_back(c);
  }else{
    std::cout<<"La ciudad ya está en el sistema"<<std::endl;
  }
}

Ciudad* RedTransporte::encontrarCiudad(std::string ciudad){
  for(int i=0;i<this->ciudades.size();i++){
    if(this->ciudades[i]->obtenerNombre()==ciudad){
      return this->ciudades[i];
    }
  }
  return nullptr;
}

void RedTransporte::agregarRuta(std::string origen,std::string destino,std::string transporte,int tiempo){
  Ciudad* o= this->encontrarCiudad(origen);
  Ciudad* d= this->encontrarCiudad(destino);
  if(o!=nullptr && d!=nullptr){
    Edge* e=new Edge(tiempo,false,transporte);
    if(transporte=="tren"){
      o->agregarConexionTren(d,e);
      d->agregarConexionTren(o,e);
    }else if(transporte=="avion"){
      o->agregarConexionAvion(d,e);
      d->agregarConexionAvion(o,e);
    }else{
      o->agregarConexionBarco(d,e);
      d->agregarConexionBarco(o,e);
    }
  }else{
    std::cout<<"Las ciudades no están en el sistema"<<std::endl;
  }
}

int RedTransporte::contarSubRedes(std::string transporte){
  int cant=0;
  for(int i=0;i<this->ciudades.size();i++){
    if(transporte=="tren"){
      cant += this->ciudades[i]->cantRedTren();
    }else if(transporte=="avion"){
      cant += this->ciudades[i]->cantRedAvion();
    }else{
      cant += this->ciudades[i]->cantRedBarco();
    }
  }
  return cant/2;
}

void RedTransporte::mejorRuta(std::string origen,std::string destino,std::string criterio){
  //std::vector<Ciudad*> r;
  Ciudad* o= this->encontrarCiudad(origen);
  Ciudad* d= this->encontrarCiudad(destino);
  if(o!=nullptr && d!=nullptr){
    if(criterio=="transbordos"){
      this->dfs(o,d);
    }
    if(criterio=="tiempo"){
      this->dijkstra(o,d);
    }
  }else{
    std::cout<<"Las ciudades no están en el sistema"<<std::endl;
  }
  //return r;
}

void RedTransporte::dijkstra(Ciudad* begin,Ciudad* end){
  this->resetValue();
  std::queue<Ciudad*> queue;
  std::multimap<Ciudad*, Ciudad*> print;
  begin->setValue(0);
  queue.push(begin);
  while(!queue.empty()){
    Ciudad *u=queue.front();
    queue.pop();
    std::multimap<Ciudad*, Edge* > aux=u->obtenerRutas();
    typename std::multimap<Ciudad*, Edge* >::iterator it=aux.begin();
    for(;it!=aux.end();it++){
      if(u->getValue()+ (it->second)->weigth < it->first->getValue()){
        print.insert(std::pair<Ciudad*,Ciudad*>(it->first,u));
        it->first->setValue(u->getValue()+  (it->second)->weigth);
        print.find(it->first)->second=u;
        queue.push(it->first);
      }
    }
  }
  std::stack<Ciudad*> track;
  track.push(end);
  while(track.top()!=begin){
    typename std::multimap<Ciudad *, Ciudad *>::iterator it=print.begin();
    for(;it!=print.end();it++){
      if(it->first==track.top()){
        track.push(it->second);
        break;
      }
    }
  }
  std::cout<<"La ruta más rápida es: "<<std::endl;
  while(!track.empty()){
    std::cout<<"  "<<"Desde "<<track.top()->obtenerNombre()<<" en ";
    std::multimap<Ciudad*, Edge* > aux=track.top()->obtenerRutas();
    track.pop();
    if(!track.empty()){
      typename std::multimap<Ciudad *, Edge *>::iterator it=aux.begin();
      for(;it!=aux.end();it++){
        if(it->first==track.top()){
          std::cout<<(it->second)->transporte<<" hasta "<<track.top()->obtenerNombre()<<std::endl;
          break;
        }
      }
    }
    Ciudad* aux2=track.top();
    track.pop();
    if(track.empty()){
      break;
    }else{
      track.push(aux2);
    }
  }
  this->resetEdgeVisited();
}

void RedTransporte::resetValue(){
  for(int i=0;i<this->ciudades.size();i++){
    this->ciudades[i]->setValue(9999);
  }
}

void RedTransporte::resetEdgeVisited(){
  for(int i=0;i<this->ciudades.size();i++){
    this->ciudades[i]->resetVisited();
  }
}

void RedTransporte::dfs(Ciudad* begin,Ciudad* end){
  std::stack<Ciudad*> ruta;
  std::vector<std::stack<Ciudad*>> v;
  end->setVisited(true);
  std::multimap<Ciudad*, Edge* > aux=end->obtenerRutas();
  typename std::multimap<Ciudad*, Edge* >::iterator it=aux.find(begin);
  if(it!=aux.end()){
    std::cout << "La ruta con menos transbordos es:" << '\n';
    std::cout<<"  "<<"Desde "<<begin->obtenerNombre()<<" en ";
    std::multimap<Ciudad*, Edge* > aux=begin->obtenerRutas();
    typename std::multimap<Ciudad *, Edge *>::iterator it=aux.begin();
    for(;it!=aux.end();it++){
      if(it->first==end){
        std::cout<<(it->second)->transporte<<" hasta "<<end->obtenerNombre()<<std::endl;
        break;
      }
    }
    end->setVisited(false);
  }else{
    typename std::multimap<Ciudad*, Edge* >::iterator it=aux.begin();
    for(;it!=aux.end();it++){
      std::stack<Ciudad*> donde;
      donde.push(end);
      donde.push(it->first);
      v.push_back(this->porAqui(it->first,begin,donde));
    }
    int cant=9999;
    if(v.size()==1){
      ruta=v[0];
    }else{
      for(int i=0;i<v.size();i++){
        if(v[i].size()<cant && v[i].top()==begin){
          cant=v[i].size();
          ruta=v[i];
        }
      }
    }
    std::cout << "La ruta con menos transbordos es:" << '\n';
    while(!ruta.empty()){
      std::cout<<"  "<<"Desde "<<ruta.top()->obtenerNombre()<<" en ";
      std::multimap<Ciudad*, Edge* > aux=ruta.top()->obtenerRutas();
      ruta.pop();
      if(!ruta.empty()){
        typename std::multimap<Ciudad *, Edge *>::iterator it=aux.begin();
        for(;it!=aux.end();it++){
          if(it->first==ruta.top()){
            std::cout<<(it->second)->transporte<<" hasta "<<ruta.top()->obtenerNombre()<<std::endl;
            break;
          }
        }
      }
      Ciudad* aux2=ruta.top();
      ruta.pop();
      if(ruta.empty()){
        break;
      }else{
        ruta.push(aux2);
      }
    }
  }
}

std::stack<Ciudad*> RedTransporte::porAqui(Ciudad* c,Ciudad* d,std::stack<Ciudad*> & ruta){
  c->setVisited(true);
  std::stack<Ciudad*> s;
  std::multimap<Ciudad*, Edge* > aux=c->obtenerRutas();
  if(aux.size()!=0){
    typename std::multimap<Ciudad*, Edge* >::iterator it=aux.begin();
    for(;it!=aux.end();it++){
      if(!it->first->getVisited()){
        ruta.push(it->first);
        if(it->first==d){
          return ruta;
        }else{
          s=porAqui(it->first,d,ruta);
          it->first->setVisited(false);
        }
      }
    }
    c->setVisited(false);
    return ruta;
  }
  if(ruta.top()->getVisited()){
    ruta.top()->setVisited(false);
    ruta.pop();
    return ruta;
  }
  ruta.top()->setVisited(false);
  ruta.pop();
  return ruta;
}

#endif
