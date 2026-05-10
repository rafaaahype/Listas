#include "listaestatica.h"

Funcionario* criar_lista(int tamanho){
  return (Funcionario*) malloc(tamanho * sizeof(Funcionario)); 
}