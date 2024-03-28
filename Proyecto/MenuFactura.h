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
    	
    	string nombreArchivo = "Factura" + to_string(contadorFacturas++) + ".txt";
    	
    	ofstream archivo(nombreArchivo.c_str(), ios::out);
        if(archivo.is_open()){
        archivo<<nombre<<endl<<apellido;
        archivo.close();
        
        }
        
        cout<<"\nFractura creada exitosamente. "<<endl;
    }
    
    void mostrarContadorFacturas(){
			cout<<"Se han creado "<< contadorFacturas << "facturas. " <<endl;
	}
    
    void mostrarFacturas(){
    	if (contadorFacturas == 0){
    		cout<<"No se ha creado ninguna factura. "<<endl;
    		return ;
		}
		cout<<"Listado de facturas creadas. "<<endl;
		for(int i = 0; i < contadorFacturas; i++){
            cout<<"Factura "<< i+1 <<endl;
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
            	cout<<"\nIngrese los datos de su factura"<<endl;
            	crearFactura();
                break;
                
            case 2:
                cout<<"\nLista de facturas creadas: "<<endl;
                mostrarFacturas();
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