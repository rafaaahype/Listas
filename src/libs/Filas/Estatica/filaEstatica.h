#include "funcionario.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED


struct filaestatica{
  int tamanho, quantidade;
  Funcionario funcionarioRemovido;
  Funcionario funcionarios[];
};
typedef struct filaestatica FilaEstatica;

FilaEstatica* criarFE(int tamanho);
int vaziaFE(FilaEstatica* filaestatica);
int cheiaFE(FilaEstatica* filaestatica);
int enfileirarFE(FilaEstatica* filaestatica, Funcionario funcionario);
Funcionario* desinfileirarFE(FilaEstatica* filaestatica);
Funcionario* consultarFE(FilaEstatica* filaestatica);
int alterarFE(FilaEstatica* filaestatica, Funcionario funcionario);
void destruirFE(FilaEstatica* filaestatica);




#endif
