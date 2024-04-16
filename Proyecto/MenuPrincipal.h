#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED
 
#include <iostream>
#include <cstdlib>
#include <string>
#include "MenuFactura.h"
#include "MenuJuegoDelUno.h"
#include <locale.h>
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
    MenuJuego menuJuego;
    menuJuego.mostrarMenuJuego();
}
void mostrarMenu(){
    string entrada;
    int opcion;
    do{
        system("cls");
        cout<< endl<<setw(70)<<" Menu Principal ";
        cout<<"\n";
        cout<< endl<< setw(66)<<"1. Factura";
        cout<< endl<< setw(68)<<"2. Juego Uno";
        cout<< endl<<setw(67)<<"3. Limpieza";
        cout<< endl<< setw(64)<<"4. Salir";
        cout<<endl<<endl<< setw(75) <<"Seleccione una opcion: ";
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
                system("cls");
                cout<< endl << endl <<setw(85)<< "Proyecto Lenguaje De Programacion 2"
                    << endl << setw(63) <<"Grupo #4"
                    << endl << setw(68) <<"Integrantes: "
                    << endl << setw(77)<<"Allan Noé Peña Guerra  20222030732"
                    << endl << setw(83)<<"Marvin Noel Valladares Nuñez  20222000861"
                    << endl << setw(81)<<"Helman Samir Lopez Antunez   20212030464"
                    << endl << setw(85)<<"Dennis Antonio Peña Hernandez   20222000874";
                system("pause");
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