#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "menu.h"

static void cadastrarAluno(listaAlunos *alunos) {
  int matricula;
  char *telefone = (char *) malloc(20 * sizeof(char));
  char *nome = (char *) malloc(50 * sizeof(char));

  printf("------------ CADASTRAR ALUNO ------------\n");
  printf("Insira a matricula: ");
  scanf("%d", &matricula);
  printf("Insira o nome: ");
  scanf(" %50[^\n]", nome);
  printf("Insira o telefone: ");
  scanf(" %20[^\n]", telefone);

  insereAluno(alunos, matricula, telefone, nome);

  printf("Aluno cadastrado com sucesso!\n");
}

static void cadastrarProfessor(listaProfessores *professores) {
  int codigo;
  char *nome = (char *) malloc(50 * sizeof(char));
  char *departamento = (char *) malloc(50 * sizeof(char));

  printf("------------ CADASTRAR PROFESSOR ------------\n");
  printf("Insira o codigo: ");
  scanf("%d", &codigo);
  printf("Insira o nome: ");
  scanf(" %50[^\n]", nome);
  printf("Insira o departamento: ");
  scanf(" %50[^\n]", departamento);

  insereProfessor(professores, codigo, departamento, nome);

  printf("Professor cadastrado com sucesso!\n");
}

static void cadastrarProjeto(listaProjetos *projetos, listaProfessores *professores) {
  int codigo, codigoProfessor;
  float orcamentoAnual, orcamentoAtual;
  
  char *descricao = (char *) malloc(100 * sizeof(char));
  char *tipo = (char *) malloc(10 * sizeof(char));

  printf("------------ CADASTRAR PROJETO ------------\n");
  printf("Insira o codigo: ");
  scanf("%d", &codigo);
  printf("Insira a descricao: ");
  scanf(" %100[^\n]", descricao);
  printf("Insira o tipo (ensino, pesquisa ou extensao): ");
  scanf(" %10[^\n]", tipo);
  printf("Insira o orcamento: ");
  scanf("%f", &orcamentoAnual);
  orcamentoAtual = orcamentoAnual;
  printf("Insira o codigo do professor responsavel: ");
  scanf("%d", &codigoProfessor);

  Professor *prof = buscaProfessor(professores, codigoProfessor);

  if (prof == NULL) {
    printf("Professor nao cadastrado!\n");
    
    free(descricao);
    free(tipo);

    return;
  }
  
  insereProjeto(projetos, codigo, descricao, tipo, orcamentoAnual, orcamentoAtual, prof);

  printf("Projeto cadastrado com sucesso!\n");
}

static void cadastrarVinculo(listaVinculos *vinculos, listaAlunos *alunos, listaProjetos *projetos) {
  float valorBolsa, orcamentoAtual;
  int codigoProjeto, matriculaAluno;

  printf("------------ CADASTRAR VINCULO ------------\n");
  printf("Insira o codigo do projeto: ");
  scanf("%d", &codigoProjeto);

  Projeto *proj = buscaProjeto(projetos, codigoProjeto);
  if (proj == NULL) {
    printf("Projeto nao cadastrado!\n");
    return;
  }

  printf("Insira a matricula do aluno: ");
  scanf("%d", &matriculaAluno);

  Aluno *al = buscaAluno(alunos, matriculaAluno);
  if (al == NULL) {
    printf("Aluno nao cadastrado!\n");
    return;
  }

  printf("Insira o valor da bolsa: ");
  scanf("%f", &valorBolsa);

  orcamentoAtual = buscaOrcamentoAtualProjeto(projetos, codigoProjeto);

  if (orcamentoAtual >= (valorBolsa * 12)) {
    insereVinculo(vinculos, al, proj, valorBolsa);
  } else {
    printf("O orcamento atual do projeto nao e suficiente!\n");
    return;
  }

  printf("Vinculo cadastrado com sucesso!\n");

}

static void removerVinculo(listaVinculos *vinculos, listaProjetos *projetos, listaAlunos *alunos) {
  int matriculaAluno, codigoProjeto, quantMeses;

  printf("------------ REMOVER VINCULO ------------\n");
  printf("Insira o codigo do projeto: ");
  scanf("%d", &codigoProjeto);

  printf("Insira a matricula do aluno: ");
  scanf("%d", &matriculaAluno);

  printf("Insira a quantidade de meses em que a bolsa nao sera mais paga: ");
  scanf("%d", &quantMeses);

  excluiVinculo(vinculos, projetos, matriculaAluno, codigoProjeto, quantMeses);

}

// menu que interage com as outras funcoes
void menu(listaAlunos *alunos, listaProfessores *professores, listaProjetos *projetos, listaVinculos *vinculos) {
  int opcao = 1;

  insereAluno(alunos, 1234, "3436623534\0", "Iuri\0");
  insereAluno(alunos, 9876, "43324231121\0", "Andriza\0");
  insereProfessor(professores, 1122, "TI\0", "Fabio\0");
  insereProfessor(professores, 9988, "Ensino\0", "Vanice\0");
  insereProjeto(projetos, 1123, "Projeto 1\0", "asfios iao ais\0", 3000, 3000, buscaProfessor(professores, 1122));
  insereProjeto(projetos, 9987, "Projeto 2\0", "asido 120ihore\0", 8000, 8000, buscaProfessor(professores, 9988));
  insereVinculo(vinculos, buscaAluno(alunos, 1234) , buscaProjeto(projetos, 1123) , 200);
  insereVinculo(vinculos, buscaAluno(alunos, 9876) , buscaProjeto(projetos, 9987) , 400);
  
  // apresentar o menu enquanto nao escolher 0 para sair
  while (opcao != 0) {
    printf("\n------------ MENU INICIAL ------------\n");
    printf("Insira uma das opcoes abaixo ou digite 0 para sair!\n");
    printf("1  - Cadastrar alunos\n");
    printf("2  - Cadastrar professores\n");
    printf("3  - Cadastrar projetos\n");
    printf("4  - Vincular aluno a projeto\n");
    printf("5  - Listar alunos\n");
    printf("6  - Listar professores\n");
    printf("7  - Listar projetos\n");
    printf("8  - Listar vinculos\n");
    printf("9  - Excluir vinculos\n");
    printf("10 - Imprimir relatorio\n");
    scanf("%d", &opcao);
    
    if (opcao == 0) {

    } 
    
    else if (opcao == 1) {
      cadastrarAluno(alunos);    
    } 
    
    else if (opcao == 2) {
      cadastrarProfessor(professores);
    } 
    
    else if (opcao == 3) {
      cadastrarProjeto(projetos, professores);
    }

    else if (opcao == 4) {
      cadastrarVinculo(vinculos, alunos, projetos);
    }

    else if (opcao == 5) {
      imprimeAlunos(alunos);
    }

    else if (opcao == 6) {
      imprimeProfessores(professores);
    }

    else if (opcao == 7) {
      imprimeProjetos(projetos);
    }

    else if (opcao == 8) {
      imprimeVinculos(vinculos);
    }

    else if (opcao == 9) {
      removerVinculo(vinculos, projetos, alunos);
    }
    
    else if (opcao == 10) {
      imprimirRelatorio(projetos, vinculos);
    }

    // se opcao nao for entre as acima, esta errado
    else {
      printf("Opcao Invalida!\n");
    }

  }
  
}