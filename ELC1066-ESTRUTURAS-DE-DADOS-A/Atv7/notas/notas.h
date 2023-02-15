/* Tipo exportado */
typedef struct notas Notas;

/* Funções exportadas */
Notas* ntn_cria_notas (int n1, int n2);

void ntn_libera_notas (Notas* n);

void ntn_modifica_nota1 (Notas * n, int n1);
void ntn_modifica_nota2 (Notas * n, int n2);

void ntn_retorna_notas (Notas * n, int * n1, int * n2);

int ntn_calcula_media (Notas * notas);
