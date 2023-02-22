typedef struct aluno Aluno;
typedef struct listaAluno listaAlunos;

listaAlunos *criaListaAlunos();
void insereAluno(listaAlunos *alunos, int matricula, int ano, char * nome);
void imprimeAlunos(listaAlunos *alunos);
void removeAluno(listaAlunos *alunos, int matricula);
void liberaLista(listaAlunos *alunos);

void imprimeRelatorioAlunos(listaAlunos *alunos, char *nomeCurso, char *centroCurso);