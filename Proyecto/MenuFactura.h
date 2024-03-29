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
    	
    	contadorFacturas++;
    	string nombreArchivo = "Factura" + to_string(contadorFacturas) + ".txt";
    	
    	ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
              archivo << "Nombre: " << nombre << "\nApellido: " << apellido << endl;
              archivo.close();
              cout << "Factura creada y guardada como " << nombreArchivo << endl;
            } else {
                 cout << "No se pudo abrir el archivo para escribir.\n";
         }
       
    }
    
    void mostrarContadorFacturas(){
			cout<<"Se han creado "<< contadorFacturas << "facturas. " <<endl;
	}
    
    void mostrarFacturas(){
    	
    	 if (contadorFacturas == 0) {
        cout << "No se ha creado ninguna factura.\n";
        return;
        
      }
        cout << "Listado de facturas creadas:\n";
        for (int i = 1; i <= contadorFacturas; i++) {
             cout << "Factura" << i << ".txt" << endl;
        }
        int numeroFactura;
        cout<<"Ingrese el numero de factura que desea ver: ";
        cin>>numeroFactura;
        
        if(numeroFactura >= 1 && numeroFactura <= contadorFacturas){
        	abrirFactura(numeroFactura);
		}else{
			cout<<"Numero factura no valido. ";
		}
	}
    
    
    void abrirFactura(int numeroFactura){
    	cout<<"\nFactura # "<<contadorFacturas<<endl;
    	cout<<"\n";
    	string nombreArchivo = "Factura" + to_string(numeroFactura) + ".txt";
    	ifstream archivo(nombreArchivo);
    	if(archivo.is_open()){
    		string linea;
    		while(getline(archivo, linea)){
    			cout<<linea<<endl;
			}
    		archivo.close();
		}else{
			cout<<"No se pudo abrir el archivo. "<<endl;
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
            
            case 5:
            	exit(0);
            	break;
            default:
                cout<<"Opcion no valida, intenta de nuevo. "<<endl;
                break;
            }
        }while (opcion!=5);
    }
};

#endif