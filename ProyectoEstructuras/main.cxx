#include "Sistema.h"
#include "Utils.h"

using namespace std;

int main(){
  Utils *utils = new Utils();
  Sistema *sistema = new Sistema();
  /*
  cout<<utils->cargar_info_asign(sistema,"listaClasesAsignacionAula-1010.csv")<<endl;
  cout<<utils->cargar_info_estud(sistema,"listaClasesInscritasEstud-1010.csv")<<endl;
  cout<<utils->cargar_info_prerreq(sistema,"prerrequisitos.csv")<<endl;
  cout<<utils->cargar_info_asign(sistema,"listaClasesAsignacionAula-1230.csv")<<endl;
  cout<<utils->cargar_info_estud(sistema,"listaClasesInscritasEstud-1230.csv")<<endl;
  utils->mostrarHorario(sistema,20043398);
  utils->proy_demanda(sistema,4186);
  utils->proy_semestres(sistema,10113429,true,true,true);
  cout<<utils->red_social(sistema);
  utils->grados_separacion(sistema,10083946,10139287);
  */
  string parametro="";
  string parametro2="";
  string comando="";
  bool estud=false;
  bool asign=false;
  bool pre=false;
  while(comando!="salir"){
    cout<<"$ ";
    cin>>comando;
    if(comando=="cargar_info_asign"||comando=="1"){
      cin>>parametro;
      cout<<utils->cargar_info_asign(sistema,parametro)<<endl;
      asign= true;
    }
    if(comando=="cargar_info_estud"||comando=="2"){
      cin>>parametro;
      cout<<utils->cargar_info_estud(sistema,parametro)<<endl;
      estud= true;
    }
    if(comando=="horario_estud"||comando=="3"){
      cin>>parametro;
      utils->mostrarHorario(sistema,atoi(parametro.c_str()));
    }
    if(comando=="cargar_info_prerreq"||comando=="4"){
      cin>>parametro;
      cout<<utils->cargar_info_prerreq(sistema,parametro)<<endl;
      pre= true;
    }
    if(comando=="proy_demanda"||comando=="5"){
      cin>>parametro;
      utils->proy_demanda(sistema,atoi(parametro.c_str()));
    }
    if(comando=="proy_semestres"||comando=="6"){
      cin>>parametro;
      utils->proy_semestres(sistema,atoi(parametro.c_str()),estud,asign,pre);
    }
    if(comando=="red_social"||comando=="7"){
      cout<<utils->red_social(sistema);
    }
    if(comando=="grados_separacion"||comando=="8"){
      cin>>parametro;
      cin>>parametro2;
      utils->grados_separacion(sistema,atoi(parametro.c_str()),atoi(parametro2.c_str()));
    }
    if(comando=="ayuda"){
      utils->mostrarAyuda();
    }
  }
  return 0;
}
