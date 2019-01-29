#ifndef __NodoBinario__HH__
#define __NodoBinario__HH__

template <class T>
class NodoBinario
{
protected:
    T dato;
    NodoBinario<T> *hijoIzq;
    NodoBinario<T> *hijoDer;
public:
    NodoBinario();
    NodoBinario(T& val);
    NodoBinario(T& val, NodoBinario<T> *izq, NodoBinario<T> *der);
    ~NodoBinario()= default;
    T& obtenerDato();
    void fijarDato(T& val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario<T> *izq);
    void fijarHijoDer(NodoBinario<T> *der);
    bool esHoja();
};
#include "NodoBinario.hxx"
#endif
