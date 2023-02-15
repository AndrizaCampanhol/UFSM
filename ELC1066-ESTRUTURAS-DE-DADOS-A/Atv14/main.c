#include "stdlib.h"
#include "stdio.h"
#include "lista.h"


void imprime(No_Het * no)
{
   No_Het *p = no;

   while(p != NULL){
      printf("\nTipo: %s", no_het_recupera_tipo(p));
      printf("\nArea: %.2f", no_het_calcula_area(p));
      p = no_het_proximo(p);
   }
}

void calculaMaiorArea(No_Het * no)
{
   No_Het *p = no;
   float area, maiorArea; 

   maiorArea = no_het_calcula_area(p);

   while(p != NULL){
      area = no_het_calcula_area(p);

      if(area > maiorArea){
         maiorArea = area;
      }
      p = no_het_proximo(p);
   }
   p = no;

   while(p != NULL){
       area = no_het_calcula_area(p);
       if(area == maiorArea){
           printf("\nMaior area");
           printf("\nTipo: %s", no_het_recupera_tipo(p));
           printf("\nArea: %.2f", area);
           return; 
      }
      p = no_het_proximo(p);
   }
}

int main (void)
{

   No_Het * n1 = no_het_cria_circ(4);

   No_Het * n2 = no_het_cria_ret(10,4);

   No_Het * n3 = no_het_cria_tri(10,4);

    if (!n2 || !n3)
    {
       exit(1);
    }

   no_het_conecta(n1, n2);
   no_het_conecta(n2, n3);

   printf("\n Impressao dos objetos criados");
   printf("\n");
   float area = no_het_calcula_area(n1);
   printf("\n Objeto: %s", no_het_recupera_tipo(n1));
   printf("\n Area: %.2f", area);

   printf("\n");
   area = no_het_calcula_area(n2);
   printf("\n Objeto: %s", no_het_recupera_tipo(n2));
   printf("\n Area: %.2f", area);

   printf("\n");
   area = no_het_calcula_area(n3);
   printf("\n Objeto: %s", no_het_recupera_tipo(n3));
   printf("\n Area: %.2f", area);

   printf("\n");
   printf("\n Impressao de todos objetos encadeados");
   imprime(n1);

   printf("\n");
   calculaMaiorArea(n1);

   return 0;
}