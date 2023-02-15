#include <stdio.h>
#include "lista.h"

int main (void)
{
   No* inicio;                             	/* declara uma lista nao iniciada*/
   lst_cria(&inicio);                  	/* inicia lista vazia*/
   lst_insere_ordenado (&inicio, 5);	/* insere na lista o elemento 5*/
   lst_insere_ordenado (&inicio, 2);	/* insere na lista o elemento 2*/
   lst_insere_ordenado (&inicio, 3);	/* insere na lista o elemento 3*/
   lst_insere_ordenado (&inicio, 1);	/* insere na lista o elemento 1*/
   lst_insere_final (&inicio, 4);      /* insere na lista o elemento 4*/
   lst_imprime (inicio);        		/* imprimira: 1 2 3 5 4*/
   return 0;
}