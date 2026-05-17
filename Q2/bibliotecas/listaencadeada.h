#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <string.h>

struct funcionario {
    char nome[100];
    char cpf[15];
    float salario;
    struct funcionario* prox;
};
typedef struct funcionario Funcionario;

Funcionario* criar_lista(void);
Funcionario* buscar_funcionario(Funcionario* lista, char cpf[15]);
Funcionario* add_lista(Funcionario* lista, Funcionario funcionario);
Funcionario* add_lista_ordenado(Funcionario* lista, Funcionario funcionario);
void imprime_lista(Funcionario* lista);
int lista_vazia(Funcionario* lista);
Funcionario* liberar_lista(Funcionario* lista);
void salvar_csv(Funcionario* lista, const char* arquivo);
Funcionario* carregar_csv(Funcionario* lista, const char* arquivo);

#endif
