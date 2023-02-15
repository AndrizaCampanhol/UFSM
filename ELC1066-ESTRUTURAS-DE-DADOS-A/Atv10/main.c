#include "stdlib.h"
#include "stdio.h"
#include "lista.h"

int main (void)
{
   No* inicio;
   lst_cria(&inicio);

   printf("\nInserindo elementos 10, 20, 30, 40, 50 e 60\n");
   lst_insere(&inicio,30);
   lst_insere(&inicio,20);
   lst_insere(&inicio,10);
   lst_insere_final(&inicio,40);
   lst_insere_final(&inicio,50);
   lst_insere_final(&inicio,60);

   lst_imprime(inicio);

   printf("\nRetirando elemento 10\n");
   lst_retira(&inicio,10);
   lst_imprime(inicio);

   printf("\nRetirando elemento 60\n");
   lst_retira(&inicio,60);
   lst_imprime(inicio);

   printf("\nRetirando elemento 40\n");
   lst_retira(&inicio,40);
   lst_imprime(inicio);

   printf("\nBuscando elemento 50\n");
   No * n = lst_busca(inicio, 50);
   if (n!=NULL){
        printf("\nAchei. Imprimindo de tras para frente\n");
        lst_imprime_para_tras(n);
        }
    else printf("\nElemento nao existe!\n");

   return 0;
}