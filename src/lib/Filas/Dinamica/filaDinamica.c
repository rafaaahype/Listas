#include "filaDinamica.h"

FilaDinamica* criarFD(){
  FilaDinamica* fila = malloc(sizeof(FilaDinamica));
  if (fila == NULL) return NULL;
  fila->inicio=NULL;
  fila->fim=NULL;
  fila->quantidade=0;
  return fila;
}

int vaziaFD(FilaDinamica* filadinamica){
  return filadinamica->quantidade==0;
}

int enfileirarFD(FilaDinamica* filadinamica, Funcionario funcionario){
  NoFilaDinamica* novo = malloc(sizeof(NoFilaDinamica));
  if(novo == NULL){ printf("ERROR ENFILEIRAR: MEMORIA INSUFICIENTE"); return 0; }
  novo->funcionario = funcionario;
  novo->proximo = NULL;
  if(vaziaFD(filadinamica)) filadinamica->inicio = novo;
  else filadinamica->fim->proximo = novo;
  filadinamica->fim = novo;
  filadinamica->quantidade++;
  return 1;
}

Funcionario* consultarFD(FilaDinamica* filadinamica){
  if(vaziaFD(filadinamica)){ printf("ERRO CONSULTAR: LISTA VAZIA"); return NULL; }
  Funcionario* funcionario = &filadinamica->inicio->funcionario;
  return funcionario;
}

Funcionario* desinfileirarFD(FilaDinamica* filadinamica){
  if(vaziaFD(filadinamica)){ printf("ERRO DESINFILEIRAR: LISTA VAZIA"); return NULL; }
  NoFilaDinamica* removido = filadinamica->inicio;
  filadinamica->funcionarioRemovido = removido->funcionario;
  filadinamica->inicio = removido->proximo;
  if(filadinamica->inicio == NULL) filadinamica->fim = NULL;
  filadinamica->quantidade--;
  free(removido);
  return &filadinamica->funcionarioRemovido;
}

int alterarFD(FilaDinamica* filadinamica, Funcionario funcionario){
  if(vaziaFD(filadinamica)){ printf("ERRO ALTERAR: LISTA VAZIA"); return 1; }
  Funcionario* func = consultarFD(filadinamica);
  strcpy(func->nome, funcionario.nome);
  strcpy(func->cpf, funcionario.cpf);
  func->salario = funcionario.salario;
  return 0;
}

void destruirFD(FilaDinamica* filadinamica) {
  if (filadinamica == NULL) return;
  while(!vaziaFD(filadinamica)) desinfileirarFD(filadinamica);
  free(filadinamica);
}
