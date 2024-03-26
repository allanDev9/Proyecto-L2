#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Factura{
    private:  //Atributos
        string nombre, apellido;

    public: //Metodos
        Factura(string, string);
        void mostrarNombre();
        void mostrarApellido();

};

Factura::Factura(string _nombre, string _apellido){
    nombre =  _nombre;
    apellido =  _apellido;
}

void Factura::mostrarNombre(){
    cout<<"Su nombre es "<<nombre<<endl;
}

void Factura::mostrarApellido(){
    cout<<"Mi apellido es "<<apellido<<endl;
}
#endif