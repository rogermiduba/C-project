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

void Inicializar(int Cantidades[3][3],float Pesos[3][3],float PesosTotales[3][3]){

 Polo Polo1("Jersey"); Camisa Camisa1("Jersey");Cuello Cuello1("Jersey"); 
 Polo Polo2("Pique"); Camisa Camisa2("Pique"); Cuello Cuello2("Pique");
 Polo Polo3("Franela"); Camisa Camisa3("Franela");Cuello Cuello3("Franela");

  //Cantidades[3][3]={0,0,0} Tipo de Tela (Jersey=0,Pique=1,Franela=2)
          //Polo,Camisa,Cuello 
  Cantidades[jersey][0]=Polo1.getPolo();Cantidades[jersey][1]=Camisa1.getCamisa();Cantidades[jersey][2]=Cuello1.getCuello();
  Cantidades[pique][0]=Polo2.getPolo();Cantidades[pique][1]=Camisa2.getCamisa();Cantidades[pique][2]=Cuello2.getCuello(); 
  Cantidades[franela][0]=Polo3.getPolo();Cantidades[franela][1]=Camisa3.getCamisa();Cantidades[franela][2]=Cuello3.getCuello();

  fstream inicio("inicio.txt",ios::in);//Archivo en modo lectura  
  
  string PesoPJ,PesoCJ,PesoCuJ,PesoPP,PesoCP,PesoCuP,PesoPF,PesoCF,PesoCuF;

  if (inicio.fail()){
    cout << "El archivo no se pudo abrir";}

  inicio.seekg(17, ios::beg);getline(inicio,PesoPJ); inicio.seekg(23, ios::beg);getline(inicio,PesoCJ); inicio.seekg(27, ios::beg);getline(inicio,PesoCuJ);
  inicio.seekg(39, ios::beg);getline(inicio,PesoPP); inicio.seekg(44, ios::beg);getline(inicio,PesoCP); inicio.seekg(48, ios::beg);getline(inicio,PesoCuP);
  inicio.seekg(61, ios::beg);getline(inicio,PesoPF); inicio.seekg(66, ios::beg);getline(inicio,PesoCF); inicio.seekg(71, ios::beg);getline(inicio,PesoCuF);
  
  Pesos[jersey][0]=(float)atof(PesoPJ.c_str()); Pesos[jersey][1]=(float)atof(PesoCJ.c_str()); Pesos[jersey][2]=(float)atof(PesoCuJ.c_str());
  Pesos[pique][0]=(float)atof(PesoPP.c_str()); Pesos[pique][1]=(float)atof(PesoCP.c_str()); Pesos[pique][2]=(float)atof(PesoCuP.c_str());
  Pesos[franela][0]=(float)atof(PesoPF.c_str()); Pesos[franela][1]=(float)atof(PesoCF.c_str()); Pesos[franela][2]=(float)atof(PesoCuF.c_str());

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        PesosTotales[i][j]=Cantidades[i][j]*Pesos[i][j];

};

void CalculoDeTiempos(float PesoTotal[3][3],Tiempo &tiempo_jersey, Tiempo &tiempo_pique,Tiempo &tiempo_franela){

  fstream inicio("inicio.txt",ios::in);//Archivo en modo lectura  
  
  string Tejido,Tenido,Acabado,ConfeccionPJ,ConfeccionPP,ConfeccionPF,ConfeccionCJ,ConfeccionCP,ConfeccionCF,ConfeccionCuJ,ConfeccionCuP,ConfeccionCuF;

  if (inicio.fail()){
    cout << "El archivo no se pudo abrir";}
  else{
  inicio.seekg(91, ios::beg);getline(inicio,Tejido); inicio.seekg(103, ios::beg);getline(inicio,Tenido); inicio.seekg(116, ios::beg);getline(inicio,Acabado),inicio.seekg(149, ios::beg);getline(inicio,ConfeccionPJ); inicio.seekg(154, ios::beg);getline(inicio,ConfeccionCJ); inicio.seekg(159, ios::beg);getline(inicio,ConfeccionCuJ),inicio.seekg(170, ios::beg);getline(inicio,ConfeccionPP); inicio.seekg(175, ios::beg);getline(inicio,ConfeccionCP); inicio.seekg(180, ios::beg);getline(inicio,ConfeccionCuP),inicio.seekg(193, ios::beg);getline(inicio,ConfeccionPF); inicio.seekg(198, ios::beg);getline(inicio,ConfeccionCF); inicio.seekg(203, ios::beg);getline(inicio,ConfeccionCuF);

  Tiempo tiempo_tejido,tiempo_tenido,tiempo_acabado,Jersey[3],Pique[3],Franela[3];
  tiempo_tejido=(Tiempo)atof(Tejido.c_str());tiempo_tenido=(Tiempo)atof(Tenido.c_str());tiempo_acabado=(Tiempo)atof(Acabado.c_str());
  Jersey[0]=(Tiempo)atof(ConfeccionPJ.c_str()); Jersey[1]=(Tiempo)atof(ConfeccionCJ.c_str()); Jersey[2]=(Tiempo)atof(ConfeccionCuJ.c_str());
  Pique[0]=(Tiempo)atof(ConfeccionPP.c_str()); Pique[1]=(Tiempo)atof(ConfeccionCP.c_str()); Pique[2]=(Tiempo)atof(ConfeccionCuP.c_str());
  Franela[0]=(Tiempo)atof(ConfeccionPF.c_str()); Franela[1]=(Tiempo)atof(ConfeccionCF.c_str()); Franela[2]=(Tiempo)atof(ConfeccionCuF.c_str());

  for (size_t i=0;i<3;i++){
        tiempo_jersey+=(((PesoTotal[jersey][i])/tiempo_tejido)+((PesoTotal[jersey][i])/tiempo_tenido)+((PesoTotal[jersey][i])/tiempo_acabado)+((PesoTotal[jersey][i])/Jersey[i]));}

  for (size_t i=0;i<3;i++){
        tiempo_pique+=((PesoTotal[pique][i]/tiempo_tejido)+(PesoTotal[pique][i]/tiempo_tenido)+(PesoTotal[pique][i]/tiempo_acabado)+(PesoTotal[pique][i]/Pique[i]));}

  for (size_t i=0;i<3;i++){
        tiempo_franela+=((PesoTotal[franela][i]/tiempo_tejido)+(PesoTotal[franela][i]/tiempo_tenido)+(PesoTotal[franela][i]/tiempo_acabado)+(PesoTotal[franela][i]/Franela[i]));}

    cout << "El tiempo de producción de Jersey es: " << tiempo_jersey/24 << " días." << endl;
    cout << "El tiempo de producción de Pique es: " << tiempo_pique/24 << " días." << endl;
    cout << "El tiempo de producción de Franela es: " << tiempo_franela/24 << " días." << endl;
  }
}

