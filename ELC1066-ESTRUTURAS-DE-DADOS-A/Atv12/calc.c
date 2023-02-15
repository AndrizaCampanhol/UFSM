#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "calc.h"
#include "pilha.h"


Calc* calc_cria ()
{
   Calc* c = (Calc*) malloc(sizeof(Calc));
   //cria pilha vazia
   c->p = pilha_cria();
   return c;
}


void calc_operando (Calc* c, float v)
{
   /* empilha operando */
   pilha_push(c->p,v);
}

void calc_operador (Calc* c, char op)
{
   float v1, v2, v;

   if (pilha_vazia(c->p))              /* desempilha segundo operando*/
      v2 = 0.0;
   else
      v2 = pilha_pop(c->p);

   if (pilha_vazia(c->p))              /* desempilha segundo operando*/
      v1 = 0.0;
   else
      v1 = pilha_pop(c->p);

   switch (op) {                               /* faz opera��o */
      case '+':    v = v1+v2;     break;
      case '-':     v = v1-v2;      break;
      case '*':     v = v1*v2;     break;
      case '/':     v = v1/v2;      break;
   }

   pilha_push(c->p,v);                     /* empilha resultado */

}

void calc_libera (Calc* c){
   pilha_libera(c->p);
   free(c);
}

float calc_calcula (Calc* c, char * equacao){
   for(int i=0; equacao[i] != '\0'; i++){
      if(equacao[i] < '0'){
         calc_operador(c, equacao[i]);
      }else{
         calc_operando(c, (float)(equacao[i] - 48));
      }
   }
   return pilha_pop(c->p);
}
