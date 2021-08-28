#include "Lista.h"

Lista::Lista()
{
	siguiente = NULL;
}

Lista::~Lista()
{
}

void Lista::INSERTA(Tipo_elemento* elemento, int posicion, Lista* lista){//(elemento 'x' a ingresar, posicion, lista)
	if(posicion == 1){
		if(lista->siguiente==NULL){
			Lista* nuevo_nodo = new Lista();
			lista->siguiente = nuevo_nodo; //head apunta hacia a1
			nuevo_nodo->siguiente = NULL;
			nuevo_nodo->valor = elemento;
			nuevo_nodo->posicion = 1;
		}
		else{
			
			Lista* nuevo = new Lista();
			nuevo->siguiente = lista->siguiente;
			lista->siguiente = nuevo;
			nuevo->valor = elemento;
			nuevo->posicion = 1;
				
			Lista* temp = new Lista();
			temp = nuevo->siguiente;
			while(temp!=NULL){
				temp->posicion = temp->posicion+1;
				temp = temp->siguiente;
			}

		}
	}//Fin del if(posicion == 1)
	else if(posicion==FIN(lista)){
		Lista* temp = new Lista();
		temp = lista->siguiente;
		while(temp!=NULL){
			if(temp->posicion==posicion-1){
				Lista* nuevo = new Lista();
				nuevo->valor = elemento;
				nuevo->posicion = temp->posicion+1;
				temp->siguiente = nuevo;
				nuevo->siguiente = NULL;
				break;
			}
			else{
				temp = temp->siguiente;
			}
		}
	}
	else if(posicion<1 || posicion>FIN(lista)){
		cout<<"No se inserto ningun elemento, posicion no valida..."<<endl;
	}
	else{
		Lista* temp = new Lista();
		temp = lista->siguiente; //guardando a1
		while(temp!=NULL){
			if(temp->posicion == posicion-1){
				Lista* nuevo = new Lista();
				nuevo->siguiente = temp->siguiente;
				nuevo->valor = elemento;
				nuevo->posicion = temp->posicion+1;
				temp->siguiente = nuevo;
				
				Lista* finish = new Lista();
				finish = nuevo->siguiente;
				int aux = 0;
				while(finish!=NULL){
					finish->posicion = finish->posicion+1;
					finish = finish->siguiente;
					aux=1;
				}
				if(aux==1){
					break;
				}
			}
			else{
				temp = temp->siguiente;
			}
		}
		
	}
	
}

int Lista::LOCALIZA(Tipo_elemento* x, Lista* L){
	Lista* temp = new Lista();
	temp = L->siguiente;
	while(temp!=NULL){
		if( equals(temp->valor->getValue(),x->getValue()) ){
			return temp->posicion;
		}
		else{
			temp = temp->siguiente;
		}
	}
	return FIN(L);
}


Tipo_elemento* Lista::RECUPERA(int p, Lista* L){
	Lista* temp = new Lista();
	temp = L->siguiente;
	while(temp!=NULL){
		if(temp->posicion==p){
			return temp->valor;
		}
		else{
			temp = temp->siguiente;
		}
	}
	Tipo_elemento* tp = NULL;
	return tp; //No esta definido, si p<1, o si p>=FIN(L)
}

void Lista::SUPRIME(int p,Lista* L){
	if(p==1){
		Lista* temp = L->siguiente->siguiente;
		L->siguiente = NULL;
		L->siguiente = temp;
		while(temp!=NULL){
			temp->posicion = temp->posicion-1;
			temp = temp->siguiente;
		}
	}
	else if(p==FIN(L)-1){
		Lista* temp = L->siguiente;
		while(temp!=NULL){
			if(temp->posicion==p-1){
				temp->siguiente = NULL;
				break;
			}
			else{
				temp = temp->siguiente;
			}
		}
	}
	else{
		Lista* temp = L->siguiente;
		while(temp!=NULL){
			if(temp->posicion==p-1){
				Lista* nuevo = temp->siguiente->siguiente;
				temp->siguiente = nuevo;
				
				int aux = 0;
				while(nuevo!=NULL){
					nuevo->posicion = nuevo->posicion-1;
					nuevo = nuevo->siguiente;
					aux=1;
				}
				if(aux==1){
					break;
				}
			}
			else{
				temp = temp->siguiente;
			}
		}
	}
}

int Lista::SIGUIENTE(int p, Lista* L){
	if(p==FIN(L)-1){
		return FIN(L);
	}
	else if(p<1 || p>=FIN(L)){
		return -1; //No esta definido
	}
	else{
		return p+1;
	}
}

int Lista::ANTERIOR(int p, Lista* L){
	if(p<=1 || p>FIN(L)){
		return -1; //No esta definido
	}
	else{
		return p-1;
	}
}

int Lista::ANULA(Lista* L){
	L->siguiente=NULL;
	cout<<"Vaciando la lista..."<<endl;
	return FIN(L);
}

int Lista::PRIMERO(Lista* L){
	if(L->siguiente==NULL){
		return FIN(L);
	}
	else{
		return L->siguiente->posicion;
	}
}
void Lista::IMPRIME_LISTA(Lista* lista){
	if(lista->siguiente==NULL){
		cout<<"No hay elementos para imprimir"<<endl;
	}
	else{
		Lista* temp = new Lista();
		temp = lista->siguiente; //guarda a1 en la variable temp
		while(temp!=NULL){
			cout<<temp->posicion<<": "<<temp->valor->getValue()<<endl;
			temp = temp->siguiente;
		}
	}
}

int Lista::FIN(Lista* L){
	if(L->siguiente==NULL){
		//cout<<"Lista vacia"<<endl;
		return 1;
	}
	else{
		int cont = 0;
		while(L!=NULL){ //L[es el head]->a1->a2->NULL
			cont++;
			L = L->siguiente;
		}
		return cont;
	}
}

//metodo equals
bool Lista::equals(string x, string y) {
	if(x.length() > y.length() || x.length() < y.length()) {
		return false;
	} else {
		bool lol = false;
		for(int i=0 ; i<x.length(); i++) {
			if(x[i]==y[i]) {
				lol = true;
			} else {
				lol = false;
				break;
			}
		}
		if(lol) {
			return true;
		} else {
			return false;
		}
	}
}