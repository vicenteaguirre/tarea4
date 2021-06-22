#include "arbol.h"

Nodo * crear_nodo(char * nombre, float nota_presentacion){
    Nodo * new_nodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(new_nodo->nombre, nombre);
    new_nodo->np = nota_presentacion;
    new_nodo->left = NULL;
    new_nodo->right = NULL;
    new_nodo->height = 1;
    return new_nodo;
}
Nodo * insertar_nodo(Nodo * nodo,char * nombre, float nota_p){
    if(nodo == NULL) nodo = crear_nodo(nombre,nota_p);    
    if(nota_p < nodo->np) nodo->left = insertar_nodo(nodo->left, nombre, nota_p);
    else if(nota_p > nodo->np) nodo->right = insertar_nodo(nodo->right,nombre,nota_p);
    nodo->height = 1 + max(height(nodo->left),height(nodo->right));
    int balance = getBalance(nodo);
    if (balance > 1 && nota_p < nodo->left->np) return rightRotate(nodo);
    if (balance < -1 && nota_p > nodo->right->np) return leftRotate(nodo);
    if (balance > 1 && nota_p > nodo->left->np) {
        nodo->left = leftRotate(nodo->left);
        return rightRotate(nodo);
    }
    if (balance < -1 && nota_p < nodo->right->np) {
        nodo->right = rightRotate(nodo->right);
        return leftRotate(nodo);
    }
    return nodo;
}
int getBalance(Nodo *N) {
  if (N == NULL) return 0;
  return (height(N->left) - height(N->right));
}
Nodo *rightRotate(Nodo *y) {
  Nodo * x = y->left;
  Nodo * T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}
Nodo *leftRotate(Nodo *x) {
  Nodo * y = x->right;
  Nodo * T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}