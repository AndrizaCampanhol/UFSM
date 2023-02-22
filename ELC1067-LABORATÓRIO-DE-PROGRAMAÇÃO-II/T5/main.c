#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "arvore.h"
#include "menu.h"

int main() {
  listaAlunos *alunos = criaListaAlunos();
  Arvore *arvore = arv_cria();
  
  menu(arvore);

  return 0;
}