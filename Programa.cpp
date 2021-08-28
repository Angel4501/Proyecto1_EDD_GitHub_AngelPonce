#include <iostream>
using namespace std;
#include "Lista.h"
#include "Tipo_elemento.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();


int main(int argc, char** argv) {
	Lista* lista = new Lista();
	//INSERTA(x,p,L)  (tipo elemento x, posicion p, lista l)
	//Llenando la lista con elementos
	lista->INSERTA(new Tipo_elemento(30),1,lista); //30
	lista->INSERTA(new Tipo_elemento(3.14),2,lista); //30, 3.14
	lista->INSERTA(new Tipo_elemento('c'),1,lista); //c, 30, 3.14
	lista->INSERTA(new Tipo_elemento("hello world"),3,lista); //c, 30, hello world, 3.14
	
	//IMPRIME_LISTA(L)
	cout<<"Los elementos de la lista son: "<<endl;
	lista->IMPRIME_LISTA(lista);
	
	//SUPRIME(int p,lista)
	//Eliminando un elemento de la lista, por medio de la posicion
	lista->SUPRIME(2,lista);
	cout<<"\nMostrando la lista con elemento eliminado: "<<endl;
	lista->IMPRIME_LISTA(lista);
	
	//RECUPERA(int p, Lista)
	//Recuperar un valor por medio de la posicion
	cout<<"\nEn la posicion 3 se encuentra: ";
	cout<<lista->RECUPERA(3,lista)->getValue()<<endl;
	
	//LOCALIZA(tipo elemento, lista)
	//Devuelve la posicion del elemento en la lista
	cout<<"\nPosicion de un elemento de la lista..."<<endl;
	cout<<"'hello world' se encuentra en la posicion: "<<lista->LOCALIZA(new Tipo_elemento("hello world"),lista)<<endl;
	
	//PRIMERO(L)
	cout<<"\nLa posicion del primer elemento de la lista es "<<lista->PRIMERO(lista)<<endl;
	
	//SIGUIENTE(L)
	cout<<"\nSIGUIENTE(p,Lista) => La posicion siguiente a 1, [caracter 'c'] es: ";
	cout<<lista->SIGUIENTE(1,lista)<<endl;
	
	//ANTERIOR(L)
	cout<<"\nANTERIOR(p,Lista) => La posicion anterior a 2, [''hello world''] es: ";
	cout<<lista->ANTERIOR(2,lista)<<endl;
	
	//FIN(L)
	cout<<"\nFIN(L)\nEl valor de FIN(L) seria "<<lista->FIN(lista)<<endl;
	
	//ANULA(L)
	cout<<"\nANULA(L)"<<endl;
	lista->ANULA(lista);
	lista->IMPRIME_LISTA(lista);//Intento imprimir la lista, pero esta ya se encuentra vacía
	
	/*int a = 0;
	while(a!=8) {
		switch(a = menu()) {
			case 1: {
				int posicion = 0;//elemento; 
				string elemento;
				cout<<"Ingrese un valor/elemento para insertarlo en la lista: ";
				cin.ignore();
				getline(cin,elemento);
				//cin>>elemento;
				cout<<"Ingrese la posicion en la cual quiere ese elemento en la lista [1,2,3...etc]: ";
				cin>>posicion;
				lista->INSERTA(new Tipo_elemento(elemento),posicion,lista);
				break;
			}
			case 2: {//Eliminar elemento
				int p = 0;
				cout<<"Ingrese posicion del elemento a eliminar: "<<endl;
				cin>>p;
				lista->SUPRIME(p,lista);
				break;
			}
			case 3: { //Print lista
				lista->IMPRIME_LISTA(lista);
				break;
			}
			case 4: {//Buscar un elemento, RECUPERA
				int p = 0;
				cout<<"Ingrese la posicion del elemento a recuperar de la lista: ";
				cin>>p;
				cout<<lista->RECUPERA(p,lista)->getValue()<<endl;
				break;
			}
			case 5: {
				string elemento;
				//int elemento;
				cout<<"Ingrese el elemento/valor que desea conocer su posicion en la lista: ";
				cin.ignore();
				getline(cin,elemento);
				//cin>>elemento;
				cout<<lista->LOCALIZA(new Tipo_elemento(elemento),lista)<<endl;
				
				break;
			}
			case 6: {
				cout<<"Vaciando lista..."<<endl;
				lista->ANULA(lista);
				break;
			}
			case 7: {
				cout<<"Posicion del primer elemento de la lista: "<<lista->PRIMERO(lista)<<endl;
				break;
			}
			case 8: {
				cout<<"Salió con éxito..."<<endl;
				break;
			}
		}	
	}*/
	return 0;
}

int menu() { //funcion menu
	int opc=0;
	while(opc!=8) {
		cout<<"|MENU|"<<endl
		    <<"1. Insertar elemento a la lista"<<endl
		    <<"2. Eliminar elemento de la lista"<<endl
		    <<"3. Imprimir lista"<<endl
		    <<"4. Buscar un elemento de la lista ingresando la posicion"<<endl
		    <<"5. Obtener la poscion de un elemento de la lista"<<endl
		    <<"6. Vaciar lista"<<endl
		    <<"7. Obtener la posicion del primer elemento de la lista"<<endl
		    <<"8. Salir del menu"<<endl
		    <<"Opcion: ";
		cin>>opc;
		if(opc>=1&&opc<=8) {
			break;
		} 
		else {
			cout<<"Opcion no valida, ingresela nuevamente..."<<endl;
		}
	}
	return opc;
}//fin de la funcion menu