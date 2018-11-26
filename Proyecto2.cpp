//Proyecto
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int jersey = 0; const int pique = 1; const int franela = 2;

class Prendas{
  int PoloJersey,PoloPique,PoloFranela,CamisaJersey,CamisaPique,CamisaFranela,CuelloJersey,CuelloPique,CuelloFranela;
public:
  Prendas(){};
  void Datos(int PJ,int PP, int PF,int CJ,int CP,int CF,int CuJ,int CuP,int CuF){
  cout <<"Polos Jersey: " ; cin >> PJ;PoloJersey=PJ; cout <<"Camisas Jersey: " ; cin >> CJ;CamisaJersey=CJ; cout <<"Cuellos Jersey: " ; cin >> CuJ;CuelloJersey=CuJ;
  cout <<"Polos Pique: " ; cin >> PP;PoloPique=PP; cout <<"Polos Franela: " ; cin >> PF;PoloFranela=PF; cout <<"Camisas Pique: " ; cin >> CP;CamisaPique=CP;
  cout <<"Camisas Franela: " ; cin >> CF;CamisaFranela=CF; cout <<"Cuellos Pique: " ; cin >> CuP;CuelloPique=CuP; cout <<"Cuellos Franela: " ; cin >> CuF;CuelloFranela=CuF;
  };
  int getPoloJersey(){return PoloJersey;};int getCamisaJersey(){return CamisaJersey;};int getCuelloJersey(){return CuelloJersey;};
  int getPoloPique(){return PoloPique;};int getCamisaPique(){return CamisaPique;};int getCuelloPique(){return CuelloPique;};
  int getPoloFranela(){return PoloFranela;};int getCamisaFranela(){return CamisaFranela;};int getCuelloFranela(){return CuelloFranela;};
};

void Inicializar(int Cantidades[3][3],float Pesos[3][3],float PesosTotales[3][3]){
  
  Prendas Pedido;
  Pedido.Datos(0, 0, 0, 0, 0, 0, 0, 0, 0);
  //Cantidades[3][3]={0,0,0} Tipo de Tela (Jersey=0,Pique=1,Franela=2)
                //Polo,Camisa,Cuello 
  Cantidades[jersey][0]=Pedido.getPoloJersey();Cantidades[jersey][1]=Pedido.getCamisaJersey();Cantidades[jersey][2]=Pedido.getCuelloJersey();
  Cantidades[pique][0]=Pedido.getPoloPique();Cantidades[pique][1]=Pedido.getCamisaPique();Cantidades[pique][2]=Pedido.getCuelloPique();
  Cantidades[franela][0]=Pedido.getPoloFranela();Cantidades[franela][1]=Pedido.getCamisaFranela();Cantidades[franela][2]=Pedido.getCuelloFranela();

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

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        cout << PesosTotales[i][j] << endl;

};

