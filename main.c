#include "lectura.h"
#include "funciones.h"


int main(int argc, char const * argv[]){
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
    out(root);
    return 0;
}