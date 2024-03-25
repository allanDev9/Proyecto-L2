#include <iostream>
#include "factura.h"

using namespace std;

int main(){
    string nombre, apellido;

    cout<<"Ingrese su nombre: ";
    cin>>nombre;

    cout<<"Ingrese su apellido: ";
    cin>>apellido;
    cout<<"\n";
    Factura factura1(nombre, apellido);
    factura1.mostrarNombre();
    factura1.mostrarApellido();
}