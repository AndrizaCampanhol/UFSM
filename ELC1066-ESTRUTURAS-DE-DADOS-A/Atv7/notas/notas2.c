#include <stdlib.h>
#include "notas.h"

struct notas {
   int n[2];
};

Notas* ntn_cria_notas (int n1, int n2){
   Notas* n = (Notas*)malloc(sizeof(Notas));
   n->n[0] = n1;
   n->n[1] = n2;
   return n;
}

void ntn_libera_notas (Notas* n){
   free(n);
}


void ntn_modifica_nota1 (Notas * n, int n1){
    n->n[0] = n1;
}

void ntn_modifica_nota2 (Notas * n, int n2){
    n->n[1] = n2;
}

void ntn_retorna_notas (Notas * n, int * n1, int * n2){
    *n1 = n->n[0];
    *n2 = n->n[1];
}

int ntn_calcula_media (Notas * n){
    return (n->n[0] + n->n[1])/2;
}