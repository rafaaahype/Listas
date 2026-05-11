#include "listaduplamenteencadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Funcionario* criar_funcionario(Funcionario funcionario){
  Funcionario* novo_funcionario = (Funcionario*) malloc(sizeof(Funcionario));
  if(novo_funcionario == NULL) return NULL;
  strcpy(novo_funcionario->nome, funcionario.nome);
  strcpy(novo_funcionario->cpf, funcionario.cpf);
  novo_funcionario->salario = funcionario.salario;
  novo_funcionario->ant = NULL;
  novo_funcionario->prox = NULL;
  return novo_funcionario;
}

Funcionario* criar_lista(void){
  return NULL;
}

Funcionario* add_lista(Funcionario* lista, Funcionario funcionario){
  if(buscar_funcionario(lista, funcionario.cpf)) return lista;
  Funcionario* novo_funcionario = criar_funcionario(funcionario);
  if(novo_funcionario == NULL) return lista;
  novo_funcionario->prox = lista;

  if(lista != NULL){
    lista->ant = novo_funcionario;
  }
  return novo_funcionario;
}
Funcionario* add_lista_ordenado(Funcionario* lista, Funcionario funcionario){
  if(buscar_funcionario(lista, funcionario.cpf)) return lista;
  Funcionario* anterior = NULL;
  Funcionario* func = lista;

  while(func != NULL && strcmp(func->nome, funcionario.nome) < 0){ anterior = func; func = func->prox; }

  Funcionario* novo_funcionario = criar_funcionario(funcionario);
  if(novo_funcionario == NULL) return lista;

  novo_funcionario->prox = func;
  novo_funcionario->ant = anterior;

  if (anterior == NULL){
    if (func != NULL) func->ant = novo_funcionario;
    return novo_funcionario;
  } else {
    anterior->prox = novo_funcionario;
    if (func != NULL) func->ant = novo_funcionario;
    return lista;
  }
}
Funcionario* buscar_funcionario(Funcionario* lista, const char cpfFunc[]){
  Funcionario* func;
  for(func = lista; func != NULL; func=func->prox) if(strcmp(func->cpf, cpfFunc) == 0) return func;
  return NULL;
}

void imprime_lista(Funcionario* lista){
  for(Funcionario* func = lista; func != NULL; func = func->prox){
    printf("\nNOME DO FUNCIONARIO: %s",func->nome);
    printf("\nCPF DO FUNCIONARIO: %s",func->cpf);
    printf("\nSALARIO DO FUNCIONARIO: %.2f\n",func->salario);
  }
}
Funcionario* remover_funcionario(Funcionario* lista, const char cpfFunc[]){
  Funcionario* func = buscar_funcionario(lista, cpfFunc);
  if(func == NULL) return lista;
  if(lista == func) lista = func->prox;
  else func->ant->prox = func->prox;
  if(func->prox != NULL) func->prox->ant = func->ant;
  free(func);
  return lista;
}

int lista_vazia(Funcionario* lista){
  return (lista == NULL);
}

Funcionario* liberar_lista(Funcionario* lista){
  Funcionario* func = lista;
  while(func != NULL){
    Funcionario* proxFunc = func->prox;
    free(func);
    func = proxFunc;
  }
  return NULL;
}
