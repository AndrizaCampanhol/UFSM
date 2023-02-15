#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

char* lelinha (void);
char* duplica (char* s);
void lenomes (char** alunos, int n);
int le_qtd();
void liberanomes (int n, char** alunos);
void imprimenomes (int n, char** alunos);
int qtde_comeca_letra (int n, char** alunos, char c);
char ** separa_melhores (int n, char** alunos, int x);
void imprimenomes2 (int n, char alunos[][81]);

char* lelinha (void)
{
   char linha[121];                  /* variável auxiliar para ler linha */
   printf("Digite um nome: ");
   scanf(" %120[^\n]",linha);
   return duplica(linha);
}

char* duplica (char* s)
{
   int n = strlen(s);
   char* d = (char*) malloc ((n+1)*sizeof(char));
   strcpy(d,s);
   return d;
}

//usada para ler nomes de n alunos na matriz alunos
void lenomes (char** alunos, int n)
{
   int i;
   for (i=0; i<n; i++)
      alunos[i] = lelinha();
}

//descobre o número de alunos a serem lidos e retorna essa informação
int le_qtd(){
   int n;
   do {
      printf("Digite o numero de alunos: ");
      scanf("%d",&n);
   } while (n>MAX);
   return n;
}

void liberanomes (int n, char** alunos)
{
   int i;
   for (i=0; i<n; i++)
      free(alunos[i]);
}

void imprimenomes (int n, char** alunos)
{
   int i;
   for (i=0; i<n; i++)
      printf("%s\n", alunos[i]);
}

//função que descubre quantos alunos tem nomes que começam com alguma letra
int qtde_comeca_letra (int n, char** alunos, char c){
   int cont = 0;
   for(int i=0; i<n; i++){
      if(alunos[i][0] == c){
         cont++;
      }
   }
   return cont;
}

//função que gera uma nova matriz contendo os x primeiros alunos de uma matriz original
char ** separa_melhores (int n, char** alunos, int x){
   char **novaMatriz = (char **) malloc (x * sizeof(char *));

    printf("\nAlunos da nova Matriz:\n");

   for (int i = 0; i < x; i++) {
      int tam = strlen(alunos[i]);
      novaMatriz[i] = (char *) malloc(tam);

      novaMatriz[i] = alunos[i];
      printf("%s\n", novaMatriz[i]);
   }
   return novaMatriz;
   free(novaMatriz);
}

//essa versao nao funciona. Voce consegue entender porque?
/*porque há incompatibilidade na passagem de parametros, 
pois alunos é declarado como ponteiro para um vetor de ponteiros na main (char** alunos)
e a função recebe valores, não endereços*/
void imprime (int n, char alunos[][81])
{
   int i;
   for (i=0; i<n; i++)
      printf("%s\n", alunos[i]);
}


int main (void)
{
   //char* alunos[MAX];
   int x;
   char c;
   char** alunos = (char **)malloc(sizeof(char*) * MAX);
   char **novaMatriz;

   int num = le_qtd();
   lenomes(alunos, num);

   printf("Insira um caracter a ser pesquisado: ");
   scanf(" %c", &c);
   int quant = qtde_comeca_letra(num, alunos, c);
   printf("\nO numero de alunos que começa com %c é %d \n", c, quant);

   printf("\nInsira o numero de alunos para a nova matriz: ");
   scanf("%d", &x);

   if(x <= num) {
       novaMatriz = (char **) malloc(x * sizeof(char *));
       novaMatriz = separa_melhores(num, alunos, x);
   }else{
      printf("\nNumero inválido! Maior que a quantidade de alunos!\n");
   }

   printf("\nNomes de todos os alunos: \n");
   imprimenomes(num,alunos);
   liberanomes(num,alunos);

   free(novaMatriz);
   return 0;
}