#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <iostream>
#include <string>
#include "MenuFactura.h"
using namespace std;

class MenuPrincipal{
    public:
        MenuPrincipal(){

    }
 
void verFactura(){
    cout<<"Mostrando factura..."<<endl;
    MenuFactura MenuFactura;
    MenuFactura.mostrarMenuFactura();
}
void iniciarJuego(){
    cout<<"Iniciando juego..."<<endl;
}
void ejecutarLimpieza(){
    cout<<"Ejecutando limpieza..."<<endl;
    system("cls");
}
void mostrarMenu(){
    int opcion=0;
    do{
        cout<<"\nMenu principal";
        cout<<"\n1. Factura"<<endl;
        cout<<"2. Juego Uno"<<endl;
        cout<<"3. Limpieza"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"\nSelecciona una opcion: ";
        cin>>opcion;

        switch (opcion){
        case 1:
             cout<<"Entrando a factura...";
            break;
        
        case 2:
            iniciarJuego();
            break;
        
        case 3:
            ejecutarLimpieza();
            break;
        
        case 4:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Opcion no valida, intentelo de nuevo. "<<endl;
            break;
        
        }

      } while (opcion!=4);
   
   }

};

#endif