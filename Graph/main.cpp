#include <iostream>
#include "Graph.h"

using namespace std;

int main(){
  Graph<int> *grafo= new Graph<int>();
  grafo->addVertex(1);
  grafo->addVertex(2);
  grafo->addVertex(3);
  grafo->addVertex(4);
  grafo->addVertex(5);
  grafo->addVertex(6);
  grafo->addEdge(1,2,0);
  grafo->addEdge(1,3,0);
  grafo->addEdge(1,4,0);
  grafo->addEdge(2,3,0);
  grafo->addEdge(2,5,0);
  grafo->addEdge(4,5,0);
  grafo->addEdge(4,6,0);
  cout<<"Recorrido plano: "<<endl;
  grafo->resetVisited();
  grafo->flatTrack();
  cout<<"Recorrido en profundidad desde 3: "<<endl;
  grafo->resetVisited();
  grafo->depthFirstSearch(6);
  cout<<endl;
  cout<<"Recorrido en anchura desde 4: "<<endl;
  grafo->resetVisited();
  grafo->breadthFirstSearch(6);
  cout<<endl;
  cout<<grafo->dijkstraPath(1)<<endl;
  /* OTRAS FUNCIONES
  grafo->eraseVertex(1);
  grafo->eraseEdge(1,2);
  grafo->hamiltonTrack(); */
  return 0;
}
