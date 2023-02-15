#include "pilha.h"

typedef struct calc Calc;

/* funções exportadas */
Calc* calc_cria ();
void calc_operando (Calc* c, float v);
void calc_operador (Calc* c, char op);
void calc_libera (Calc* c);

float calc_calcula (Calc* c, char* equacao);

/* tipo representando a calculadora */
struct calc {
   Pilha* p;	/* pilha de operandos */
};
