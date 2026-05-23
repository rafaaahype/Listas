#ifndef FILACIRCULAR_H_INCLUDED
#define FILACIRCULAR_H_INCLUDED

#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filacircular{
  int tamanho, inicio, fim, quantidade;
  Funcionario funcionarioRemovido;
  Funcionario funcionarios[];
};
typedef struct filacircular FilaCircular;

FilaCircular* criarFC(int tamanho);
int vaziaFC(FilaCircular* filacircular);
int cheiaFC(FilaCircular* filacircular);
int enfileirarFC(FilaCircular* filacircular, Funcionario funcionario);
Funcionario* desinfileirarFC(FilaCircular* filacircular);
Funcionario* consultarFC(FilaCircular* filacircular);
int alterarFC(FilaCircular* filacircular, Funcionario funcionario);
void imprimirFC(FilaCircular* filacircular);
void destruirFC(FilaCircular* filacircular);

#endif
