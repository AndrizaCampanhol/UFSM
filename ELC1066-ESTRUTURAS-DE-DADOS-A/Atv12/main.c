#include "stdlib.h"
#include "stdio.h"
#include "pilha.h"
#include "calc.h"

void imprime (Pilha * p){
   if(pilha_vazia(p)){
      printf("Pilha vazia.\n");
   }else{
      while(!pilha_vazia(p)){
         float n = pilha_pop(p);
         printf("info: %.2f\n", n);
      }
   }
}

Pilha * invertePilha (Pilha * p){
   Pilha *p2 = pilha_cria();
   if(pilha_vazia(p)){
      printf("Pilha vazia.\n");
   }else{
      while(!pilha_vazia(p)){
         pilha_push(p2, pilha_pop(p));
      }
   }
   return p2;
}

int main (void)
{
   Pilha * p1 = pilha_cria();
   pilha_push(p1, 4);
   pilha_push(p1, 6);
   pilha_push(p1, 8);

   printf("\nimpressao da pilha 1\n");
   imprime(p1);
    
   //depois da impressao a pilha ficou vazia. Po isso os elementos serao empilhados novamente
   pilha_push(p1, 4);
   pilha_push(p1, 6);
   pilha_push(p1, 8);

   Pilha * p2 = invertePilha(p1);
   printf("\n\nimpressao da pilha invertida\n");
   imprime(p2);

   
   char equacao[] = "125+-";
   printf("\n\nCalculando resultado da equacao %s", equacao);
   Calc * calc = calc_cria();
   printf("\nResultado: %.0f",calc_calcula(calc, equacao));
   printf("\n");
   

   return 0;
}

