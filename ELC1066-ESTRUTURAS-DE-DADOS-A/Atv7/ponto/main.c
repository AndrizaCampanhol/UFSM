#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main (void)
{
   Ponto* p = pto_cria(2.0,1.0);
   Ponto* q = pto_cria(3.4,2.1);

   Circulo* c1 = circ_cria(1.0,1.0,3.0);
   Circulo* c2 = circ_cria(0.5,0.5,1.0);

   float circA1 = circ_calcula(c1);
   float circA2 = circ_calcula(c2);

   int verifP = circ_verifica_ponto_interno(c1, p);
   if(verifP == 1){
      printf("O ponto está dentro do circulo!\n");
   }else{
      printf("O ponto está fora do ciruclo!\n");
   }

   int verifC = circ_verifica_circ_interno(c1, c2);
   if(verifC == 1){
      printf("O circulo está dentro do outro!\n");
   }else{
      printf("O circulo está fora do outro!\n");
   }

   float d = pto_calcula_distancia(p,q);
   printf("Distancia entre pontos: %f\n",d);
   
   circ_libera(c1);
   circ_libera(c2);
   pto_libera(q);
   pto_libera(p);
   return 0;
}
