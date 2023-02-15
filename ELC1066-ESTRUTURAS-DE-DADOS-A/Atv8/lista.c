#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct no{
   int info;
   struct no* prox;
};

No * lst_localiza_ultimo_menor(No * inicio, int v) {
   No *ant = NULL;
   No* p = inicio;

   while(p != NULL && p->info < v){
      ant = p;
      p = p->prox;
   }
   return ant;
}

No * lst_localiza_ultimo(No * inicio) {
   No *ant = NULL;
   No* p = inicio;

   while(p != NULL){
      ant = p;
      p = p->prox;
   }
   return ant;
}

void insere_lista(No** inicio, int v, No * ant){
   /* cria novo elemento */
   No* novo = (No*) malloc(sizeof (No));
   novo->info = v;
   /* encadeia elemento */
   if (ant == NULL){         /* insere elemento no inicio	*/
      novo->prox = *inicio;
      *inicio = novo;
   }
   else {                           /* insere elemento no meio da lista */
      novo->prox = ant->prox;
      ant->prox = novo;
   }
}

/* funcao de criacao */
void lst_cria (No ** inicio)
{
    *inicio = NULL;
}

/* retorna 1 se vazia ou 0 se nao vazia */
int lst_vazia (No* inicio)
{
   return (inicio == NULL);
}

/* insercao no inicio */
void lst_insere (No** inicio, int i)
{
   No* novo = (No*) malloc(sizeof (No));
   novo->info = i;
   novo->prox = *inicio;
   *inicio = novo;
}

void lst_insere_ordenado(No** inicio, int v)
{
   No* ant = lst_localiza_ultimo_menor(*inicio, v);	/* ponteiro para elemento anterior	*/
   insere_lista(inicio, v, ant);
}

void lst_insere_final (No** inicio, int v)
{
   No* ant = lst_localiza_ultimo(*inicio);	/* ponteiro para o ultimo elemento	*/
   insere_lista(inicio, v, ant);
}

void lst_imprime (No* inicio)
{
   No* p = inicio;
   while (p != NULL) {
      printf("info = %d\n", p->info);
      p = p->prox;
   }
}