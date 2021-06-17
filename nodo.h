#pragma once

typedef struct nodo{
    char nombre[101];
    float np;
    struct nodo * left;
    struct nodo * right;
    int height;
}Nodo;
