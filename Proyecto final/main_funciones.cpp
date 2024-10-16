#include "main_funciones.h"
#include "lista.h"
#include "fila.h"
#include "arbol.h"
#include <iostream>

using std :: cout;
using std :: cin;
using std :: endl;

const int personasMax = 50;
const int personasMin = 10;

void generarGrupoPersonas( F &fila, L &lista, F &primero, F &ultimo, AB &arbol )
{
    int opt = 0;
    if ( fila != NULL )
    {
        cout << endl << "Ya existe un grupo creado!" << endl <<
        "Desea crear otro?" << endl <<
        " 1 : Si" << endl <<
        " 2 : No" << endl << endl <<
        " Ingreso de opcion:";
        cin >> opt;

        if ( opt == 2 ) {
            cout << endl << "Se cancelo la operacion..." << endl;
            return;
        }
    }
    
    if ( opt == 1 ) 
    {
        cout << endl << "Datos eliminados..." << endl;
        limpiarFila( fila, primero, ultimo );
        limpiarLista( lista );
        eliminarArbol(arbol);
        cout << endl << "Generando nuevos..." << endl;
    }

    int numPersonas;
    do 
    { 
        numPersonas = ( rand() % 50 ) + 1; 
    } 
    while ( numPersonas > personasMax || numPersonas < personasMin );

    for ( int i = 0; i < numPersonas; i++ )
    {
        int horas = intAleatorio( 40, 20 );
        pushFila( fila, horas, primero, ultimo);
        pushListaFinal( lista, horas, intAleatorio( 999, 100 ), intAleatorio( 3, 0) );
    }
    calcularPagos( lista );
    cout << endl << "Se genero el grupo de personas satisfactoriamente..." << endl;
}

void menu()
{
    cout << endl << 
    " 1 : Generar/reacer un grupo de personas " << endl <<
    " 2 : Mostrar la fila de horas por trabajador" << endl << 
    " 3 : Mostrar los lista de los trabajadores" << endl <<
    " 4 : Mostrar la jerarquia de las horas" << endl <<
    " 5 : Mostrar la jerarquia de los sueldos" << endl << 
    " 6 : Mostrar recorridos del arbol" << endl <<
    " 0 : Finalizar programa" << endl << endl <<
    " Ingreso de opcion: ";
}

int intAleatorio( int max, int min )
{
    int temp;
    do { 
        temp = rand() % max + 1; 
    } while ( temp > max || temp < min );
    return temp;
}

void mostrarHoras(AB &arbol, F primero)
{
    if ( primero == NULL )
    {
        cout << endl << "No se puede realizar esa accion" << endl;
        return;
    }
    cout << endl << "El promedio de horas fue: " <<  promedioHoras(primero) << endl << endl;
    llenarArbolHoras(arbol, primero);
    mostrarArbol(arbol, 1);
    eliminarArbol(arbol);
}

void mostrarSalarios(AB& arbol, L lista)
{
    if ( lista == NULL )
    {
        cout << endl << "No se puede realizar esa accion" << endl;
        return;
    }
    cout << endl << "El promedio de salaros fue: " << promedioSueldos(lista) << endl << endl;
    llenarArbolSalario(arbol, lista);
    mostrarArbol(arbol, 1);
    eliminarArbol(arbol);
}

void mostrarRecorridos(AB& arbol, L lista, F primero)
{
    if (lista == NULL)
    {
        cout << endl << "No es posible hacer esta accion" << endl;
        return;
    }
    
    cout << endl << "Recorrido para horas: " << endl;
    llenarArbolHoras(arbol, primero);
    RecorridosProfundidad(arbol);
    eliminarArbol(arbol);

    cout << endl << "Recorrido para salarios:" << endl;
    llenarArbolSalario(arbol, lista);
    RecorridosProfundidad(arbol);
    eliminarArbol(arbol);
}