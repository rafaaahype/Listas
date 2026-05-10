#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED

#include <stdlib.h>
#define MAXIMO_FUNCIONARIOS 20  

typedef struct {
	char nome[100];
	char cpf[15];
	float salario;
} Funcionario;

Funcionario* criar_lista(int tamanho);
void adicionar(Funcionario lista_funcionario[], Funcionario funcionario, int indice);
#endif
