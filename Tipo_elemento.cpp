#include "Tipo_elemento.h"

Tipo_elemento::Tipo_elemento(string cad) {
	s = cad;
}

Tipo_elemento::Tipo_elemento(int entero){
	x = entero;
	ostringstream out;
	out << x;
	s = out.str();
}

Tipo_elemento::Tipo_elemento(double real){
	d = real;
	ostringstream out;
	out << d;
	s = out.str();
}

Tipo_elemento::Tipo_elemento(char caracter){
	c = caracter;
	s+=c;
}

Tipo_elemento::~Tipo_elemento() {
}

string Tipo_elemento::getValue() {
	return s;
}

