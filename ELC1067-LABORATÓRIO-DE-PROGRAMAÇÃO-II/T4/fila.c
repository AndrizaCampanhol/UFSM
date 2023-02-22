#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

typedef struct no {
  int ticket;
  struct no* prox;
} No;

struct fila {
  No* ini;
  No* fim;
};

Fila* fila_cria () {
  Fila* f = (Fila*) malloc(sizeof(Fila));
  
  f->ini = NULL;
  f->fim = NULL;
  
  return f;
}

static int fila_vazia (Fila* f) {
  return (f->ini==NULL);
}

static void fila_insere (Fila* f, int ticket) {
  No *n = (No *) malloc(sizeof (No));

  n->ticket = ticket;
  n->prox = NULL;

  if (f->fim != NULL){
    f->fim->prox = n;
  } else {
    f->ini = n;
  }
  f->fim = n;
}

static void fila_retira (Fila *f) {
  if (fila_vazia(f)) {
    printf("A fila esta vazia!\n");
    return;
  }

  No* t = f->ini;
  int v = t->ticket;
  f->ini = t->prox;
  if (f->ini == NULL) {
    f->fim = NULL;
  }
  free(t);

  printf("O aluno foi retirado da fila!\n");
}

static void fila_libera (Fila* f) {
  No* q = f->ini;

  while (q != NULL) {
    No* t = q->prox;
    free(q);
    q = t;
  }
  free(f);
}

static int tamanho_fila (Fila *f) {
  if (fila_vazia(f)) {
    return 0;
  }

  int quantidade = 0;
  No *pessoa = f->ini;

  while (pessoa != NULL){
    quantidade++;
    
    pessoa = pessoa->prox;
  }
  return quantidade;
}

static void move_fila_unica (Fila *unica, Fila *outra) {
  No *elemento = outra->ini;
  
  // retira da outra fila
  outra->ini = elemento->prox;
  if (outra->ini == NULL) {
    outra->fim = NULL;
  }

  //insere na fila unica
  elemento->prox = NULL;
  if (unica->fim != NULL) {
    unica->fim->prox = elemento;
  } else {
    unica->ini = elemento;
  }
  unica->fim = elemento;
}

void adicionar_fila (Fila *f) {
  int ticket;

  printf("Insira o numero do ticket: ");
  scanf("%d", &ticket);

  fila_insere (f, ticket);

  printf("Aluno adicionado com sucesso!\n");
}

void retirar_fila_unica (Fila *f) {
  fila_retira(f);
}

void fusao_fila_unica (Fila *unica, Fila *normal, Fila *alta) {
  int quantidade = tamanho_fila(unica);

  if (fila_vazia(alta) && fila_vazia(normal)) {
    printf("A fila normal e de alta prioridade estao vazias!\n");
    return;
  }

  if (quantidade == 10) {
    printf("A fila unica ja esta cheia!\n");
    return;
  }

  for (int i = quantidade; i < 10; i++) {
    if (!fila_vazia(alta)) {
      move_fila_unica(unica, alta);
    } else if (!fila_vazia(normal)) {
      move_fila_unica(unica, normal);
    }
  }
  printf("Fusao realizada com sucesso!\n");
}

void liberar_fila (Fila *f) {
  fila_libera(f);
}

void imprime_fila (Fila *f) {
  if (fila_vazia(f)) {
    printf("A fila esta vazia!\n");
    return;
  }

  int tam;
  No *elemento = f->ini;

  tam = tamanho_fila(f);

  for (int i = 0; i < tam; i++) {
    printf("%d\n", elemento->ticket);
    elemento = elemento->prox;
  }
}