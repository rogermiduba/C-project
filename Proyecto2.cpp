//Proyecto
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

const int jersey = 0; const int pique = 1; const int franela = 2;
const int polo = 0; const int camisa = 1; const int cuello = 2;
const float tiempo_tejido=1.0; const float tiempo_tenido=10.0;
const float tiempo_acabado=20.0;

class Prenda{
  float TiempoDeTejido;
  float TiempoDeTenido;
  float TiempoDeAcabado;
  int Cantidades[3][3];
public:
  Prenda(){
    cout<< "Polos Jersey: ";cin >> Cantidades[jersey][0];
    cout<< "Camisas Jersey: ";cin >> Cantidades[jersey][1]; 
    cout<< "Cuellos Jersey: ";cin >> Cantidades[jersey][2]; 
    cout<< endl;
    cout<< "Polos Pique: ";cin >> Cantidades[pique][0];
    cout<< "Camisas Pique: ";cin >> Cantidades[pique][1];
    cout<< "Cuellos Pique: ";cin >> Cantidades[pique][2]; 
    cout <<endl;
    cout<< "Polos Franela: ";cin >> Cantidades[franela][0]; 
    cout<< "Camisas Franela: ";cin >> Cantidades[franela][1]; 
    cout<< "Cuellos Franela: ";cin >> Cantidades[franela][2];
    cout << endl;
    fstream inicio("inicio.txt", ios::in);
    inicio.seekg(16, ios::beg);
    TiempoDeTejido=inicio.get();
    inicio.seekg(18, ios::beg);
    TiempoDeTenido=inicio.get();
    inicio.seekg(20, ios::beg);
    TiempoDeAcabado=inicio.get();
  };
};

class Jersey: public Prenda{
  float PesoPorPrenda[3];
  float TiempoDeConfeccion[3];
public:
  Jersey(){
    fstream inicio("inicio.txt", ios::in);
    inicio.seekg(3, ios::beg);
    TiempoDeConfeccion[polo]=inicio.get();
    inicio.seekg(4, ios::beg);
    TiempoDeConfeccion[camisa]=inicio.get();
    inicio.seekg(5, ios::beg);
    TiempoDeConfeccion[cuello]=inicio.get();

    inicio.seekg(23, ios::beg);
    TiempoDeConfeccion[polo]=inicio.get();
    inicio.seekg(24, ios::beg);
    TiempoDeConfeccion[camisa]=inicio.get();
    inicio.seekg(25, ios::beg);
    TiempoDeConfeccion[cuello]=inicio.get();
  };
};

class Pique: public Prenda{
  float PesoPorPrenda[3];
  float TiempoDeConfeccion[3];
public:
  Pique(){
    fstream inicio("inicio.txt", ios::in);
    inicio.seekg(7, ios::beg);
    TiempoDeConfeccion[polo]=inicio.get();
    inicio.seekg(8, ios::beg);
    TiempoDeConfeccion[camisa]=inicio.get();
    inicio.seekg(9, ios::beg);
    TiempoDeConfeccion[cuello]=inicio.get();

    inicio.seekg(27, ios::beg);
    TiempoDeConfeccion[polo]=inicio.get();
    inicio.seekg(28, ios::beg);
    TiempoDeConfeccion[camisa]=inicio.get();
    inicio.seekg(29, ios::beg);
    TiempoDeConfeccion[cuello]=inicio.get();
  };
};

class Franela: public Prenda{
  float PesoPorPrenda[3];
  float TiempoDeConfeccion[3];
public:
  Franela(){
    fstream inicio("inicio.txt", ios::in);
    inicio.seekg(11, ios::beg);
    TiempoDeConfeccion[polo]=inicio.get();
    inicio.seekg(12, ios::beg);
    TiempoDeConfeccion[camisa]=inicio.get();
    inicio.seekg(13, ios::beg);
    TiempoDeConfeccion[cuello]=inicio.get();

    inicio.seekg(31, ios::beg);
    TiempoDeConfeccion[polo]=inicio.get();
    inicio.seekg(32, ios::beg);
    TiempoDeConfeccion[camisa]=inicio.get();
    inicio.seekg(33, ios::beg);
    TiempoDeConfeccion[cuello]=inicio.get();
  };
};

void Calculo_tiempos(float PesoTotal[3][3], float Jersey[3],float Pique[3], float Franela[3],float &tiempo_jersey, float &tiempo_pique,float &tiempo_franela)
{

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

void Cantidad_materia_prima(float PesoTotal[3][3],float MateriasPrimas[3])
{float MateriaPrimaJersey=0,MateriaPrimaPique=0,MateriaPrimaFranela=0;

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
}

void Ganancias_esperadas(int Cantidades[3][3], float RowsMaterials[3])
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

    return ;
}


void Calendario_fecha_entrega(float tiempo_dias)
{
    int year=0, month=0, day=0, days_after;
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
            break;
        }

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
    return;
}

int main(){

    int Cantidades[3/*Telas*/][3/*Prendas*/] = {
            {0,0,0},//Jersey
            {0,0,0},//Pique
            {0,0,0} //Franela
            //{Polos,Camisas,Cuellos}
    };
    float Pesos[3/*Telas*/][3/*Prendas*/];
    float PesoTotal[3][3];
    float ConfeccionJersey[3]={0.2,0.5,0.05};//{polos,camisas,cuellos}
    float ConfeccionPique[3]={0.22,0.33,0.04};//{polos,camisas,cuellos}
    float ConfeccionFranela[3]={0.25,0.5,0.05};//{polos,camisas,cuellos}
    float MateriasPrimas[3];
    float tiempo_jersey=0;float tiempo_pique=0; float tiempo_franela=0;
    Prenda Cantidad;
    
    Calculo_tiempos(PesoTotal,ConfeccionJersey,ConfeccionPique,ConfeccionFranela,tiempo_jersey,tiempo_pique,tiempo_franela); cout << endl;
    Cantidad_materia_prima(PesoTotal,MateriasPrimas);cout << endl;
    Ganancias_esperadas(Cantidades,MateriasPrimas); cout << endl;
    tiempo_jersey/=24;tiempo_pique/=24;tiempo_franela/=24;
    cout << "Fecha de entrega Jersey: "; Calendario_fecha_entrega(tiempo_jersey); cout << endl;
    cout << "Fecha de entrega Pique: "; Calendario_fecha_entrega(tiempo_pique); cout << endl;
    cout << "Fecha de entrega Pique: "; Calendario_fecha_entrega(tiempo_franela); cout << endl;

    if (tiempo_franela<tiempo_jersey && tiempo_franela <tiempo_pique)
        cout << "Se sugiere que primero se elabore la tiempo se demore en el proceso de confección Franela." << endl;
    else if (tiempo_jersey<tiempo_franela && tiempo_jersey <tiempo_pique)
        cout << "Se sugiere que primero se elabore la tiempo se demore en el proceso de confección Jersey." << tiempo_jersey << endl;
    else if (tiempo_pique<tiempo_jersey && tiempo_pique <tiempo_franela)
        cout << "Se sugiere que primero se elabore la tiempo se demore en el proceso de confección Pique." << tiempo_pique << endl;

    return 0;
}
