#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <time.h>

time_t endTime = 0;

//verifica o conteudo da entrada
bool validInput(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        if(atoi(argv[i]) <= 0){
            return false;
        }
    }
    return true;
}

//funcao para calcular o tempo
void treeTime(time_t startTime){
    printf("Tempo de criação da árvore %f segundos\n", (double)(endTime - startTime)/CLOCKS_PER_SEC);
}

// Andriza Campanhol (202011132) - Primeiro Trabalho de SO - Criação de Processos em Árvore

int main(int argc, char *argv[]){

    if(argc < 2){ //verifica o tamanho da entrada
        printf("Nao informou a quantidade de filhos dos processos de cada nivel da arvore!\n");
        exit(1);
    }
    if(!validInput(argc, argv)){ //verifica o conteudo da entrada
        printf("ERRO! Entrada invalida!\n");
        exit(1);
    }

    time_t startTime = clock();
    pid_t rootPid = getpid();

    pid_t root; //cria o inicio da arvore
    printf("Sou o inicio da arvore com pid = %d\n\n", getpid());

    int waitControl = 0;

    for(int i = 1; i < argc; i++){
        int cont = 0;
        for(int j = 0; j < atoi(argv[i]); j++){
            root = fork();
    
            if(root < 0){
                printf("ERRO AO FORKAR!");
            }
            else if(root == 0){ //quando é filho
                printf("FILHO | PID = %d | PPID = %d\n", getpid(), getppid());
                waitControl = 0;
                break;
            }else{ //quando é pai
                printf("PAI | PID = %d | PPID = %d\n", getpid(), getppid());
                cont += 1;
            }
        }
        if(cont == atoi(argv[i])){ //controla se já foi pai numero suficiente
            waitControl = cont; //controla quantos filhos tem que esperar
            break;
        }
    }
    
    for(int i = 0; i < waitControl; i++){ //espera dos filhos
        printf("\n--------------------------------------------------\n");
        printf("Sou o PAI com pid = %d e estou esperando meu filho\n", getpid());
        printf("--------------------------------------------------\n");
        wait(NULL);
    }

    //processos finalizados
    printf("\n--------------------------------\n");
    printf("Processo com pid = %d finalizado\n", getpid());
    printf("--------------------------------\n");
    endTime += clock();

    if(rootPid == getpid()){ //funcao para calcular o tempo
        treeTime(startTime);
    }

    getchar(); //para compilar a arvore
    return 0;
}