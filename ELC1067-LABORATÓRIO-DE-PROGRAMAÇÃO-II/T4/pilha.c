#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

typedef struct no {
  int id;
  struct no *prox;
} No;

struct pilha {
  No *prim;
};

Pilha* pilha_cria () {
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));

  p->prim = NULL;

  return p;
}

int pilha_vazia (Pilha* p) {
  return (p->prim==NULL);
}

void pilha_push (Pilha* p, int id) {
  No* novo = (No*) malloc(sizeof (No));

  novo->id = id;
  novo->prox = p->prim;
  p->prim = novo;
  
  printf("Bandeja adicionada a pilha!\n");
}

void pilha_pop (Pilha* p) {
  if (pilha_vazia(p)) {
    printf("A pilha esta vazia!\n");
    return;
  }

  No* elemento = p->prim;
  p->prim = elemento->prox;
  
  free(elemento);
  
  printf("Bandeja retirada da pilha!\n");
}

void pilha_libera (Pilha* p) {
  No* q = p->prim;

  while (q != NULL) {
    No* t = q->prox;
    
    free(q);
    
    q = t;
  }
  free(p);
}

void imprime_pilha (Pilha *p) {
  
  if (pilha_vazia(p)) {
    printf("A pilha esta vazia!\n");
    return;
  }

  int id;
  No *elemento = p->prim;

  while (elemento != NULL) {
    id = elemento->id;
    printf("%d\n", id);

    elemento = elemento->prox;
  }
}