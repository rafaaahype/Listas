#include "filaCircular.h"
#include <stdio.h>

int main(){
  FilaCircular* spooler = criarFC(10);
  if(spooler == NULL){
    printf("Erro ao criar spooler.\n");
    return 1;
  }

  Funcionario funcionario1 = {"Ana", "111.111.111-11", 3500.0, FUNCIONARIO};
  Funcionario funcionario2 = {"Bruno", "222.222.222-22", 9000.0, DIRETOR};
  Funcionario funcionario3 = {"Carla", "333.333.333-33", 6000.0, COORDENADOR};
  Funcionario funcionario4 = {"Diego", "444.444.444-44", 3200.0, 1};
  Funcionario funcionario5 = {"Elisa", "555.555.555-55", 9200.0, 3};

  enfileirarFC(spooler, funcionario1);
  enfileirarFC(spooler, funcionario2);
  enfileirarFC(spooler, funcionario3);
  enfileirarFC(spooler, funcionario4);
  enfileirarFC(spooler, funcionario5);

  imprimirFC(spooler);

  printf("\nImprimindo documentos:\n");
  while(!vaziaFC(spooler)){
    Funcionario* funcionario = desinfileirarFC(spooler);
    printf("Impresso: %s\n", funcionario->nome);
  }

  destruirFC(spooler);
  return 0;
}
