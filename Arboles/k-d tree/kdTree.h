#ifndef __kdTree__HH__
#define __kdTree__HH__

#include "NodoKdTree.h"
class kdTree
{
protected:
    NodoKdTree *raiz;

public:
    kdTree();
    void preOrden(NodoKdTree *nodo);
    void inOrden(NodoKdTree *nodo);
    void posOrden(NodoKdTree *nodo);
    void nivelOrden(NodoKdTree *nodo);
    int altura(NodoKdTree *nodo);
    int tamano();
    NodoKdTree* buscar(NodoKdTree *nodo, coor val);
    bool insertar(NodoKdTree *nodo, coor val);
    bool eliminar(NodoKdTree *padre, NodoKdTree *nodo, coor val);
};
#include "kdTree.hxx"
#endif
