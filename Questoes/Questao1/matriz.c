#include "matriz.h"
#include <stdlib.h>

struct Matriz
{
    int linhas;
    int colunas;
    float *dados;
};

Matriz *dimensionarMatriz(int linhas, int colunas)
{
    Matriz *m = malloc(sizeof(Matriz));
    m->linhas = linhas;
    m->colunas = colunas;
    m->dados = calloc(linhas * colunas, sizeof(float));
    return m;
}

void destruirMatriz(Matriz *m)
{
    free(m->dados);
    free(m);
}

void adicionarElementoMatriz(Matriz *m, float elemento, int linha, int coluna)
{
    m->dados[(linha - 1) * m->colunas + (coluna - 1)] = elemento;
}

float buscarElementoMatriz(Matriz *m, int linha, int coluna)
{
    return m->dados[(linha - 1) * m->colunas + (coluna - 1)];
}

void removerElementoMatriz(Matriz *m, int linha, int coluna)
{
    m->dados[(linha - 1) * m->colunas + (coluna - 1)] = 0;
}

void preencherMatriz(Matriz *m)
{
    for (int i = 1; i <= m->linhas; i++)
        for (int j = 1; j <= m->colunas; j++)
        {
            float elemento;
            printf("Digite elemento [%d][%d]: ", i, j);
            scanf("%f", &elemento);
            adicionarElementoMatriz(m, elemento, i, j);
        }
}

void exibirMatriz(Matriz *m)
{
    for (int i = 1; i <= m->linhas; i++)
    {
        for (int j = 1; j <= m->colunas; j++)
            printf("%6.2f ", buscarElementoMatriz(m, i, j));
        putchar('\n');
    }
}
void zerarMatriz(Matriz *m)
{
    for (int i = 1; i <= m->linhas; i++)
        for (int j = 1; j <= m->colunas; j++)
            removerElementoMatriz(m, i, j);
}

Matriz *somarMatrizes(Matriz *a, Matriz *b)
{
    if (a->linhas != b->linhas || a->colunas != b->colunas)
    {
        printf("Dimensoes incompativeis para soma.\n");
        return NULL;
    }
    Matriz *r = dimensionarMatriz(a->linhas, a->colunas);
    for (int i = 1; i <= a->linhas; i++)
        for (int j = 1; j <= a->colunas; j++)
            adicionarElementoMatriz(r,
                                    buscarElementoMatriz(a, i, j) + buscarElementoMatriz(b, i, j), i, j);
    return r;
}