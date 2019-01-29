#ifndef ARBOL_EXPRESION_H
#define ARBOL_EXPRESION_H

#include "NodoExpresion.h"
#include <iostream>
#include <vector>
#include <string.h>

class ArbolExpresion{
	protected:
		NodoExpresion *raiz;
	public:
		ArbolExpresion();
		~ArbolExpresion();
		bool esVacio();
		std::string datoRaiz();
		NodoExpresion* obtenerRaiz();
		void fijarRaiz(NodoExpresion* dato) ;
		void llenarDesdePrefija(std::string &expresion);
		void llenarDesdePosfija(std::string &expresion) ;
		std::string obtenerPrefija();
		std::string obtenerInfija();
		std::string obtenerPosfija();
		int evaluar();
		bool esOperador(std::string dato);
};

#include "ArbolExpresion.hxx"
#endif
