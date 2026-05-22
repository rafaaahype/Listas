#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

struct funcionario{
  char nome[100];
	char cpf[15];
	float salario;
};
typedef struct funcionario Funcionario;

#endif