#include "rotaciones.h"
/*
//Balance
int getBalance(Nodo * N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}


// Right rotate
Nodo * rightRotate(Nodo * y) {
  Nodo *x = y->left;
  Nodo *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
Nodo *leftRotate(Nodo * x) {
  Nodo *y = x->right;
  Nodo *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}*/