#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include "MenuFactura.h"
using namespace std;

class MenuPrincipal{
    public:
    	
void verFactura(){
    cout<<"Ingreso a la opcion de factura..."<<endl;
        MenuFactura menuFactura;
        menuFactura.mostrarMenuFactura();
 }
 void iniciarJuego(){
    cout<<"Iniciando juego..."<<endl;
}
void ejecutarLimpieza(){
    cout<<"Ejecutando limpieza..."<<endl;
}
void mostrarMenu(){
    int opcion=0;
    do{
        cout<<"\n Bienvenido ";
        cout<<"\n\n1. Factura"<<endl;
        cout<<"2. Juego Uno"<<endl;
        cout<<"3. Limpieza"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>opcion;

        switch (opcion){
        case 1:
            verFactura();
            break;
        
        case 2:
            iniciarJuego();
            break;
        
        case 3:
            ejecutarLimpieza();
            system("cls");
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