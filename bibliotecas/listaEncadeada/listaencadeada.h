
#include <string.h>
#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

struct funcionario{
  char nome[100];
	char cpf[15];
	float salario;
  struct funcionario* prox;
};
typedef struct funcionario Funcionario;
Funcionario* criar_lista(void);
Funcionario* buscar_funcionario(Funcionario* lista, char cpfFunc[15]);
Funcionario* add_lista(Funcionario* lista, Funcionario funcionario);
Funcionario* add_lista_ordenado(Funcionario* lista, Funcionario funcionario);
void imprime_lista(Funcionario* lista);
int lista_vazia(Funcionario* lista);
Funcionario* liberar_lista(Funcionario* lista);

#endif
