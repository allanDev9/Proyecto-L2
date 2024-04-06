#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include "MenuFactura.h"
#include "MenuJuegoDelUno.h"
#include <iomanip>
using namespace std;

class MenuPrincipal{
    public:
void verFactura(){
	system("cls");
    MenuFactura menuFactura;
    menuFactura.mostrarMenuFactura();
 }
 void verJuegoDelUno(){
    system("cls");
    MenuJuego menujuego;
    menujuego.mostrarMenuJuego();
}
void mostrarMenu(){
    string entrada;
    int opcion;
    do{
        system("cls");
        cout<< endl<<setw(64)<<" Menu Principal ";
        cout<<"\n";
        cout<< endl<< setw(61)<<"1. Factura";
        cout<< endl<< setw(63)<<"2. Juego Uno";
        cout<< endl<<setw(62)<<"3. Limpieza";
        cout<< endl<< setw(59)<<"4. Salir";
        cout<<endl<<endl<< setw(74) <<"Seleccione una opcion: ";
        cin>>entrada;

        bool esValido = false;

        if (entrada.length() == 1)
        { 
            int codigoAscii = entrada[0];
            if (codigoAscii >= '1' && codigoAscii <= '4')
            {
                opcion = codigoAscii - '0'; 
                esValido = true;
            }
        }

        if (!esValido)
        {
            cout <<endl<< setw(83) << "Opcion no valida, intentelo de nuevo. ";
            cout << "\n";
            system("pause");
            opcion = 0;
        }
        else{
            switch (opcion){
            case 1:
                verFactura();
                break;

            case 2:
                verJuegoDelUno();
                break;

            case 3:
                system("cls");
                break;

            case 4:
                exit(0);
                break;

            default:
                break;
            }
          }
        }
      while (opcion!=4);
     
   }
};

#endif