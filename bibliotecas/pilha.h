#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct pilha Pilha;

Pilha* cria(void);
void empilhar(Pilha* p, float v);
float desempilhar(Pilha* p);
int vazia(Pilha* p);
void libera(Pilha* p);
void imprime(Pilha* p);

#endif
