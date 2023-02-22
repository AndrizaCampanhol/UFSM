#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "fila.h"
#include "menu.h"

int main () {

  Fila *unica = fila_cria();
  Fila *normal = fila_cria();
  Fila *alta = fila_cria();
  Pilha *bandejas = pilha_cria();

  menu(unica, normal, alta, bandejas);

  liberar_fila(unica);
  liberar_fila(normal);
  liberar_fila(alta);
  pilha_libera(bandejas);

  return 0;
}