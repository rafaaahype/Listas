#include "listaencadeada.h"
#include <stdlib.h>
#include <stdio.h>

Funcionario* criar_lista(void) {
    return NULL;
}

/* ORIGINAL*/
Funcionario* buscar_funcionario(Funcionario* lista, char cpf[15]) {
    for (Funcionario* func = lista; func != NULL; func = func->prox)
        if (strcmp(func->cpf, cpf) == 0)
            return func;
    return NULL;
}

/* ORIGINAL*/
Funcionario* add_lista(Funcionario* lista, Funcionario funcionario) {
    if (buscar_funcionario(lista, funcionario.cpf)) return lista;

    Funcionario* novo = (Funcionario*) malloc(sizeof(Funcionario));
    strcpy(novo->nome,   funcionario.nome);
    strcpy(novo->cpf,    funcionario.cpf);
    novo->salario = funcionario.salario;
    novo->prox    = lista;
    return novo;
}

/* ORIGINAL*/
Funcionario* add_lista_ordenado(Funcionario* lista, Funcionario funcionario) {
    if (buscar_funcionario(lista, funcionario.cpf)) return lista;

    Funcionario* anterior = NULL;
    Funcionario* atual    = lista;


    while (atual != NULL && strcmp(atual->nome, funcionario.nome) < 0) {
        anterior = atual;
        atual    = atual->prox;
    }

    Funcionario* novo = (Funcionario*) malloc(sizeof(Funcionario));
    strcpy(novo->nome, funcionario.nome);
    strcpy(novo->cpf,  funcionario.cpf);
    novo->salario = funcionario.salario;
    novo->prox    = atual;

    if (anterior == NULL)
        lista = novo;
    else
        anterior->prox = novo;

    return lista;
}

void imprime_lista(Funcionario* lista) {
    if (lista_vazia(lista)) { puts("Lista vazia."); return; }
    for (Funcionario* func = lista; func != NULL; func = func->prox)
        printf("Nome: %-30s CPF: %-15s Salario: R$ %.2f\n",func->nome, func->cpf, func->salario);
}

int lista_vazia(Funcionario* lista) {
    return lista == NULL;
}

/*ORIGINAL*/
Funcionario* liberar_lista(Funcionario* lista) {
    while (lista != NULL) {
        Funcionario* proximo = lista->prox;
        free(lista);
        lista = proximo;
    }
    return NULL;
}

/*grava a lista em arquivo CSV*/
void salvar_csv(Funcionario* lista, const char* arquivo) {
    FILE* fp = fopen(arquivo, "w");
    if (!fp) { printf("Erro ao abrir %s\n", arquivo); return; }
    fprintf(fp, "nome,cpf,salario\n"); /* cabeçalho */
    for (Funcionario* func = lista; func != NULL; func = func->prox)
        fprintf(fp, "%s,%s,%.2f\n", func->nome, func->cpf, func->salario);
    fclose(fp);
    printf("Salvo em %s\n", arquivo);
}

/* lê o CSV e insere cada linha na lista ordenada*/
Funcionario* carregar_csv(Funcionario* lista, const char* arquivo) {
    FILE* fp = fopen(arquivo, "r");
    if (!fp) { printf("Arquivo %s nao encontrado.\n", arquivo); return lista; }
    char linha[256];
    fgets(linha, sizeof(linha), fp);
    while (fgets(linha, sizeof(linha), fp)) {
        Funcionario f;
        if (sscanf(linha, "%99[^,],%14[^,],%f", f.nome, f.cpf, &f.salario) == 3)
            lista = add_lista_ordenado(lista, f);
    }
    fclose(fp);
    return lista;
}