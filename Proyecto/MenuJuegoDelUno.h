#ifndef MENUJUEGODELUNO_H_INCLUDED
#define MENUJUEGODELUNO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>
#include <ctime>
using namespace std;

class MenuJuego{
    public:
    void inciarJuegoDelUno(){
        string cartas = "1A , 2A, 3A, 4A, 5A, 6A, 7A, 8A, 9A, +2A, ReversaA, BloquearTurnoA,"
                        "1R, 2R, 3R, 4R, 5R, 6R, 7R, 8R, 9R, +2R, ReversaR, BloquearTurnoR,"
                        "1AM, 2AM, 3AM, 4AM, 5AM, 6AM, 7AM, 8AM, 9AM, +2AM, ReversaAM, BloquearTurnoAM,"
                        "1V, 2V, 3V, 4V, 5V, 6V, 7V, 8V, 9V, +2V, ReversaV, BloquearTurnoV,"
                        "+4_1, +4_2, +4_3, +4_4, CambioDeColor1, CambioDeColor2, CambioDeColor3, CambioDeColor4";
        
        string jugadorUno[7];

    srand(time(NULL));
    for (int i = 0; i < 7; i++){
        int indiceCarta = rand()% cartas.size();
        jugadorUno[i]=cartas.substr(0, indiceCarta);
        cartas.erase(0, indiceCarta + 1);
    }
    cout<<"Cartas del jugador uno: "<<endl;
    for(const auto& cartas : jugadorUno){
        cout<< cartas <<endl;
       }
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