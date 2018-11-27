//Proyecto
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int jersey = 0; const int pique = 1; const int franela = 2; typedef float Tiempo;

class Prendas{
  string Tela;
public:
  Prendas(){};
  Prendas(string tipo):Tela(tipo){};
  ~Prendas(){};
};

class Polo: public Prendas{
  int Polos;
  string tela;
public:
  Polo(string tipo):Prendas(tipo){
    cout << "Polos "<<tipo <<": ";cin>>Polos;
  };
  int getPolo(){return Polos;};
};

class Camisa: public Prendas{
  int Camisas;
  string tela;
public:
  Camisa(string tipo):Prendas(tipo){
    cout << "Camisas "<< tipo <<": ";cin>>Camisas;
  };
  int getCamisa(){return Camisas;};
};

class Cuello: public Prendas{
  int Cuellos;
public:
  Cuello(string tipo):Prendas(tipo){
    cout << "Cuellos "<< tipo <<": ";cin>>Cuellos;
  };
  int getCuello(){return Cuellos;};
};

void Inicializar(string tipo,Polo Polos,Camisa Camisas, Cuello Cuellos,float PesosTotales[3][3]){

  fstream inicio("inicio.txt",ios::in);//Archivo en modo lectura  
  
  string PesoPJ,PesoCJ,PesoCuJ,PesoPP,PesoCP,PesoCuP,PesoPF,PesoCF,PesoCuF;

  if (inicio.fail()){
    cout << "El archivo no se pudo abrir";}

  inicio.seekg(17, ios::beg);getline(inicio,PesoPJ); inicio.seekg(23, ios::beg);getline(inicio,PesoCJ); inicio.seekg(27, ios::beg);getline(inicio,PesoCuJ);
  inicio.seekg(39, ios::beg);getline(inicio,PesoPP); inicio.seekg(44, ios::beg);getline(inicio,PesoCP); inicio.seekg(48, ios::beg);getline(inicio,PesoCuP);
  inicio.seekg(61, ios::beg);getline(inicio,PesoPF); inicio.seekg(66, ios::beg);getline(inicio,PesoCF); inicio.seekg(71, ios::beg);getline(inicio,PesoCuF);
  if (tipo=="Jersey"){
  PesosTotales[jersey][0]=((float)atof(PesoPJ.c_str()))*Polos.getPolo(); 
  PesosTotales[jersey][1]=((float)atof(PesoCJ.c_str()))*Camisas.getCamisa(); 
  PesosTotales[jersey][2]=((float)atof(PesoCuJ.c_str()))*Cuellos.getCuello();}
  else if(tipo=="Pique"){
  PesosTotales[pique][0]=((float)atof(PesoPP.c_str()))*Polos.getPolo(); 
  PesosTotales[pique][1]=((float)atof(PesoCP.c_str()))*Camisas.getCamisa(); 
  PesosTotales[pique][2]=((float)atof(PesoCuP.c_str()))*Cuellos.getCuello();}
  else if(tipo=="Franela"){
  PesosTotales[franela][0]=((float)atof(PesoPF.c_str()))*Polos.getPolo(); 
  PesosTotales[franela][1]=((float)atof(PesoCF.c_str()))*Camisas.getCamisa(); 
  PesosTotales[franela][2]=((float)atof(PesoCuF.c_str()))*Cuellos.getCuello();}

};

