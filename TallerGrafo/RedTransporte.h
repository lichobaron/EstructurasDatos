#ifndef __RedTransporte__HH__
#define __RedTransporte__HH__
#include <vector>
#include <queue>
#include <stack>
#include "Ciudad.h"

class RedTransporte{
protected:
  std::vector<Ciudad*> ciudades;
public:
  RedTransporte();
  void agregarCiudad(std::string ciudad);
  Ciudad* encontrarCiudad(std::string ciudad);
  void agregarRuta(std::string origen,std::string destino,std::string transporte,int tiempo);
  int contarSubRedes(std::string transporte);
  void mejorRuta(std::string origen,std::string destino,std::string criterio);
  void dijkstra(Ciudad* begin,Ciudad* end);
  std::stack<Ciudad*> porAqui(Ciudad* c,Ciudad* d,std::stack<Ciudad*>&ruta);
  void dfs(Ciudad* begin,Ciudad* end);
  void resetValue();
  void resetEdgeVisited();
};

#include "RedTransporte.hxx"
#endif
