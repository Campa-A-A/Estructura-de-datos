#include "fila.h"
#include "lista.h"

#ifndef ARBOL_UTILIDADES_H
#define ARBOL_UTILIDADES_H

typedef struct nodoArbol
{
    int numero;
    nodoArbol *izq;
    nodoArbol *der;
} *AB;

void insertarNodo( AB &arbol, int _numero_ );
void mostrarArbol( AB arbol, int nivel );
void eliminarArbol(AB &arbol);
void llenarArbolHoras(AB& arbol, F primero);
void llenarArbolSalario(AB& arbol, L lista);
void RecorridoInorden(AB arbol);
void RecorridoPreorden(AB arbol);
void RecorridoPosorden(AB arbol);
void RecorridosProfundidad(AB arbol);

#endif // ARBOL_UTILIDADES_H