#include <iostream>
#include "Graph.h"

using namespace std;

int main(){
  Graph<char> *grafo= new Graph<char>();
  grafo->addVertex('s');
  grafo->addVertex('t');
  grafo->addVertex('y');
  grafo->addVertex('x');
  grafo->addVertex('z');
  grafo->addEdge('s','t',10);
  grafo->addEdge('s','y',5);
  grafo->addEdge('t','x',1);
  grafo->addEdge('t','y',2);
  grafo->addEdge('y','t',3);
  grafo->addEdge('y','x',9);
  grafo->addEdge('y','z',2);
  grafo->addEdge('x','z',4);
  grafo->addEdge('z','x',6);
  grafo->addEdge('z','s',0);
  cout<<"Recorrido plano: "<<endl;
  grafo->resetVisited();
  grafo->flatTrack();
  cout<<"Recorrido en profundidad desde s: "<<endl;
  grafo->resetVisited();
  grafo->depthFirstSearch('s');
  cout<<endl;
  cout<<"Recorrido en anchura desde s: "<<endl;
  grafo->resetVisited();
  grafo->breadthFirstSearch('s');
  cout<<endl;
  cout<<"Camino mas corto de s a x: "<<endl;
  grafo->dijkstra('s','t');
   /*OTRAS FUNCIONES
  grafo->eraseVertex(1);
  grafo->eraseEdge(1,2); */
  return 0;
}
