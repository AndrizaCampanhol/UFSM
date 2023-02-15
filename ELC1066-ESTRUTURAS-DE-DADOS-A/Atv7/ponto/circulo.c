#include <stdlib.h>
#include "circulo.h"
#define PI 3.14159

struct circulo {
   Ponto* p;
   float r;
};

Circulo* circ_cria (float x, float y, float r){
   Circulo* c = (Circulo*)malloc(sizeof(Circulo));
   c->p = pto_cria(x,y);
   c->r = r;
   return c;
}

float circ_calcula (Circulo* c){
   return PI*c->r*c->r;
}

int circ_verifica_ponto_interno (Circulo* c, Ponto* p){
   float d = pto_calcula_distancia(c->p,p);
   return (d < c->r);
}

int circ_verifica_circ_interno (Circulo* c1, Circulo* c2){
   float d = pto_calcula_distancia(c1->p, c2->p);
   return (d < (c1->r - c2->r));
}

void circ_libera (Circulo* c){
   pto_libera(c->p);
   free(c);
}
