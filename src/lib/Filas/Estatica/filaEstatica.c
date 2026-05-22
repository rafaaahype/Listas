#include "filaEstatica.h"

FilaEstatica* criarFE(int tamanho){
  FilaEstatica* fila = malloc(sizeof(FilaEstatica) + tamanho * sizeof(Funcionario));
  if (fila == NULL) return NULL;
  fila->tamanho = tamanho;
  fila->quantidade=0;
  return fila;
}

int vaziaFE(FilaEstatica* filaestatica){
  return filaestatica->quantidade==0;
}
int cheiaFE(FilaEstatica* filaestatica){
  return filaestatica->quantidade==filaestatica->tamanho;
}

int enfileirarFE(FilaEstatica* filaestatica, Funcionario funcionario){
  if(cheiaFE(filaestatica)){ printf("ERROR ENFILEIRAR: FILA CHEIA"); return 0; }
  filaestatica->funcionarios[filaestatica->quantidade] = funcionario;
  filaestatica->quantidade++;
  return 1;
}

Funcionario* consultarFE(FilaEstatica* filaestatica){
  if(vaziaFE(filaestatica)){ printf("ERRO CONSULTAR: LISTA VAZIA"); return NULL; }
  Funcionario* funcionario = &filaestatica->funcionarios[0];
  return funcionario;
}

Funcionario* desinfileirarFE(FilaEstatica* filaestatica){
  if(vaziaFE(filaestatica)){ printf("ERRO DESINFILEIRAR: LISTA VAZIA"); return NULL; }
  filaestatica->funcionarioRemovido = filaestatica->funcionarios[0];
  for(int i=0; i<filaestatica->quantidade-1; i++){
    filaestatica->funcionarios[i] = filaestatica->funcionarios[i+1];
  }
  filaestatica->quantidade--;
  return &filaestatica->funcionarioRemovido;
}

int alterarFE(FilaEstatica* filaestatica, Funcionario funcionario){
  if(vaziaFE(filaestatica)){ printf("ERRO ALTERAR: LISTA VAZIA"); return 1; }
  Funcionario* func = consultarFE(filaestatica);
  strcpy(func->nome, funcionario.nome);
  strcpy(func->cpf, funcionario.cpf);
  func->salario = funcionario.salario;
  return 0;
}

void destruirFE(FilaEstatica* filaestatica) {
  if (filaestatica == NULL) return;
  free(filaestatica);
}
