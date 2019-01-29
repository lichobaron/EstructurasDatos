#ifndef __Graph__HXX__
#define __Graph__HXX__

#include "Graph.h"

template<class T>
void Graph<T>::addVertex(T data){
  this->vertexs.insert(new Vertex<T>(data));
}

template<class T>
void Graph<T>::addEdge(T data1, T data2, int weight){
  Vertex<T> *v1= this->searchVertex(data1);
  Vertex<T> *v2= this->searchVertex(data2);
  typename std::set<Vertex<T> *>::iterator it = this->vertexs.find(v1);
  if(it!=this->vertexs.end()){
    it = this->vertexs.find(v2);
    if(it!=this->vertexs.end()){
      v1->addAdyacent(v2, weight);
      v2->addAdyacent(v1, weight);
    }
  }
}

template<class T>
void Graph<T>::eraseEdge(T data1, T data2){
  Vertex<T> * v1= this->searchVertex(data1);
  Vertex<T> * v2= this->searchVertex(data2);
  if(v1!=nullptr&&v2!=nullptr){
    v1->eraseEdge(v2);
  }
}

template<class T>
void Graph<T>::eraseVertex(T data){
  Vertex<T>* v= this->searchVertex(data);
  if(v!=nullptr){
    typename std::set<Vertex<T> *>::iterator it = this->vertexs.find(v);
    typename std::set<Vertex<T> *>::iterator it2;
    if(it2!=this->vertexs.end()){
      for(it2=this->vertexs.begin();it2!=this->vertexs.end();it2++){
        (*it2)->eraseEdge(v);
      }
      this->vertexs.erase(it);
    }
  }
}

template<class T>
Vertex<T>* Graph<T>::searchVertex(T data){
  typename std::set<Vertex<T> *>::iterator it = this->vertexs.begin();
  for(;it!=this->vertexs.end();it++){
    if((*it)->getData()==data){
      return *it;
    }
  }
  return nullptr;
}

template<class T>
void Graph<T>::flatTrack(){
  typename std::set<Vertex<T> *>::iterator it = this->vertexs.begin();
  for(;it!=this->vertexs.end();it++){
    std::cout<<(*it)->getData()<<", ";
  }
  std::cout<<std::endl;
}

template<class T>
void Graph<T>::resetVisited(){
  typename std::set<Vertex<T> *>::iterator it = this->vertexs.begin();
  for(;it!=this->vertexs.end();it++){
    (*it)->setVisited(false);
  }
}

template<class T>
void Graph<T>::resetValue(){
  typename std::set<Vertex<T> *>::iterator it = this->vertexs.begin();
  for(;it!=this->vertexs.end();it++){
    (*it)->setValue(9999);
  }
}

template<class T>
void Graph<T>::depthFirstSearch(T begin){
  Vertex<T> *v= this->searchVertex(begin);
  if(v!=nullptr){
    std::cout<<v->getData()<<", ";
    v->setVisited(true);
    std::map<Vertex<T> *, int> aux=v->getAdy();
    typename std::map<Vertex<T> *, int>::iterator it=aux.begin();
    for(;it!=aux.end();it++){
      if(it->first->getVisited()==false){
        depthFirstSearch(it->first->getData());
      }
    }
  }
}

template<class T>
void Graph<T>::breadthFirstSearch(T begin){
  Vertex<T> *v= this->searchVertex(begin);
  if(v!=nullptr){
    std::queue<Vertex<T>*> track;
    track.push(v);
    while(!track.empty()){
      if(track.front()->getVisited()==false){
        track.front()->setVisited(true);
        std::map<Vertex<T> *, int> aux=track.front()->getAdy();
        typename std::map<Vertex<T> *, int>::iterator it=aux.begin();
        for(;it!=aux.end();it++){
          if(it->first->getVisited()==false){
            track.push(it->first);
          }
        }
        std::cout<<track.front()->getData()<<", ";
      }
      track.pop();
    }
  }
}

template <class T>
std::stack<T> Graph<T>::dijkstra(T begin, T end){
  this->resetValue();
  std::priority_queue<Vertex<T>*, std::vector<Vertex<T>*>, VertComparator<T>> queue;
  std::map<Vertex<T>*, Vertex<T>*> print;
  Vertex<T> *v= this->searchVertex(begin);
  v->setValue(0);
  queue.push(v);
  while(!queue.empty()){
    Vertex<T> *u=queue.top();
    queue.pop();
    std::map<Vertex<T> *, int> aux=u->getAdy();
    typename std::map<Vertex<T> *, int>::iterator it=aux.begin();
    for(;it!=aux.end();it++){
      if(u->getValue()+it->second<it->first->getValue()){
        print.insert(std::pair<Vertex<T>*,Vertex<T>*>(it->first,u));
        it->first->setValue(u->getValue()+it->second);
        print.find(it->first)->second=u;
        queue.push(it->first);
      }
    }
  }
  std::stack<T> track;
  track.push(end);
  if(this->searchVertex(end)->getValue()!=9999){
    while(track.top()!=begin){
      typename std::map<Vertex<T> *, Vertex<T> *>::iterator it=print.begin();
      for(;it!=print.end();it++){
        if(it->first->getData()==track.top()){
          track.push(it->second->getData());
          break;
        }
      }
    }
  }
  /*
  while(!track.empty()){
    std::cout<<track.top()<<", ";
    track.pop();
  }
  std::cout<<std::endl;
  */
  return track;
}

#endif
