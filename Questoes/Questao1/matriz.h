#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>

typedef struct Matriz Matriz;

Matriz *dimensionarMatriz(int linhas, int colunas);
void destruirMatriz(Matriz *m);
void adicionarElementoMatriz(Matriz *m, float elemento, int linha, int coluna);
float buscarElementoMatriz(Matriz *m, int linha, int coluna);
void removerElementoMatriz(Matriz *m, int linha, int coluna);
void preencherMatriz(Matriz *m);
void exibirMatriz(Matriz *m);
void    zerarMatriz(Matriz* m);
Matriz *somarMatrizes(Matriz *a, Matriz *b);

#endif