void CalculoDeTiempos(float PesoTotal[3][3],Tiempo &tiempo_jersey, Tiempo &tiempo_pique,Tiempo &tiempo_franela){

  fstream inicio("inicio.txt",ios::in);//Archivo en modo lectura  
  
  string Tejido,Tenido,Acabado,ConfeccionPJ,ConfeccionPP,ConfeccionPF,ConfeccionCJ,ConfeccionCP,ConfeccionCF,ConfeccionCuJ,ConfeccionCuP,ConfeccionCuF;

  if (inicio.fail()){
    cout << "El archivo no se pudo abrir";}
  else{
  inicio.seekg(91, ios::beg);getline(inicio,Tejido); inicio.seekg(103, ios::beg);getline(inicio,Tenido); inicio.seekg(116, ios::beg);getline(inicio,Acabado),inicio.seekg(149, ios::beg);getline(inicio,ConfeccionPJ); inicio.seekg(154, ios::beg);getline(inicio,ConfeccionCJ); inicio.seekg(159, ios::beg);getline(inicio,ConfeccionCuJ),inicio.seekg(170, ios::beg);getline(inicio,ConfeccionPP); inicio.seekg(175, ios::beg);getline(inicio,ConfeccionCP); inicio.seekg(180, ios::beg);getline(inicio,ConfeccionCuP),inicio.seekg(193, ios::beg);getline(inicio,ConfeccionPF); inicio.seekg(198, ios::beg);getline(inicio,ConfeccionCF); inicio.seekg(203, ios::beg);getline(inicio,ConfeccionCuF);

  Tiempo Jersey[3],Pique[3],Franela[3];
  
  Jersey[0]=(Tiempo)atof(ConfeccionPJ.c_str()); Jersey[1]=(Tiempo)atof(ConfeccionCJ.c_str()); Jersey[2]=(Tiempo)atof(ConfeccionCuJ.c_str());
  Pique[0]=(Tiempo)atof(ConfeccionPP.c_str()); Pique[1]=(Tiempo)atof(ConfeccionCP.c_str()); Pique[2]=(Tiempo)atof(ConfeccionCuP.c_str());
  Franela[0]=(Tiempo)atof(ConfeccionPF.c_str()); Franela[1]=(Tiempo)atof(ConfeccionCF.c_str()); Franela[2]=(Tiempo)atof(ConfeccionCuF.c_str());

  for (size_t i=0;i<3;i++){
        tiempo_jersey+=(((PesoTotal[jersey][i])/((Tiempo)atof(Tejido.c_str())))+((PesoTotal[jersey][i])/((Tiempo)atof(Tenido.c_str())))+((PesoTotal[jersey][i])/((Tiempo)atof(Acabado.c_str())))+((PesoTotal[jersey][i])/Jersey[i]));}

  for (size_t i=0;i<3;i++){
        tiempo_pique+=((PesoTotal[pique][i]/((Tiempo)atof(Tejido.c_str())))+(PesoTotal[pique][i]/((Tiempo)atof(Tenido.c_str())))+(PesoTotal[pique][i]/((Tiempo)atof(Acabado.c_str())))+(PesoTotal[pique][i]/Pique[i]));}

  for (size_t i=0;i<3;i++){
        tiempo_franela+=((PesoTotal[franela][i]/((Tiempo)atof(Tejido.c_str())))+(PesoTotal[franela][i]/((Tiempo)atof(Tenido.c_str())))+(PesoTotal[franela][i]/((Tiempo)atof(Acabado.c_str())))+(PesoTotal[franela][i]/Franela[i]));}

    cout << "El tiempo de producción de Jersey es: " << tiempo_jersey/24 << " días." << endl;
    cout << "El tiempo de producción de Pique es: " << tiempo_pique/24 << " días." << endl;
    cout << "El tiempo de producción de Franela es: " << tiempo_franela/24 << " días." << endl;
  }
}

void CalculoDeMateriaPrima(float PesoTotal[3][3],float MateriasPrimas[3]){
float MateriaPrimaJersey=0,MateriaPrimaPique=0,MateriaPrimaFranela=0;

  fstream inicio("inicio.txt",ios::in);//Archivo en modo lectura  
  
  string ProduccionJersey,ProduccionPique,ProduccionFranela;

  if (inicio.fail()){
    cout << "El archivo no se pudo abrir";}
  else{
  inicio.seekg(220, ios::beg);getline(inicio,ProduccionJersey); inicio.seekg(235, ios::beg);getline(inicio,ProduccionPique); inicio.seekg(252, ios::beg);getline(inicio,ProduccionFranela);

    for (int i=0;i<3;i++)
        MateriaPrimaJersey+=PesoTotal[jersey][i];

    for (int i=0;i<3;i++)
        MateriaPrimaPique+=PesoTotal[pique][i];

    for (int i=0;i<3;i++)
        MateriaPrimaFranela+=PesoTotal[franela][i];

    cout << "La materia prima es " << MateriaPrimaJersey/((float)atof(ProduccionJersey.c_str())) << " Kg de hilo para Jersey." << endl ;
    cout << "La materia prima es " << MateriaPrimaPique/((float)atof(ProduccionPique.c_str())) << " Kg de hilo para Pique." << endl ;
    cout << "La materia prima es " << MateriaPrimaFranela/((float)atof(ProduccionFranela.c_str())) << " Kg de hilo para Franela." << endl ;

    MateriasPrimas[jersey]=MateriaPrimaJersey/((float)atof(ProduccionJersey.c_str()));
    MateriasPrimas[pique]=MateriaPrimaPique/((float)atof(ProduccionPique.c_str()));
    MateriasPrimas[franela]=MateriaPrimaFranela/((float)atof(ProduccionFranela.c_str()));
  }
};

