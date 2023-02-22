#include <stdio.h>
#include "arvore.h"
#include "menu.h"

// menu que interage com as outras funcoes
void menu(Arvore *arvore) {
  int opcao = 1;
  
  // apresentar o menu enquanto nao escolher 0 para sair
  while (opcao != 0) {
    printf("\n------------ MENU INICIAL ------------\n");
    printf("Insira uma das opcoes abaixo ou digite 0 para sair!\n");
    printf("1  - Adicionar curso\n");
    printf("2  - Remover curso\n");
    printf("3  - Adicionar aluno a um curso\n");
    printf("4  - Remover aluno de um curso\n");
    printf("5  - Imprimir cursos\n");
    printf("6  - Imprimir alunos matriculados em um curso\n");
    printf("7  - Imprimir vinculos entre alunos e cursos\n");
    scanf("%d", &opcao);
    
    if (opcao == 0) {
      printf("------------ SAIU! ------------\n");
    } 
    
    else if (opcao == 1) {
      printf("------------ ADICIONANDO CURSO ------------\n");
      adicionarCurso(arvore);
    } 
    
    else if (opcao == 2) {
      printf("------------ REMOVENDO CURSO ------------\n");
      removerCurso(arvore);
      
    } 
    
    else if (opcao == 3) {
      printf("------------ ADICIONANDO ALUNO A UM CURSO ------------\n");
      adicionarAluno(arvore);
    }

    else if (opcao == 4) {
      printf("------------ REMOVENDO ALUNO DE UM CURSO ------------\n");
      removerAluno(arvore);
    }

    else if (opcao == 5) {
      printf("------------ IMPRIMINDO CURSOS ------------\n");
      imprimirCursos(arvore);
    }

    else if (opcao == 6) {
      printf("------------ IMPRIMINDO ALUNOS MATRICULADOS EM UM CURSO ------------\n");
      imprimirAlunos(arvore);
    }

    else if (opcao == 7) {
      printf("------------ IMPRIMINDO VINCULOS ENTRE ALUNOS E CURSOS ------------\n");
      imprimirRelatorio(arvore);

    }

    // se opcao nao for entre as acima, esta errado
    else {
      printf("Opcao Invalida!\n");
    }

  }
  
}