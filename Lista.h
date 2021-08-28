#ifndef LISTA_H
#define LISTA_H
#include<string>
#include "Tipo_elemento.h"
#include<iostream>
using namespace std;
class Lista
{
	private:
		Tipo_elemento* valor;
		Lista* siguiente;//header, encabezamiento. El nodo que apunta hacia a1
		int posicion;
		
		bool equals(string,string);
	public:
		Lista();
		~Lista();
		void INSERTA(Tipo_elemento*,int,Lista*); //(elemento 'x' a ingresar, posicion, lista)
		int LOCALIZA(Tipo_elemento*,Lista*);
		Tipo_elemento* RECUPERA(int p, Lista* L);
		void SUPRIME(int,Lista*);
		int SIGUIENTE(int,Lista*);
		int ANTERIOR(int,Lista*);
		int ANULA(Lista*);
		int PRIMERO(Lista*);
		void IMPRIME_LISTA(Lista*);
		int FIN(Lista*);
	protected:
};

#endif