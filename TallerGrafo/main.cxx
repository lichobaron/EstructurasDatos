#include <iostream>
#include "RedTransporte.h"
using namespace std;

int main(){
  RedTransporte* rT=new RedTransporte();
  int opc;
  /*rT->agregarCiudad("Bogota");
  rT->agregarCiudad("Cali");
  rT->agregarCiudad("Madrid");
  rT->agregarCiudad("Paris");
  rT->agregarCiudad("Nueva York");
  rT->agregarCiudad("Mexico DF");
  //==================================
  //rT->agregarRuta("Paris","Madrid","avion",3);
  rT->agregarRuta("Bogota","Cali","avion",3);
  rT->agregarRuta("Paris","Bogota","avion",3);
  //rT->agregarRuta("Madrid","Paris","tren",5);
  //rT->agregarRuta("Bogotá","Cali","tren",7);
  rT->agregarRuta("Nueva York","Paris","avion",3);
  rT->agregarRuta("Mexico DF","Nueva York","avion",1);
  //rT->agregarRuta("Mexico DF","Bogotá","avion",1);
  rT->agregarRuta("Cali","Mexico DF","avion",1);
  rT->agregarRuta("Bogota","Nueva York","barco",12);
  //==================================
  //cout<<rT->contarSubRedes("barco")<<endl;
  //==================================
  rT->mejorRuta("Bogotá","Nueva York","tiempo");*/
  do{
    string c1="";
    string c2="";
    string t="";
    int tiempo;
    cout << "    Menú" << '\n';
    cout << "1. Agregar Ciudad." << '\n'<<"2. Agregar Ruta."<<endl<<"3. Contar SubRedes."<<endl<<"4. Calcular Mejor Ruta."
    <<endl<<"5. Salir.\n";
    cin>>opc;
    switch (opc) {
      case 1:
        cout<<"Ingrese nombre ciudad:\n";
        cin>>c1;
        rT->agregarCiudad(c1);
        cout<<"==============================\n";
        break;
      case 2:
        cout<<"Ingrese ciudad de origen: ";
        cin>>c1;
        cout<<endl;
        cout<<"Ingrese ciudad de destino: ";
        cin>>c2;
        cout<<endl;
        cout<<"Ingrese medio de transporte tren/avion/barco: ";
        cin>>t;
        cout<<endl;
        cout<<"Ingrese tiempo de viaje: ";
        cin>>tiempo;
        cout<<endl;
        rT->agregarRuta(c1,c2,t,tiempo);
        cout<<"==============================\n";
        break;
      case 3:
        cout<<"Ingrese medio de transporte que desea contar tren/avion/barco: ";
        cin>>t;
        cout<<"\nPara el medio de transporte "<<t<<", existen "<<rT->contarSubRedes(t)<<" SubRedes.\n";
        cout<<"==============================\n";
        break;
      case 4:
        cout<<"Ingrese ciudad de origen: ";
        cin>>c1;
        cout<<endl;
        cout<<"Ingrese ciudad de destino: ";
        cin>>c2;
        cout<<endl;
        cout<<"Ingrese criterio tiempo/transbordos:\n";
        cin>>t;
        cout<<endl;
        rT->mejorRuta(c1,c2,t);
        cout<<"==============================\n";
        break;
    }
  }while(opc!=5);
  return 0;
}
