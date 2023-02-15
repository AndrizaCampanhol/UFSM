#include "stdlib.h"
#include "stdio.h"
#include "grafo.h"

void imprime_tab (Grafo * grafo, int vertice);
void encontra_mais_popular(Grafo * grafo);


void imprime_tab (Grafo * grafo, int vertice)
{
    static int tab = 0;
    static int v2 = -1;
    static int prof = 0;
    int x;
    for(x=0;x<tab;x++)
        printf("   ");
    if (v2!=-1)
        printf("%d -- %d (%d)\n", v2,vertice, grafo_busca_aresta(grafo, v2, vertice));

    if (prof==3) return;

    tab+=1;
    int num_vertices = 0;
    int * vertices = grafo_busca_vertices_saida(grafo, vertice, &num_vertices);
    int total_vertices = grafo_qtd_vertices(grafo);
    int i = 0;
    for (i=0;i<num_vertices;i++){
        v2 = vertice;
        prof++;
        imprime_tab(grafo, vertices[i]);
    }
    tab-=1;
}

void encontra_mais_popular(Grafo * grafo)
{
    int verMaisPopular = -1; 
    int valorAresta = -1;
    int popularidade = 0;
    int soma = 0;
    int totalVertices = grafo_qtd_vertices(grafo);

    for (int i = 0; i < totalVertices; i++) {
        for (int j = 0; j < totalVertices; j++) {
            valorAresta = grafo_busca_aresta(grafo, j, i);
            if (valorAresta != -1) {
                soma += valorAresta;
            }
            if (soma > popularidade) {
                popularidade = soma;
                verMaisPopular = i;
            }
        }
        soma = 0;
    }
    printf("O vertice mais popular é %d com popularidade %d\n", verMaisPopular, popularidade);
}


int main()
{
   Grafo * grafo = grafo_cria();

   grafo_insere_aresta(grafo, 1, 2, 1);
   grafo_insere_aresta(grafo, 1, 3, 1);
   grafo_insere_aresta(grafo, 1, 4, 1);

   grafo_insere_aresta(grafo, 2, 3, 1);
   grafo_insere_aresta(grafo, 2, 4, 1);
   grafo_insere_aresta(grafo, 3, 4, 1);

   grafo_insere_aresta(grafo, 4, 8, 10);

   printf("Imprime no TAD:\n");
   grafo_imprime_tab(grafo, 1);

   printf("\nImprime na main:\n");
   imprime_tab(grafo, 1);

    int cont = 0;
    int vertice = 1;
    int * vertices = grafo_busca_vertices_saida(grafo, vertice, &cont);
    int i;
    printf("Os vertices de saida do vertice %d sao:\n", vertice );
    for (i=0;i<cont;i++){
        printf("%d\n", vertices[i]);

    }


   encontra_mais_popular(grafo);

   grafo_libera(grafo);

   return 0;
}