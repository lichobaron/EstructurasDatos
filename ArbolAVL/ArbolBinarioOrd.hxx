#ifndef __ArbolBinarioOrd__HXX__
#define __ArbolBinarioOrd__HXX__
#include "ArbolBinarioOrd.h"
#include <queue>

using namespace std;

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd()
{
    this->raiz=nullptr;
}

template <class T>
ArbolBinarioOrd<T>:: ArbolBinarioOrd(T& val)
{
    this->raiz->fijarDato(val);
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio()
{
    if(this->raiz== nullptr)
    {
        return true;
    }
    return false;
}

template <class T>
NodoBinario<T> *ArbolBinarioOrd<T>::obtenerRaiz()
{
    return this->raiz;
}

template <class T>
T& ArbolBinarioOrd<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}

template <class T>
void ArbolBinarioOrd<T>::preOrden(NodoBinario<T> *nodo)
{
    cout<<nodo->obtenerDato()<<",";
    if(nodo->obtenerHijoIzq()!=nullptr)
    {
        this->preOrden(nodo->obtenerHijoIzq());
    }
    if(nodo->obtenerHijoDer()!=nullptr)
    {
        this->preOrden(nodo->obtenerHijoDer());
    }
}

template <class T>
void ArbolBinarioOrd<T>::inOrden(NodoBinario<T> *nodo)
{
    if(nodo->obtenerHijoIzq()!=nullptr)
    {
        this->inOrden(nodo->obtenerHijoIzq());
    }
    cout<<nodo->obtenerDato()<<",";
    if(nodo->obtenerHijoDer()!=nullptr)
    {
        this->inOrden(nodo->obtenerHijoDer());
    }
}

