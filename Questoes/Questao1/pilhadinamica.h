#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct pilhadinamica PilhaDinamica;

No* ret_ini(No* l);
No* ins_ini (No* l, float v);
PilhaDinamica* cria_dinamica(void);
void empilhar_dinamicamente(PilhaDinamica* p, float v);
float desempilhar_dinamicamente(PilhaDinamica* p);
int vazia_dinamica(PilhaDinamica* p);
void libera_dinamica(PilhaDinamica* p);
void imprime_dinamica(PilhaDinamica* p);

#endif
