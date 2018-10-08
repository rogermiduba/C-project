//Proyecto
#include <iostream>
#include <iomanip>
using namespace std;

const int jersey = 0; const int pique = 1; const int franela = 2;
const float tiempo_tejido=1.0; const float tiempo_tenido=10.0;
const float tiempo_acabado=20.0;

float Input_data(int Cantidades[3][3], float Pesos[3][3], float PesoTotal[3][3])
{
    cout<< "Polos Jersey: ";cin >> Cantidades[jersey][0]; cout << "Peso(kg)/prenda - Polos Jersey: ";cin >> Pesos[jersey][0];
    cout<< "Camisas Jersey: ";cin >> Cantidades[jersey][1]; cout << "Peso(kg)/prenda - Camisas Jersey: ";cin >> Pesos[jersey][1];
    cout<< "Cuellos Jersey: ";cin >> Cantidades[jersey][2]; cout << "Peso(kg)/prenda - Cuellos Jersey: " ;cin >> Pesos[jersey][2];
    cout<< endl;
    cout<< "Polos Pique: ";cin >> Cantidades[pique][0]; cout << "Peso(kg)/prenda - Polos Pique: ";cin >> Pesos[pique][0];
    cout<< "Camisas Pique: ";cin >> Cantidades[pique][1]; cout << "Peso(kg)/prenda - Camisas Pique: ";cin >> Pesos[pique][1];
    cout<< "Cuellos Pique: ";cin >> Cantidades[pique][2]; cout << "Peso(kg)/prenda - Cuellos Pique: ";cin >> Pesos[pique][2];
    cout <<endl;
    cout<< "Polos Franela: ";cin >> Cantidades[franela][0]; cout << "Peso(kg)/prenda - Polos Franela: ";cin >> Pesos[franela][0];
    cout<< "Camisas Franela: ";cin >> Cantidades[franela][1]; cout << "Peso(kg)/prenda - Camisas Franela: ";cin >> Pesos[franela][1];
    cout<< "Cuellos Franela: ";cin >> Cantidades[franela][2]; cout << "Peso(kg)/prenda - Cuellos Franela: ";cin >> Pesos[franela][2];
    cout << endl;
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            PesoTotal[i][j]=Cantidades[i][j]*Pesos[i][j];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << setw(5) << PesoTotal[i][j];}
            cout << endl;}

    return PesoTotal[3][3];
}

float Calculo_tiempos(float PesoTotal[3][3])
{float tiempo_jersey=0,tiempo_pique=0,tiempo_franela=0;
  
float ConfeccionPrendasJersey[3]={0.2,0.5,0.05};//{polos,camisas,cuellos}
float ConfeccionPrendasPique[3]={0.22,0.33,0.04};//{polos,camisas,cuellos}
float ConfeccionPrendasFranela[3]={0.25,0.5,0.05};//{polos,camisas,cuellos}

for (size_t i=0;i<3;i++){
  tiempo_jersey+=PesoTotal[jersey][i]*tiempo_tejido*tiempo_tenido*tiempo_acabado*ConfeccionPrendasJersey[i];}

for (size_t i=0;i<3;i++){
  tiempo_pique+=PesoTotal[pique][i]*tiempo_tejido*tiempo_tenido*tiempo_acabado*ConfeccionPrendasPique[i];}

for (size_t i=0;i<3;i++){
  tiempo_franela+=PesoTotal[franela][i]*tiempo_tejido*tiempo_tenido*tiempo_acabado*ConfeccionPrendasFranela[i];}

cout << "El tiempo de producción de Jersey es: " << tiempo_jersey/24 << " días." << endl;
cout << "El tiempo de producción de Pique es: " << tiempo_pique/24 << " días." << endl;
cout << "El tiempo de producción de Franela es: " << tiempo_franela/24 << " días." << endl;

return tiempo_jersey,tiempo_pique,tiempo_franela;
}

float Cantidad_materia_prima(float PesoTotal[3][3]){
 
  for(int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      cout << setw(5) << PesoTotal[i][j];}
      cout << endl;}

  float MateriaPrimaJersey=0,MateriaPrimaPique=0, MateriaPrimaFranela=0;
  
  for (int i=0;i<3;i++)   
      MateriaPrimaJersey+=PesoTotal[jersey][i];

  for (int i=0;i<3;i++)
      MateriaPrimaPique+=PesoTotal[pique][i];
  
  for (int i=0;i<3;i++)   
    MateriaPrimaFranela+=PesoTotal[franela][i];    

  cout << "La materia prima es " << MateriaPrimaJersey/0.7 << "Kg de hilo para Jersey." << endl ;
  cout << "La materia prima es " << MateriaPrimaPique/0.5 << "Kg de hilo para Pique." << endl ;
  cout << "La materia prima es " << MateriaPrimaFranela/0.3 << "Kg de hilo para Franela." << endl ;

  return MateriaPrimaJersey, MateriaPrimaPique, MateriaPrimaFranela;
}

int main()
{
  int Cantidades[3/*Telas*/][3/*Prendas*/] = {
        {0,0,0},//Jersey
        {0,0,0},//Pique
        {0,0,0} //Franela
        //{Polos,Camisas,Cuellos}
    }; 
    float Pesos[3/*Telas*/][3/*Prendas*/];
    float PesoTotal[3][3];

    Input_data(Cantidades,Pesos,PesoTotal); cout << endl;
    Calculo_tiempos(PesoTotal); cout << endl;
    Cantidad_materia_prima(PesoTotal);    

    return 0;
}
