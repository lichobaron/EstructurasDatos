#ifndef __Vertex__HXX__
#define __Vertex__HXX__

#include "Vertex.h"

template<class T>
bool operator == (const Vertex<T> &v1, const Vertex<T> &v2){
  return v1.data==v2.data;
}

template<class T>
bool operator != (const Vertex<T> &v1, const Vertex<T> &v2){
  return v1.data!=v2.data;
}

template<class T>
bool operator <= (const Vertex<T> &v1, const Vertex<T> &v2){
  return v1.data<=v2.data;
}

template<class T>
bool operator >= (const Vertex<T> &v1, const Vertex<T> &v2){
  return v1.data>=v2.data;
}

template<class T>
bool operator < (const Vertex<T> &v1, const Vertex<T> &v2){
  return v1.data<v2.data;
}

template<class T>
bool operator > (const Vertex<T> &v1, const Vertex<T> &v2){
  return v1.data>v2.data;
}

template<class T>
std::ostream& operator <<(std::ostream &o, const Vertex<T> &v1){
  o<<v1.data;
  return o;
}

template<class T>
Vertex<T>::Vertex(T data){
  this->data=data;
}

template<class T>
T Vertex<T>::getData() const{
  return this->data;
}

template<class T>
bool Vertex<T>::getVisited(){
  return this->visited;
}

template<class T>
int Vertex<T>::getValue(){
  return this->value;
}

template<class T>
void Vertex<T>::setValue(int value){
  this->value= value;
}

template<class T>
void Vertex<T>::setVisited(bool visited){
  this->visited=visited;
}

template<class T>
std::map<Vertex<T>*, int> Vertex<T>::getAdy(){
  return this->ady;
}

template<class T>
void Vertex<T>::addAdyacent(Vertex<T> *v, int weight){
  this->ady.insert(std::pair<Vertex<T>*,int>(v,weight));
}

template<class T>
void Vertex<T>::eraseEdge(Vertex<T> *v){
  typename std::map<Vertex<T> *, int>::iterator it = this->ady.find(v);
  if(it!= this->ady.end()){
    this->ady.erase(it);
  }
}

template<class T>
int Vertex<T>::getDist(Vertex<T> *t){
  return this->ady.find(t)->second;
}

template<class T>
bool Vertex<T>::allAdy(){
  bool x=true;
  typename std::map<Vertex<T> *, int>::iterator it=this->ady.begin();
  for(;it!=this->ady.end();it++){
    if(it->first->getVisited()==false){
      x=false;
    }
  }
  return x;
}

#endif