template <class T>
void ArbolBinarioOrd<T>::posOrden(NodoBinario<T> *nodo)
{
    if(nodo->obtenerHijoIzq()!=nullptr)
    {
        this->posOrden(nodo->obtenerHijoIzq());
    }
    if(nodo->obtenerHijoDer()!=nullptr)
    {
        this->posOrden(nodo->obtenerHijoDer());
    }
    cout<<nodo->obtenerDato()<<",";
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden(NodoBinario<T> *nodo)
{
  queue<NodoBinario<T>*> cola;
  NodoBinario<T> *aux= nodo;
  cola.push(nodo);
  while(!cola.empty()){
    if(cola.front()->obtenerHijoIzq()!=nullptr){
      aux= cola.front()->obtenerHijoIzq();
      cola.push(aux);
    }
    if(cola.front()->obtenerHijoDer()!=nullptr){
      aux= cola.front()->obtenerHijoDer();
      cola.push(aux);
    }
    cout<<cola.front()->obtenerDato()<<",";
    cola.pop();
  }

}

template <class T>
int ArbolBinarioOrd<T>::altura(NodoBinario<T> *nodo)
{
  int h1=0, h2=0;
  if(nodo==nullptr){
    return -1;
  }
  if(nodo->obtenerHijoIzq()!=nullptr){
    h1= 1+ altura(nodo->obtenerHijoIzq());
  }
  if(nodo->obtenerHijoDer()!=nullptr){
    h2= 1+ altura(nodo->obtenerHijoDer());
  }
  if(h1>h2){
    return h1;
  }
  else{
    return h2;
  }

}

template <class T>
int ArbolBinarioOrd<T>::tamano()
{

}

template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::buscar(NodoBinario<T> *nodo, T& val){
  if(nodo->obtenerDato()==val){
    return nodo;
  }
  if(val<nodo->obtenerDato()){
    return buscar(nodo->obtenerHijoIzq(), val);
  }
  if(val>nodo->obtenerDato()){
    return buscar(nodo->obtenerHijoDer(), val);
  }
  return nullptr;
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(NodoBinario<T> *nodo, T& val)
{
    if(!this->esVacio())
    {
        if(val!= nodo->obtenerDato())
        {
            if(nodo->obtenerHijoIzq()==nullptr||nodo->obtenerHijoDer()==nullptr)
            {
                if(val>nodo->obtenerDato())
                {
                    if(nodo->obtenerHijoDer()==nullptr)
                    {
                        nodo->fijarHijoDer(new NodoBinario<T>(val));
                        return true;
                    }
                    else
                    {
                        insertar(nodo->obtenerHijoDer(),val);
                    }
                }
                else
                {
                    if(nodo->obtenerHijoIzq()==nullptr)
                    {
                        nodo->fijarHijoIzq(new NodoBinario<T>(val));
                        return true;
                    }
                    else
                    {
                        insertar(nodo->obtenerHijoIzq(),val);
                    }
                }
            }
            else
            {
                if(val>nodo->obtenerDato())
                {
                    insertar(nodo->obtenerHijoDer(),val);
                }
                else
                {
                    insertar(nodo->obtenerHijoIzq(),val);
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        this->raiz= new NodoBinario<T>(val);
        return true;
    }
    this->balancear(this->raiz);
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(NodoBinario<T> *padre, NodoBinario<T> *nodo, T& val){
  if(nodo->obtenerDato()==val){
    if(nodo->obtenerHijoIzq()==nullptr && nodo->obtenerHijoDer()==nullptr){
      if(padre!=nullptr){
        if(padre->obtenerHijoIzq()->obtenerDato()==val){
          padre->fijarHijoIzq(nullptr);
        }
        if(padre->obtenerHijoDer()->obtenerDato()==val){
          padre->fijarHijoDer(nullptr);
        }
      }
      delete(nodo);
    }
    if(nodo->obtenerHijoIzq()!=nullptr && nodo->obtenerHijoDer()!=nullptr){
      if(padre!=nullptr){
        nodo->fijarDato(maximo(nodo->obtenerHijoIzq()));
      }
      delete(this->buscar(nodo->obtenerHijoIzq(),nodo->obtenerDato()));
    }
    if(nodo->obtenerHijoIzq()!=nullptr && nodo->obtenerHijoDer()==nullptr){
      if(padre!=nullptr){
        if(padre->obtenerHijoIzq()->obtenerDato()==val){
          padre->fijarHijoIzq(nodo->obtenerHijoIzq());
        }
        if(padre->obtenerHijoDer()->obtenerDato()==val){
          padre->fijarHijoDer(nodo->obtenerHijoIzq());
        }
      }
      delete(nodo);
    }
    if(nodo->obtenerHijoIzq()==nullptr && nodo->obtenerHijoDer()!=nullptr){
      if(padre!=nullptr){
        if(padre->obtenerHijoIzq()->obtenerDato()==val){
          padre->fijarHijoIzq(nodo->obtenerHijoDer());
        }
        if(padre->obtenerHijoDer()->obtenerDato()==val){
          padre->fijarHijoDer(nodo->obtenerHijoDer());
        }
      }
      delete(nodo);
    }
  }
  if(val<nodo->obtenerDato()){
    eliminar(nodo, nodo->obtenerHijoIzq(),val);
  }
  if(val>nodo->obtenerDato()){
    eliminar(nodo, nodo->obtenerHijoDer(),val);
  }
  this->balancear(this->raiz);
}

template <class T>
T& ArbolBinarioOrd<T>::minimo(NodoBinario<T> * nodo){
  if(nodo->obtenerHijoIzq()!=nullptr)
  {
      return minimo(nodo->obtenerHijoIzq());
  }
  return nodo->obtenerDato();
}

template <class T>
T& ArbolBinarioOrd<T>::maximo(NodoBinario<T> * nodo){
  if(nodo->obtenerHijoDer()!=nullptr)
  {
      return maximo(nodo->obtenerHijoDer());
  }
  return nodo->obtenerDato();
}

template <class T>
bool ArbolBinarioOrd<T>::balancear(NodoBinario<T> *nodo){
  int diferencia= altura(nodo->obtenerHijoIzq()) - altura(nodo->obtenerHijoDer());
  if(diferencia==2){
    int d1=altura(nodo->obtenerHijoIzq()->obtenerHijoIzq()) - altura(nodo->obtenerHijoIzq()->obtenerHijoDer());
    if(d1>0){
      nodo= this->rotacionDer(nodo);
    }
    if(d1<0){
      NodoBinario<T> *aux= this->rotacionIzq(nodo->obtenerHijoIzq());
      nodo->fijarHijoIzq(aux);
      nodo= this->rotacionDer(nodo);
    }
  }
  if(diferencia==-2){
    int d2=altura(nodo->obtenerHijoDer()->obtenerHijoIzq())- altura(nodo->obtenerHijoDer()->obtenerHijoDer());
    if(d2>0){
      NodoBinario<T> *aux= this->rotacionDer(nodo->obtenerHijoDer());
      nodo->fijarHijoDer(aux);
      nodo= this->rotacionIzq(nodo);
    }
    if(d2<0){
      nodo= this->rotacionIzq(nodo);
    }
  }
}

template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::rotacionDer(NodoBinario<T>* padre){
  NodoBinario<T>* npadre= padre->obtenerHijoIzq();
  padre->fijarHijoIzq(npadre->obtenerHijoDer());
  npadre->fijarHijoDer(padre);
  return npadre;
}

template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::rotacionIzq(NodoBinario<T>* padre){
  NodoBinario<T>* npadre= padre->obtenerHijoDer();
  padre->fijarHijoDer(npadre->obtenerHijoIzq());
  npadre->fijarHijoIzq(padre);
  return npadre;
}

#endif
