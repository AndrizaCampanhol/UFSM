#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista.h"

struct aluno {
  int matricula;
  char *telefone;
  char *nome;

  struct aluno* prox;
};

struct listaAluno {
  Aluno* inicio;
};

struct professor {
  int codigo;
  char *nome;
  char *departamento;

  struct professor* prox;
};

struct listaProfessor {
  struct professor* inicio;
};

struct projeto {
  int codigo;
  char *descri;
  char *tipo;
  float orcamentoAnual;
  float orcamentoAtual;
  Professor* prof;

  struct projeto* prox;
};

struct listaProjeto {
  Projeto* inicio;
};

struct vinculo {
  Aluno* vinculado;
  Projeto* proj;
  float valorBolsa;

  struct vinculo* prox;
};

struct listaVinculo {
  Vinculo* inicio;
};

// ----------------------------------------------- Alunos ----------------------------------------------- //

static Aluno *localizaUltimoAluno(listaAlunos *alunos) {
  Aluno* p = alunos->inicio;
  Aluno* ant = NULL;
  
  while (p != NULL){
    ant = p;
    p = p->prox;
  }

  return ant;
}

listaAlunos *criaListaAlunos() {
  listaAlunos *alunos = (listaAlunos *) malloc(sizeof(listaAlunos));

  alunos->inicio = NULL;

  return alunos;
}

static Aluno *criaAluno(int matricula, char *telefone, char * nome){
  Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
  
  aluno->matricula = matricula;
  aluno->telefone = telefone;
  aluno->nome = nome;
  aluno->prox = NULL;

  return aluno;
}

void insereAluno(listaAlunos *alunos, int matricula, char *telefone, char * nome) {

  Aluno *ant = localizaUltimoAluno(alunos);

  Aluno *al = criaAluno(matricula, telefone, nome);

  if (ant == NULL) {
    alunos->inicio = al;
  } else {                           
    ant->prox = al;
  }

}

