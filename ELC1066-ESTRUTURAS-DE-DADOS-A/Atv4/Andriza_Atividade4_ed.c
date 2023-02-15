#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//função que retorna um vetor de caracteres com um prefixo de outro vetor passado como argumento (com return)
char * quebrar (char* s1, int n){
   char *s2 = (char *) malloc(n+1);
   //testa alocação de memoria
   if(s2 == NULL){
      printf("Erro na alocação de memória!");
      exit(1);
   }
   int i;
   for(i=0; i<n; i++){
      s2[i] = s1[i];
   } 
   s2[i] = '\0';
   return s2;
}

//função que retorna (por referencia) um vetor de caracteres com um prefixo de outro vetor passado como argumento
void quebrar2 (char* s1, int n, char** s3){
   (*s3) = (char *) malloc(n+1);
   //testa alocação de memoria
   if(s3 == NULL){
      printf("Erro na alocação de memória!");
      exit(1);
   }
   int i;
   for(i=0; i<n; i++){
      (*s3)[i] = s1[i];
   }
   (*s3)[i] = '\0';
}

int main(){
   char s1[] = "joao do pulo";
   char * s2, * s3;

   int n = 7;
   s2 = quebrar(s1, n);
   printf("\nOs primeiros %d caracteres de %s sao %s", n, s1, s2);
   //recebe o vetor s2 com um prefixo retornado (return) pela função quebrar

   quebrar2(s1, n, &s3);
   printf("\nOs primeiros %d caracteres de %s sao %s", n, s1, s3);
   //chama a função quebrar2, o vetor s3 com um prefixo é retornado (por referencia)

   //libera o espaço de memória alocado
   free(s2);
   free(s3);
   return 0;
}