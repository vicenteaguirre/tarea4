#include "lectura.h"

Nodo * lectura_csv(FILE* f, Nodo * root) {
  char line[1001]; // Sirve para la lectura del csv
  float sum = 0; //suma las notas del alumno
  int count = 0; //cant de notas del alumno
  char* field; // Sirve para la lectura del csv
  char * nombre;// Nombre del alumno
  float np; //Nota de presentacion del alumno
  fgets(line, 1000, f);
  while (fgets(line, 1000, f) != NULL) {
    field = strtok(line, ",");
    nombre = field;
    field = strtok(NULL, ",");
    sum = 0.0;
    count = 0;
    while (field != NULL) {
      sum += atof(field);
      count++;
      field = strtok(NULL, ",");
    }
    np = sum/count;
    root = insertar_nodo(root, nombre, np);
  }
  return root;
}