#include "listaencadeada.h"
#include <stdlib.h>
#include <stdio.h>
Funcionario* criar_lista(void){
  return NULL;
}

Funcionario* buscar_funcionario(Funcionario* lista, char cpfFunc[15]){
  for(Funcionario* func = lista; func!=NULL; func=func->prox){
    if(strcmp(func->cpf, cpfFunc) == 0){
      return func;
    }
  }
  return NULL;
}

Funcionario* add_lista(Funcionario* lista, Funcionario funcionario){
  if(buscar_funcionario(lista, funcionario.cpf)) return lista;
  Funcionario* nova_lista = (Funcionario*) malloc(sizeof(Funcionario));
  strcpy(nova_lista->nome, funcionario.nome);
  strcpy(nova_lista->cpf, funcionario.cpf);
  nova_lista->salario = funcionario.salario;
  nova_lista->prox = lista;
  return nova_lista;
}
Funcionario* add_lista_ordenado(Funcionario* lista, Funcionario funcionario){
  if(buscar_funcionario(lista, funcionario.cpf)) return lista;
  Funcionario* anterior = NULL;
  Funcionario* func = lista;

  while(func != NULL && strcmp(func->nome, funcionario.nome) < 0){ anterior = func; func = func->prox; }

  Funcionario* nova_lista = (Funcionario*) malloc(sizeof(Funcionario));
  strcpy(nova_lista->nome, funcionario.nome);
  strcpy(nova_lista ->cpf, funcionario.cpf);
  nova_lista->salario = funcionario.salario;

  if (anterior == NULL){
    nova_lista->prox = lista;
    lista = nova_lista;
  } else {
    nova_lista->prox = anterior->prox;
    anterior->prox = nova_lista;
    return lista;
  }
  return lista;

}

void imprime_lista(Funcionario* lista){
  for(Funcionario* func = lista; func != NULL; func = func->prox){
    printf("\nNOME DO FUNCIONARIO: %s",func->nome);
    printf("\nCPF DO FUNCIONARIO: %s",func->cpf);
    printf("\nSALARIO DO FUNCIONARIO: %.2f",func->salario);
  }
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