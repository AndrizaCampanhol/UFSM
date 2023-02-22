#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

// ----------------------------------------------- Structs ----------------------------------------------- //

struct aluno {
  int matricula;
  int ano;
  char *nome;

  struct aluno* prox;
};

struct listaAluno {
  Aluno* inicio;
};

// ----------------------------------------------- Auxiliares ----------------------------------------------- //

static Aluno *localizaAlunoAnterior(listaAlunos *alunos, int matricula) {
  Aluno* p = alunos->inicio;
  Aluno* ant = NULL;

  while (p != NULL && p->matricula < matricula){
    ant = p;
    
    p = p->prox;
  }

  return ant;
}

// ----------------------------------------------- Criar ----------------------------------------------- //

listaAlunos *criaListaAlunos() {
  listaAlunos *alunos = (listaAlunos *) malloc(sizeof(listaAlunos));

  alunos->inicio = NULL;

  return alunos;
}

static Aluno *criaAluno(int matricula, int ano, char * nome){
  Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
  
  aluno->matricula = matricula;
  aluno->ano = ano;
  aluno->nome = nome;
  aluno->prox = NULL;

  return aluno;
}

// ----------------------------------------------- Buscar ----------------------------------------------- //

Aluno * buscaAluno (listaAlunos *alunos, int matricula) {
  Aluno* a = alunos->inicio;

  while (a != NULL) {
    if (a->matricula == matricula){
      //printf("%s, %d\n", a->nome, a->matricula);
      return a;
    }
    a = a->prox;
  }
  return NULL;
}

// ----------------------------------------------- Inserir ----------------------------------------------- //

void insereAluno(listaAlunos *alunos, int matricula, int ano, char * nome) {

  Aluno *al = criaAluno(matricula, ano, nome);

  Aluno *ant = localizaAlunoAnterior(alunos, matricula);
  

  if (ant == NULL) {
    al->prox = alunos->inicio;
    alunos->inicio = al;
    //printf("Anterior = NULL\n");
  } else {                           
    //printf("Anterior = %d\n", ant->matricula);
    al->prox = ant->prox;
    ant->prox = al;
  }
}

// ----------------------------------------------- Remover ----------------------------------------------- //

void removeAluno(listaAlunos *alunos, int matricula) {
  
  Aluno *al = buscaAluno(alunos, matricula);

  if (al == NULL) {
    printf("Aluno nao encontrado!\n");
    return;
  } 
  
  Aluno *ant = localizaAlunoAnterior(alunos, matricula);

  if (ant == NULL) {
    alunos->inicio = al->prox;
  } else {
    ant->prox = al->prox;
  }

  free(al->nome);
  free(al);

  printf("Aluno removido com sucesso!\n");
}

void liberaLista(listaAlunos *alunos) {
  
  Aluno *al = alunos->inicio;
  Aluno *aux;

  while (al != NULL) {
    aux = al->prox;

    free(al->nome);
    free(al);

    al = aux;
  }

  alunos->inicio = NULL;
}

// ----------------------------------------------- Imprimir ----------------------------------------------- //

void imprimeAlunos (listaAlunos *alunos) {
  Aluno* a = alunos->inicio;

  while (a != NULL) {
    printf("\nMatricula: %d\nNome: %s\nAno de Ingresso: %d\n", a->matricula, a->nome, a->ano);
    a = a->prox;
  }
}

void imprimeRelatorioAlunos(listaAlunos *alunos, char *nomeCurso, char *centroCurso) {
  Aluno* a = alunos->inicio;

  while (a != NULL) {
    printf("\nMatricula: %d\nNome: %s\nCurso: %s\nCentro: %s\n", a->matricula, a->nome, nomeCurso, centroCurso);
    a = a->prox;
  }
}