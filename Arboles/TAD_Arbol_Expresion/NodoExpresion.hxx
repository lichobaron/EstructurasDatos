#ifndef NODO_EXPRESION_HXX
#define NODO_EXPRESION_HXX
#include "NodoExpresion.h"
NodoExpresion::NodoExpresion(){
}

NodoExpresion::NodoExpresion(std::string val){
	this->dato = val ;
}

NodoExpresion::NodoExpresion(std::string val, NodoExpresion *izq, NodoExpresion *der){
	this->dato= val ;
	this->hijoIzq = izq ;
	this->hijoDer = der ;
}
NodoExpresion::~NodoExpresion(){

}
std::string NodoExpresion::obtenerDato(){
	return this->dato ;
}
void NodoExpresion::fijarDato(std::string val) {///Debo verificar si el dato que me llega es un operando o un operador CORREGIRRRRR
	///this->dato=val ;
}
bool NodoExpresion::obtenerOperando(){
	return this->operando ;
}
void NodoExpresion::fijarOperando(bool clase) {
	this->operando = clase ;
}
NodoExpresion* NodoExpresion::obtenerHijoIzq(){
	return this->hijoIzq ;
}

NodoExpresion* NodoExpresion::obtenerHijoDer(){
	return this->hijoDer  ;
}
void NodoExpresion::fijarHijoIzq(NodoExpresion *izq) {
	this->hijoIzq = izq ;
}
void NodoExpresion::fijarHijoDer(NodoExpresion *der) {
	this->hijoDer = der ;
}

bool NodoExpresion::esOperador(std::string dato){
	if(dato=="+"||dato=="-"||dato=="*"||dato=="/"||dato=="%"||dato=="^"||dato==">"||dato=="<"||dato=="<="||dato==">="||dato=="!="||dato=="=="||dato=="!"){
		return true ;
	}else{
		return false ;
	}
}
bool NodoExpresion::llenarDesdePrefija(std::string value){
	if(this->esOperador(this->obtenerDato())){
		if(this->hijoIzq == nullptr){
			this->fijarHijoIzq(new NodoExpresion(value));
			std::cout<<"\n Lo inserte -> "<<this->hijoIzq->obtenerDato()<<" En izq  PADRE "<<this->obtenerDato() ;
			return true ;
		}else{
			if(this->hijoIzq->llenarDesdePrefija(value) == true){
				return true ;
			}else{
				if(this->hijoDer == nullptr){
					this->fijarHijoDer(new NodoExpresion(value)) ;
					std::cout<<"\n Lo inserte -> "<<this->hijoDer->obtenerDato()<<" En der PADRE "<<this->obtenerDato() ;
					return true ;
				}else{
					if(this->hijoDer->llenarDesdePrefija(value) == true){
						return true ;
					}else{
						return false ;
					}
				}
			}
		}
	}else{
		return false ;
	}
}
bool NodoExpresion::llenarDesdePosfija(std::string value){
	if(this->esOperador(this->obtenerDato())){
		if(this->hijoDer == nullptr){
			this->fijarHijoDer(new NodoExpresion(value));
			std::cout<<"\n Lo inserte -> "<<this->hijoDer->obtenerDato()<<" En der PADRE "<<this->obtenerDato() ;
			return true ;
		}else{
			if(this->hijoDer->llenarDesdePosfija(value) == true){
				return true ;
			}else{
				if(this->hijoIzq == nullptr){
					this->fijarHijoIzq(new NodoExpresion(value)) ;
					std::cout<<"\n Lo inserte -> "<<this->hijoIzq->obtenerDato()<<" En izq  PADRE "<<this->obtenerDato() ;
					return true ;
				}else{
					if(this->hijoIzq->llenarDesdePosfija(value) == true){
						return true ;
					}else{
						return false ;
					}
				}
			}
		}
	}else{
		return false ;
	}
}
void NodoExpresion::obtenerPrefija(std::string &value){
	value+= this->obtenerDato() ;
	value+= " " ;
	if(this->obtenerHijoIzq() != nullptr){
		this->obtenerHijoIzq()->obtenerPrefija(value);
	}
	if(this->obtenerHijoDer() != nullptr){
		this->obtenerHijoDer()->obtenerPrefija(value);
	}
}
void NodoExpresion::obtenerPosfija(std::string &value){
	if(this->obtenerHijoIzq() == nullptr){
		value += this->obtenerDato() ;
		value += " " ;
	}else{
		this->obtenerHijoIzq()->obtenerPosfija(value) ;
		if(this->obtenerHijoDer() != nullptr){
			this->obtenerHijoDer()->obtenerPosfija(value);
		}
		value += this->obtenerDato();
		value += " ";
	}
}
void NodoExpresion::obtenerInfija(std::string &value){
	if(this->obtenerHijoIzq() == nullptr){
		value += this->obtenerDato() ;
		value += " ";
	}else{
		value += "( ";
		this->obtenerHijoIzq()->obtenerInfija(value) ;
		value += this->obtenerDato() ;
		value += " ";
		if(this->obtenerHijoDer() != nullptr){
			this->obtenerHijoDer()->obtenerInfija(value);
		}
		value += ") ";
	}
}
int NodoExpresion::evaluar(){
	int res = 0 ;
	int izq = 0 ;
	int der = 0 ;
	if(this->obtenerHijoIzq() != nullptr){
		if(esOperador(this->obtenerHijoIzq()->obtenerDato()) ){
			izq = this->obtenerHijoIzq()->evaluar() ;
		}else{
			izq = atoi(this->obtenerHijoIzq()->obtenerDato().c_str());
		}
	}
	if(this->obtenerHijoDer() != nullptr){
		if(esOperador(this->obtenerHijoDer()->obtenerDato())){
			der = this->obtenerHijoDer()->evaluar() ;
		}else{
			der = atoi(this->obtenerHijoDer()->obtenerDato().c_str()) ;
		}
	}
	if(this->obtenerDato() == "+"){
		res = izq + der ;
	}else{
		if(this->obtenerDato() == "-"){
			res = izq - der ;
		}else{
			if(this->obtenerDato() == "*"){
				res = izq * der ;
			}else{
				if(this->obtenerDato() == "/"){
					res = izq / der ;
				}else{
					if(this->obtenerDato() == "%"){
						res = izq % der ;
					}else{
						if(this->obtenerDato() == "^"){
							res = static_cast<int> (pow ((double)izq ,(double)der) ) ;
						}else{
							if(this->obtenerDato() == ">"){
								if(izq > der){
									res = 1 ;
								}else{
									res = 0 ;
								}
							}else{
								if(this->obtenerDato() == "<"){
									if(izq < der){
										res = 1 ;
									}else{
										res = 0 ;
									}
								}else{
									if(this->obtenerDato() == "=="){
										if(izq == der){
											res = 1 ;
										}else{
											res = 0 ;
										}
									}else{
										if(this->obtenerDato() == ">="){
											if(izq >= der){
												res = 1 ;
											}else{
												res = 0 ;
											}
										}else{
											if(this->obtenerDato() == "<="){
												if(izq <= der){
													res = 1 ;
												}else{
													res = 0 ;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return res ; 
}
#endif
