#include "lista.h"
#include "stdlib.h"
#include "stdio.h"

int main (void)
{
   No* inicio;                          /* declara uma lista nao iniciada*/
   lst_cria(&inicio);                  	/* inicia lista vazia*/
   lst_insere_ordenado (&inicio, 5);	/* insere na lista o elemento 5*/
   lst_insere_ordenado (&inicio, 2);	/* insere na lista o elemento 2*/
   lst_insere_ordenado (&inicio, 3);	/* insere na lista o elemento 3*/
   lst_insere_ordenado (&inicio, 1);	/* insere na lista o elemento 1*/
   lst_retira(&inicio, 5);
   lst_retira_comeco(&inicio);
   lst_retira_final(&inicio);
   lst_imprime (inicio);        		/* imprimir: 2 3 1*/
   int menores = lst_conta_menores(inicio, 4);
   printf("Número de elementos com valor menor que 4: %d\n", menores);
   No* n = lst_busca(inicio, 12);
   if (n==NULL)
        printf("No nao encontrado");    /* entrar aqui*/
   else printf("No encontrado");
   return 0;
}

