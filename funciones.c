#include "funciones.h"


int cant_alumnos(Nodo * root){
    if(root == NULL) return 0;
    else return 1 + cant_alumnos(root->left) + cant_alumnos(root->right);
}
float total_np(Nodo * root){
    if(root == NULL) return 0;
    else return root->np + total_np(root->left) + total_np(root->right);
}
float min_np(Nodo * root){
    if(root == NULL) return 10;
    else{
        float temp ;
        temp = min_flt( min_np(root->left), min_np(root->right));
        return(min_flt(root->np,temp));
    }
}
float max_np(Nodo * root){
    if(root == NULL) return 0.0;
    else{
        float temp ;
        temp = max_flt( max_np(root->left), max_np(root->right));
        return(max_flt(root->np,temp));
    }
}
void out(Nodo * root){
    FILE * fichero;
    fichero = fopen("out.txt", "w");
    fprintf(fichero,"Numero de alumnos: %d\n",cant_alumnos(root));
    float promedio = total_np(root)/cant_alumnos(root);
    fprintf(fichero,"Promedio: %.1f\n",promedio); // Listo
    fprintf(fichero,"Minimo: %.1f\n",min_np(root));
    fprintf(fichero,"Maximo: %.1f",max_np(root));
    fclose(fichero);
}
