#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pcb{
    int id;
    char* status;
    int tamVet;
    int* vet;
    struct pcb* prox;
    struct pcb* proxProc;
};
typedef struct pcb PCB;

struct list{
    PCB* inicio; 
};
typedef struct list List;

List *createList(){
    List *lista = (List *) malloc(sizeof(List));
    lista->inicio = NULL;

    return lista;
}

int findProxInt(FILE* file){
    char c;
    int cont = 0;
    while(!feof(file)){
        fscanf(file, "%c", &c);
        if(c >= 48 && c <= 57){
            cont = cont*10 + (c - 48);
        }else{
            return cont;
        }
    }
}

int *findProcInfo(FILE* file, int* tamVet){
    char c;
    int cont = 0, i = 0;
    int *vet = (int *) malloc(sizeof(int));
    do{
        fscanf(file, "%c", &c);
        if(c == '\n'){
            break;
        }
        if(c != ' '){
            cont = cont*10 + (c - 48);
            vet[i] = cont;
        }else{
            i++;
            cont = 0;
            vet = realloc(vet, sizeof(int)*(i+1));
        }
    }while(!feof(file));
    *tamVet = (i);
    return vet;
}

PCB *createPCB(FILE* file, int contProc){
    PCB *pcb = (PCB *) malloc(sizeof(PCB));
    pcb->id = contProc;
    pcb->status = malloc(sizeof(char)*10);
    strcpy(pcb->status, "new");
    pcb->vet = findProcInfo(file, &pcb->tamVet);
    pcb->prox = NULL;
    pcb->proxProc = NULL;

    return pcb;
}

int readStr(FILE* file){
    int aux;
    char* str = malloc(sizeof (char));
    if(fscanf(file, "%[^\n ] ", str) != EOF){
        aux = atoi(str);
    }
    free(str);
    return aux;
}

char *readLine(FILE* file){
    char info[20];
    char* aux = malloc(sizeof (char)*20);
    if(fgets(info, sizeof(info), file) != NULL){
        aux = info;
    }
    return aux;
}

PCB *locLastPcb(List* list){
    PCB* p = list->inicio;
    PCB* ant = NULL;

    while(p != NULL){
        ant = p;
        p = p->prox;
    } 
    return ant;
}

PCB *locLastProc(List* list){
    PCB* p = list->inicio;
    PCB* ant = NULL;

    while(p != NULL){
        ant = p;
        p = p->proxProc;
    } 
    return ant;
}

int countProcList(List* list){
    PCB* pcb = list->inicio;
    int cont = 0;

    while(pcb != NULL){
        cont++;
        pcb = pcb->prox;
    }
    return cont;  
}

void removeProcList(List* list){
    PCB* p = list->inicio;

    list->inicio = list->inicio->prox;

    p->prox = NULL;
}

void procToListNew(FILE* file, List* listNew, List* listProc, int tempProc, int contProc){
    PCB *antN = locLastPcb(listNew);
    PCB *antP = locLastProc(listProc);
    PCB *pcb = createPCB(file, contProc);

    if(antP == NULL){
        listProc->inicio = pcb;
    }else{
        antP->proxProc = pcb;
    }

    if(antN == NULL){
        listNew->inicio = pcb;
    }else{
        antN->prox = pcb;
    }
}

void procToOtherList(List* listIn, List* listOut, char* statu){
    PCB *ant = locLastPcb(listIn);    
    if(ant == NULL){
        listIn->inicio = listOut->inicio;
        strcpy(listIn->inicio->status, statu);
    }else{
        ant->prox = listOut->inicio;
        strcpy(ant->prox->status, statu);
    }
    removeProcList(listOut);
}

void testFile(FILE* file){
    if(file == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
}

void printPCB(List* list){
    PCB* pcb = list->inicio;

    while(pcb != NULL){
        printf("id=%d\nstatus=%s\ntamVet=%d\n", pcb->id, pcb->status, pcb->tamVet);
        pcb = pcb->prox;
    }  
}

void printProc(FILE* result, int temp, List* list){
    PCB* pcb = list->inicio;

    printf("<%d>", temp);
    fprintf(result,"<%d>", temp);
    while(pcb != NULL){
        printf(" <%s>", pcb->status);
        fprintf(result," <%s>", pcb->status);
        pcb = pcb->proxProc;
    }
    printf("\n");
    fprintf(result,"\n");
}

int main(){

    FILE* file = fopen("in2.txt","r");
    FILE* result = fopen("out2.txt", "w");

    testFile(file);
    testFile(result);

    List *listNew = createList();
    List *listReady = createList();
    List *listRunning = createList();
    List *listExit = createList();
    List *listProc = createList();

    int qtde_proc, qtde_disp, tempProc, contProc = 0, temp = 0;

    qtde_proc = readStr(file);
    qtde_disp = readStr(file);

    int* vetTempDisp = malloc(sizeof (int)*qtde_disp);

    for(int i = 0; i < qtde_disp; i++){
        vetTempDisp[i] = readStr(file);
    }

    tempProc = findProxInt(file);
    int controlTimeCPU = 0, controlCPU = 0, controlExit = 0;

    while(countProcList(listExit) < qtde_proc){
        if(controlExit == 1){
            procToOtherList(listExit, listRunning, "terminated");
            controlExit = 0;
        }

        if(countProcList(listRunning) == 0){
            if(countProcList(listReady) > 0){
                listRunning->inicio = listReady->inicio;
                strcpy(listRunning->inicio->status, "running");
                removeProcList(listReady);
            }
        }
        
        if(countProcList(listRunning) == 1){
            int i = 0;
            if(controlTimeCPU == 4){
                controlTimeCPU = 0;
                controlCPU = 1;
                controlExit = 0;
            }else{
                controlTimeCPU++;
                listRunning->inicio->vet[i] = listRunning->inicio->vet[i] - 1;
                if(listRunning->inicio->vet[i] == 0){
                    controlTimeCPU = 0;
                    controlCPU = 0;
                    controlExit = 1;
                }
            }
        }

        while(countProcList(listReady) <= 2 && countProcList(listNew) > 0){
            procToOtherList(listReady, listNew, "ready");
        }

        if(controlCPU == 1){
            procToOtherList(listReady, listRunning, "ready");
            controlCPU = 0;
        }

        while(tempProc == temp){ 
            procToListNew(file, listNew, listProc, tempProc, contProc);
            tempProc = findProxInt(file);
            contProc++;
        }
        printProc(result, temp, listProc);
        temp++;
    }
    
    free(vetTempDisp);
    fclose(file);
    return 0;
}