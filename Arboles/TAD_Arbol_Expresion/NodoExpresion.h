#ifndef NODO_EXPRESION_H
#define NODO_EXPRESION_H

#include <iostream>
#include <math.h>

class NodoExpresion {
	protected:
		std::string dato ;
		bool operando ;
		NodoExpresion *hijoIzq ;
		NodoExpresion *hijoDer ;

	public:
		NodoExpresion();
		NodoExpresion(std::string val);
		NodoExpresion(std::string val, NodoExpresion *izq, NodoExpresion *der);
		~NodoExpresion();
		bool llenarDesdePrefija(std::string value);
		bool llenarDesdePosfija(std::string value);
		void obtenerPrefija(std::string &value);
		void obtenerPosfija(std::string &value);
		void obtenerInfija(std::string &value);
		int evaluar();
		std::string obtenerDato();
		void fijarDato(std::string val) ;
		bool obtenerOperando();
		void fijarOperando(bool clase) ;
		NodoExpresion* obtenerHijoIzq();
		NodoExpresion* obtenerHijoDer();
		void fijarHijoIzq(NodoExpresion *izq) ;
		void fijarHijoDer(NodoExpresion *der) ;
		bool esOperador(std::string dato);

};
#include "NodoExpresion.hxx"
#endif