void CalculoDeCostos(string tipo, Polo Polos, Camisa Camisas, Cuello Cuellos,float RowsMaterials[3],float &ganancia){

  fstream inicio("inicio.txt",ios::in);//Archivo en modo lectura  
  
  string VentaPJ,VentaPP,VentaPF,VentaCJ,VentaCP,VentaCF,VentaCuJ,VentaCuP,VentaCuF,PrecioHilo;
  
  if (inicio.fail()){
    cout << "El archivo no se pudo abrir";}
  else{
  inicio.seekg(272, ios::beg);getline(inicio,PrecioHilo); 
  inicio.seekg(288, ios::beg);getline(inicio,VentaPJ); inicio.seekg(291, ios::beg);getline(inicio,VentaCJ);inicio.seekg(294, ios::beg);getline(inicio,VentaCuJ);

  inicio.seekg(308, ios::beg);getline(inicio,VentaPP); inicio.seekg(311, ios::beg);getline(inicio,VentaCP);inicio.seekg(314, ios::beg);getline(inicio,VentaCuP);
  
  inicio.seekg(331, ios::beg);getline(inicio,VentaPF); inicio.seekg(334, ios::beg);getline(inicio,VentaCF);inicio.seekg(337, ios::beg);getline(inicio,VentaCuF);

    if(tipo=="Jersey"){
        ganancia=(Polos.getPolo()*((float)atof(VentaPJ.c_str())))+(Camisas.getCamisa()*((float)atof(VentaCJ.c_str())))+(Cuellos.getCuello()*((float)atof(VentaCuJ.c_str())));

        ganancia-=(RowsMaterials[jersey]*((float)atof(PrecioHilo.c_str())));
        cout << "La ganancia por Jerseys es " <<ganancia <<" soles." << endl;
    }

    if(tipo=="Pique"){
        ganancia=(Polos.getPolo()*((float)atof(VentaPP.c_str())))+(Camisas.getCamisa()*((float)atof(VentaCP.c_str())))+(Cuellos.getCuello()*((float)atof(VentaCuP.c_str())));

        ganancia-=(RowsMaterials[pique]*((float)atof(PrecioHilo.c_str())));
        cout << "La ganancia por Piques es " <<ganancia <<" soles." << endl;
    }

    if(tipo=="Franela"){
        ganancia=(Polos.getPolo()*((float)atof(VentaPF.c_str())))+(Camisas.getCamisa()*((float)atof(VentaCF.c_str())))+(Cuellos.getCuello()*((float)atof(VentaCuF.c_str())));
        ganancia-=(RowsMaterials[franela]*((float)atof(PrecioHilo.c_str())));
        cout << "La ganancia por Franelas es " << ganancia <<" soles." << endl;
    }   
  }
};

