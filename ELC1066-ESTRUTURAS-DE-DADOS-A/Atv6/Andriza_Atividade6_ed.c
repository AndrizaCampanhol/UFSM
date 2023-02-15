#include <stdio.h>
#include <stdlib.h>

struct aluno {
   int mat;
   char nome[81];
   char end[121];
   char tel[21];
};

typedef struct aluno Aluno;

void inicializa (int n, Aluno** tab)
{
   int i;
   for (i=0; i<n; i++)
      tab[i] = NULL;
}

//Usada para realizar a entrada dos dados de um aluno
Aluno* cria_aluno(){
   Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));

   printf("Entre com a matricula:");
   scanf("%d", &aluno->mat);
   printf("Entre com o nome:");
   scanf(" %[^\n]", aluno->nome);
   printf("Entre com o endereco:");
   scanf(" %[^\n]", aluno->end);
   printf("Entre com o telefone:");
   scanf(" %[^\n]", aluno->tel);

   return aluno;
}

//Usada para adicionar um aluno (passado como último parâmetro) no vetor
void preenche (int n, Aluno** tab, int i, Aluno *aluno)
{
   if (i<0 || i>=n) {
      printf("Indice fora do limite do vetor\n");
      exit(1);	/* aborta o programa */
   }

if (tab[i]==NULL){
   tab[i] = (Aluno*)malloc(sizeof(Aluno));
   tab[i] = aluno;
   }
}

void retira (int n, Aluno** tab, int i)
{
   if (i<0 || i>=n) {
      printf("Indice fora do limite do vetor\n");
      exit(1);	/* aborta o programa */
   }

   if (tab[i] != NULL){
      free(tab[i]);
      tab[i] = NULL;  /* indica que na posi��o n�o mais existe dado */
   }
}

void imprime (int n, Aluno** tab, int i)
{
   if (i<0 || i>=n) {
      printf("Indice fora do limite do vetor\n");
      exit(1);	/* aborta o programa */
   }

   if (tab[i] != NULL){
      printf("Matricula: %d\n", tab[i]->mat);
      printf("Nome: %s\n", tab[i]->nome);
      printf("Endereco: %s\n", tab[i]->end);
      printf("Telefone: %s\n", tab[i]->tel);
      printf("-----------------------------\n");
   }
}

void imprime_tudo (int n, Aluno** tab)
{
   int i;
   printf("-----------------------------\n");
   for (i=0; i<n; i++)
      imprime(n,tab,i);
}

//função que insira um aluno na primeira posição do vetor e mova todos os demais alunos uma posição adiante.
void adiciona(int n, Aluno ** tab, Aluno * al){
   for(int i = (n-1); i >= 0; i--){
      if(i > 0){
         tab[i] = tab[i-1];
      }
   }
   tab[0] = al;
}

int main (void)
{
   int tam = 3;

   Aluno* tab[tam];
   Aluno *aluno;

   inicializa(tam,tab);

   aluno = cria_aluno();
   preenche(tam,tab,0, aluno);

   aluno = cria_aluno();
   preenche(tam,tab,1, aluno);

   aluno = cria_aluno();
   preenche(tam,tab,2, aluno);

   printf("Novo aluno na primeira posição\n");
   aluno = cria_aluno();
   adiciona(tam,tab, aluno);

   imprime_tudo(tam,tab);

   retira(tam,tab,0);
   retira(tam,tab,1);
   retira(tam,tab,2);

   free(aluno);
   return 0;
}