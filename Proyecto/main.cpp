#include <iostream>
#include "MenuFactura.h"
#include "MenuPrincipal.h"
#include "factura.h"
#include <wchar.h>
 
using namespace std;

int main(){  
    setlocale(LC_ALL, "");
    MenuPrincipal menu;
    menu.mostrarMenu();
    
    return 0;
}