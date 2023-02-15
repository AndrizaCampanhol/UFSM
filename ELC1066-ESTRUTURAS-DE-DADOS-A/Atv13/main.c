#include "stdlib.h"
#include "stdio.h"
#include "fila.h"

void imprime (Fila * f){
   int tam = fila_tamanho(f);
   int num;
   
   for(int i = 0; i < tam; i++){
      num = fila_retira(f);
      printf("info: %d\n", num);
   }
}

void imprime2 (Fila * f){
   int tam = fila_tamanho(f);
   int num;

   for(int i = 0; i < tam; i++){
      num = fila_retira(f);
      fila_insere(f, num);
      printf("info: %d\n", num);
   }
}

Fila * separaPares (Fila * f){
   Fila *par = fila_cria();
   int tam = fila_tamanho(f);
   int num;

   for(int i = 0; i < tam; i++){
      num = fila_retira(f);
      fila_insere(f, num);

      if((num % 2) == 0){
         fila_insere(par, num);
      }
   }
   return par; 
}

int main (void)
{

   Fila * f = fila_cria();
   fila_insere(f, 10);
   fila_insere(f, 15);
   fila_insere(f, 20);


   int tam = fila_tamanho(f);
   printf("\nTamanho da lista: %d", tam);

   printf("\nElementos\n");
   imprime(f);
   
   fila_insere(f, 40);
   fila_insere(f, 45);
   fila_insere(f, 50);

   printf("\nElementos\n");
   imprime2(f);

   printf("\n\nElementos pares\n");
   Fila * f2 = separaPares(f);
   imprime2(f2);
   return 0;
}