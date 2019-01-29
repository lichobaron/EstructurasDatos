#ifndef __ArbolAsignatura__HXX__
#define __ArbolAsignatura__HXX__

#include "ArbolAsignatura.h"


ArbolAsignatura::ArbolAsignatura(){
this->raiz=nullptr;
}

ArbolAsignatura::ArbolAsignatura(NodoAsignatura *r){
  this->raiz=r;
}

NodoAsignatura* ArbolAsignatura::obtenerRaiz(){
  return this->raiz;
}

bool ArbolAsignatura::llenarArbol(Asignatura* asignatura, Sistema *sistema, int it){
 this->raiz= new NodoAsignatura();
 return this->raiz->crearArbol(asignatura, sistema, it);
}

void ArbolAsignatura::imprimirArbol(NodoAsignatura *raiz){
  std::cout<<raiz->obtenerNombre()<<" Inscritos: "<<raiz->obtenerInscritos()<<std::endl;
  for(int i=0; i<raiz->obtenerHijos().size();i++){
    this->imprimirArbol(raiz->obtenerHijos()[i]);
  }
}

bool buscarRepetido(std::vector<NodoAsignatura*> repetidos, int IDCurso){
  for(int i=0;i<repetidos.size();i++){
    if(repetidos[i]->obtenerIDCurso()==IDCurso){
      return true;
    }
  }
  return false;
}

bool ArbolAsignatura::calcularDemanda(Semestre *semestre){
  std::queue<NodoAsignatura *> aux;
  std::vector<NodoAsignatura *> nodos;
  std::vector<NodoAsignatura *> repetidos;
  if(this->raiz->obtenerAsignatura()!=nullptr){
    aux.push(this->raiz);
    aux.push(new NodoAsignatura(nullptr));
    while(!aux.empty()){
      for(int i=0;i<aux.front()->obtenerHijos().size();i++){
        aux.push(aux.front()->obtenerHijos()[i]);
        if(i==aux.front()->obtenerHijos().size()-1){
          aux.push(new NodoAsignatura(nullptr));
        }
      }
      nodos.push_back(aux.front());
      aux.pop();
    }
  }
  else{
    //std::cout<<"La informacion necesaria no ha sido cargada completamente."<<std::cout<<std::endl;
    return false;
  }
  int suma= 0;
  bool x= false;
  int sem= semestre->obtenerCcloElect();
  for(int i=2;i<nodos.size()-1;i++){
    if(nodos[i]->obtenerAsignatura()!=nullptr){
      if(buscarRepetido(repetidos,nodos[i]->obtenerIDCurso())==false){
        suma=suma+nodos[i]->obtenerInscritos();
        repetidos.push_back(nodos[i]);
      }
    }
    else{
      x=true;
      if(sem%100==10){
          sem=sem+20;
          std::cout<<"    Estudiantes en el semestre "<<sem<<": "<<suma<<std::endl;
      }else if(sem%100==30){
          sem=sem+80;
          std::cout<<"    Estudiantes en el semestre "<<sem<<": "<<suma<<std::endl;
      }
      suma=0;
    }
  }
  if(!x){
    for(int i=2;i<nodos.size();i++){
      if(nodos[i]->obtenerAsignatura()!=nullptr){
        if(buscarRepetido(repetidos,nodos[i]->obtenerIDCurso())==false){
          suma=suma+nodos[i]->obtenerInscritos();
          repetidos.push_back(nodos[i]);
        }
      }
      else{
        if(sem%100==10){
            sem=sem+20;
            std::cout<<"    Estudiantes en el semestre "<<sem<<": "<<suma<<std::endl;
        }else if(sem%100==30){
            sem=sem+80;
            std::cout<<"    Estudiantes en el semestre "<<sem<<": "<<suma<<std::endl;
        }
        suma=0;
      }
    }
  }
  return true;
}

void ArbolAsignatura::nivelOrden(int sem){
  std::queue<NodoAsignatura*> aux;
  aux.push(this->raiz);
  std::vector<NodoAsignatura*> aux2;
  bool y=true;
  while(!aux.empty() ){
    bool x=false;
    for(int i=0;i<aux2.size();i++){
      if(aux.front()->obtenerAsignatura()!=nullptr){
        if(aux.front()->obtenerNombre()==aux2[i]->obtenerNombre()){
          x=true;
        }
      }
    }
    if(!x){
      if(!aux.front()->obtenerHijos().empty()){
        if(aux.front()->obtenerHijos().size()<=3){
          for(int i=0;i<aux.front()->obtenerHijos().size();i++){
            aux.push(aux.front()->obtenerHijos()[i]);
            if(i==aux.front()->obtenerHijos().size()-1){
              aux.push(new NodoAsignatura(nullptr));
            }
          }
        }else{
          for(int i=0;i<4;i++){
            aux.push(aux.front()->obtenerHijos()[i]);
          }
          aux.push(new NodoAsignatura(nullptr));
          for(int i=4;i<aux.front()->obtenerHijos().size();i++){
            aux.push(aux.front()->obtenerHijos()[i]);
            if(i==aux.front()->obtenerHijos().size()-1){
              aux.push(new NodoAsignatura(nullptr));
            }
          }
        }
      }
      if(aux.front()==this->raiz || (aux.front()->obtenerAsignatura()==nullptr && aux.size()>1)){
        aux.pop();
        if(y){
          if(sem%100==10){
            sem=sem+20;
            std::cout<<"    Posibles materias para el semestre "<<sem<<" : "<<std::endl;
          }else if(sem%100==30){
            sem=sem+80;
            std::cout<<"    Posibles materias para el semestre "<<sem<<" : "<<std::endl;
          }
          y=false;
        }
      }else{
        if(aux.size()>1){
          aux2.push_back(aux.front());
          std::cout<<"      "<<aux.front()->obtenerNombre()<<std::endl;
          y=true;
        }
        aux.pop();
      }
    }else{
      aux.pop();
    }
  }
}

