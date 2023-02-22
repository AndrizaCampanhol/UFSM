#include <stdlib.h>
#include <stdio.h>

#include "lista.h"
#include "arvore.h"

// ----------------------------------------------- Structs ----------------------------------------------- //

struct curso {
  int codigo;
  char *nome;
  char *centro;
  listaAlunos *alunos;

  struct curso* pai;
  struct curso* esq;
  struct curso* dir;
};

struct arvore {
  Curso * raiz;
};

// ----------------------------------------------- Declaracoes ----------------------------------------------- //

static void arv_insere_no2 (Curso * curso, int codigo, char *nome, char *centro, listaAlunos *alunos);
static void arv_insere (Curso *pai, Curso *filho, int dir);
static int arv_remove_no2(Curso ** curso, int codigo);
static void arv_remove_no3(Curso ** filho);
static Curso * encontra_maior(Curso * curso);
static Curso * encontra_menor(Curso * curso);

// ----------------------------------------------- Criar ----------------------------------------------- //

Arvore * arv_cria () {
  Arvore * arv = (Arvore *) malloc(sizeof(Arvore));
  
  arv->raiz = NULL;
  
  return arv;
}

Curso * arv_cria_no (int codigo, char *nome, char *centro, listaAlunos *alunos) {
  Curso *novo = (Curso *) malloc(sizeof(Curso));
  
  novo->codigo = codigo;
  novo->nome = nome;
  novo->centro = centro;
  novo->alunos = alunos;
  
  novo->esq = NULL;
  novo->dir = NULL;
  novo->pai = NULL;
  
  return novo;
}

// ----------------------------------------------- Inserir ----------------------------------------------- //

static void arv_insere_no (Arvore * arv, int codigo, char *nome, char *centro, listaAlunos *alunos) {
  if (arv->raiz==NULL){
    Curso *filho = arv_cria_no (codigo, nome, centro, alunos);
    arv->raiz = filho;
    return;
  }

  arv_insere_no2(arv->raiz, codigo, nome, centro, alunos);

}

static void arv_insere (Curso *pai, Curso *filho, int dir) {
  if (dir)
    pai->dir = filho;
  else
    pai->esq = filho;

  filho->pai = pai;

}

static void arv_insere_no2 (Curso * curso, int codigo, char *nome, char *centro, listaAlunos *alunos) {
  if (curso==NULL) return;

  if (codigo < curso->codigo) {
    if (curso->esq == NULL){
      Curso * filho = arv_cria_no (codigo, nome, centro, alunos);
      arv_insere(curso, filho, 0);
      return;
    }

    arv_insere_no2(curso->esq, codigo, nome, centro, alunos);
  }
  else {
    if (curso->dir==NULL){
      Curso * filho = arv_cria_no (codigo, nome, centro, alunos);
      arv_insere(curso, filho, 1);
      return;
    }

    arv_insere_no2(curso->dir, codigo, nome, centro, alunos);
  }

}

// ----------------------------------------------- Remover ----------------------------------------------- //

static Curso * encontra_maior(Curso * curso) {
  if (curso->dir==NULL) return curso;
  return encontra_maior(curso->dir);
}

static Curso * encontra_menor(Curso * curso) {
  if (curso->esq==NULL) return curso;
  return encontra_menor(curso->esq);
}


static int arv_remove_no(Arvore * arv, int codigo) {
  if (arv->raiz==NULL) return 0;

  return arv_remove_no2(&(arv->raiz), codigo);
}

static int arv_remove_no2(Curso ** curso, int codigo){
  if (*curso == NULL) return 0;

  if ((*curso)->codigo == codigo) {
    free((*curso)->nome);
    free((*curso)->centro);
    liberaLista((*curso)->alunos);
    free((*curso)->alunos);

    arv_remove_no3(curso);
    return 1;
  }

  if (codigo < (*curso)->codigo)
    return arv_remove_no2(&((*curso)->esq), codigo);
  else return arv_remove_no2(&((*curso)->dir), codigo);

}

static void arv_remove_no3(Curso ** filho) {
  if ((*filho)->esq == NULL && (*filho)->dir == NULL) {
    if ((*filho)->pai == NULL){
      (*filho) = NULL;
      
      return;
    }
    if ((*filho)->pai->esq == (*filho)) {
      (*filho)->pai->esq = NULL;
    }
    else {
      (*filho)->pai->dir = NULL;
    }
    
    free(*filho);
    
    return;
  }
  
  if ((*filho)->esq!=NULL) {
    Curso * maior = encontra_maior((*filho)->esq);
    
    (*filho)->codigo = maior->codigo;
    (*filho)->nome = maior->nome;
    (*filho)->centro = maior->centro;
    (*filho)->alunos = maior->alunos;

    arv_remove_no3(&maior);
    return;
  }

  else {

    Curso * menor = encontra_menor((*filho)->dir);
    (*filho)->codigo = menor->codigo;
    (*filho)->nome = menor->nome;
    (*filho)->centro = menor->centro;
    (*filho)->alunos = menor->alunos;

    arv_remove_no3(&menor);
    return;
  }

}