void CalculoDeMateriaPrima(float PesoTotal[3][3],float MateriasPrimas[3]){
float MateriaPrimaJersey=0,MateriaPrimaPique=0,MateriaPrimaFranela=0;

    for (int i=0;i<3;i++)
        MateriaPrimaJersey+=PesoTotal[jersey][i];

    for (int i=0;i<3;i++)
        MateriaPrimaPique+=PesoTotal[pique][i];

    for (int i=0;i<3;i++)
        MateriaPrimaFranela+=PesoTotal[franela][i];

    cout << "La materia prima es " << MateriaPrimaJersey/0.7 << " Kg de hilo para Jersey." << endl ;
    cout << "La materia prima es " << MateriaPrimaPique/0.5 << " Kg de hilo para Pique." << endl ;
    cout << "La materia prima es " << MateriaPrimaFranela/0.3 << " Kg de hilo para Franela." << endl ;

    MateriasPrimas[jersey]=MateriaPrimaJersey/0.7;
    MateriasPrimas[pique]=MateriaPrimaPique/0.5;
    MateriasPrimas[franela]=MateriaPrimaFranela/0.3;

};

void CalculoDeCostos(int Cantidades[3][3], float RowsMaterials[3])
{float ganancia_jersey=0,ganancia_pique=0,ganancia_franela=0;

    float VentaJersey[3]={30,50,5};//{polos,camisas,cuellos}
    float VentaPique[3]={60,75,10};//{polos,camisas,cuellos}
    float VentaFranela[3]={60,80,15};//{polos,camisas,cuellos}

    for(size_t i=0;i<3;i++){
        ganancia_jersey+=Cantidades[jersey][i]*VentaJersey[i];
    }

    ganancia_jersey-=(RowsMaterials[jersey]*10.0);

    for(size_t i=0;i<3;i++){
        ganancia_pique+=Cantidades[pique][i]*VentaPique[i];
    }

    ganancia_pique-=(RowsMaterials[pique]*10.0);

    for(size_t i=0;i<3;i++){
        ganancia_franela+=Cantidades[franela][i]*VentaFranela[i];
    }

    ganancia_franela-=(RowsMaterials[franela]*10.0);

    cout << "La ganancia por Jerseys es " <<ganancia_jersey <<" soles." << endl;
    cout << "La ganancia por Piques es " <<ganancia_pique <<" soles." << endl;
    cout << "La ganancia por Franelas es " <<ganancia_franela <<" soles." << endl;

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

void Salidas(float &tiempo_jersey,float &tiempo_pique,float &tiempo_franela){

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
 int Cantidades[3][3]={0};
 float Pesos[3][3];
 float PesosTotales[3][3];
 float MateriasPrimas[3];
 float tiempo_jersey=0;float tiempo_pique=0; float tiempo_franela=0;

 Inicializar(Cantidades,Pesos,PesosTotales);//inicializar(...), funcion que inicializa los arreglos y genera el archivo de pedido
 
 CalculoDeTiempos(PesosTotales,tiempo_jersey,tiempo_pique,tiempo_franela);//calculo tiempos(...), funcion que calcula los tiempos de produccion por producto y prenda.
 
 CalculoDeMateriaPrima(PesosTotales,MateriasPrimas);//calculo materia prima(...), funcion que calcula los requerimientos de materia prima (hilo) por tipo de tela.  //I.e. Materia prima=Kg tela / rendimiento

 CalculoDeCostos(Cantidades,MateriasPrimas); //calculo costos(...), funci´on que calcula los costos y estima la ganancia por tipo de tela

 Salidas(tiempo_jersey,tiempo_pique,tiempo_franela);//salidas(...) , funci´on que genera el a

  return 0;
}
