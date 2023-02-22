#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_mutex;
int rodada = 0, maxRodada;
int numClientes, numGarcoms, capaciGarcoms;

typedef struct Pedido{
    sem_t* sem_pedido;
    int cliente;
    int garcom;
    struct Pedido *prox;
} Pedidos;

typedef struct list{
    Pedidos* inicio;
} List;

typedef struct{
    int id;
    List* inicio;
} Pessoa;


List *createList(){
    List *lista = (List *) malloc(sizeof(List));
    lista->inicio = NULL;

    return lista;
}

Pedidos *createPedido(int cliente){
    Pedidos *ped = (Pedidos *) malloc(sizeof(Pedidos));
    sem_t *sem = (sem_t *) malloc(sizeof(sem_t));
    sem_init(sem, 0, 0);
    ped->sem_pedido = sem;
    ped->cliente = cliente;
    ped->garcom = 0;
    ped->prox = NULL;

    return ped;
}

Pedidos *locLastList(List* list){
    Pedidos* p = list->inicio;
    Pedidos* ant = NULL;

    while(p != NULL){
        ant = p;
        p = p->prox;
    } 
    return ant;
}

sem_t* pedToList(List* list, Pedidos* pedido){
    Pedidos* antList = locLastList(list);

    if(antList == NULL){
        list->inicio = pedido;
        
    }else{
        antList->prox = pedido;
    }
    return pedido->sem_pedido;
}

int recebeMaxPedidos(List* list, int garcom){
    Pedidos* p = list->inicio;
    int aux = 0, result = 0;

    while(p != NULL && capaciGarcoms != aux){
        if(p->garcom == 0){
            printf("############################################\n");
            printf("## Garcom %d esta registrando os pedidos!!! ##\n", garcom);
            printf("############################################\n");
            p->garcom = garcom;
            aux++;
            result = 1;
        }
        p = p->prox;
    }
    return result;
}

void entregaPedidos(List* list, int garcom){
    Pedidos* p = list->inicio;

    printf("#############################################\n");
    printf("## Garcom %d esta entregando os pedidos!!! ##\n", garcom);
    printf("#############################################\n");

    while(p != NULL){
        if(p->garcom == garcom){
            sem_post(p->sem_pedido);
        }
        p = p->prox;
    }
}

void *clientes(void *clientes){
    Pessoa cliente = *(Pessoa *) clientes;
    
    while(rodada < maxRodada){
        sem_wait(&sem_mutex);
        printf("------------------------------------\n");
        printf("O cliente %d esta fazendo um pedido!\n", cliente.id);
        printf("------------------------------------\n");
        sem_t* ped = pedToList(cliente.inicio,createPedido(cliente.id));
        sem_post(&sem_mutex);
        sem_wait(ped);
        printf("------------------------------------\n");
        printf("Pedido do cliente %d entregue!\n", cliente.id);
        printf("Cliente %d estah consumindo!\n", cliente.id);
        printf("------------------------------------\n");
        sleep(rand()%3+2);
    }
    numClientes--;
}

void *garcoms(void *garcoms){
    Pessoa garcom = *(Pessoa *) garcoms;
    
    while(numClientes > 0 || rodada < maxRodada){
        sem_wait(&sem_mutex);
        if(recebeMaxPedidos(garcom.inicio, garcom.id) == 1){
            entregaPedidos(garcom.inicio, garcom.id);
            rodada++;
        }
        sem_post(&sem_mutex);
    }
}

int main(int argc, char *argv[]){
    if(argc < 5 || argc > 5){
        printf("Argumentos Insuficientes!\n");
        exit(1);
    }

    numClientes = atoi(argv[1]);
    numGarcoms = atoi(argv[2]);
    capaciGarcoms = atoi(argv[3]);
    maxRodada = atoi(argv[4]);

    int numClientesAux = numClientes;

    pthread_t thrGarcoms[numGarcoms], thrClientes[numClientes];

    sem_init(&sem_mutex, 0, 1);

    List* list = createList();

    printf("####################################\n");
    printf("## Abertura das Rodadas Livres!!! ##\n");
    printf("####################################\n");

    Pessoa *xGarcoms;
    for(int i = 0; i < numGarcoms; i++){
        xGarcoms = malloc(sizeof(Pessoa));
        xGarcoms->id = i + 1;
        xGarcoms->inicio = list;
        pthread_create(&thrGarcoms[i], NULL, garcoms, (void*)xGarcoms);
    }

    Pessoa *xClientes;
    for(int i = 0; i < numClientes; i++){
        xClientes = malloc(sizeof(Pessoa));
        xClientes->id = i + 1;
        xClientes->inicio = list;
        pthread_create(&thrClientes[i], NULL, clientes, (void*)xClientes);
    }

    for(int i = 0; i < numGarcoms; i++){
        pthread_join(thrGarcoms[i], NULL);
    }

    for(int i = 0; i < numClientesAux; i++){
        pthread_join(thrClientes[i], NULL);
    }

    return 0;
}