#ifndef MENUFACTURA_H_INCLUDED
#define MENUFACTURA_H_INCLUDED

#include <iostream>
#include "factura.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;

class MenuFactura{
	private:
    int contadorFacturas = 0;	
    public:
    void crearFactura(){
    	system("cls");
    	Factura nuevaFactura;
    	string nombre, apellido, descripcion;
        int dia, mes, anio, Cantidad;
    	float precioTotal=0;

        
    cout<< setw(75) <<"Ingrese los datos de su factura";
    cout<<"\n\n";

    while(true){
        cout << setw(63) << "Ingrese su primer nombre: ";
        getline(cin, nombre);
        if (nombre.empty() || nombre.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< setw(90)<< "Nombre inválido, solo se permiten letras y espacios. Intente de nuevo: ";
            cout<<"\n";
            system("pause");
            system("cls");
        } else {
            break;
        }
    } 

    // Ingreso y validación del apellido
    system("cls");
    while(true){
        cout << setw(65) << "Ingrese su primer apellido: ";
        getline(cin, apellido);
        if (apellido.empty() || apellido.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< setw(90)<< "Apellido inválido, solo se permiten letras y espacios. Intente de nuevo: ";
            cout<<"\n";
            system("pause");
            system("cls");
        } else {
            break;
        }
    } 

    system("cls");
        
        while (true) {
        cout << setw(65) << "Ingrese el día (DD): ";
        cin >> dia;
        if (cin.fail() || dia < 1 || dia > 31) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << endl << setw(75) << "Entrada inválida. Por favor, ingrese un número válido para el día (1-31).";
            cout<<"\n";
            system("pause");
            system("cls");
        } else {
            break; // Salir del bucle si la entrada es válida
        }
    }

    // Validación del mes
    while (true) {
        system("cls");
        cout << setw(65) << "Ingrese el mes (MM): ";
        cin >> mes;
        if (cin.fail() || mes < 1 || mes > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << setw(75)<< "Entrada inválida. Por favor, ingrese un número válido para el mes (1-12).";
            cout<<"\n";
            system("pause");
            system("cls");
        } else {
            break;
        }
    }

    // Validación del año
    while (true) {
        system("cls");
        cout << setw(65) << "Ingrese el año (YYYY): ";
        cin >> anio;
        if (cin.fail() || anio < 1900 || anio > 2024) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << setw(75)<< "Entrada inválida. Por favor, ingrese un número válido para el año (1900-2024).";
            cout<<"\n";
            system("pause");
            system("cls");
        } else {
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
    
        
        
        cout<< setw(80) <<"Ingrese la cantidad de productos que desea adquirir: ";
        cin>>Cantidad;
        system("cls");
       
        Producto* productos = new Producto[Cantidad];

        cin.ignore();

        for (int i = 0; i < Cantidad; i++){
            cout<<"Ingrese el nombre del producto " << (i + 1) << ": ";
            cin>>productos[i].descripcion;
            system("cls");
            cout<<"Ingrese la cantidad de " << productos[i].descripcion <<": ";
            cin>> productos[i].cantidad;
            system("cls");
            cout<<"Ingrese el precio de " << productos[i].descripcion <<": ";
            cin>> productos[i].precio;
            system("cls");
            cin.ignore();
            precioTotal += productos[i].precio * productos[i].cantidad;
            system("cls");
        }
        
        string fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
        
    	contadorFacturas++;
    	string nombreArchivo = "Factura" + to_string(contadorFacturas) + ".txt";
    	
    	ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
              archivo<<setw(70)<<"Nombre: " << nombre << "\n"
                    <<setw(72)<<"Apellido: "<< apellido
                    <<setw(69)<< "Fecha: "<< fecha;

            for (int i = 0; i < Cantidad; i++){
                archivo<< "\nProducto: " << productos[i].descripcion
                       << "\nCantidad: " << productos[i].cantidad
                       << "\nPrecio: " << fixed << setprecision(2) << productos[i].precio;
                }
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
        	cout<< endl<< setw(67)<<"Menu Factura";
        	cout<<"\n";
            cout<< endl<<setw(66)<<"1. Factura";
            cout<< endl<<setw(70)<<"2. Ver factura";
            cout<< endl<<setw(67)<<"3. Regresar";
            cout<< endl<<setw(75)<<"4. Limpiar pantalla";
            cout<< endl<<setw(64)<<"5. Salir";
            cout<< endl<<endl<<setw(75)<<"Seleccione una opcion: ";
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