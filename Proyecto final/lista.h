#ifndef LISTA_UTILIDADES_H
#define LISTA_UTILIDADES_H

typedef struct nodoLista
{   
    int numeroEmpleado;
    int nivelEmpleado;
    int horasTrabajadas;
    float sueldoBase;
    float iva, isr, vida;
    float bono;
    float sueldoFinal;
    nodoLista *sig;
} *L;

void pushListaFinal( L &lista, int horas, int numEmpleado, int nivel );
void limpiarLista( L &lista );
void calcularPagos( L &lista );
float descuentos( int nivel, float sueldo, int type);
float bono( int nivel, float sueldo );
void imprimirRecibo( L ); 
int promedioSueldos(L lista);

#endif // LISTA_UTILIDADES_H
