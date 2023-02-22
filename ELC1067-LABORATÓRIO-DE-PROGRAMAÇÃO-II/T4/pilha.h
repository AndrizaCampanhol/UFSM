typedef struct pilha Pilha;

Pilha* pilha_cria ();
int pilha_vazia (Pilha* p);
void pilha_push (Pilha* p, int id);
void pilha_pop (Pilha* p);
void imprime_pilha (Pilha *p);
void pilha_libera (Pilha* p);