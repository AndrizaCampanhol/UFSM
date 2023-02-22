#include "lista.h"

typedef struct arvore Arvore;
typedef struct curso Curso;

Arvore * arv_cria ();

void adicionarCurso(Arvore *arvore);
void imprimirCursos(Arvore *arvore);
void removerCurso (Arvore *arvore);
void adicionarAluno(Arvore *arvore);
void imprimirAlunos(Arvore *arvore);
void removerAluno(Arvore *arvore);

void imprimirRelatorio(Arvore *arvore);