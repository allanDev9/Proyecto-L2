#include <iostream>
#include "MenuFactura.h"
#include "MenuPrincipal.h"
#include "factura.h"

using namespace std;

int main(){
    MenuPrincipal menu;
    menu.mostrarMenu();

    MenuFactura menuFactura;
    menuFactura.mostrarMenuFactura();
    
    string nombre, apellido;

    cout<<"Ingrese su nombre: ";
    cin>>nombre;

    cout<<"Ingrese su apellido: ";
    cin>>apellido;
    cout<<"\n";
    Factura factura1(nombre, apellido);
    factura1.mostrarNombre();
    factura1.mostrarApellido();

    return 0;
}