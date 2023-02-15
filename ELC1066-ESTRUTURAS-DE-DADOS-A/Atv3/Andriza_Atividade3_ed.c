#include <stdio.h>
#include <stdlib.h>

//função que preenche o vetor (com malloc)
char * cria1(int *vet, int num){
   char *res = (char *) malloc(num * sizeof(char));

   for(int i=0; i<num; i++){
      if(vet[i] > 0){
         res[i] = '+';
      } else if(vet[i] < 0){
         res[i] = '-';
      } else{
         res[i] = '0';
      }
   }
   return res;
}

//função que preenche o vetor (sem malloc)
void cria2(int *vet, int num, char *vet2){
   for(int i=0; i<num; i++){
      if(vet[i] > 0){
         vet2[i] = '+';
      } else if(vet[i] < 0){
         vet2[i] = '-';
      } else{
         vet2[i] = '0';
      }
   }
}

int main(){
   int v[] = {2,-5,0,-6,1};
   int num = 5;

   char * v1 = cria1(v, num);
   //use a função cria1 para preencher o vetor v1

   int i;
   for (i=0; i<num; i++)
      printf("%c ",v1[i]);

   printf("\n");

   char v2[num];
   cria2(v, num, v2);
   //use a função cria2 para preencher o vetor v2

   for (i=0; i<num; i++)
      printf("%c ",v2[i]);

   free(v1);
}