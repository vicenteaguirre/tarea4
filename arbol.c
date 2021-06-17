#include "arbol.h"
int max(int a, int b){
    return (a > b)? a : b;
}
int height(Nodo * N) {
  if (N == NULL)
    return 0;
  return N->height;
}
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
    // Insertion
    if(nodo == NULL) return crear_nodo(nombre,nota_p);
    
    if(nota_p < nodo->np) nodo->left = insertar_nodo(nodo->left, nombre, nota_p);

    else if(nota_p > nodo->np) nodo->right = insertar_nodo(nodo->right,nombre,nota_p);
    
    else return nodo;
    
    // Update height
    nodo->height = 1 + max(height(nodo->left),height(nodo->right));
    
    int balance = getBalance(nodo);

    printf("%s -> Altura nodo:%d\n",nodo->nombre,balance);

    //Condiciones, falta ver si lo hacemos despues de insertar todo o cuando vamos insertando
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
void print_nodos(Nodo *root){ //IRD
  if (root->left!=NULL) print_nodos(root->left);
    printf("%s: %.1f, Altura: %d\n", root->nombre, root->np, root->height);
  if (root->right!=NULL) print_nodos(root->right);;

}
void print_izq(Nodo *root){ //IRD
  if (root->left!=NULL) print_nodos(root->left);
    printf("%s: %.1f, Altura: %d\n", root->nombre, root->np, root->height);
}
void print_der(Nodo *root){ //IRD
  if (root->right!=NULL) print_nodos(root->right);;
  printf("%s: %.1f, Altura: %d\n", root->nombre, root->np, root->height);
}

// Get the balance factor
int getBalance(Nodo *N) {
  if (N == NULL)
    return 0;
  return (height(N->left) - height(N->right));
}

// Right rotate
Nodo *rightRotate(Nodo *y) {
  Nodo * x = y->left;
  Nodo * T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
Nodo *leftRotate(Nodo *x) {
  Nodo * y = x->right;
  Nodo * T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}