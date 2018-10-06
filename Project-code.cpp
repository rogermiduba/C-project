//Proyecto
#include <iostream>
#include <iomanip>
using namespace std;

void Input_data(int Cantidades[3][3], float Pesos[3][3], float PesoTotal[3][3])
{
    cout<< "Polos Jersey: ";cin >> Cantidades[0][0]; cout << "Peso(kg)/prenda - Polos Jersey: ";cin >> Pesos[0][0];
    cout<< "Camisas Jersey: ";cin >> Cantidades[0][1]; cout << "Peso(kg)/prenda - Camisas Jersey: ";cin >> Pesos[0][1];
    cout<< "Cuellos Jersey: ";cin >> Cantidades[0][2]; cout << "Peso(kg)/prenda - Cuellos Jersey: " ;cin >> Pesos[0][2];
    cout<< endl;
    cout<< "Polos Pique: ";cin >> Cantidades[1][0]; cout << "Peso(kg)/prenda - Polos Pique: ";cin >> Pesos[1][0];
    cout<< "Camisas Pique: ";cin >> Cantidades[1][1]; cout << "Peso(kg)/prenda - Camisas Pique: ";cin >> Pesos[1][1];
    cout<< "Cuellos Pique: ";cin >> Cantidades[1][2]; cout << "Peso(kg)/prenda - Cuellos Pique: ";cin >> Pesos[1][2];
    cout <<endl;
    cout<< "Polos Franela: ";cin >> Cantidades[2][0]; cout << "Peso(kg)/prenda - Polos Franela: ";cin >> Pesos[2][0];
    cout<< "Camisas Franela: ";cin >> Cantidades[2][1]; cout << "Peso(kg)/prenda - Camisas Franela: ";cin >> Pesos[2][1];
    cout<< "Cuellos Franela: ";cin >> Cantidades[2][2]; cout << "Peso(kg)/prenda - Cuellos Franela: ";cin >> Pesos[2][2];
    cout << endl;
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            PesoTotal[i][j]=Cantidades[i][j]*Pesos[i][j];
    return;
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
    Input_data(Cantidades,Pesos,PesoTotal);
    }
    return 0;
}
