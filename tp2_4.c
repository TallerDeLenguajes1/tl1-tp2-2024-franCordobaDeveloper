#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct compu
{
    int velocidad; // entre 1 y 3 GHz
    int anio; // entre 2015 y 2024
    int cantidad; // entre 1 y 8
    char *tipo_cpu; // valores del arreglo de tipo
};

// Declaracion de Funciones
struct compu cargarDatos();
void mostrarLista(struct compu pcs);
void computadoraVieja(struct compu pcs[5]);
void computadoraVeloz(struct compu pcs[5]);


int main() {

    struct compu pcs[5];
    srand(time(NULL));

    // Carga de datos las pcs
    for(int i = 0; i < 5; i++) {
        pcs[i] = cargarDatos();
    }

    // Muestro las PC random
    printf("\t ----- Datos de la pcs ----- \n");
    for(int i = 0; i < 5; i++ ) {
        printf("\t\t ----- Computadora [%d] ----- \n", i + 1);
        mostrarLista(pcs[i]);
    }
    printf("\n\n");
    // Muestro la PC mas vieja y mas velocidad
    printf("\t\t ----- pc mas vieja ----- \n");
    computadoraVieja(pcs);
    
    printf("\n\n");

    printf("\t\t ----- pcs mas veloz (GHz) -----\n");
    computadoraVeloz(pcs);


    return 0;
}

struct compu cargarDatos() {
    struct compu aux;
    char *tipos[6] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int rand();

    // Genero los datos Random
    aux.velocidad = rand() % 4;
    aux.anio = rand() % 9 + 2015;
    aux.tipo_cpu = tipos[rand() % 6];
    aux.cantidad = rand() % 8 + 1;
    return aux;

}

void mostrarLista(struct compu pcs ) {
    // Muestro los datos de la pcs
    printf("\t\t Tipo de procesador: %s\n", pcs.tipo_cpu);
    printf("\t\t Cantidad de nucleos(entre 1 y 8): %d\n", pcs.cantidad);
    printf("\t\t Velocidad de procesamiento: %d GHz\n", pcs.velocidad);
    printf("\t\t Anio de fabricacion: %d\n", pcs.anio);
    printf("\n");
}

void computadoraVieja(struct compu pcs[5]) {
    struct compu aux = pcs[0];
    for(int i = 0; i < 5; i++ ) {
        if( aux.anio > pcs[i].anio ) {
            aux = pcs[i];
        }
    }
    
    printf("\t\t Anio de fabricacion: %d\n", aux.anio);
    printf("\t\t Tipo de procesador es: %s\n", aux.tipo_cpu);
    printf("\t\t Cantidad de nucleos(entre 1 y 8): %d\n", aux.cantidad);
    printf("\t\t Velocidad de procesamiento en GHz: %d\n", aux.velocidad);
    printf("\n\n");

}


void computadoraVeloz(struct compu pcs[5]) {

    struct compu aux = pcs[0];
    for (int i = 0; i < 5; i++) {
        if (aux.velocidad < pcs[i].velocidad) {
            aux = pcs[i];
        }
    }
    printf("\t\t Velocidad de procesamiento en GHz: %d\n", aux.velocidad);
    printf("\t\t Tipo de procesador es: %s\n", aux.tipo_cpu);
    printf("\t\t Cantidad de nucleos: %d\n", aux.cantidad);
    printf("\t\t Anio de fabricacion: %d\n", aux.anio);
    printf("\n\n");
}