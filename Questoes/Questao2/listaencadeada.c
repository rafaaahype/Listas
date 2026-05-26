#include "listaencadeada.h"
#include <stdlib.h>
#include <stdio.h>

/* ORIGINAL*/
No *criar_lista(void)
{
    return NULL;
}

/* ORIGINAL*/
No *buscar_funcionario(No *lista, char cpf[15])
{
    for (No *func = lista; func != NULL; func = func->prox)
        if (strcmp(func->dados.cpf, cpf) == 0)
            return func;
    return NULL;
}

/* ORIGINAL*/
No *add_lista(No *lista, Funcionario funcionario)
{
    if (buscar_funcionario(lista, funcionario.cpf))
        return lista;

    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->dados.nome, funcionario.nome);
    strcpy(novo->dados.cpf, funcionario.cpf);
    novo->dados.salario = funcionario.salario;
    novo->prox = lista;
    return novo;
}

/* ORIGINAL*/
No *add_lista_ordenado(No *lista, Funcionario funcionario)
{
    if (buscar_funcionario(lista, funcionario.cpf))
        return lista;

    No *anterior = NULL;
    No *atual = lista;

    while (atual != NULL && strcmp(atual->dados.nome, funcionario.nome) < 0)
    {
        anterior = atual;
        atual = atual->prox;
    }

    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->dados.nome, funcionario.nome);
    strcpy(novo->dados.cpf, funcionario.cpf);
    novo->dados.salario = funcionario.salario;
    novo->prox = atual;

    if (anterior == NULL)
        lista = novo;
    else
        anterior->prox = novo;

    return lista;
}

/* ORIGINAL*/
void imprime_lista(No *lista)
{
    if (lista_vazia(lista))
    {
        puts("Lista vazia.");
        return;
    }
    for (No *func = lista; func != NULL; func = func->prox)
        printf("Nome: %-30s CPF: %-15s Salario: R$ %.2f\n",
               func->dados.nome, func->dados.cpf, func->dados.salario);
}

/* ORIGINAL*/
int lista_vazia(No *lista)
{
    return lista == NULL;
}

/*ORIGINAL*/
No *liberar_lista(No *lista)
{
    while (lista != NULL)
    {
        No *proximo = lista->prox;
        free(lista);
        lista = proximo;
    }
    return NULL;
}

/*grava a lista em arquivo CSV*/
void salvar_csv(No *lista, const char *arquivo)
{
    FILE *fp = fopen(arquivo, "w");
    if (!fp)
    {
        printf("Erro ao abrir %s\n", arquivo);
        return;
    }
    fprintf(fp, "nome,cpf,salario\n"); /* cabeçalho */
    for (No *func = lista; func != NULL; func = func->prox)
        fprintf(fp, "%s,%s,%.2f\n", func->dados.nome, func->dados.cpf, func->dados.salario);
    fclose(fp);
    printf("Salvo em %s\n", arquivo);
}

/* lê o CSV e insere cada linha na lista ordenada*/
No *carregar_csv(No *lista, const char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        printf("Arquivo %s nao encontrado.\n", arquivo);
        return lista;
    }
    char linha[256];
    fgets(linha, sizeof(linha), fp);
    while (fgets(linha, sizeof(linha), fp))
    {
        Funcionario f;
        if (sscanf(linha, "%99[^,],%14[^,],%f", f.nome, f.cpf, &f.salario) == 3)
            lista = add_lista_ordenado(lista, f);
    }
    fclose(fp);
    return lista;
}

No *remover_funcionario(No *lista, char cpf[15])
{
    No *anterior = NULL;
    No *atual = lista;

    while (atual != NULL && strcmp(atual->dados.cpf, cpf) != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Nao encontrado.\n");
        return lista;
    }

    if (anterior == NULL)
        lista = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    printf("Removido com sucesso.\n");
    return lista;
}