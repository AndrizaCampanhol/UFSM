#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definir o formato do tipo Aluno
struct aluno {
  int mat;
  char nome[81];
  float nota1;
  float nota2;
  float notaFinal;
  char status;
};
typedef struct aluno Aluno;

// funcao para preencher o vetor
void preenche(Aluno *vet, int i, int mat, char *nome, float nota1, float nota2) {
  vet[i].mat = mat;
  vet[i].nota1 = nota1;
  vet[i].nota2 = nota2;

  for (int j = 0; j < strlen(nome); j++) {
    vet[i].nome[j] = nome[j];
  }

  // calcular a nota final
  vet[i].notaFinal = (nota1 + nota2) / 2;

  // verificar se foi aprovado ou reprovado(status)
  if (vet[i].notaFinal >= 7) {
    vet[i].status = 'A';
  } else {
    vet[i].status = 'R';
  }
}

// imprimir dados de todos os alunos
void imprimirDados(Aluno *vet, int tam) {
  
  printf("\nDADOS DOS ALUNOS:\n");
  for (int i = 0; i < tam; i++){
    printf("-> ALUNO %d <-\n", (i + 1));
    printf("Matrícula: %d\n", vet[i].mat);
    printf("Nome: %s\n", vet[i].nome);
    printf("Nota 1: %.2f\n", vet[i].nota1);
    printf("Nota 2: %.2f\n", vet[i].nota2);
    printf("Nota Final: %.2f\n", vet[i].notaFinal);
    printf("Status: %c\n", vet[i].status);
  }
}

// imprimir nomes dos alunos aprovados
void nomesAprovados(Aluno *vet, int tam){
  printf("\nNOME(S) DO(S) ALUNO(S) APROVADO(S): \n");
  for (int i = 0; i < tam; i++){
    if (vet[i].notaFinal >= 7){
      printf("%s\n", vet[i].nome);
    }
  }
}

// imprimir matrícula dos alunos reprovados
void matriculasReprovados(Aluno *vet, int tam) {
  printf("\nMATRICULA(S) DO(S) ALUNO(S) REPROVADO(S): \n");
  for (int i = 0; i < tam; i++){
    if (vet[i].notaFinal < 7){
      printf("%d\n", vet[i].mat);
    }
  }
}

// calcular e retornar a média da turma
float calcularMedia(Aluno *vet, int tam) {
  float soma = 0, media = 0;

  for (int i = 0; i < tam; i++) {
    soma += vet[i].notaFinal;
  }

  media = soma/tam;

  return media;
}

// imprimir número de alunos acima da média
void acimaMedia(Aluno *vet, int tam, float media) {
  int numAlunos = 0;

  for (int i = 0; i < tam; i++) {
    if (vet[i].notaFinal > media) {
      numAlunos++;
    }
  }

  printf("\nNUMERO DE ALUNOS ACIMA DA MEDIA DA TURMA: %d\n", numAlunos);
}

// imprimir numero de alunos abaixo
void abaixoMedia(Aluno *vet, int tam, float media) {
  int numAlunos = 0;

  for (int i = 0; i < tam; i++) {
    if (vet[i].notaFinal < media) {
      numAlunos++;
    }
  }

  printf("\nNUMERO DE ALUNOS ABAIXO DA MEDIA DA TURMA: %d\n", numAlunos);
}

// imprimir nomes dos alunos aprovados, mas que estao abaixo da media da turma
void nomeAprovadosAbaixo(Aluno *vet, int tam, float media){
  printf("\nNOME DOS ALUNOS APROVADOS ABAIXO DA MÉDIA DA TURMA: \n");
  for (int i = 0; i < tam; i ++){
    if (vet[i].notaFinal >= 7 && vet[i].notaFinal < media){
       printf("%s\n", vet[i].nome);
    }
  }
}

// imprimir nome do(s) aluno(s) com a maior nota
void alunoMaiorNota(Aluno *vet, int tam) {
  float maiorNota = vet[0].notaFinal;

  printf("\nNOME(S) DO(S) ALUNO(S) COM A MAIOR NOTA: \n");

  for (int i = 0; i < tam; i++) {
    if (vet[i].notaFinal > maiorNota) {
      maiorNota = vet[i].notaFinal;
    }
  }
  
  for (int i = 0; i < tam; i++) {
    if (vet[i].notaFinal == maiorNota) {
      printf("%s\n", vet[i].nome);
    }
  }
}

// imprimir nome do(s) aluno(s) com a menor nota
void alunoMenorNota(Aluno *vet, int tam) {
  float menorNota = vet[0].notaFinal;

  printf("\nMATRICULA(S) DO(S) ALUNO(S) COM A MENOR NOTA: \n");

  for (int i = 0; i < tam; i++) {
    if (vet[i].notaFinal < menorNota) {
      menorNota = vet[i].notaFinal;
    }
  }
  
  for (int i = 0; i < tam; i++) {
    if (vet[i].notaFinal == menorNota) {
      printf("%d", vet[i].mat);
    }
  }
}

void main() {
  // vetor de alunos
  Aluno *vet;

  // tamanho do vetor
  int tam;

  // informacoes do aluno a serem informadas
  int mat;
  char nome[81];
  float nota1, nota2;

  float media;

  // pegar tamanho do vetor
  printf("Insira o tamanho do vetor: ");
  scanf("%d", &tam);

  // reservar espaço na memoria
  vet = (Aluno *) malloc(tam * sizeof(Aluno));

  // solicitar as informacoes de cada aluno
  for (int i = 0; i < tam; i++) {
    printf("-> ALUNO %d <-\n", (i + 1));
    printf("Matricula: ");
    scanf("%d", &mat);

    printf("Nome: ");
    scanf("%s", nome);

    printf("Nota 1: ");
    scanf("%f", &nota1);

    printf("Nota 2: ");
    scanf("%f", &nota2);

    // chamar função para preencher o vetor
    preenche(vet, i, mat, nome, nota1, nota2);
  }

  // Imprimir relatorios
  imprimirDados(vet, tam);
  nomesAprovados(vet, tam);
  matriculasReprovados(vet, tam);
  media = calcularMedia(vet, tam);
  printf("MEDIA DA TURMA: %.2f\n", media);
  acimaMedia(vet, tam, media);
  abaixoMedia(vet, tam, media);
  nomeAprovadosAbaixo(vet, tam, media);
  alunoMaiorNota(vet, tam);
  alunoMenorNota(vet, tam);
}