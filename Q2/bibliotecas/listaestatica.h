#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#include "listaencadeada.h" /* reutilizando o struct Funcionario */

#define CAPACIDADE 100

typedef struct
{
    Funcionario dados[CAPACIDADE];
    int tamanho;
} ListaEstatica;

ListaEstatica criar_lista_est(void);
int lista_vazia_est(ListaEstatica *lista);
int lista_cheia_est(ListaEstatica *lista);
int buscar_est(ListaEstatica *lista, char cpf[15]);
int add_lista_est(ListaEstatica *lista, Funcionario f);
void imprime_lista_est(ListaEstatica *lista);
void salvar_csv_est(ListaEstatica *lista, const char *arquivo);
void carregar_csv_est(ListaEstatica *lista, const char *arquivo);
int remover_est(ListaEstatica *lista, char cpf[15]);

#endif
