#include <stdlib.h>
#include "notas.h"

struct notas {
   int n1;
   int n2;
};

Notas* ntn_cria_notas (int n1, int n2){
   Notas* n = (Notas*)malloc(sizeof(Notas));
   n->n1 = n1;
   n->n2 = n2;
   return n;
}

void ntn_libera_notas (Notas* n){
   free(n);
}


void ntn_modifica_nota1 (Notas * n, int n1){
    n->n1 = n1;
}

void ntn_modifica_nota2 (Notas * n, int n2){
    n->n2 = n2;
}

void ntn_retorna_notas (Notas * n, int * n1, int * n2){
    *n1 = n->n1;
    *n2 = n->n2;
}

int ntn_calcula_media (Notas * n){
    return (n->n1 + n->n2)/2;
}


