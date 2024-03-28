#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Factura{
	private:
		string nombre, apellido;
		
	public:
	void establecerDatos(string _nombre, string _apellido){
		
		nombre = _nombre; 
		apellido = _apellido;
		
	}
	void mostrarDatos(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;

    }
};
#endif