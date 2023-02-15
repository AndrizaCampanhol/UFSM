#include "stdlib.h"
#include "stdio.h"
#include "grafo.h"
#include "limits.h"

struct item{
    Vertice * vertice;
    struct item  * precedente;
    struct item  * prox_item;
};

typedef struct item Item;

typedef struct lista{
    Item * primeiro_item;
    Item * ultimo_item;
} Lista;

void menor_caminho (Grafo * grafo, Vertice * origem, Vertice * destino);

Lista * cria_lista();
Item * adiciona_item(Lista * lista, Vertice * vertice);
Item * busca_item(Lista * lista, Vertice * vertice);

//essa eh a funcao a ser implementada. Ela pode ser inspirada na bfs e usar as funcoes que manipulam lista
void menor_caminho (Grafo * grafo, Vertice * origem, Vertice * destino){
    Lista * lista = cria_lista();
    adiciona_item(lista, origem);
    Item * item = lista->primeiro_item;
    Item * anterior = item;
    
    while (item != NULL){
        int cont = 0;
        Vertice ** v_dest = grafo_busca_vertices_saida(grafo, item->vertice, &cont);

        for (int i=0;i<cont;i++){
            Item * item_ = busca_item(lista, v_dest[i]);
            if (item_ == NULL){
                item_ = adiciona_item(lista, v_dest[i]);
            }
        }
        
        if(item->vertice == destino){
            break;
        }

        //apenas a primeira parte, só encontra o vertice de destino (caminho mais curto)
        //faltam os vertices do caminho (prescedente)
        
        item = item->prox_item;
    }
    
    if (item == NULL) {
        printf("Nao existe um caminho entre os itens!\n");
        return;
    }

    while (item != NULL) {
        printf("%s\n", grafo_retorna_nome(item->vertice));
        item = item->precedente;
    }
}




Lista * cria_lista(){
    Lista * lista = (Lista*) malloc(sizeof(Lista));
    lista->primeiro_item = NULL;
    lista->ultimo_item = NULL;
    return lista;
}

Item * adiciona_item(Lista * lista, Vertice * vertice){
    Item * item = (Item *)malloc(sizeof(Item));
    item->vertice = vertice;
    item->prox_item = NULL;
    item->precedente = NULL;

    if (lista->primeiro_item==NULL){
        lista->primeiro_item = item;
        lista->ultimo_item = item;
    }
    else{
        lista->ultimo_item->prox_item = item;
        lista->ultimo_item = item;
    }
    return item;

}


Item * busca_item(Lista * lista, Vertice * vertice){
    Item * item = lista->primeiro_item;
    while (item!=NULL){
        if (item->vertice == vertice)
            return item;
        item = item->prox_item;
    }
    return NULL;
}


int main()
{
   Grafo * grafo = grafo_cria(10);
   Vertice * vSantaMaria = grafo_cria_vertice(grafo, "Santa Maria");
   Vertice * vRosario = grafo_cria_vertice(grafo, "Rosario do Sul");
   Vertice * vSaoSepe = grafo_cria_vertice(grafo, "Sao Sepe");
   Vertice * vSaoVicente = grafo_cria_vertice(grafo, "Sao Vicente");
   Vertice * vSaoPedro = grafo_cria_vertice(grafo, "Sao Pedro");
   Vertice * vSaoGabriel = grafo_cria_vertice(grafo, "Sao Gabriel");


   grafo_insere_aresta(grafo, vSantaMaria, vRosario, 430); //230
   grafo_insere_aresta(grafo, vSantaMaria, vSaoPedro, 60);
   grafo_insere_aresta(grafo, vSaoPedro, vSantaMaria, 60);
   grafo_insere_aresta(grafo, vSaoPedro, vSaoVicente, 50);
   grafo_insere_aresta(grafo, vSaoVicente, vRosario, 130);
   grafo_insere_aresta(grafo, vSantaMaria, vSaoSepe, 80);
   grafo_insere_aresta(grafo, vSaoSepe, vSaoGabriel, 140);
   grafo_insere_aresta(grafo, vSaoGabriel, vRosario, 60);

   menor_caminho(grafo, vSantaMaria, vRosario);

   grafo_libera(grafo);

   return 0;
}
