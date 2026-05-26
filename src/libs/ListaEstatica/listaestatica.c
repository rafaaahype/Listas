#include "listaestatica.h"
#include <stdio.h>
#include <string.h>

ListaEstatica criar_lista_est() {
    ListaEstatica lista;
    lista.tamanho = 0;
    return lista;
}


int lista_vazia_est(ListaEstatica* lista) {
    return lista->tamanho == 0;
}

int lista_cheia_est(ListaEstatica* lista) {
    return lista->tamanho == CAPACIDADE;
}

/* retorna índice do CPF ou -1 se não encontrado */
int buscar_est(ListaEstatica* lista, char cpf[15]) {
    for (int i = 0; i < lista->tamanho; i++)
        if (strcmp(lista->dados[i].cpf, cpf) == 0)
            return i;
    return -1;
}

/* insere em ordem alfabética por nome */
int add_lista_est(ListaEstatica* lista, Funcionario f) {
    if (lista_cheia_est(lista))          return 0;
    if (buscar_est(lista, f.cpf) != -1)  return 0;

    /* acha posição de inserção */
    int pos = lista->tamanho;
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->dados[i].nome, f.nome) > 0) {
            pos = i;
            break;
        }
    }

    /* desloca os elementos maiores para a direita */
    for (int i = lista->tamanho; i > pos; i--)
        lista->dados[i] = lista->dados[i - 1];

    lista->dados[pos] = f;
    lista->tamanho++;
    return 1;
}

void imprime_lista_est(ListaEstatica* lista) {
    if (lista_vazia_est(lista)) { puts("Lista estatica vazia."); return; }
    for (int i = 0; i < lista->tamanho; i++)
        printf("Nome: %-30s CPF: %-15s Salario: R$ %.2f\n",
               lista->dados[i].nome,
               lista->dados[i].cpf,
               lista->dados[i].salario);
}

void salvar_csv_est(ListaEstatica* lista, const char* arquivo) {
    FILE* fp = fopen(arquivo, "w");
    if (!fp) { printf("Erro ao abrir %s\n", arquivo); return; }
    fprintf(fp, "nome,cpf,salario\n");
    for (int i = 0; i < lista->tamanho; i++)
        fprintf(fp, "%s,%s,%.2f\n",
                lista->dados[i].nome,
                lista->dados[i].cpf,
                lista->dados[i].salario);
    fclose(fp);
    printf("Salvo em %s\n", arquivo);
}

void carregar_csv_est(ListaEstatica* lista, const char* arquivo) {
    FILE* fp = fopen(arquivo, "r");
    if (!fp) { printf("Arquivo %s nao encontrado.\n", arquivo); return; }
    char linha[256];
    fgets(linha, sizeof(linha), fp);
    while (fgets(linha, sizeof(linha), fp)) {
        Funcionario f;
        if (scanf(linha, "%99[^,],%14[^,],%f", f.nome, f.cpf, &f.salario) == 3)
            add_lista_est(lista, f);
    }
    fclose(fp);
}
