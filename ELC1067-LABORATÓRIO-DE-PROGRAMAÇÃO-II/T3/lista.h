typedef struct listaAluno listaAlunos;
typedef struct listaProfessor listaProfessores;
typedef struct listaProjeto listaProjetos;
typedef struct listaVinculo listaVinculos;

typedef struct professor Professor;
typedef struct aluno Aluno;
typedef struct projeto Projeto;
typedef struct vinculo Vinculo;


listaAlunos *criaListaAlunos();
void insereAluno(listaAlunos *alunos, int matricula, char *telefone, char * nome);
void imprimeAlunos(listaAlunos *alunos);
Aluno * buscaAluno (listaAlunos *alunos, int matricula);

listaProfessores *criaListaProfessores();
void insereProfessor(listaProfessores *professores, int codigo, char *departamento, char * nome);
void imprimeProfessores(listaProfessores *professores);
Professor * buscaProfessor (listaProfessores *professores, int codigo);

listaProjetos *criaListaProjetos();
void insereProjeto(listaProjetos *projetos, int codigo, char * descri, char * tipo, float orcamentoAnual, float orcamentoAtual, Professor *prof);
void imprimeProjetos (listaProjetos *projetos);
Projeto * buscaProjeto (listaProjetos *projetos, int codigo);
void imprimirRelatorio (listaProjetos *projetos, listaVinculos *vinculos);

float buscaOrcamentoAtualProjeto (listaProjetos *projetos, int codigo);


listaVinculos *criaListaVinculos();
void insereVinculo(listaVinculos *vinculos, Aluno *vinculado, Projeto *proj, float valorBolsa);
void excluiVinculo(listaVinculos *vinculos, listaProjetos *projetos, int matricula, int codigo, int quantMeses);
void imprimeVinculos (listaVinculos *vinculos);