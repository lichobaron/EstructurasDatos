#ifndef __NodoKdTree__HH__
#define __NodoKdTree__HH__
struct coor
{
  int x,y;
};
class NodoKdTree
{
protected:
    coor coordenada;
    NodoKdTree *hijoIzq;
    NodoKdTree *hijoDer;
public:

    NodoKdTree();
    NodoKdTree(coor val);
    NodoKdTree(coor val, NodoKdTree *izq, NodoKdTree *der);
    ~NodoKdTree()= default;
    coor obtenerDato();
    void fijarDato(coor val);
    NodoKdTree* obtenerHijoIzq();
    NodoKdTree* obtenerHijoDer();
    void fijarHijoIzq(NodoKdTree *izq);
    void fijarHijoDer(NodoKdTree *der);
};
#include "NodoKdTree.hxx"
#endif
