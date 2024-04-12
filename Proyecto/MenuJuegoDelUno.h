#ifndef MENUJUEGODELUNO_H_INCLUDED
#define MENUJUEGODELUNO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

class MenuJuego{ 
    public:
    void inciarJuegoDelUno(){
        system("cls");
        string cartasStr = "1A,2A,3A,4A,5A,6A,7A,8A,9A,+2A,ReversaA,BloquearTurnoA,"
                        "1R,2R,3R,4R,5R,6R,7R,8R,9R,+2R,ReversaR,BloquearTurnoR,"
                        "1AM,2AM,3AM,4AM,5AM,6AM,7AM,8AM,9AM,+2AM,ReversaAM,BloquearTurnoAM,"
                        "1V,2V,3V,4V,5V,6V,7V,8V,9V,+2V,ReversaV,BloquearTurnoV,"
                        "+4_1,+4_2,+4_3,+4_4,CambioDeColor1,CambioDeColor2,CambioDeColor3,CambioDeColor4";

    vector<string> todasLasCartas;
    stringstream ss(cartasStr);
    string carta;
    while (getline(ss, carta, ',')){
        todasLasCartas.push_back(carta);
        }
        const int cartasPorJugador = 7;
        vector<string> jugadores[4];

    for (int j = 0; j < 4; j++){
        cout << "\n\nCartas del jugador " << (j + 1) << ":" << endl;
        for (int i = 0; i < cartasPorJugador; i++){
            int indiceCarta = rand() % todasLasCartas.size();           
            string carta = todasLasCartas[indiceCarta];                 
            jugadores[j].push_back(carta);                              
            todasLasCartas.erase(todasLasCartas.begin() + indiceCarta); 
            cout << carta << endl;                                   
           }
            system("pause");
        }
        while (!todasLasCartas.empty())
        {
            // Seleccionar una carta aleatoria de la baraja
            int indiceCartaDeLaBaraja = rand() % todasLasCartas.size();
            string cartaDeLaBaraja = todasLasCartas[indiceCartaDeLaBaraja];
            cout << "\n\nCarta de la baraja: " << cartaDeLaBaraja << endl;

            // Iterar sobre cada jugador
            for (int j = 0; j < 4; j++)
            {
                // Verificar si la carta de la baraja coincide con alguna carta de la mano del jugador
                auto it = find(jugadores[j].begin(), jugadores[j].end(), cartaDeLaBaraja);
                if (it != jugadores[j].end())
                {
                    cout << "La carta tirada coincide con una carta del jugador " << (j + 1) << ". Eliminando la carta del jugador." << endl;
                    jugadores[j].erase(it); // Eliminar la carta de la mano del jugador
                    break;                  // Pasar al siguiente jugador
                }
            }

            cout << "\nCartas del jugador"<< endl;
            for (const auto &carta : jugadores[0])
            {
                cout << carta << endl;
            }

            system("pause"); // Pausa antes de pasar al siguiente jugador

            // Eliminar la carta de la baraja seleccionada
            todasLasCartas.erase(todasLasCartas.begin() + indiceCartaDeLaBaraja);
        }

        system("pause");
    }
    void mostrarMenuJuego(){
        string entrada;
        int opcion;
        do
        {
            system("cls");
            cout << endl<< setw(72) << " Menu Juego Del Uno ";
            cout << "\n";
            cout << endl<< setw(61) << "1. Uno";
            cout << endl<< setw(66) << "2. Regresar";
            cout << endl<< setw(65) << "3. Limpiar";
            cout << endl<< setw(63) << "4. Salir";
            cout << endl<< endl<< setw(75) << "Seleccione una opcion: ";
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