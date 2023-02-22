typedef struct fila Fila;

Fila* fila_cria ();
void adicionar_fila (Fila *f);
void retirar_fila_unica (Fila *f);
void fusao_fila_unica (Fila *unica, Fila *normal, Fila *alta);
void imprime_fila (Fila *f);
void liberar_fila (Fila *f);