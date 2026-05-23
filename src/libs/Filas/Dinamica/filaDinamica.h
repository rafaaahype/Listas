#include "funcionario.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED


struct nofiladinamica{
  Funcionario funcionario;
  struct nofiladinamica* proximo;
};
typedef struct nofiladinamica NoFilaDinamica;

struct filadinamica{
  NoFilaDinamica* inicio;
  NoFilaDinamica* fim;
  int quantidade;
  Funcionario funcionarioRemovido;
};
typedef struct filadinamica FilaDinamica;

FilaDinamica* criarFD();
int vaziaFD(FilaDinamica* filadinamica);
int enfileirarFD(FilaDinamica* filadinamica, Funcionario funcionario);
Funcionario* desinfileirarFD(FilaDinamica* filadinamica);
Funcionario* consultarFD(FilaDinamica* filadinamica);
int alterarFD(FilaDinamica* filadinamica, Funcionario funcionario);
void destruirFD(FilaDinamica* filadinamica);




#endif
