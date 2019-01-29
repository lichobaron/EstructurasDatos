#include <iostream>
#include "Arbol.h"
#include "Nodo.h"

int main  (int arc , char* argv[]){
    int a=5 ;
    int b2 = 10 ;
    int b1 = 20 ;
    int b3 = 30 ;
    int b4 = 40 ;
    int b5 = 50 ;
    int b6 = 60 ;
Arbol<int> arbol = Arbol<int>(a) ;
arbol.insertarNodo(a , b2);
arbol.insertarNodo(a , b3);
arbol.insertarNodo(a , b4);
arbol.insertarNodo(b2 , b5);
arbol.insertarNodo(b2 , b6);
arbol.imprimirpreOrden();
return 0 ;
}
