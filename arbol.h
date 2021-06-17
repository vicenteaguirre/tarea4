#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "rotaciones.h"



int max(int a, int b);
int height(Nodo * N);
Nodo * crear_nodo(char * nombre, float nota_presentacion);
Nodo * insertar_nodo(Nodo * root,char * nombre, float nota_presentacion);
void print_nodos(Nodo *root);
void print_izq(Nodo *root);
void print_der(Nodo *root);

//Balance
int getBalance(Nodo * N);

// Right rotate
Nodo *rightRotate(Nodo * y);

// Left rotate
Nodo *leftRotate(Nodo *x);