#include "funcionario.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef FILACIRCULAR_H_INCLUDED
#define FILACIRCULAR_H_INCLUDED


struct filacircular{
  int tamanho, inicio, fim, quantidade;
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
void destruirFC(FilaCircular* filacircular);




#endif