#ifndef MENUFACTURA_H_INCLUDED
#define MENUFACTURA_H_INCLUDED

#include <iostream>
#include "factura.h"
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class MenuFactura{
	private:
		int contadorFacturas = 0;	
    public:
    void crearFactura(){
    	Factura nuevaFactura;
    	string nombre, apellido;
    	
    	cout<<"\nIngrese su nombre: ";
    	cin>>nombre;
    	
    	cout<<"\nIngrese su apellido: ";
    	cin>>apellido;
    	
    	nuevaFactura.establecerDatos(nombre, apellido);
    	
    	cout<<"\nFactura creada exitosamente. "<<endl;
    	ofstream archivo;
        archivo.open("1.Factura.txt",ios::out);
        archivo<<nombre<<endl<<apellido;
    }
    
    void mostrarContadorFacturas(){
    	ofstream archivo;
    	if (contadorFacturas == 0){
    		cout<<"No se ha creado ninguna factura. "<<endl;
		}
		else if(contadorFacturas == 1){
			cout<<"Se ha creador 1 Factura. "<<endl;
		}
		else{
			cout<<"Se han creado "<<contadorFacturas<< " facturas. "<<endl;
		}
	}
    void mostrarMenuFactura(){
        int opcion=0;
        do{
            cout<<"\n1. Factura";
            cout<<"\n2. Ver factura"<<endl;
            cout<<"3. Regresar"<<endl;
            cout<<"4. Limpiar pantalla"<<endl;
            cout<<"5. Salir"<<endl;
            cin>>opcion;
            
            switch (opcion){
            case 1:
            	cout<<"\nIngresa los datos de su factura"<<endl;
            	crearFactura();
                break;
                
            case 2:
                cout<<"Mostrando factura...";
                mostrarContadorFacturas();
                break;
            
            case 3:
            	return;
                break;

            case 4:
                system("cls");
                break;
                
            default:
                cout<<"Opcion no valida, intenta de nuevo. "<<endl;
                break;
            }
        }while (opcion!=5);
		exit(0);
    }
};

#endif