#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct municipio
{
 char* nome;
 int populacao;
 int** dados; //matriz de dados
};
typedef struct municipio Municipio;

// funcao para preencher o vetor
void preenche(Municipio *vetMunicipio, int numDias , int i) {

  int numColunas = 3;

  vetMunicipio[i].nome = (char *) malloc(40 * sizeof(char));
  
  // recebe os dados
  printf("\n-> MUNICÍPIO %d <-\n", (i + 1));
  printf("Nome: ");
  scanf(" %40[^\n]", vetMunicipio[i].nome);

  printf("População: ");
  scanf("%d", &vetMunicipio[i].populacao);

  // aloca espaco para o vetor de dias de todos os municipios
  vetMunicipio[i].dados = (int **) malloc(numDias * sizeof(int *));
  // aloca espaco para o vetor de dados de cada dia
  for (int l = 0; l < numDias; l++) {
    vetMunicipio[i].dados[l] = (int *) malloc(numColunas * sizeof(int));
  }

  // percorre e preenche a matriz de dados do municipio
  for (int l = 0; l < numDias; l++) {
    for (int j = 0; j < numColunas; j++) {
      if (j == 0) {
        vetMunicipio[i].dados[l][j] = l+1;
        printf("Dia %d: \n", vetMunicipio[i].dados[l][j]);
      } else if (j == 1) {
        printf("Insira a quantidade de casos no dia: ");
        scanf("%d", &vetMunicipio[i].dados[l][j]);
      } else {
        printf("Insira a quantidade de óbitos no dia: ");
        scanf("%d", &vetMunicipio[i].dados[l][j]);
      }
    }
  }
  
}

// funcao para imprimir os dados gerais, de todos os municipios
void imprimir(Municipio *vetMunicipio, int numMunicipios, int numDias) {
  int confirmados = 0, novosConfirmados, obitos, novosObitos;
  float incidencia, mortalidade;


  printf("\n------------ DADOS EPIDEMIOLOGICOS ------------\n");

  for (int l = 0; l < numMunicipios; l++) {
    printf("\n");
    
    //limpar as variaveis
    confirmados = 0;
    novosConfirmados = 0;
    incidencia = 0;
    obitos = 0;
    novosObitos = 0;
    mortalidade = 0;

    //percorrer a matriz de dados
    for (int j = 0; j < numDias; j++) {
      confirmados += vetMunicipio[l].dados[j][1];
      obitos += vetMunicipio[l].dados[j][2];
    }
    
    novosConfirmados = vetMunicipio[l].dados[numDias-1][1];
    incidencia = (confirmados * 100000)/vetMunicipio[l].populacao;

    novosObitos = vetMunicipio[l].dados[numDias-1][2];
    mortalidade = (obitos * 100000)/vetMunicipio[l].populacao;;
    
    // imprime os dados, formatados corretamente
    printf("\t%s\nConfirmados: %d\nNovos Confirmados: %d\nIncidencia: %.2f\nObitos: %d\nNovos Obitos: %d\nMortalidade: %.2f\n", vetMunicipio[l].nome, confirmados, novosConfirmados, incidencia, obitos, novosObitos, mortalidade);
  }

}

// busca dados especificos de um municipio
void buscar(Municipio *vetMunicipio, int numMunicipios, int numDias) {
  int numColunas = 3;

  char *nomeMunicipio = (char *) malloc(40 * sizeof(char));
  int posicaoMunicipio = -1;

  printf("\nInsira o nome de um municipio: ");
  scanf(" %40[^\n]", nomeMunicipio);

  // percorre o vetor e acha a posicao em que o nome for igual
  for (int l = 0; l < numMunicipios; l++) {
    if (strcmp(nomeMunicipio, vetMunicipio[l].nome) == 0) {
      posicaoMunicipio = l;
    }
  }

  if (posicaoMunicipio == -1) {
    printf("\nMunicipio nao localizado!\n");
    return;
  }
  
  printf("\n------------ DADOS DO MUNICIPIO ------------\n");
  printf("\n-> %s <-\n", vetMunicipio[posicaoMunicipio].nome);

  printf("População: %d\n", vetMunicipio[posicaoMunicipio].populacao);

  // percorre o vetor de dados do municipio e imprime os dados de cada dia 
  for (int l = 0; l < numDias; l++) {
    for (int j = 0; j < numColunas; j++) {
      if (j == 0) {
        printf("Dia %d:\n", vetMunicipio[posicaoMunicipio].dados[l][j]);
      } else if (j == 1) {
        printf("Quantidade de casos: %d\n", vetMunicipio[posicaoMunicipio].dados[l][j]);
      } else {
        printf("Quantidade de óbitos: %d\n", vetMunicipio[posicaoMunicipio].dados[l][j]);
      }
    }
  }
}

// menu que interage com as outras funcoes
void menu(Municipio *vetMunicipio, int numMunicipios, int numDias) {
  int opcao = 1;
  int preenchido = 0;

  // apresentar o menu enquanto nao escolher 0 para sair
  while (opcao != 0) {
    printf("\n------------ MENU INICIAL ------------\n");
    printf("Insira uma das opções abaixo ou digite 0 para sair!\n");
    printf("1 - Inserir dados\n");
    printf("2 - Listar dados epidemiológicos gerais\n");
    printf("3 - Buscar município na lista\n");
    scanf("%d", &opcao);
    
    if (opcao == 0) {

    } 
    // se opcao for 1, para cada municipio do vetor, chama a funcao preenche
    else if (opcao == 1) {
      if (preenchido == 1){
        printf("Você já inseriu a(s) %d cidade(s)!\n", numMunicipios);
      } else {
        for (int i = 0; i < numMunicipios; i++) {
          preenche(vetMunicipio, numDias, i);
        }
        preenchido = 1;
      }
    
    } 
    // se opcao for 2 e o vetor ja estiver preenchido, imprime os dados gerais
    else if (opcao == 2) {
    
      if (preenchido == 1) {
        imprimir(vetMunicipio, numMunicipios, numDias);
      } else {
        printf("Você ainda não inseriu nenhum dado!\n");
      }
    
    } 
    // se opcao for 3 e o vetor ja estiver preenchido, imprime os dados especificos
    else if (opcao == 3) {
    
      if (preenchido == 1) {
        buscar(vetMunicipio, numMunicipios, numDias);
      } else {
        printf("Você ainda não inseriu nenhum dado!\n");
      }
    
    }
    // se opcao nao for entre as acima, esta errado
    else {
      printf("Opcao Invalida!\n");
    }

  }
  
}

// prepara o ambiente
int main() {
  
  // vetor de municipios
  Municipio *vetMunicipios;

  // quantidade de municipios e dias, para calcular o tamanho do vetor e da matriz de dados
  int numMunicipios;
  int numDias;

  printf("Insira o número de municípios: ");
  scanf("%d", &numMunicipios);

  printf("Insira a quantidade de dias: ");
  scanf("%d", &numDias);

  // reservar espaço na memoria para o vetor de Municipios
  vetMunicipios = (Municipio *) malloc(numMunicipios * sizeof(Municipio));

  // chamar o menu principal
  menu(vetMunicipios, numMunicipios, numDias);

  free(vetMunicipios);
  return 0;
}