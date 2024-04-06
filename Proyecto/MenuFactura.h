#ifndef MENUFACTURA_H_INCLUDED
#define MENUFACTURA_H_INCLUDED

#include <iostream>
#include "factura.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

class MenuFactura{
	private:
    int contadorFacturas = 0;	
    public:
    void crearFactura(){
    	system("cls");
    	Factura nuevaFactura;
    	string nombre, apellido;
        int dia, mes, anio;
    	
    	cout<< setw(75) <<"Ingrese los datos de su factura";
    	cout<<"\n\n";
    	cout<< setw(63) <<"Ingrese su nombre: ";
    	cin>>nombre;
    	cout<< setw(65) <<"Ingrese su apellido: ";
    	cin>>apellido;
        cout<< setw(65) <<" Ingrese el dia (DD): ";
        cin>>dia;
        cout<< setw(65) <<" Ingrese el mes (MM): ";
        cin>>mes;
        cout<< setw(65) <<" Ingrese el año (YYYY): ";
        cin>>anio;

        string fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);

    	nuevaFactura.establecerDatos(nombre, apellido, fecha);
    	
    	contadorFacturas++;
    	string nombreArchivo = "Factura" + to_string(contadorFacturas) + ".txt";
    	
    	ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
              archivo<<setw(70)<<"Nombre: " << nombre << "\n"<<setw(72)<<"Apellido: "<< apellido<<setw(69)<< "Fecha: "<< fecha << endl;
              archivo.close();
              cout << endl<< setw(72) << "Factura creada exitosamente. " << endl;
              system("pause");
              system("cls");
            } else {  
                 cout << setw(75) << "No se pudo abrir el archivo para escribir.\n";
                 
         }
       
    }
    
    void mostrarContadorFacturas(){
			cout<< endl<< setw (62)<< "Se han creado "<< contadorFacturas << " factura. " <<endl;
	}
    
    void mostrarFacturas(){
    	
    	 if (contadorFacturas == 0) {
        cout << "No se ha creado ninguna factura.\n";
        return;
        
      }
      	system("cls");
      	cout<<"\n";
        mostrarContadorFacturas();
        cout << setw(75) << "Listado de facturas creadas: ";
        cout<<"\n";
        for (int i = 1; i <= contadorFacturas; i++) {
             cout<< endl << setw(61) << "Factura" << i << ".txt" << endl;
        }
        int numeroFactura;
        cout << setw(80) <<"Ingrese el numero de factura que desea ver: ";
        cin>>numeroFactura;
        system("cls");
        
        if(numeroFactura >= 1 && numeroFactura <= contadorFacturas){
        	abrirFactura(numeroFactura);
		}else{
			cout<< setw(75) <<"Numero factura no valido. "<<endl<<endl;
			system("pause");
			system("cls");
		}
    }
    void abrirFactura(int numeroFactura){
    	cout<< endl<< setw(73) <<"Factura # "<<contadorFacturas<<endl;
    	cout<<"\n";
    	string nombreArchivo = "Factura" + to_string(numeroFactura) + ".txt";
    	ifstream archivo(nombreArchivo);
    	if(archivo.is_open()){
    		string linea;
    		
            while (getline(archivo, linea)){
                cout<<linea<<endl;
            }

    		archivo.close();
    		cout<<"\n\n";
    		system("pause");
    		system("cls");
		}else{
			cout<< setw(50) <<"No se pudo abrir el archivo. "<<endl;
		}
        
    }
	void mostrarMenuFactura(){
        string entrada;
        int opcion=0;
        do{ 
            system("cls");
        	cout<< endl<< setw(64)<<"Menu Factura";
        	cout<<"\n";
            cout<< endl<<setw(61)<<"1. Factura";
            cout<< endl<<setw(65)<<"2. Ver factura";
            cout<< endl<<setw(62)<<"3. Regresar";
            cout<< endl<<setw(70)<<"4. Limpiar pantalla";
            cout<< endl<<setw(59)<<"5. Salir";
            cout<< endl<<endl<<setw(74)<<"Seleccione una opcion: ";
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
                    crearFactura();
                    break;

                case 2:
                    mostrarFacturas();
                    break;

                case 3:
                    system("cls");
                    return;
                    break;

                case 4:
                    system("cls");
                    break;

                case 5:
                    exit(0);
                    break;
                default:
                    break;
                }
              }
            }
        while (opcion!=5);
    }
};

#endif