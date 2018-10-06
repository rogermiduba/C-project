//Proyecto
#include <iostream>
using namespace std;

void Input_data(Cantidades[3][3], Pesos[3][3])
{
    float cantidadpolosjersey, cantidadpolospique,cantidadpolosfranela,cantidadcamisasjersey,cantidadcamisaspique,cantidadcamisasfranela,cantidadcuellosjersey, cantidadcuellospique,cantidadcuellosfranela,kgpolosjersey,kgpolospique,kgpolosfranela,kgcamisasjersey,kgcamisaspique,kgcamisasfranela,kgcuellosjersey, kgcuellospique,kgcuellosfranela;

cout<< "Polos Jersey:";cin >> cantidadpolosjersey; cout << "kg/prenda:";cin >> kgpolosjersey;
cout<< "Camisas Jersey:";cin >> cantidadcamisasjersey; cout << "Kg/prenda:";cin >> kgcamisasjersey;
cout<< "Cuellos Jersey:";cin >> cantidadcuellosjersey; cout << "Kg/prenda";cin >> kgcuellosjersey;
cout<< endl;
cout<< "Polos Pique:";cin >> cantidadpolospique; cout << "Kg/prenda:";cin >> kgpolospique;
cout<< "Camisas Pique:";cin >> cantidadcamisaspique; cout << "Kg/prenda:";cin >> kgcamisaspique;
cout<< "Cuellos Pique:";cin >> cantidadcuellospique; cout << "Kg/prenda:";cin >> kgcuellospique;
cout <<endl;
cout<< "Polos Franela:";cin >> cantidadpolosfranela; cout << "Kg/prenda:";cin >> kgpolosfranela;
cout<< "Camisas Franela:";cin >> cantidadcamisasfranela; cout << "Kg/prenda:";cin >> kgcamisasfranela;
cout<< "Cuellos Franela:";cin >> cantidadcuellosfranela; cout << "Kg/prenda:";cin >> kgcuellosfranela;
cout << endl;
}

int main()
{
    int Cantidades[3/*Telas*/][3/*Prendas*/] = {
        {0,0,0},//Jersey
        {0,0,0},//Pique
        {0,0,0} //Franela
//{Polos,Camisas,Cuellos}
    };
    
    
    float Pesos[3/*Telas*/][3/*Prendas*/] = {
        {0,0,0},//Jersey
        {0,0,0},//Pique
        {0,0,0} //Franela
//{Polos,Camisas,Cuellos}
    };
    
    
    return 0;
}
