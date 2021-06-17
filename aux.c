#include "aux.h"

//https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

int profundidad(Nodo *raiz) { 
    if (raiz == NULL)
        return -1;
    else {
        int left = profundidad(raiz->left);
        int right = profundidad(raiz->right);
        if (left > right)
            return (left + 1);
        else 
            return (right + 1);
    }

}