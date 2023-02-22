#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

time_t tempo;

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

// Andriza Campanhol (202011132) - Segundo Trabalho de SO - Busca em arquivo com Threads

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Nao informou a string a ser buscada!\n");
        exit(1);
    }
    
    char *buscaString = argv[1];
    FILE *arquivo = fopen("File1_test1.txt", "r");
    
    if(findString(arquivo, buscaString)){
        printf("Palavra %s encontrada em %f segundos!\n", buscaString, (float)tempo/CLOCKS_PER_SEC);
    }else{
        printf("Palavra não encontrada!\n");
    }

    fclose(arquivo);
    return 0;
}
