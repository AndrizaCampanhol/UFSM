#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

static No * lst_localiza_ultimo_menor(No * inicio, int v);
static No * lst_localiza_ultimo(No * inicio, int v);
static void insere_lista(No** inicio, int v, No * ant);

struct no{
   int info;
   struct no* prox;
};


/* funcao de criacao */
void lst_cria (No ** inicio)
{
    *inicio = NULL;
}

void lst_libera (No** inicio)
{
   No* p = *inicio;
   while (p != NULL) {
      No* t = p->prox;
      free(p);
      p = t;
   }
 *inicio = NULL;
}


/* retorna 1 se vazia ou 0 se nao vazia */
int lst_vazia (No* inicio)
{
   return (inicio == NULL);
}




/* insercao no inicio */
void lst_insere_comeco (No** inicio, int i)
{
   No* novo = (No*) malloc(sizeof (No));
   novo->info = i;
   novo->prox = *inicio;
   *inicio = novo;
}

void lst_insere_ordenado (No** inicio, int v)
{
   No* ant = lst_localiza_ultimo_menor(*inicio, v);	/* ponteiro para elemento anterior	*/
   insere_lista(inicio, v, ant);
}

void lst_insere_final (No** inicio, int v)
{
   No* ant = lst_localiza_ultimo(*inicio, v);	/* ponteiro para o ultimo elemento	*/
   insere_lista(inicio, v, ant);
}

void lst_retira (No** inicio, int v)
{
   No* ant = NULL;
   No* p = *inicio;

   while (p != NULL && p->info != v){
      ant = p;
      p = p->prox;
   }

 if (p == NULL)   return;

   if (ant == NULL)
      *inicio = p->prox;
   else
      ant->prox = p->prox;

   free(p);
}

void lst_retira_comeco (No** inicio){
   No* p = *inicio;
   No *q = p->prox;

   free(p);
   *inicio = q;
}

void lst_retira_final (No** inicio){
   No* p = *inicio;
   No *ant = NULL;

   while (p->prox != NULL){
      ant = p;
      p = p->prox;
   }
   free(p);
   ant->prox = NULL;
}

int lst_conta_menores (No* inicio, int v){
   No *p = inicio;
   int menores = 0;

   while(p != NULL && p->info < v){
      menores++;
      p = p->prox;
   }
   return menores;
}

No* lst_busca (No* inicio, int v)
{
   No* p = inicio;
   while (p!=NULL)
   {
        if (p->info ==  v)
            return  p;
        p = p->prox;
   }
return NULL;
}

void lst_imprime (No* inicio)
{
   No* p = inicio;
   while (p != NULL) {
      printf("info = %d\n", p->info);
      p = p->prox;
   }
}

static void insere_lista(No** inicio, int v, No * ant)
{
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



static No * lst_localiza_ultimo_menor(No * inicio, int v){
   No* p = inicio;	/* ponteiro para percorrer a lista	*/
   No* ant = NULL;	/* ponteiro para elemento anterior	*/
   /* procura posicao de insercao */
   while (p != NULL && p->info < v){
      ant = p;
      p = p->prox;
   }
   return ant;

}

static No * lst_localiza_ultimo(No * inicio, int v){
   No* p = inicio;	/* ponteiro para percorrer a lista	*/
   No* ant = NULL;	/* ponteiro para elemento anterior	*/
   /* procura posi??????o de inser??????o */
   while (p != NULL){
      ant = p;
      p = p->prox;
   }
   return ant;

}


