#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char nombre[101];
    float np;
    struct nodo * left;
    struct nodo * right;
    int height;
}Nodo;
