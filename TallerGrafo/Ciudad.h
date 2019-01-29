#ifndef __Ciudad__HH__
#define __Ciudad__HH__
#include <map>

struct Edge{
  unsigned long weigth ;
  std::string transporte;
  bool visited ;
  Edge(unsigned long weigth , bool visited,std::string t) : weigth(weigth) , visited(visited), transporte(t){
  }
};
class Ciudad{
protected:
  std::string nombre;
  std::map<Ciudad*,Edge*> tren;
  std::map<Ciudad*,Edge*> avion;
  std::map<Ciudad*,Edge*> barco;
  int value;
  bool visited;
public:
  Ciudad(std::string nombre);
  std::string obtenerNombre();
  void agregarConexionTren(Ciudad* destino,Edge* ed);
  int cantRedTren();
  void agregarConexionAvion(Ciudad* destino,Edge* ed);
  int cantRedAvion();
  void agregarConexionBarco(Ciudad* destino,Edge* ed);
  int cantRedBarco();
  void setValue(int value);
  int getValue();
  std::multimap<Ciudad*, Edge*> obtenerRutas();
  void resetVisited();
  bool getVisited();
  void setVisited(bool v);
};

#include "Ciudad.hxx"
#endif
