#include "fila.h"
#include "lista.h"
#include "arbol.h"

#ifndef MAIN_UTILIDADES_H
#define MAIN_UTILIDADES_H

void generarGrupoPersonas( F &fila, L &lista, F &primero, F &ultimo, AB &arbol );
void menu();
int intAleatorio( int max, int min );
void mostrarHoras(AB &arbol, F primero);
void mostrarSalarios(AB &arbol, L lista);
void mostrarRecorridos(AB& arbol, L lista, F primero);

#endif // MAIN_UTILIDADES_H