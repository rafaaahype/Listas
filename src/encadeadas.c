#include <stdio.h>
#include <string.h>
#include "../bibliotecas/listaEncadeada/listaencadeada.h"
int main(void){
  Funcionario* lista = criar_lista();

  for(int i=0; i<3; i++){
    Funcionario func;
    printf("DIGITE O NOME DO FUNCIONARIO: ");
    scanf("%s", func.nome);
    printf("DIGITE O CPF DO FUNCIONARIO: ");
    scanf("%s", func.cpf);
    printf("DIGITE O SALARIO DO FUNCIONARIO: ");
    scanf("%f", &func.salario);
    lista = add_lista_ordenado(lista, func);


  }
  imprime_lista(lista);
  lista = liberar_lista(lista);
  imprime_lista(lista);
  return 0;
}