#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include "pilha.h"

typedef struct calc Calc;

Calc* cria_calc(char* f);
void operando(Calc* c, float v);
void operador(Calc* c, char op);
void libera_calc(Calc* c);

#endif
