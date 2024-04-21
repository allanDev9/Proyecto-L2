#include <iostream>
#include "MenuFactura.h"
#include "MenuPrincipal.h"
#include "factura.h"
#include <locale>
using namespace std;

int main(){  
    
    setlocale(LC_ALL, "Spanish");
    MenuPrincipal menu;
    menu.mostrarMenu();
    
    return 0;
}