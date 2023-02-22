#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "menu.h"

int main() {
  
  listaAlunos *alunos = criaListaAlunos();
  listaProfessores *professores = criaListaProfessores();
  listaProjetos *projetos = criaListaProjetos();
  listaVinculos *vinculos = criaListaVinculos();

  menu(alunos, professores, projetos, vinculos);

  // listaAlunos * alunos = criaListaAlunos();
  // insereAluno(alunos, 125125, 3436634, "Cachorro\0");
  // insereAluno(alunos, 122211, 431121, "Gato\0");
  // imprimeAlunos(alunos);

  // printf("\n\n");

  // listaProfessores * professores = criaListaProfessores();
  // insereProfessor(professores, 232, "ração\0", "Cachorro Mestre\0");
  // insereProfessor(professores, 675, "areia de gato\0", "Gato Mestre\0");
  // imprimeProfessores(professores);

  // printf("\n\n");

  // listaProjetos * projetos = criaListaProjetos();
  // insereProjeto(projetos, 2153, "Projeto 1\0", "asfios iao ais\0", 3453, 2385.4, buscaProfessor(professores, 232));
  // insereProjeto(projetos, 35335, "oidpjds sdfpjodsf\0", "asido 120ihore\0", 8534.6, 212.4, buscaProfessor(professores, 675));
  // imprimeProjetos(projetos);

  // printf("\n\n");

  // listaVinculos * vinculos = criaListaVinculos();
  // insereVinculo(vinculos, buscaAluno(alunos, 125125) , buscaProjeto(projetos, 2153) , 215.5);
  // insereVinculo(vinculos, buscaAluno(alunos, 122211) , buscaProjeto(projetos, 35335) , 5567.5);
  // imprimeVinculos(vinculos);
  // excluiVinculo(vinculos, 122211, 35335);
  // imprimeVinculos(vinculos);

  //Aluno *vinculado, Projeto *proj, float valorBolsa

  return 0;
}