#include "funciones.h"
float max_flt(float a, float b){
  if(a>b)return a;
  else if(a<b) return b;
  else return a;
}
float min_flt(float a, float b){
  if(a>b)return b;
  else if(a<b) return a;
  else return a;
}
int cant_alumnos(Nodo * root){
    if(root == NULL) return 0;
    else return 1 + cant_alumnos(root->left) + cant_alumnos(root->right);
}


float total_np(Nodo * root){
    if(root == NULL) return 0;
    else return root->np + total_np(root->left) + total_np(root->right);
}

float min_np(Nodo * root){
    if(root == NULL){
        return 10;
     }
     else{
        float temp ;
        temp = min_flt( min_np(root->left), min_np(root->right));
        return(min_flt(root->np,temp));
    }
}
float max_np(Nodo * root){
    if(root == NULL){
        return 0.0;
     }
     else{
        float temp ;
        temp = max_flt( max_np(root->left), max_np(root->right));
        return(max_flt(root->np,temp));
    }
}
