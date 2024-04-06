#ifndef MENUJUEGODELUNO_H_INCLUDED
#define MENUJUEGODELUNO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>
using namespace std;

class MenuJuego{
    private:
    
    public:
    void inciarJuegoDelUno(){

    }

    void mostrarMenuJuego(){
        string entrada;
        int opcion;
        do
        {
            system("cls");
            cout << endl<< setw(69) << " Menu Juego Del Uno ";
            cout << "\n";
            cout << endl<< setw(61) << "1. Uno";
            cout << endl<< setw(66) << "2. Regresar";
            cout << endl<< setw(65) << "3. Limpiar";
            cout << endl<< setw(63) << "4. Salir";
            cout << endl<< endl<< setw(74) << "Seleccione una opcion: ";
            cin >> entrada;

            bool esValido = false;

            if (entrada.length() == 1)
            {
                int codigoAscii = entrada[0];
                if (codigoAscii >= '1' && codigoAscii <= '4'){
                    opcion = codigoAscii - '0';
                    esValido = true;
                }
            }

            if (!esValido){
                cout << endl<< setw(83) << "Opcion no valida, intentelo de nuevo. ";
                cout << "\n";
                system("pause");
                opcion = 0;
            }
            else{
                switch (opcion){
                case 1:
                    inciarJuegoDelUno();
                    break;

                case 2:
                    system("cls");
                    return;
                    break;

                case 3:
                    system("cls");
                    break;

                case 4:
                    exit(0);
                    break;

                default:
                    break;
                }
            }
        } while (opcion != 4);
    }
};
#endif