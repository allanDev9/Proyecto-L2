#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include "MenuFactura.h"
#include <iomanip>
using namespace std;

class MenuPrincipal{
    public:
    	
void verFactura(){
	system("cls");
        MenuFactura menuFactura;
        menuFactura.mostrarMenuFactura();
 }
 void iniciarJuego(){
    cout<<"Iniciando juego..."<<endl;
}
void mostrarMenu(){
    int opcion=0;
    do{
        cout<< setw(61)<< " Bienvenido ";
        cout<<"\n";
        cout<< endl<<setw(64)<<" Menu Principal ";
        cout<<"\n";
        cout<< endl<< setw(61)<<"1. Factura";
        cout<< endl<< setw(63)<<"2. Juego Uno";
        cout<< endl<<setw(62)<<"3. Limpieza";
         cout<< endl<< setw(59)<<"4. Salir";
        cout<<endl<<endl<< setw(74) <<"Seleccione una opcion: ";
        cin>>opcion;

        switch (opcion){
        case 1:
            verFactura();
            break;
        
        case 2:
            iniciarJuego();
            break;
        
        case 3:
            system("cls");
            break;
        
        case 4:
        	exit(0);
        	break;
        	
        default:
            cout<<"Opcion no valida, intentelo de nuevo. "<<endl;
            break;
        
        }

      } while (opcion!=4);
   		exit(0);
   }

};

#endif