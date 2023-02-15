#include "lista.h"
#include "stdlib.h"
#include "stdio.h"

int main (void)
{
   No* inicio;                      /* declara uma lista n�o iniciada*/
   int contador = 0;                // declara um contador
   lst_cria(&inicio);               /* inicia lista vazia*/
   lst_insere_final (&inicio, 7);	/* insere na lista o elemento 7*/
   lst_insere_final (&inicio, 2);	/* insere na lista o elemento 2*/
   lst_insere_final (&inicio, 8);	/* insere na lista o elemento 8*/
   lst_insere_final (&inicio, 1);	/* insere na lista o elemento 1*/

   lst_retira_rec(&inicio, 2);

   lst_imprime_rec (inicio);
   No* n = lst_busca(inicio, 8);
   if (n==NULL)
      printf("No nao encontrado\n");
   else printf("No encontrado\n");

   //chama funcao que busca o elemento 2 (rec)
   No* bus = lst_busca_rec(inicio, 2);
   if (bus == NULL)
      printf("No nao encontrado\n");
   else printf("No encontrado\n");

   int cont = lst_conta_menores(inicio, 6);
   printf("\nExistem %d valores na lista menores do que 6", cont);

   //chama funcao que conta a quantidade de valores menores que 10 (rec)
   lst_conta_menores_rec(inicio, 10, &contador);
   printf("\nExistem %d valores na lista menores do que 10\n", contador);

   //retira os elementos da lista
   lst_retira_rec(&inicio, 1);
   lst_retira_rec(&inicio, 7);
   lst_retira_rec(&inicio, 8);

   //insere novos elementos para ordenar
   lst_insere_ordenado(&inicio, 2);
   lst_insere_ordenado(&inicio, 6);
   lst_insere_ordenado(&inicio, 5);
   lst_insere_ordenado(&inicio, 4);
   
   //imprime para checar se os novos elementos estão ordenados
   printf("\nImprime ordenado:\n");
   lst_imprime_rec(inicio);

   //insere um elemento no final
   lst_insere_final(&inicio, 1);

   //imprime para checar se o novo elemento está no final
   printf("\nImprime com novo valor final:\n");
   lst_imprime_rec(inicio);

   return 0;
}

