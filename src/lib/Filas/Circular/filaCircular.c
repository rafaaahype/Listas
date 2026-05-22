#include "filaCircular.h"

FilaCircular* criarFC(int tamanho){
  FilaCircular* fila = malloc(sizeof(FilaCircular) + tamanho * sizeof(Funcionario));
  if (fila == NULL) return NULL;
  fila->tamanho = tamanho;
  fila->inicio=0;
  fila->fim=-1;
  fila->quantidade=0;
  return fila;
}

int vaziaFC(FilaCircular* filacircular){
  return filacircular->quantidade==0;
}
int cheiaFC(FilaCircular* filacircular){
  return filacircular->quantidade==filacircular->tamanho;
}

int enfileirarFC(FilaCircular* filacircular, Funcionario funcionario){
  if(cheiaFC(filacircular)){ printf("ERROR ENFILEIRAR: FILA CHEIA"); return 0; }
  if(filacircular->fim+1==filacircular->tamanho) filacircular->fim=0;
  else filacircular->fim++;
  filacircular->funcionarios[filacircular->fim] = funcionario;
  filacircular->quantidade++;
  // printf("FUNC: %s ADICIONADO: %d", filacircular->funcionarios[filacircular->fim].nome, filacircular->fim);
  return 1;
}

Funcionario* consultarFC(FilaCircular* filacircular){
  if(vaziaFC(filacircular)){ printf("ERRO CONSULTAR: LISTA VAZIA"); return NULL; }
  Funcionario* funcionario = &filacircular->funcionarios[filacircular->inicio];
  return funcionario;
}

Funcionario* desinfileirarFC(FilaCircular* filacircular){
  if(vaziaFC(filacircular)){ printf("ERRO DESINFILEIRAR: LISTA VAZIA"); return NULL; }
  Funcionario* funcionario = consultarFC(filacircular);
  if(filacircular->inicio+1==filacircular->tamanho) filacircular->inicio=0;
  else filacircular->inicio++;
  filacircular->quantidade--;
  return funcionario;
}

int alterarFC(FilaCircular* filacircular, Funcionario funcionario){
  if(vaziaFC(filacircular)){ printf("ERRO ALTERAR: LISTA VAZIA"); return 1; }
  Funcionario* func = consultarFC(filacircular);
  strcpy(func->nome, funcionario.nome);
  strcpy(func->cpf, funcionario.cpf);
  func->salario = funcionario.salario;
  return 0;
}

void destruirFC(FilaCircular* filacircular) {
  if (filacircular == NULL) return;
  free(filacircular);
}
