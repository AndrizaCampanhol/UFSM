/* Tipo exportado */
typedef struct no No;

/* Funcoes exportadas */
void lst_cria (No ** inicio);
int lst_vazia (No* inicio);
void lst_insere (No** inicio, int i);
No * lst_localiza_ultimo_menor(No * inicio, int v);
No * lst_localiza_ultimo(No * inicio);
void insere_lista(No** inicio, int v, No * ant);
void lst_insere_ordenado (No** inicio, int v);
void lst_insere_final (No** inicio, int v);
void lst_imprime (No* inicio);