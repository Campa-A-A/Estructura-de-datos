
// ALEJANDRO CAMPA ALONSO 215833

#include "arbol.h"
#include "fila.h"
#include "lista.h"
#include "main_funciones.h"

#include <ctime>
#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

int main()
{
    srand(time(NULL));

    int optMenu;
    L lista = NULL;
    F fila = NULL;
    F primero = NULL, ultimo = NULL;
    AB arbol = NULL;

    do
    {
        menu();
        cin >> optMenu;

        switch ( optMenu )
        {
        case 1:
            generarGrupoPersonas( fila, lista, primero, ultimo, arbol );
            break;
        case 2:
            mostrarHoras( primero );
            break;
        case 3:
            imprimirRecibo(lista);
            break;
        case 4:
            // fila - horas
            mostrarHoras(arbol, primero);
            break;
        case 5:
            // lista - salarios
            mostrarSalarios(arbol, lista);
            break;
        case 6 :
            mostrarRecorridos(arbol, lista, primero);
            break;
        case 0:
            cout << endl << "Saliendo del programa...";
            break;
        default:
            cout << endl << "Opcion invalida" << endl;
            break;
        }
        
    } while ( optMenu );

    return 0;
}