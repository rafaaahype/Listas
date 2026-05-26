#include "filaCircular.h"

static int proximoIndice(FilaCircular* filacircular, int indice){
  return (indice + 1) % filacircular->tamanho;
}

static int indiceLogico(FilaCircular* filacircular, int posicao){
  return (filacircular->inicio + posicao) % filacircular->tamanho;
}

static const char* nomeCargo(Cargo cargo){
  switch(cargo){
    case DIRETOR: return "Diretor";
    case COORDENADOR: return "Coordenador";
    case FUNCIONARIO: return "Funcionario";
    default: return "Cargo invalido";
  }
}

FilaCircular* criarFC(int tamanho){
  if (tamanho <= 0) return NULL;
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

  int posicaoInsercao = filacircular->quantidade;
  for(int i = 0; i < filacircular->quantidade; i++){
    int indiceAtual = indiceLogico(filacircular, i);
    if(funcionario.cargo < filacircular->funcionarios[indiceAtual].cargo){
      posicaoInsercao = i;
      break;
    }
  }

  for(int i = filacircular->quantidade; i > posicaoInsercao; i--){
    int destino = indiceLogico(filacircular, i);
    int origem = indiceLogico(filacircular, i - 1);
    filacircular->funcionarios[destino] = filacircular->funcionarios[origem];
  }

  filacircular->funcionarios[indiceLogico(filacircular, posicaoInsercao)] = funcionario;
  filacircular->fim = indiceLogico(filacircular, filacircular->quantidade);
  filacircular->quantidade++;
  return 1;
}

Funcionario* consultarFC(FilaCircular* filacircular){
  if(vaziaFC(filacircular)){ printf("ERRO CONSULTAR: LISTA VAZIA"); return NULL; }
  Funcionario* funcionario = &filacircular->funcionarios[filacircular->inicio];
  return funcionario;
}

Funcionario* desinfileirarFC(FilaCircular* filacircular){
  if(vaziaFC(filacircular)){ printf("ERRO DESINFILEIRAR: LISTA VAZIA"); return NULL; }
  filacircular->funcionarioRemovido = filacircular->funcionarios[filacircular->inicio];
  filacircular->inicio = proximoIndice(filacircular, filacircular->inicio);
  filacircular->quantidade--;

  if(vaziaFC(filacircular)){
    filacircular->inicio = 0;
    filacircular->fim = -1;
  }

  return &filacircular->funcionarioRemovido;
}

int alterarFC(FilaCircular* filacircular, Funcionario funcionario){
  if(vaziaFC(filacircular)){ printf("ERRO ALTERAR: LISTA VAZIA"); return 1; }
  Funcionario* func = consultarFC(filacircular);
  strcpy(func->nome, funcionario.nome);
  strcpy(func->cpf, funcionario.cpf);
  func->salario = funcionario.salario;
  func->cargo = funcionario.cargo;
  return 0;
}

void imprimirFC(FilaCircular* filacircular){
  if(vaziaFC(filacircular)){ printf("FILA DE IMPRESSAO VAZIA\n"); return; }

  printf("FILA DE IMPRESSAO:\n");
  for(int i = 0; i < filacircular->quantidade; i++){
    Funcionario* funcionario = &filacircular->funcionarios[indiceLogico(filacircular, i)];
    printf("%d. %s - %s - prioridade %d\n",
      i + 1,
      funcionario->nome,
      nomeCargo(funcionario->cargo),
      funcionario->cargo
    );
  }
}

void destruirFC(FilaCircular* filacircular) {
  if (filacircular == NULL) return;
  free(filacircular);
}
