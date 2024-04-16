#ifndef MENUJUEGODELUNO_H_INCLUDED
#define MENUJUEGODELUNO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>
#include <ctime>
#include <vector>
#include <sstream>
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
            system("cls");
        }
    while (!todasLasCartas.empty()) {
        // Seleccionar una carta aleatoria de la baraja
        int indiceCartaDeLaBaraja = rand() % todasLasCartas.size();
        string cartaDeLaBaraja = todasLasCartas[indiceCartaDeLaBaraja];
        string colorDeLaBaraja = cartaDeLaBaraja.substr(cartaDeLaBaraja.size() - 1, 1); // Supone que el último caracter es el color

        cout << "\n\nCarta de la baraja: " << cartaDeLaBaraja << endl;

        // Iterar sobre cada jugador
        for (int j = 0; j < 4; j++) {
            bool cartaEncontrada = false;

            cout << "\nCartas del jugador " << (j + 1) << ":" << endl;
            for (const string& carta : jugadores[j]) {
            cout << carta << " ";
        }
            cout << endl;

            for (auto it = jugadores[j].begin(); it != jugadores[j].end(); ++it) {
                string colorJugador = it->substr(it->size() - 1, 1);

                if (colorJugador == colorDeLaBaraja) {
                    cout << "Eliminando la carta del jugador: " << *it << endl;
                    jugadores[j].erase(it);
                    cartaEncontrada = true;
                    break;  // Solo eliminamos una carta a la vez
                }
            }

        if (!cartaEncontrada && !todasLasCartas.empty()) {
            int indiceNuevaCarta = rand() % todasLasCartas.size();
            jugadores[j].push_back(todasLasCartas[indiceNuevaCarta]);
            todasLasCartas.erase(todasLasCartas.begin() + indiceNuevaCarta);
            cout << "Una nueva carta ha sido añadida al jugador " << (j + 1) << ": " << jugadores[j].back() << endl;
        }

        system("pause"); // Pausa para permitir al usuario ver el cambio
        system("cls"); // Limpia la pantalla para el siguiente jugador
    }

    // Eliminar la carta de la baraja seleccionada
    todasLasCartas.erase(todasLasCartas.begin() + indiceCartaDeLaBaraja);
}
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
                cout << endl<< setw(83) <<"Opcion no valida, intentelo de nuevo. ";
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