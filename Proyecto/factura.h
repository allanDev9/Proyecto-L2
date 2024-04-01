#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Factura{
	private:
		string nombre, apellido;
		int fecha;
		
	public:
	void establecerDatos(string _nombre, string _apellido, int _fecha){
		
		nombre = _nombre; 
		apellido = _apellido;
		fecha = _fecha;

		
	}
};
#endif