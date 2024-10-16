#include "lista.h"

#include<iostream>

using std :: cout;
using std :: endl;

void pushListaFinal( L &lista, int horas, int numEmpleado, int nivel )
{   
    L aux = new nodoLista;
    L aux2 = new nodoLista;
    
    aux->horasTrabajadas = horas;
    aux->numeroEmpleado = numEmpleado;
    aux->nivelEmpleado = nivel;
    aux->sig = NULL;
    
    if( lista == NULL) 
    {
    	lista = aux;
	}
	else {

        aux2 = lista;
		while ( aux2->sig != NULL )
		{
			aux2 = aux2->sig;
		}
		aux2->sig = aux;
	}
}

void limpiarLista( L &lista )
{
    while ( lista != NULL ) 
    {
        L aux = lista;
        lista = lista->sig;
        delete aux;
    }
    lista = NULL;
}

float descuentos( int nivel, float sueldo, int type )
{
    switch ( type )
    {
    case 1: // iva
        return sueldo * 0.16;   
        break;
    case 2: // isr
        return sueldo * 0.10;   
        break;
    case 3: // seguro vida
        return ( nivel > 1 ? sueldo * 0.114 : 0 );
        break;
    default:
        return 0;
        break;
    }
}

float bono( int nivel, float sueldo )
{
    float indexBono[3][2] =  
    { 
        { 1, 0.064 }, { 2, 0.139 }, { 3, 0.214 } 
    };

    for ( int i = 0; i < 4; i++ )
    {
        if ( i == nivel ) 
        {
            return ( !nivel ? 70 : sueldo * indexBono[i-1][1] );
        }
    }
    return 0;
}

void calcularPagos( L &lista )
{
    L aux = lista;
    while ( aux != NULL )
    {
        aux->sueldoBase = aux->horasTrabajadas * 250;
        aux->iva = descuentos( aux->nivelEmpleado, aux->sueldoBase, 1 );
        aux->isr = descuentos( aux->nivelEmpleado, aux->sueldoBase, 2 );
        aux->vida = descuentos( aux->nivelEmpleado, aux->sueldoBase, 3 );
        aux->bono = bono( aux->nivelEmpleado, aux->sueldoBase );
        aux->sueldoFinal = aux->sueldoBase + aux->bono - ( aux->iva + aux->isr + aux->vida );
        aux = aux->sig;
    }
}

void imprimirRecibo( L lista )
{
    if ( lista == NULL )
    {
        cout << endl << "No existe una lista" << endl;
        return;
    }
    
    cout << endl << "     Recibo por empleado " << endl;
    while ( lista != NULL )
    {   
        cout << "...................................." << endl << 
        "Numero empleado: " << lista->numeroEmpleado << endl <<
        "Nivel: " << lista->nivelEmpleado << endl <<
        "Horas trabajadas: " << lista->horasTrabajadas << endl << 
        "Sueldo base: $" << lista->sueldoBase << endl << 
        "IVA: $" << lista->iva << endl <<
        "ISR: $" << lista->isr << endl <<
        "Seguro de vida: $" << lista->vida<< endl << 
        "Bono: $" << lista->bono << endl << 
        "Sueldo final: $" << lista->sueldoFinal << endl << 
        "...................................." << endl << endl;
        lista = lista->sig;
    }
} 

int promedioSueldos(L lista)
{
    int suma = 0, i = 1;
    for (; lista != NULL; i++)
    {
        suma += lista->sueldoFinal;
        lista = lista->sig;
    }
    return suma / i;
}