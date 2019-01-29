#ifndef __ArbolBinarioOrd__HH__
#define __ArbolBinarioOrd__HH__

using namespace std;
#include "NodoBinario.h"
template<class T>
class ArbolBinarioOrd
{
protected:
    NodoBinario<T> *raiz;

public:
    ArbolBinarioOrd();
    ArbolBinarioOrd(T& val);
    ~ArbolBinarioOrd()= default;
    bool esVacio();
    T& datoRaiz();
    void preOrden(NodoBinario<T> *nodo);
    void inOrden(NodoBinario<T> *nodo);
    void posOrden(NodoBinario<T> *nodo);
    void nivelOrden(NodoBinario<T> *nodo);
    int altura(NodoBinario<T> *nodo);
    int tamano();
    NodoBinario<T>* buscar(NodoBinario<T> *nodo, T& val);
    bool insertar(NodoBinario<T> *nodo, T& val);
    bool eliminar(NodoBinario<T> *padre, NodoBinario<T> *nodo, T& val);
    T& minimo(NodoBinario<T> * nodo);
    T& maximo(NodoBinario<T> * nodo);
    NodoBinario<T> *obtenerRaiz();
    bool balancear(NodoBinario<T> *nodo);
    NodoBinario<T>* rotacionDer(NodoBinario<T>* padre);
    NodoBinario<T>* rotacionIzq(NodoBinario<T>* padre);
};
#include "ArbolBinarioOrd.hxx"
#endif
