typedef struct no No;

void lst_cria (No ** inicio);
void lst_libera (No** inicio);
int lst_vazia (No* inicio);
void lst_insere_comeco (No** inicio, int i);
void lst_insere_ordenado (No** inicio, int v);
void lst_insere_final (No** inicio, int v);
void lst_retira (No** inicio, int v);
void lst_retira_comeco (No** inicio);
void lst_retira_final (No** inicio);
int lst_conta_menores (No* inicio, int v);
No* lst_busca (No* inicio, int v);
void lst_imprime (No* inicio);
