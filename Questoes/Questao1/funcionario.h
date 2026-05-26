#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

typedef enum cargo{
  DIRETOR = 1,
  COORDENADOR = 2,
  FUNCIONARIO = 3
} Cargo;

struct funcionario{
  char nome[100];
	char cpf[15];
	float salario;
  Cargo cargo;
};
typedef struct funcionario Funcionario;

#endif
