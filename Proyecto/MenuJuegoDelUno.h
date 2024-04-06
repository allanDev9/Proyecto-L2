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
        int cartas[108] = {1A, 2A, 3A, 4A, 5A, 6A, 7A, 8A, 9A, +2A, ReversaA, BloquearTurnoA,
                            1R, 2R, 3R, 4R, 5R, 6R, 7R, 8R, 9R, +2R, ReversaR, BloquearTurnoR,
                            1AA, 2AA, 3AA, 4AA, 5AA, 6AA, 7AA, 8AA, 9AA, +2AA, ReversaAA, BloquearTurnoAA,
                            1V, 2V, 3V, 4V, 5V, 6V, 7V, 8V, 9V, +2V, ReversaV, BloquearTurnoV,
                            +4, +4, +4, +4};
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