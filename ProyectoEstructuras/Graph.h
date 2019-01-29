#ifndef __Graph__HH__
#define __Graph__HH__

#include <set>
#include <map>
#include <queue>
#include <stack>
#include "Vertex.h"

template < class T >
struct VertComparator
{
    bool operator()(const Vertex<T>* a, const Vertex<T>* b ) const
    {
        return a->getData() < b->getData();
    }
};

template <class T>
class Graph{

protected:
   std::set<Vertex<T> *, VertComparator<T>> vertexs;

public:
  void addVertex(T data);
  void addEdge(T data1, T data2, int weight);
  void eraseEdge(T data1, T data2);
  void eraseVertex(T data);
  Vertex<T>* searchVertex(T data);
  void resetVisited();
  void resetValue();
  void flatTrack();
  void depthFirstSearch(T begin);
  void breadthFirstSearch(T begin);
  void eulerTrack(T begin);
  std::stack<T> dijkstra(T begin, T end);
  int shortestPath(T begin, T end, int sum, std::queue<Vertex<T>*> &track);
};

#include "Graph.hxx"
#endif
