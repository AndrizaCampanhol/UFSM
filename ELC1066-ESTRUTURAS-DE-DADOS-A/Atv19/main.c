#include "stdlib.h"
#include "stdio.h"
#include "arvore.h"

int quant_maiores(No * no, int v);
int gera_vetor_maiores(No * no, int v, int ** vetor);

int calcula_altura(No * no);
int balanceada(No * no);

void imprime_asc(No * no){
    if (no==NULL)
        return;

    imprime_asc(arv_busca_filho(no,0));
    printf("%d, ",arv_busca_valor(no) );
    imprime_asc(arv_busca_filho(no,1));

}

int altura_maior(int esq, int dir){
    if(esq >= dir){
        return esq;
    }else{
        return dir;
    }
}


int calcula_altura(No * no){
    if(no == NULL){
        return 0;
    }
    return 1 + altura_maior(calcula_altura(arv_busca_filho(no, 0)), calcula_altura(arv_busca_filho(no, 1)));
}


int balanceada(No * no)
{
    if(no == NULL){
    return 1;
    }
    
    int alturaEsq, alturaDir;
    
    alturaEsq = calcula_altura(arv_busca_filho(no, 0));
    alturaDir = calcula_altura(arv_busca_filho(no, 1));
    
    if(abs(alturaEsq - alturaDir) <= 1 && balanceada(arv_busca_filho(no, 0)) && balanceada(arv_busca_filho(no,1))){
        return 1;
    }
    return 0;
}


int quant_maiores(No * no, int v)
{
    if(no==NULL) return 0;
    static int contador = 0;
    if(arv_busca_valor(no) > v){
        contador++;
    }
    quant_maiores(arv_busca_filho(no,0),v);
    quant_maiores(arv_busca_filho(no,1),v);
    return contador;
}

int gera_vetor_maiores(No * no, int v, int ** vetor){
    if(no==NULL) return 0;
    static int i = 0;
    static int aux = 0;
    static int tam;
    
    if(aux == 0){
        tam = quant_maiores(no, v);
        *vetor = (int *) malloc(tam * sizeof(int));
    }
    
    if(arv_busca_valor(no) > v){
        (*vetor)[i] = arv_busca_valor(no);
        i++;
        
        if(i == quant_maiores(no,v)){
            return quant_maiores(no, v);
        }
    }
    aux = aux + 1;
    gera_vetor_maiores(arv_busca_filho(no,0),v, vetor);
    gera_vetor_maiores(arv_busca_filho(no,1),v, vetor);
    
    return tam;
}


int main()
{

   printf("\n\n******************* TESTE 1 ******************************");
   Arvore * arv = arv_cria();

   arv_insere_no(arv, 1);
   arv_insere_no(arv, 2);
   arv_insere_no(arv, 3);
   arv_insere_no(arv, 4);
   arv_insere_no(arv, 5);
   arv_insere_no(arv, 6);
   arv_insere_no(arv, 7);

   printf("\n");
   int bal = balanceada(arv_busca_raiz(arv));
   if (bal)
        printf("\nBalanceada");
    else printf("\nNao Balanceada");


   printf("\n\n******************* TESTE 2 ******************************");
   Arvore * arv1 = arv_cria();

   arv_insere_no(arv1, 4);
   arv_insere_no(arv1, 6);
   arv_insere_no(arv1, 2);
   arv_insere_no(arv1, 5);
   arv_insere_no(arv1, 1);
   arv_insere_no(arv1, 7);
   arv_insere_no(arv1, 3);

   printf("\n");
    bal = balanceada(arv_busca_raiz(arv1));
   if (bal)
        printf("\nBalanceada");
    else printf("\nNao Balanceada");


   int * vetor;
   int tam = gera_vetor_maiores(arv_busca_raiz(arv1), 3, &vetor);

   printf("\n\nvetor gerado: ");
   int x;
   for(x=0;x<tam;x++){
     printf("%d ", vetor[x]);
   }
   printf("\n");

   return 0;
}
