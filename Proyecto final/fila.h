#ifndef FILA_UTILIDADES_H
#define FILA_UTILIDADES_H

typedef struct nodoFila
{
    int horasTrabajadas;
    nodoFila *sig;  
} *F;

void pushFila( F &fila, int horasTrabajadas, F &primero, F &ultimo );
void limpiarFila( F &fila, F &primero, F &ultimo );
void mostrarHoras( F primero );
int promedioHoras(F primero);

#endif // FILA_UTILIDADES_H