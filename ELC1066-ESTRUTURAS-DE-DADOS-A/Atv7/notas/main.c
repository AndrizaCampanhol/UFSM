#include <stdio.h>
#include "notas.h"

int main (void)
{
   Notas * n = ntn_cria_notas(50, 70);

   int media = ntn_calcula_media(n);
   printf("media: %d \n", media);

   int nota1, nota2;
   ntn_retorna_notas(n, &nota1, &nota2);

   ntn_modifica_nota1(n, nota1 + 10);
   ntn_modifica_nota2(n, nota2 + 10);

   media = ntn_calcula_media(n);
   printf("nova media: %d \n", media);

   return 0;
}