bool ArbolAsignatura::nodoRepetido(NodoAsignatura * nodo){
  if(!this->raiz->obtenerHijos().empty()){
    std::queue<NodoAsignatura*> q;
    for(int i=0;i<this->raiz->obtenerHijos().size();i++){
      q.push(this->raiz->obtenerHijos()[i]);
    }
    while(!q.empty()){
      if(!q.front()->obtenerHijos().empty()){
        for(int i=0;i<q.front()->obtenerHijos().size();i++){
          q.push(q.front()->obtenerHijos()[i]);
        }
      }
      if(q.front()->obtenerNombre()==nodo->obtenerNombre()){
        return true;
      }
      q.pop();
    }
  }
  return false;
}

void ArbolAsignatura::agregarHijo(NodoAsignatura * asig){
  this->raiz->agregarHijoAux(asig);
}

void ArbolAsignatura::arbolIndividual(Sistema *sistema,std::vector<Asignatura*> v,Asignatura * a){
  this->raiz= new NodoAsignatura(a);
  for(int i=0;i<sistema->obtenerSemestres().size();i++){
    Semestre *d=sistema->obtenerSemestres()[i];
    for(int j=0;j<d->obtenerAsignaturas().size();j++){
      Asignatura *b=d->obtenerAsignaturas()[j];
      bool e=false;
      for(int k=0;k<b->obtenerPrerrequisitos().size();k++){
        if(a==b->obtenerPrerrequisitos()[k]){
          e=true;
        }
      }
      bool agrego=false;
      std::queue<Asignatura*> q2;
      if(e){
        for(int k=0;k<b->obtenerPrerrequisitos().size();k++){
          bool esta=false;
          for(int l=0;l<v.size();l++){
            if(v[l]==b->obtenerPrerrequisitos()[k]){
              esta=true;
              continue;
            }
          }
          if(!esta){
            std::vector<Asignatura*> prede;
            for(int m=0;m<d->obtenerAsignaturas().size();m++){
              Asignatura *b2=d->obtenerAsignaturas()[m];
              for(int l=0;l<b2->obtenerPrerrequisitos().size();l++){
                if(b2->obtenerPrerrequisitos()[l]==b->obtenerPrerrequisitos()[k]){
                  prede.push_back(b2);
                  break;
                }
              }
            }
            if(prede.size()==1){
              this->agregarHijo(new NodoAsignatura(b->obtenerPrerrequisitos()[k]));
              q2.push(b->obtenerPrerrequisitos()[k]);
            }
            else{
              ArbolAsignatura* aux= arbolFut(d,v,b->obtenerPrerrequisitos()[k],prede);
              this->agregarHijo(aux->obtenerRaiz());
              q2.push(aux->obtenerRaiz()->obtenerAsignatura());
            }
            agrego=true;
          }
        }
      }
      if(!agrego && e){
        this->agregarHijo(new NodoAsignatura(b));
      }
      else{
        if(agrego && e){
          while(!q2.empty()){
            NodoAsignatura* n=this->obtenerNodo(q2.front());
            n->agregarHijo(b);
            q2.pop();
          }
        }
      }
    }
  }
}

ArbolAsignatura * ArbolAsignatura::arbolFut(Semestre* sem, std::vector<Asignatura*> &v,Asignatura * a,std::vector<Asignatura*> fut){
  ArbolAsignatura *r=new ArbolAsignatura(new NodoAsignatura(a));
  v.push_back(a);
  std::queue<Asignatura*> q;
  q.push(a);
  while(!q.empty()){
    bool e=false;
    Asignatura *a2;
    for(int i=0;i<sem->obtenerAsignaturas().size();i++){
      a2=sem->obtenerAsignaturas()[i];
      for(int j=0;j<a2->obtenerPrerrequisitos().size();j++){
        if(a2->obtenerPrerrequisitos()[j]==q.front()){
          e=true;
        }
      }
    }
    if(e){
      bool e2=false;
      for(int i=0;i<v.size();i++){
        if(a2==v[i]){
          e2=true;
        }
      }
      if(!e2){
        q.push(a2);
        v.push_back(a2);
        NodoAsignatura * aux= r->obtenerNodo(q.front());
        if(aux==nullptr){
          r->agregarHijo(new NodoAsignatura(a2));
        }else{
          aux->agregarHijo(a2);
        }
      }
    }
    q.pop();
  }
  return r;
}

NodoAsignatura* ArbolAsignatura::obtenerNodo(Asignatura* a){
  return this->raiz->obtenerNodo(a);
}

#endif
