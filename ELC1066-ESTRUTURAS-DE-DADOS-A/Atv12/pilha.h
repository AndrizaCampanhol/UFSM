typedef struct pilha Pilha;

Pilha* pilha_cria (void);
int pilha_vazia (Pilha* p);

void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);

void pilha_libera (Pilha* p);