void CalculoDeTiempos(float PesoTotal[3][3],float &tiempo_jersey, float &tiempo_pique,float &tiempo_franela){

  fstream inicio("inicio.txt",ios::in);//Archivo en modo lectura  
  
  string Tejido,Tenido,Acabado,ConfeccionPJ,ConfeccionPP,ConfeccionPF,ConfeccionCJ,ConfeccionCP,ConfeccionCF,ConfeccionCuJ,ConfeccionCuP,ConfeccionCuF;

  if (inicio.fail()){
    cout << "El archivo no se pudo abrir";}

  inicio.seekg(91, ios::beg);getline(inicio,Tejido); inicio.seekg(103, ios::beg);getline(inicio,Tenido); inicio.seekg(116, ios::beg);getline(inicio,Acabado),inicio.seekg(149, ios::beg);getline(inicio,ConfeccionPJ); inicio.seekg(154, ios::beg);getline(inicio,ConfeccionCJ); inicio.seekg(159, ios::beg);getline(inicio,ConfeccionCuJ),inicio.seekg(170, ios::beg);getline(inicio,ConfeccionPP); inicio.seekg(175, ios::beg);getline(inicio,ConfeccionCP); inicio.seekg(180, ios::beg);getline(inicio,ConfeccionCuP),inicio.seekg(193, ios::beg);getline(inicio,ConfeccionPF); inicio.seekg(198, ios::beg);getline(inicio,ConfeccionCF); inicio.seekg(203, ios::beg);getline(inicio,ConfeccionCuF);

  float tiempo_tejido,tiempo_tenido,tiempo_acabado,Jersey[3],Pique[3],Franela[3];
  tiempo_tejido=(float)atof(Tejido.c_str());tiempo_tenido=(float)atof(Tenido.c_str());tiempo_acabado=(float)atof(Acabado.c_str());
  Jersey[0]=(float)atof(ConfeccionPJ.c_str()); Jersey[1]=(float)atof(ConfeccionCJ.c_str()); Jersey[2]=(float)atof(ConfeccionCuJ.c_str());
  Pique[0]=(float)atof(ConfeccionPP.c_str()); Pique[1]=(float)atof(ConfeccionCP.c_str()); Pique[2]=(float)atof(ConfeccionCuP.c_str());
  Franela[0]=(float)atof(ConfeccionPF.c_str()); Franela[1]=(float)atof(ConfeccionCF.c_str()); Franela[2]=(float)atof(ConfeccionCuF.c_str());

  cout << tiempo_tejido << " " << tiempo_tenido << " " << tiempo_acabado <<endl << ConfeccionPJ << " " << ConfeccionCJ << " " << ConfeccionCuJ << endl << ConfeccionPP << " " << ConfeccionCP << " " << ConfeccionCuP << endl << ConfeccionPF << " " << ConfeccionCF << " " << ConfeccionCuF << endl;

  for (size_t i=0;i<3;i++){
        tiempo_jersey+=(((PesoTotal[jersey][i])/tiempo_tejido)+((PesoTotal[jersey][i])/tiempo_tenido)+((PesoTotal[jersey][i])/tiempo_acabado)+((PesoTotal[jersey][i])/Jersey[i]));}

  for (size_t i=0;i<3;i++){
        tiempo_pique+=((PesoTotal[pique][i]/tiempo_tejido)+(PesoTotal[pique][i]/tiempo_tenido)+(PesoTotal[pique][i]/tiempo_acabado)+(PesoTotal[pique][i]/Pique[i]));}

  for (size_t i=0;i<3;i++){
        tiempo_franela+=((PesoTotal[franela][i]/tiempo_tejido)+(PesoTotal[franela][i]/tiempo_tenido)+(PesoTotal[franela][i]/tiempo_acabado)+(PesoTotal[franela][i]/Franela[i]));}

    cout << "El tiempo de producción de Jersey es: " << tiempo_jersey/24 << " días." << endl;
    cout << "El tiempo de producción de Pique es: " << tiempo_pique/24 << " días." << endl;
    cout << "El tiempo de producción de Franela es: " << tiempo_franela/24 << " días." << endl;

    return;
}

void CalculoDeMateriaPrima(float PesoTotal[3][3],float MateriasPrimas[3]){
float MateriaPrimaJersey=0,MateriaPrimaPique=0,MateriaPrimaFranela=0;

    for (int i=0;i<3;i++)
        MateriaPrimaJersey+=PesoTotal[jersey][i];

    for (int i=0;i<3;i++)
        MateriaPrimaPique+=PesoTotal[pique][i];

    for (int i=0;i<3;i++)
        MateriaPrimaFranela+=PesoTotal[franela][i];

    cout << "La materia prima es " << MateriaPrimaJersey/0.7 << "Kg de hilo para Jersey." << endl ;
    cout << "La materia prima es " << MateriaPrimaPique/0.5 << "Kg de hilo para Pique." << endl ;
    cout << "La materia prima es " << MateriaPrimaFranela/0.3 << "Kg de hilo para Franela." << endl ;

    MateriasPrimas[jersey]=MateriaPrimaJersey/0.7;
    MateriasPrimas[pique]=MateriaPrimaPique/0.5;
    MateriasPrimas[franela]=MateriaPrimaFranela/0.3;

    return ;
};

void CalculoDeCostos(){};

void Salidas(){};


int main(){
 int Cantidades[3][3]={0};
 float Pesos[3][3];
 float PesosTotales[3][3];
 float MateriasPrimas[3];
 float tiempo_jersey=0;float tiempo_pique=0; float tiempo_franela=0;

 Inicializar(Cantidades,Pesos,PesosTotales);//inicializar(...), funcion que inicializa los arreglos y genera el archivo de pedido
 
 CalculoDeTiempos(PesosTotales,tiempo_jersey,tiempo_pique,tiempo_franela);//calculo tiempos(...), funcion que calcula los tiempos de produccion por producto y prenda.
 
 CalculoDeMateriaPrima(PesosTotales,MateriasPrimas);//calculo materia prima(...), funcion que calcula los requerimientos de materia prima (hilo) por tipo de tela.  //I.e. Materia prima=Kg tela / rendimiento

 CalculoDeCostos(); //calculo costos(...), funci´on que calcula los costos y estima la ganancia por tipo de tela
 
 Salidas();//salidas(...) , funci´on que genera el a

  return 0;
}
