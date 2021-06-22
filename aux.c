#include "aux.h"

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
int max(int a, int b){
  if(a>b)return a;
  else if(a<b) return b;
  else return a;
}
int height(Nodo * N) {
  if (N == NULL) return -1;
  return N->height;
}