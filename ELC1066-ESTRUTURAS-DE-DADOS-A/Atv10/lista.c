#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

struct no {
   int info;
   struct no* ant;
   struct no* prox;
};

void lst_cria (No ** inicio){
   *inicio = NULL;
}

/* funcao busca: busca um elemento na lista */
No* lst_busca (No* inicio, int v)
{
   No* p = inicio;
   while(p!=NULL) {
       if (p->info == v)
          return p;
       p=p->prox;
   }

   return NULL;	/* nao achou o elemento */
}

void lst_insere (No** inicio, int v)
{
   No* novo = (No*) malloc(sizeof(No));
   novo->info = v;
   novo->prox = *inicio;
   novo->ant = NULL;
   if (*inicio != NULL)
      (*inicio)->ant = novo;
   *inicio = novo;
}

void lst_insere_final (No** inicio, int v){
   No* novof = (No*) malloc(sizeof(No));
   No* ant = *inicio;

   if(novof == NULL){
      return; 
   }
   if(ant == NULL){
      return;
   }
   
   novof->info = v;
   novof->prox = NULL;

   if(*inicio == NULL){
      novof->ant = NULL;
      *inicio = novof;
   }else{
      while(ant->prox != NULL){
         ant = ant->prox;
      }
      ant->prox = novof;
      novof->ant = ant; 
   }
}

/* funcao retira: remove elemento da lista */
void lst_retira (No** inicio, int v)
{
   No* p = lst_busca(*inicio,v);
   if (p == NULL)
      return ;                             /* nao achou o elemento: */

   /* retira elemento do encadeamento */
   if (*inicio == p)		/* testa se e o primeiro elemento */
      *inicio = p->prox;
   else
      p->ant->prox = p->prox;

   if (p->prox != NULL) 	/* testa se e o ultimo elemento */
      p->prox->ant = p->ant;
   free(p);
}

void lst_imprime(No * inicio){
   No* i = inicio;

   if(i){
      do{
         printf("%d\n", i->info);
         i = i->prox;
      }while(i != NULL);
   }
}

void lst_imprime_para_tras(No * inicio){
   No* i = inicio;

   while(i->prox != 0){
      i = i->prox;
   }

   if(i){
      do{
         printf("%d\n", i->info);
         i = i->ant;
      }while(i != NULL);
   }
}