#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

time_t tempo;
FILE *arquivo1, *arquivo2, *arquivo3, *arquivo4;
char *buscaString;

bool findString(FILE *arquivo, char *buscaString){
    char c;
    int cont = 0;
    while((c = fgetc(arquivo)) != EOF){
        if(c == buscaString[cont]){
            cont++;
            if(cont == strlen(buscaString)){
            tempo = clock();
            return true;
            }
        }else{
            cont=0;
        }
    }
    return false;
}

void * Thread0(){
    if(findString(arquivo1, buscaString)){
        printf("Palavra %s encontrada em %f segundos na thread 1!\n", buscaString, (float)tempo/CLOCKS_PER_SEC);
    }else{
        printf("Palavra não encontrada na thread 1!\n");
    }
}

void * Thread1(){
    if(findString(arquivo2, buscaString)){
        printf("Palavra %s encontrada em %f segundos na thread 2!\n", buscaString, (float)tempo/CLOCKS_PER_SEC);
    }else{
        printf("Palavra não encontrada na thread 2!\n");
    }
}

void * Thread2(){
    if(findString(arquivo3, buscaString)){
        printf("Palavra %s encontrada em %f segundos na thread 3!\n", buscaString, (float)tempo/CLOCKS_PER_SEC);
    }else{
        printf("Palavra não encontrada na thread 3!\n");
    }
}

void * Thread3(){
    if(findString(arquivo4, buscaString)){
        printf("Palavra %s encontrada em %f segundos na thread 4!\n", buscaString, (float)tempo/CLOCKS_PER_SEC);
    }else{
        printf("Palavra não encontrada na thread 4!\n");
    }
}

// Andriza Campanhol (202011132) - Segundo Trabalho de SO - Busca em arquivo com Threads

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Nao informou a string a ser buscada!\n");
        exit(1);
    }

    pthread_t t0, t1, t2, t3;

    buscaString = argv[1];
    arquivo1 = fopen("File1_test3.txt", "r");
    arquivo2 = fopen("File2_test3.txt", "r");
    arquivo3 = fopen("File3_test3.txt", "r");
    arquivo4 = fopen("File4_test3.txt", "r");

    pthread_create(&t0, NULL, Thread0, NULL);
    pthread_create(&t1, NULL, Thread1, NULL);
    pthread_create(&t2, NULL, Thread2, NULL);
    pthread_create(&t3, NULL, Thread3, NULL);
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);
    fclose(arquivo4);
    return 0;
}