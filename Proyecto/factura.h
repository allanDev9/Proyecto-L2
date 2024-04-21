#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Factura{
	private:
		string  fecha, descripcion, precio, cantidad, Producto;
		
	public:
		void establecerDatos(  string _fecha){
		
		fecha = _fecha;
		

	}
};

struct Producto : public Factura{
	string descripcion;
	int cantidad;
    float precio;
};

#endif