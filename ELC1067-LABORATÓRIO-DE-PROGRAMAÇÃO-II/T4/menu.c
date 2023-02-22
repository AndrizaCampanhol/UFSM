#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include "menu.h"

// menu que interage com as outras funcoes
void menu(Fila *unica, Fila *normal, Fila *alta, Pilha *bandejas) {
  int opcao = 1;
  int idBandeja = 1;
  
  // apresentar o menu enquanto nao escolher 0 para sair
  while (opcao != 0) {
    printf("\n------------ MENU INICIAL ------------\n");
    printf("Insira uma das opcoes abaixo ou digite 0 para sair!\n");
    printf("1  - Adicionar aluno na fila normal\n");
    printf("2  - Adicionar aluno na fila de prioridade alta\n");
    printf("3  - Fundir filas em fila unica para ingresso\n");
    printf("4  - Adicionar bandejas\n");
    printf("5  - Retirada de bandejas pela fila unica\n");
    printf("6  - Retirada de aluno da fila unica\n");
    printf("7  - Imprimir relatorio de filas e pilha de bandejas\n");
    scanf("%d", &opcao);
    
    if (opcao == 0) {
     printf("------------ SAIU! ------------\n");
    } 
    
    else if (opcao == 1) {
      printf("------------ ADICIONANDO ALUNO NA FILA NORMAL ------------\n");
      adicionar_fila(normal);
    } 
    
    else if (opcao == 2) {
      printf("------------ ADICIONANDO ALUNO NA FILA DE ALTA PRIORIDADE ------------\n");
      adicionar_fila(alta);
    } 
    
    else if (opcao == 3) {
      printf("------------ FORMANDO FILA UNICA ------------\n");
      fusao_fila_unica(unica, normal, alta);
    }

    else if (opcao == 4) {
      printf("------------ ADICIONANDO BANDEJAS A PILHA ------------\n");
      pilha_push(bandejas, idBandeja);
      idBandeja++;
    }

    else if (opcao == 5) {
      printf("------------ RETIRANDO BANDEJA ------------\n");
      pilha_pop(bandejas);
    }

    else if (opcao == 6) {
      printf("------------ RETIRANDO ALUNO DA FILA UNICA ------------\n");
      retirar_fila_unica(unica);
    }

    else if (opcao == 7) {
      printf("------------ IMPRIMINDO RELATORIO DE FILAS ------------\n");
      printf("\nFila Unica: \n");
      imprime_fila(unica);
      printf("\nFila de Alta Prioridade: \n");
      imprime_fila(alta);
      printf("\nFila Normal: \n");
      imprime_fila(normal);

      printf("\n------------ IMPRIMINDO PILHA DE BANDEJAS ------------\n");
      imprime_pilha(bandejas);
    }
    
    // se opcao nao for entre as acima, esta errado
    else {
      printf("Opcao Invalida!\n");
    }
  }
}