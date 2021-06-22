#include "nodo.h"
#include "aux.h"

Nodo * crear_nodo(char * nombre, float nota_presentacion);
Nodo * insertar_nodo(Nodo * root,char * nombre, float nota_presentacion);
int getBalance(Nodo * N);
Nodo *rightRotate(Nodo * y);
Nodo *leftRotate(Nodo *x);
