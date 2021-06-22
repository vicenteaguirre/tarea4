#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "lectura.h"
#include "aux.h"
#include "funciones.h"


int main(int argc, char const * argv[]){
    printf("\nInicio del programa\n\n");
    FILE * file;
    if (argc != 2) {
        fprintf(stderr, "Debe ingresar solamente un argumento.");        
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "El archivo no existe.");
        return 2;
    }
    Nodo * root = NULL;
    root = lectura_csv(file,root);
    printf("Numero de alumnos: %d\n",cant_alumnos(root)); // Listo
    float promedio = total_np(root)/cant_alumnos(root);
    printf("Promedio: %.1f\n",promedio); // Listo
    printf("Minimo: %.1f\n",min_np(root));
    printf("Maximo: %.1f\n",max_np(root));
    printf("\n");
    return 0;
}