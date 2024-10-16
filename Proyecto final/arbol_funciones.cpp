#include "arbol.h"
#include "fila.h"
#include "lista.h"
#include <iostream>

using std :: endl;
using std :: cout;

void insertarNodo( AB &arbol, int _numero )
{
	if ( arbol == NULL )
	{
		AB nodo = new nodoArbol;
		nodo->numero = _numero;
		nodo->izq = NULL;
		nodo->der = NULL;
		
		arbol = nodo;
	}
	else if ( _numero < arbol->numero ) //izq
	{
		insertarNodo( arbol->izq, _numero );
	}
	else if ( _numero >= arbol->numero ) //der
	{
        insertarNodo( arbol->der, _numero );
	}
}

void eliminarArbol( AB& arbol )
{
	if ( arbol != NULL )
	{
		eliminarArbol(arbol->izq);
		eliminarArbol(arbol->der);
		arbol = NULL;
		delete (arbol);
	}
}

void mostrarArbol( AB arbol, int nivel )
{
	if( arbol == NULL )
    {
		return;
    }
		
	mostrarArbol( arbol->der, nivel+1 );
	
	for(int i=0; i<nivel; i++)
	{
		cout<<"\t";
	}
	
	cout<<arbol->numero<<endl;
	
	mostrarArbol( arbol->izq, nivel+1 );
}

void llenarArbolHoras(AB& arbol, F primero)
{
	insertarNodo(arbol, promedioHoras(primero));
	while ( primero != NULL )
	{
		insertarNodo(arbol, primero->horasTrabajadas);
		primero = primero->sig;
	}
}

void llenarArbolSalario(AB& arbol, L lista)
{
	insertarNodo(arbol, promedioSueldos(lista));
	while (lista != NULL)
	{
		insertarNodo(arbol, lista->sueldoFinal);
		lista = lista->sig;
	}
}

void RecorridoInorden(AB arbol)// IZQ - RAIZ - DER
{
	if (arbol != NULL)
	{
		RecorridoInorden(arbol->izq);
		cout << arbol->numero << " ";
		RecorridoInorden(arbol->der);
	}
	else {
		return;
	}
}

void RecorridoPreorden(AB arbol) // RAIZ - IZQ - DER
{
	if (arbol != NULL)
	{
		cout << arbol->numero << " ";//Raiz
		RecorridoPreorden(arbol->izq);
		RecorridoPreorden(arbol->der);
	}
	else
	{
		return;
	}
}

void RecorridoPosorden(AB arbol) // IZQ - DER - RAIZ
{
	if (arbol != NULL)
	{
		RecorridoPosorden(arbol->izq);
		RecorridoPosorden(arbol->der);
		cout << arbol->numero << " ";//Raiz
	}
	else
	{
		return;
	}
}

void RecorridosProfundidad(AB arbol)
{
	if ( arbol == NULL)
	{
		return;
	}
	cout << endl << "Recorrido Inorden: ";
	RecorridoInorden(arbol);
	cout << endl << "Recorrido Preorden: ";
	RecorridoPreorden(arbol);
	cout << endl << "Recorrido Posorden: ";
	RecorridoPosorden(arbol);
	cout << endl;
}