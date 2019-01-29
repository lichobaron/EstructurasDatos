#ifndef __Vertex__HH__
#define __Vertex__HH__

#include <iostream>
#include <map>

template <class T>
class Vertex
{
protected:
    T data;
    std::map<Vertex<T>*, int> ady;
    bool visited= false;
    int value=9999;

public:
    template<T> friend bool operator == (const Vertex<T> &v1, const Vertex<T> &v2);
    template<T> friend bool operator != (const Vertex<T> &v1, const Vertex<T> &v2);
    template<T> friend bool operator <= (const Vertex<T> &v1, const Vertex<T> &v2);
    template<T> friend bool operator >= (const Vertex<T> &v1, const Vertex<T> &v2);
    template<T> friend bool operator < (const Vertex<T> &v1, const Vertex<T> &v2);
    template<T> friend bool operator > (const Vertex<T> &v1, const Vertex<T> &v2);
    template<T> friend std::ostream& operator <<(std::ostream &o, const Vertex<T> &v1);
    Vertex(T data);
    T getData() const;
    bool getVisited();
    void setVisited(bool visited);
    int getValue();
    void setValue(int value);
    std::map<Vertex<T>*, int> getAdy();
    void addAdyacent(Vertex<T> *v, int weight);
    void eraseEdge(Vertex<T> *v);
    int getDist(Vertex<T> *t);
    bool allAdy();
};

#include "Vertex.hxx"
#endif
