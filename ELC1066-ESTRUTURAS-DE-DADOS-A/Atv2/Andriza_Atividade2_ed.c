#include <stdio.h>

//função que compara os valores
int compara(int *v, int y){
    if(v[y]>v[y+1]){
        return 1;
    } else{
        return 0;
    }
}

//função que troca os valores
int troca(int *v, int y){
    int temp = v[y];
    v[y] = v[y+1];
    v[y+1] = temp;
}

int main ( void )
{
   int v[] = {1,6,7,3,5};

   int x, ord, cont = 0;
   for (x=4;x>0;x--){
       int y;
       cont++;
       for (y=0;y<x;y++){
           if (compara(v, y) == 1)
           {
               troca(v, y);
               ord = 1;
           } else{
               ord = 0;
           }         
       }
       //para a operação, caso todos os valores estiverem ordenados
       if(ord == 0){
           break;
       }
   }

   for (x=0;x<5;x++){
      printf ("%d ", v[x]);
   }
   //imprime o contador que informa quantas vezes o laço é percorrido até ordenar os valores
   printf ("\nO laço foi percorrido %d vezes", cont);
   return 0;
}