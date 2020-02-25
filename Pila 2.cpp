#include <iostream>
#include <conio.h>
#include <string>  
#include "Gotoxy.h"  // Libreria para el uso del Gotoxy
#include <stdlib.h> 

using namespace std;
struct nodo{
	string dato;
	nodo *siguiente;
};
//Llamadas de los metodos "pila"
void AgregarPila(nodo*&, string);
void SacarPila(nodo*&, string &);

// Metodo principal
main (){
char res; 
int opc;        //opcion para el switch
string dato;  
float conty; // conty es el contador para que la lista se imprima hacia abajo 
int contx=2;    //Inicializando en 2 para que el primer resultado de case 2 de sin residuos
nodo  *pila=NULL;

	do{
	cout<<"\t\tRegistro de personas\n1) Insertar datos de persona(s)\n2) Mostrar datos persona(s)\nSeleccione opcion: ";
	cin>>opc;
system("cls"); //limpiar pantalla
	switch(opc){
case 1:
		do{
	gotoxy(0,0);cout<<"Nombre";
	gotoxy(15,0);cout<<"Edad";
	gotoxy(0,1);cin>>dato;
			AgregarPila(pila,dato);			
	gotoxy(15,1);	cin>>dato;
			AgregarPila(pila,dato);
		gotoxy(0,2);cout<<"Deseas agregar otra persona S/N: ";
			cin>>res;
		system("cls");//limpiar pantalla
			}	
	while(res != 'n');
	break;
case 2:
	gotoxy(15,0);cout<<"Nombre";
	gotoxy(0,0);cout<<"Edad";
	while (pila != NULL){
		SacarPila(pila,dato);
		if (contx%2==0)// Utilizo un metdodo de evaluacion (par impar) para acomodar las edades y los nombres en columnas diferentes
		{
		gotoxy(0,1+conty);cout<<dato;
		}else {
			gotoxy(15,1+conty);cout<<dato;		
		}
		
	contx= contx+1;
	conty = conty+0.5;
	
	}
	cout<<endl<<endl<<endl<<endl;system("pause");	
	break;
default: 
	cout<<"Opcion no valida";
}
system("cls");//limpiar pantalla
cout<<"Desea otra accion S/N: ";
cin>>res;
system("cls");//limpiar pantalla
}
while(res!= 'n');

}

// PILA (Insertar a la pila y sacar de la pila)
void AgregarPila(nodo *&pila, string n){
	
	nodo *nvo_nodo= new nodo();
	nvo_nodo -> dato =n;
	nvo_nodo -> siguiente = pila;
	pila = nvo_nodo;	
}

void SacarPila(nodo *&pila, string &n){
	nodo *aux= pila;
	n = aux -> dato;
	pila =aux -> siguiente;
	delete aux;	
}
