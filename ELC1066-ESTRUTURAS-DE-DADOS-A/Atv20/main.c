#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void imprime(No * no);

void imprime(No * no)
{

    static int endent = 0;
    if (no==NULL)
        return;

    int i;
    for (i=0;i<endent;i++)
        printf("  ");

    printf("%d\n", arv_busca_valor_no(no));
    endent++;
    imprime(arv_busca_filho(no));
    endent--;
    imprime(arv_busca_irmao(no));

}


int possui_valor(No * no, int valor){
     if (no==NULL)
        return 0;

    if (arv_busca_valor_no(no) == valor) {
        return 1;
    }

    int possui = possui_valor(arv_busca_irmao(no), valor);

    if (possui == 1){
        return 1;
    }
    
    return possui_valor(arv_busca_filho(no), valor);
}


void imprime_discrepancias(No * no){
    if(no==NULL){
        return;
    }
    
    No * filho = arv_busca_filho(no);
    
    while(filho != NULL){
        if(arv_busca_valor_no(no) < arv_busca_valor_no(filho)){
            printf("\nFilho %d maior que pai %d \n", arv_busca_valor_no(filho), arv_busca_valor_no(no));
        }
        filho = arv_busca_irmao(filho);
    }
    imprime_discrepancias(arv_busca_filho(no));
    imprime_discrepancias(arv_busca_irmao(no));
}


int busca_maior_quant_filhos(No * no){
    if (no==NULL)
        return 0;

    No * filho = arv_busca_filho(no);
    int quant = 0;
    
    while (filho != NULL) {       
        filho = arv_busca_irmao(filho);
        quant++;
    }

    if (busca_maior_quant_filhos(arv_busca_filho(no)) > quant){
     quant = busca_maior_quant_filhos(arv_busca_filho(no));
    }

    if (busca_maior_quant_filhos(arv_busca_irmao(no)) > quant){
    quant = busca_maior_quant_filhos(arv_busca_irmao(no));
    }

    return quant;
}



int main()
{
    Arvore * arv = arv_cria_arvore();
    No * n1 = arv_cria_no(1);
    No * n2 = arv_cria_no(2);
    No * n3 = arv_cria_no(3);
    No * n4 = arv_cria_no(4);
    No * n5 = arv_cria_no(5);
    No * n6 = arv_cria_no(6);

    No * n7 = arv_cria_no(7);
    No * n8 = arv_cria_no(8);
    No * n9 = arv_cria_no(9);
    No * n10 = arv_cria_no(10);

    arv_insere_no(n1, n2);
    arv_insere_no(n1, n3);

    arv_insere_no(n2, n4);
    arv_insere_no(n3, n5);

    arv_insere_no(n5, n6);

    arv_insere_no(n6, n7);
    arv_insere_no(n6, n8);
    arv_insere_no(n6, n9);
    arv_insere_no(n6, n10);

    arv_seta_raiz(arv, n1);


    printf("Arvore: ");
    printf("\n");
    imprime(arv_pega_raiz(arv));
    printf("\n");

    int valor = 10;
    int resp = possui_valor(arv_pega_raiz(arv), valor);
    if (resp)
        printf("\nA arvore possui o valor %d", valor);
    else printf("\nA arvore nao possui o valor %d", valor);

    printf("\nImpressao de discrepancias da arvore\n");
    imprime_discrepancias(arv_pega_raiz(arv));

    int quant = busca_maior_quant_filhos(arv_pega_raiz(arv));
    printf("\n\nGrau da arvore: %d\n", quant);

    return 0;
}
