#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "funcionario.h"
#include <string.h>

struct no {
    Funcionario dados;
    struct no *prox;
};
typedef struct no No;

No *criar_lista(void);
No *buscar_funcionario(No *lista, char cpf[15]);
No *add_lista(No *lista, Funcionario funcionario);
No *add_lista_ordenado(No *lista, Funcionario funcionario);
void imprime_lista(No *lista);
int lista_vazia(No *lista);
No *liberar_lista(No *lista);
void salvar_csv(No *lista, const char *arquivo);
No *carregar_csv(No *lista, const char *arquivo);
No *remover_funcionario(No *lista, char cpf[15]);

#endif
