#include "stdlib.h"
#include "stdio.h"
#include "arvore.h"

void imprime_tab (No* pai, char * lado){
    if (pai==NULL)
        return;
        
    static int tab = 1;
    
    for(int i=0; i<tab; i++){
        printf("---");
    }
    printf("%d(%s)\n", arv_busca_valor(pai), lado);
    
    tab++;
    imprime_tab(arv_busca_filho(pai, 0), "esq");
    imprime_tab(arv_busca_filho(pai, 1), "dir");
    tab--;
}

int main()
{
   Arvore * arv = arv_cria();
   No * no1 = arv_cria_no(10);
   No * no2 = arv_cria_no(20);
   No * no3 = arv_cria_no(30);
   No * no4 = arv_cria_no(40);
   No * no5 = arv_cria_no(50);

   No * no6 = arv_cria_no(60);

   arv_insere(no1, no2, 0);
   arv_insere(no1, no3, 1);
   arv_insere(no3, no4, 0);
   arv_insere(no3, no5, 1);
   arv_insere(no3, no6, 1);
   arv_seta_raiz (arv, no1);

   arv_imprime(arv_busca_raiz(arv));
   
   printf("\n\n");
   arv_imprime_tab(arv_busca_raiz(arv), "raiz");
   
   printf("\n\n");
   imprime_tab(arv_busca_raiz(arv), "raiz");
   
   printf("\n\n");
   arv_insere_final(no1, no5, 0);
   arv_insere_final(no1, no5, 1);
   imprime_tab(arv_busca_raiz(arv), "raiz");

   return 0;
}