#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pilha.h"


/* nó da lista para armazenar valores reais */
struct no{
   float info;
   struct no* prox;
};

typedef struct no No;

/* estrutura da pilha */
struct pilha {
   No* prim;    /* aponta para o topo da pilha */
};


Pilha* pilha_cria (void)
{
   Pilha* p = (Pilha*) malloc(sizeof(Pilha));
   p->prim = NULL;
   return p;
}


void pilha_libera (Pilha* p)
{
   No* q = p->prim;
   while (q!=NULL) {
      No* t = q->prox;
      free(q);
      q = t;
   }
   free(p);
}

int pilha_vazia (Pilha* p)
{
   return (p->prim==NULL);
}


void pilha_push (Pilha* p, float v)
{
   No* n = (No*) malloc(sizeof (No));
   n->info = v;
   n->prox = p->prim;
   p->prim = n;
}


float pilha_pop (Pilha* p)
{
   No* t;     float v;
   if (pilha_vazia(p)) {
      printf("Pilha vazia.\n");
      exit(1);	    /* aborta programa */
   }
   t = p->prim;
   v = t->info;
   p->prim = t->prox;
   free(t);
   return v;
}