void CalendarioFechaEntrega(float tiempo_dias, int &day,int &month, int &year)
{
    int days_after;
    char month_ch[10]={0};
    string month_str;
    char *registro;
    time_t tAct = time(nullptr);
    registro=asctime(localtime(&tAct));
    for(int i=0;i<4;i++)
        year+=(registro[i+20] - '0')*pow(10,3-i);

    for(int i=0;i<2;i++)
        day+=(registro[i+8] - '0')*pow(10,1-i);

    for(int i=0;i<3;i++)
        month_ch[i]=registro[4+i];

    month_str = string(month_ch);

    int dias_por_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    string nomb_mes[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    if(year%4==0)
        dias_por_mes[1]++;

    for(int i=0;i<12;i++)
        if(month_str==nomb_mes[i]){
            month=i+1;
            break;}

    if(tiempo_dias/int(tiempo_dias)!=0)
        days_after=int(tiempo_dias)+1;
    else
        days_after=int(tiempo_dias);

    int contador=0;
    while(contador<days_after){
        day++;
        cout<<"";

        if(day==dias_por_mes[month-1]+1){
            day=1;
            month++;
        }
        if(month==13){
            month=1;
            year++;
        }
        contador++;
    }

    cout<<day<<"/"<<month<<"/"<<year<<"\n";

}

void Salidas(float &tiempo_jersey,float &tiempo_pique,float &tiempo_franela)
{

  int day=0,month=0,year=0;
  fstream pedido("pedido.txt",ios::out);
  tiempo_jersey/=24;
  CalendarioFechaEntrega(tiempo_jersey,day,month,year);
  pedido << "La fecha de entra de Jersey es "<< day <<"/"<< month <<"/"<< year << endl;
  day=0,month=0,year=0;
  tiempo_pique/=24;
  CalendarioFechaEntrega(tiempo_pique,day,month,year);
  pedido << "La fecha de entra de Pique es "<< day <<"/"<< month <<"/"<< year << endl;
  day=0,month=0,year=0;
  tiempo_franela/=24;
  CalendarioFechaEntrega(tiempo_franela,day,month,year);
  pedido << "La fecha de entra de Franela es "<< day <<"/"<< month <<"/"<< year << endl;

};

int main(){
  
 float PesosTotales[3][3];
 float MateriasPrimas[3];
 float tiempo_jersey=0, tiempo_pique=0, tiempo_franela=0;
 float ganancia_jersey=0,ganancia_pique=0,ganancia_franela=0;
 Polo Polo1("Jersey"); Camisa Camisa1("Jersey");Cuello Cuello1("Jersey"); 
 Polo Polo2("Pique"); Camisa Camisa2("Pique"); Cuello Cuello2("Pique");
 Polo Polo3("Franela"); Camisa Camisa3("Franela");Cuello Cuello3("Franela");

 Inicializar("Jersey",Polo1,Camisa1,Cuello1,PesosTotales);
 Inicializar("Pique",Polo2,Camisa2,Cuello2,PesosTotales);
 Inicializar("Franela",Polo3,Camisa3,Cuello3,PesosTotales);//inicializar(...), funcion que inicializa los arreglos y genera el archivo de pedido
 
 CalculoDeTiempos(PesosTotales,tiempo_jersey,tiempo_pique,tiempo_franela);//calculo tiempos(...), funcion que calcula los tiempos de produccion por producto y prenda.
 
 CalculoDeMateriaPrima(PesosTotales,MateriasPrimas);//calculo materia prima(...), funcion que calcula los requerimientos de materia prima (hilo) por tipo de tela.  //I.e. Materia prima=Kg tela / rendimiento

 CalculoDeCostos("Jersey",Polo1,Camisa1,Cuello1,MateriasPrimas,ganancia_jersey);
 CalculoDeCostos("Pique",Polo2,Camisa2,Cuello2,MateriasPrimas,ganancia_pique); 
 CalculoDeCostos("Franela",Polo3,Camisa3,Cuello3,MateriasPrimas,ganancia_franela); //calculo costos(...), funci´on que calcula los costos y estima la ganancia por tipo de tela

 Salidas(tiempo_jersey,tiempo_pique,tiempo_franela);//salidas(...) , funcion que genera el  archivo de salida (’pedido.txt’) con fechas de entrega programadas
 
 if(ganancia_jersey>ganancia_pique and ganancia_jersey>ganancia_franela){
  cout << "Se sugiere empezar por la fabricación de Jersey. ";
  if (ganancia_pique>ganancia_franela)
    cout << "Seguidamente la fabricación de Pique y por último la de Franela." << endl ;
  else
    cout << "Seguidamente la fabricación de Franela y por último la de Pique." << endl ;
 }

 if(ganancia_pique>ganancia_jersey && ganancia_pique>ganancia_franela){
  cout << "Se sugiere empezar por la fabricación de Pique. ";
  if (ganancia_jersey>ganancia_franela)
    cout << "Seguidamente la fabricación de Jersey y por último la de Franela." << endl ;
  else
    cout << "Seguidamente la fabricación de Franela y por último la de Jersey." << endl ;
 }

  if(ganancia_franela>ganancia_pique && ganancia_franela>ganancia_jersey){
  cout << "Se sugiere empezar por la fabricación de Franela. ";
  if (ganancia_jersey>ganancia_pique)
    cout << "Seguidamente la fabricación de Jersey y por último la de Pique." << endl ;
  else
    cout << "Seguidamente la fabricación de Pique y por último la de Jersey." << endl ;
  }

  return 0;
}
