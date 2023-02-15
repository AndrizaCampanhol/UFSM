#include <stdio.h>


int calcula_fatorial (int n);
int calcula_arranjo (int n, int k);
void calcula_arranjo2 (int n, int k, int *r);

/* função para calcular o valor do fatorial */
int calcula_fatorial (int n){
   int i;

   int f = 1;
   for (i = 1; i <= n; i++)
      f *= i;
   return f;
}

/* função para calcular o arranjo utilizando passagem por valor */
int calcula_arranjo (int n, int k){
   int a = (calcula_fatorial(n)) / (calcula_fatorial(n - k));
   return a;
}

/* função para calcular o arranjo utilizando passagem por referencia */
void calcula_arranjo2 (int n, int k, int *r){
   *r = (calcula_fatorial(n)) / (calcula_fatorial(n - k));
}

int main (void){
   int n, r;
   printf("Digite um numero nao negativo:");
   scanf("%d", &n);
   r = calcula_fatorial(n);
   printf("Fatorial = %d\n", r);


   int k = 2;
   //calculo do arranjo usando passagem por valor
   r = calcula_arranjo(n, k); //utiliza a variavel r para receber o valor do arranjo retornado pela função
   printf("Arranjo de %d elementos tomados de %d a %d = %d\n", n,k,k,r);

   //calculo do arranjo usando passagem por referencia
   calcula_arranjo2(n, k, &r); //chama a função e passa o endereço de r, o valor do arranjo é atribuido por meio do ponteiro criado na função
   printf("Arranjo de %d elementos tomados de %d a %d = %d\n", n,k,k,r);

   return 0;
}