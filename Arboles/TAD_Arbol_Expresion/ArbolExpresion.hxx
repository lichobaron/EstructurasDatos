#ifndef ARBOL_EXPRESION_HXX
#define ARBOL_EXPRESION_HXX

#include "ArbolExpresion.h"

ArbolExpresion::ArbolExpresion(){
}
ArbolExpresion::~ArbolExpresion(){
}
bool ArbolExpresion::esVacio(){
	if(this->raiz==nullptr)
	return true ;
	return false ;
}
std::string ArbolExpresion::datoRaiz(){
	return (this->raiz)->obtenerDato();
}
NodoExpresion* ArbolExpresion::obtenerRaiz(){
	return this->raiz ;
}
void ArbolExpresion::fijarRaiz(NodoExpresion* dato){
	this->raiz = dato ;
}
void ArbolExpresion::llenarDesdePrefija(std::string &expresion){

	bool esraiz = false ;
	bool raiznumber = false ;
	bool ciclo = true ;
	std::string subs ;
	while (expresion.find(" ", 0) != std::string::npos && ciclo){
		size_t  pos = expresion.find(" ", 0);
		subs = expresion.substr(0, pos);
		expresion.erase(0, pos + 1);
		if(!esraiz){
			this->fijarRaiz(new NodoExpresion(subs)) ;
			if(!esOperador(subs)){
				raiznumber = true ;
				ciclo = false ;
			}
		}else{
			if(!raiznumber){
				this->raiz->llenarDesdePrefija(subs);
			}
		}
		esraiz = true ;
	}
	if(esraiz){
		if(!raiznumber){
			if (expresion.size() > 0 )
			{
				this->raiz->llenarDesdePrefija(expresion);
			}
		}
	}
}
void ArbolExpresion::llenarDesdePosfija(std::string &expresion){
	bool esraiz = false ;
	bool raiznumber = false ;
	bool ciclo = true ;
	std::string subs ;
	std::vector<std::string>operadores ;
	while (expresion.find(" ", 0) != std::string::npos && ciclo){
		size_t  pos = expresion.find(" ", 0);
		subs = expresion.substr(0, pos);
		expresion.erase(0, pos + 1);
		operadores.push_back(subs) ;
	}
	if (expresion.size() > 0 )
	{
		operadores.push_back(expresion);
	}
	/*/*/
	for(std::vector<std::string>::reverse_iterator it = operadores.rbegin() ; it != operadores.rend() ;++it){
		if(!esraiz){
			this->fijarRaiz(new NodoExpresion(*it)) ;
			if(!esOperador(*it)){
				raiznumber = true ;
				ciclo = false ;
			}
		}else{
			if(!raiznumber){
				this->raiz->llenarDesdePosfija(*it);
			}
		}
		esraiz = true ;
	}

}
std::string ArbolExpresion::obtenerPrefija(){
	std::string temp = "";
	this->raiz->obtenerPrefija(temp);
	return temp ;
}
std::string ArbolExpresion::obtenerInfija(){
	std::string temp = "";
	this->raiz->obtenerInfija(temp);
	return temp ;
}
std::string ArbolExpresion::obtenerPosfija(){
	std::string temp = "";
	this->raiz->obtenerPosfija(temp);
	return temp ;
}
int ArbolExpresion::evaluar(){
	return this->raiz->evaluar() ;
}
bool ArbolExpresion::esOperador(std::string dato){
	if(dato=="+"||dato=="-"||dato=="*"||dato=="/"||dato=="%"||dato=="^"||dato==">"||dato=="<"||dato=="<="||dato==">="||dato=="!="||dato=="=="||dato=="!"){
		return true ;
	}else{
		return false ;
	}
}
#endif
