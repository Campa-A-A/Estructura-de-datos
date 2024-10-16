#include "fila.h"

#include <iostream>

using std :: endl;
using std :: cout;

void pushFila( F &fila, int horasTrabajadas, F &primero, F &ultimo )
{
    fila = new nodoFila;
    fila->horasTrabajadas = horasTrabajadas;
    fila->sig = NULL;

    if( primero == NULL ) {
        ultimo = primero = fila;
    }
    else {
        ultimo->sig = fila;
        ultimo = fila;
    }
}

void limpiarFila( F &fila, F &primero, F &ultimo )
{
    while ( fila != NULL ) 
    {
        F aux = fila;
        fila = fila->sig;
        delete aux;
    }
    primero = ultimo = NULL;
    fila = NULL;
}

void mostrarHoras( F primero )
{
    F aux = primero;

    if ( primero == NULL )
    {
        cout << endl << "No existe una lista" << endl;
        return;
    }
    
    cout << endl;
    for ( int i = 1; aux != NULL; i++ )
    {
        cout <<"\nEmpleado " << i << ": " << aux->horasTrabajadas << " horas";
        aux = aux->sig;
    }
    cout << endl;
}

int promedioHoras(F primero)
{
    int suma = 0, i = 1;
    for ( ; primero != NULL; i++)
    {
        suma += primero->horasTrabajadas;
        primero = primero->sig;
    }
    return suma / i;
}