// ----------------------------------------------- Buscar ----------------------------------------------- //

Curso * buscarCurso(Curso * curso, int codigo){
  if (curso==NULL)
    return NULL;

  if (curso->codigo == codigo)
    return curso;
  if (codigo < curso->codigo)
    return buscarCurso(curso->esq, codigo);

  return buscarCurso(curso->dir, codigo);

}

static Curso* buscaFilho(Curso * curso, int dir) {
  if (dir)
    return curso->dir;
  else return curso->esq;
}

// ----------------------------------------------- Imprimir ----------------------------------------------- //

static void imprimeCursos(Curso * curso) {
  if (curso == NULL)
    return;

  imprimeCursos(buscaFilho(curso,0));

  printf("\nCodigo: %d\nNome: %s\nCentro: %s\n", curso->codigo, curso->nome, curso->centro);

  imprimeCursos(buscaFilho(curso,1));

}

// ----------------------------------------------- Interagir com o Usuario ----------------------------------------------- //

void adicionarCurso(Arvore *arvore) {
  int codigo;
  char *nome = (char *) malloc(50 * sizeof(char));
  char *centro = (char *) malloc(50 * sizeof(char));
  listaAlunos *alunos = criaListaAlunos();

  printf("Insira o codigo: ");
  scanf("%d", &codigo);
  printf("Insira o nome: ");
  scanf(" %50[^\n]", nome);
  printf("Insira o centro: ");
  scanf(" %50[^\n]", centro);
  

  arv_insere_no(arvore, codigo, nome, centro, alunos);
  
  printf("Curso adicionado com sucesso!\n");
}

void removerCurso(Arvore *arvore) {
  int codigo;

  printf("Insira o codigo do curso: ");
  scanf("%d", &codigo);

  if (arv_remove_no(arvore, codigo)) {
    printf("Curso removido com sucesso!\n");
  } else {
    printf("Ocorreu um erro na remocao do curso!\n");
  };
}

void adicionarAluno(Arvore *arvore) {
  int codigo, matricula, ano;
  char *nome;
  Curso *curso;


  printf("Insira o codigo do curso: ");
  scanf("%d", &codigo);

  curso = buscarCurso(arvore->raiz, codigo);

  if (curso == NULL) {
    printf("Curso nao cadastrado!\n");
    return;
  }

  nome = (char *) malloc(50);

  printf("Insira a matricula do aluno: ");
  scanf("%d", &matricula);
  printf("Insira o nome do aluno: ");
  scanf(" %50[^\n]", nome);
  printf("Insira o ano de ingresso do aluno: ");
  scanf("%d", &ano);

  insereAluno(curso->alunos, matricula, ano, nome);
  printf("Aluno adicionado com sucesso!\n");
  
}

void removerAluno(Arvore *arvore) {
  int codigo, matricula;
  Curso *curso;

  printf("Insira o codigo do curso: ");
  scanf("%d", &codigo);

  curso = buscarCurso(arvore->raiz, codigo);

  if (curso == NULL) {
    printf("Curso nao cadastrado!\n");
    return;
  }

  printf("Insira a matricula do aluno: ");
  scanf("%d", &matricula);

  removeAluno(curso->alunos, matricula);
  
}

void imprimirCursos(Arvore *arvore) {
  imprimeCursos(arvore->raiz);
}


void imprimirAlunos(Arvore *arvore) {
  int codigo, matricula;
  Curso *curso;

  printf("Insira o codigo do curso: ");
  scanf("%d", &codigo);

  curso = buscarCurso(arvore->raiz, codigo);

  if (curso == NULL) {
    printf("Curso nao cadastrado!\n");
    return;
  }

  imprimeAlunos(curso->alunos);
  
}

void imprimeRelatorioCursos (Curso *curso) {
  if (curso == NULL)
    return;

  imprimeRelatorioCursos(buscaFilho(curso,0));

  imprimeRelatorioAlunos(curso->alunos, curso->nome, curso->centro);

  imprimeRelatorioCursos(buscaFilho(curso,1));
}

void imprimirRelatorio(Arvore *arvore) {
  imprimeRelatorioCursos(arvore->raiz);
}