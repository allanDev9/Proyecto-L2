#ifndef MENUFACTURA_H_INCLUDED
#define MENUFACTURA_H_INCLUDED

#include <iostream>
#include <string>
#include "MenuPrincipal.h"
using namespace std;

class MenuFactura{
    private:
        int menuFactura;
    public:
    void mostrarMenuFactura(){
        int opcion=0;
        do{
            cout<<"\n1. Factura";
            cout<<"\n2. Ver factura"<<endl;
            cout<<"3. Limpiar pantalla"<<endl;
            cout<<"4. Salir"<<endl;
            cout<<"\nSeleccione una opcion: ";
            cin>>opcion;

            switch (opcion){
            case 1:
                cout<<"Entrando a factura...";
                break;
            
            case 2:
                cout<<"Mostrando factura...";
                break;
            
            case 3:
                system("cls");
                break;

            case 4:
                cout<<"Saliendo del programa...";
                break;

            default:
                cout<<"Opcion no valida, intenta de nuevo. "<<endl;
                break;
            }
        }while (opcion!=4);

    }
};

#endif