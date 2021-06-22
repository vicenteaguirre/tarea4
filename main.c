#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "lectura.h"
#include "aux.h"


int main(int argc, char const * argv[]){
    printf("Inicio del programa\n\n");
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
    printf("\n\n---------");
    int altura_arbol = profundidad(root);
    printf("Altura del arbol = %d\n",altura_arbol);
    print_nodos(root);
    printf("\n");

    printf("-------- Nodos izq --------\n");
    print_izq(root);
    printf("-------- Nodos der --------\n");
    print_der(root);
    return 0;
}