Aluno * buscaAluno (listaAlunos *alunos, int matricula)
{
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

void imprimeAlunos (listaAlunos *alunos)
{
  Aluno* a = alunos->inicio;
  
  printf("------------ LISTA DE ALUNOS ------------\n");

  while (a != NULL) {
    printf("Matricula: %d\nNome: %s\nTelefone: %s\n\n", a->matricula, a->nome, a->telefone);
    a = a->prox;
  }
  
}

// ----------------------------------------------- Professores ----------------------------------------------- //

static Professor *localizaUltimoProfessor(listaProfessores *professores) {
  Professor* p = professores->inicio;
  Professor* ant = NULL;
  
  while (p != NULL){
    ant = p;
    p = p->prox;
  }

  return ant;
}


listaProfessores *criaListaProfessores() {
  listaProfessores *professores = (listaProfessores *) malloc(sizeof(listaProfessores));

  professores->inicio = NULL;

  return professores;
}

static Professor *criaProfessor(int codigo, char *departamento, char * nome){
  Professor *prof = (Professor *) malloc(sizeof(Professor));
  
  prof->codigo = codigo;
  prof->departamento = departamento;
  prof->nome = nome;
  prof->prox = NULL;

  return prof;
}

void insereProfessor(listaProfessores *professores, int codigo, char *departamento, char * nome) {

  Professor *ant = localizaUltimoProfessor(professores);

  Professor *al = criaProfessor(codigo, departamento, nome);

  if (ant == NULL) {
    professores->inicio = al;
  } else {
    ant->prox = al;
  }

}

Professor * buscaProfessor (listaProfessores *professores, int codigo)
{
  Professor* p = professores->inicio;
  
  while (p != NULL) {
    //printf("%s, %d\n", p->nome, p->codigo);

    if (p->codigo == codigo){
      //printf("%s, %d\n", p->nome, p->codigo);
      return p;
    }
    p = p->prox;
  }
  return NULL;
}


void imprimeProfessores (listaProfessores *professores)
{
  Professor* p = professores->inicio;
  
  printf("------------ LISTA DE PROFESSORES ------------\n");

  while (p != NULL) {
    printf("Codigo: %d\nNome: %s\nDepartamento: %s\n\n", p->codigo, p->nome, p->departamento);
    p = p->prox;
  }
  
}

// ----------------------------------------------- Projetos ----------------------------------------------- //


static Projeto *localizaUltimoProjeto(listaProjetos *projetos) {
  Projeto* p = projetos->inicio;
  Projeto* ant = NULL;
  
  while (p != NULL){
    ant = p;
    p = p->prox;
  }

  return ant;
}


listaProjetos *criaListaProjetos() {
  listaProjetos *projetos = (listaProjetos *) malloc(sizeof(listaProjetos));

  projetos->inicio = NULL;

  return projetos;
}

static Projeto *criaProjeto(listaProjetos *projetos, int codigo, char * descri, char * tipo, float orcamentoAnual, float orcamentoAtual, Professor *prof){
  Projeto *proj = (Projeto *) malloc(sizeof(Projeto));
  
  proj->codigo = codigo;
  proj->descri = descri;
  proj->orcamentoAnual = orcamentoAnual;
  proj->orcamentoAtual = orcamentoAtual;
  proj->tipo = tipo;
  proj->prof = prof;
  proj->prox = NULL;

  return proj;
}

void insereProjeto(listaProjetos *projetos, int codigo, char * descri, char * tipo, float orcamentoAnual, float orcamentoAtual, Professor *prof) {

  Projeto *ant = localizaUltimoProjeto(projetos);

  Projeto *al = criaProjeto(projetos, codigo, descri, tipo, orcamentoAnual, orcamentoAtual, prof);

  if (ant == NULL) {
    projetos->inicio = al;
  } else {
    ant->prox = al;
  }

}

Projeto * buscaProjeto (listaProjetos *projetos, int codigo)
{
  Projeto* p = projetos->inicio;
  
  while (p != NULL) {
    if (p->codigo == codigo){
      return p;
    }
    p = p->prox;
  }
  return NULL;
}

void imprimeProjetos (listaProjetos *projetos)
{
  Projeto* p = projetos->inicio;
  
  printf("------------ LISTA DE PROJETOS ------------\n");

  while (p != NULL) {
    printf("Codigo: %d\nDescricao: %s\nTipo: %s\nOrcamento Aprovado: R$%.2f\nOrcamento Atual: R$%.2f\nProfessor: %s (%d)\n\n", p->codigo, p->descri, p->tipo, p->orcamentoAnual, p->orcamentoAtual, p->prof->nome, p->prof->codigo);
    p = p->prox;
  }
  
}

float buscaOrcamentoAtualProjeto (listaProjetos *projetos, int codigo) {
  Projeto *proj = buscaProjeto(projetos, codigo);

  return proj->orcamentoAtual;
}

// ----------------------------------------------- Vinculos ----------------------------------------------- //

Vinculo * buscaVinculo (listaVinculos *vinculos, int matricula, int codigo)
{
  Vinculo* v = vinculos->inicio;
  
  while (v != NULL) {
    if (v->proj->codigo == codigo && v->vinculado->matricula == matricula){
      return v;
    }
    v = v->prox;
  }

  return NULL;

}

Vinculo * buscaVinculoAnterior (listaVinculos *vinculos, int matricula, int codigo)
{
  Vinculo* v = vinculos->inicio;
  Vinculo* ant = NULL;
  
  while (v != NULL) {
    if (v->proj->codigo == codigo && v->vinculado->matricula == matricula){
      return ant;
    }
    ant = v;
    v = v->prox;
  }

  return NULL;

}

static Vinculo *localizaUltimoVinculo(listaVinculos *vinculos) {
  Vinculo* p = vinculos->inicio;
  Vinculo* ant = NULL;
  
  while (p != NULL){
    ant = p;
    p = p->prox;
  }

  return ant;
}


listaVinculos *criaListaVinculos() {
  listaVinculos *vinculos = (listaVinculos *) malloc(sizeof(listaVinculos));

  vinculos->inicio = NULL;

  return vinculos;
}

static Vinculo *criaVinculo(listaVinculos *vinculos, Aluno *vinculado, Projeto *proj, float valorBolsa) {
  Vinculo *vinc = (Vinculo *) malloc(sizeof(Vinculo));
  
  vinc->vinculado = vinculado;
  vinc->proj = proj;
  vinc->valorBolsa = valorBolsa;
  vinc->prox = NULL;

  proj->orcamentoAtual = (proj->orcamentoAtual - (valorBolsa * 12));

  return vinc;
}

void insereVinculo(listaVinculos *vinculos, Aluno *vinculado, Projeto *proj, float valorBolsa) {

  Vinculo *ant = localizaUltimoVinculo(vinculos);

  Vinculo *al = criaVinculo(vinculos, vinculado, proj, valorBolsa);

  if (ant == NULL) {
    vinculos->inicio = al;
  } else {
    ant->prox = al;
  }

}

void excluiVinculo(listaVinculos *vinculos, listaProjetos *projetos, int matricula, int codigo, int quantMeses) {
  Vinculo *v = buscaVinculo(vinculos, matricula, codigo);
  Vinculo *ant = buscaVinculoAnterior(vinculos, matricula, codigo);
  Projeto *proj = buscaProjeto(projetos, codigo);

  if (v == NULL) {
    printf("Vinculo nao encontrado!\n");
    return;
  }

  printf("Vinculo = %s - %d\n", v->vinculado->nome, v->proj->codigo);

  proj->orcamentoAtual = (proj->orcamentoAtual + (v->valorBolsa * quantMeses));

  if (ant == NULL) {
    vinculos->inicio = v->prox;
  } else {
    //printf("Anterior = %s - %d\n", ant->vinculado->nome, ant->proj->codigo);
    ant->prox = v->prox;
  }

  free(v);

  printf("Vinculo removido com sucesso!\n");
  
}

void imprimeVinculos (listaVinculos *vinculos)
{
  Vinculo* p = vinculos->inicio;
  
  printf("------------ LISTA DE VINCULOS ------------\n");

  while (p != NULL) {
    printf("Aluno: %s (%d)\nProjeto: %d\nBolsa (valor mensal): R$%.2f\n\n", p->vinculado->nome, p->vinculado->matricula, p->proj->codigo, p->valorBolsa);
    p = p->prox;
  }
  
}

// ----------------------------------------------- Relatorio ----------------------------------------------- //

static void vinculosProjeto (listaVinculos *vinculos, int codigo)
{
  Vinculo* v = vinculos->inicio;
  int existemVinculados = 0;
  
  while (v != NULL) {
    if (v->proj->codigo == codigo){
      existemVinculados = 1;
      printf("\t%s\n", v->vinculado->nome);
    }
    v = v->prox;
  }

  if (existemVinculados == 0) {
    printf("Nao ha alunos vinculados a este projeto!\n");
  }

}

void imprimirRelatorio (listaProjetos *projetos, listaVinculos *vinculos) {
  Projeto* p = projetos->inicio;
  
  printf("------------ RELATORIO DE PROJETOS ------------\n");

  while (p != NULL) {
    
    printf("Codigo: %d\nTipo: %s\nProfessor: %s\nOrcamento Atual: R$%.2f\n", p->codigo, p->tipo, p->prof->nome, p->orcamentoAtual);
    printf("Vinculados:\n");
    vinculosProjeto(vinculos, p->codigo);
    printf ("\n");

    p = p->prox;
  }
  
}