#include "filaCircular.h"
#include "filaDinamica.h"
#include "filaEstatica.h"
#include <stdio.h>

void menuPrincipal(){
  printf("\nMENU PRINCIPAL\n");
  printf("1 - Fila Circular\n");
  printf("2 - Fila Estatica\n");
  printf("3 - Fila Dinamica\n");
  printf("0 - Sair\n");
  printf("Opcao: ");
}

void menuOperacoes(){
  printf("\n1 - Enfileirar\n");
  printf("2 - Desinfileirar\n");
  printf("3 - Consultar\n");
  printf("4 - Alterar inicio\n");
  printf("5 - Verificar vazia\n");
  printf("6 - Verificar cheia\n");
  printf("0 - Voltar\n");
  printf("Opcao: ");
}

void imprimirFuncionario(Funcionario* funcionario){
  if(funcionario == NULL) return;
  printf("Nome: %s\n", funcionario->nome);
  printf("CPF: %s\n", funcionario->cpf);
  printf("Salario: %.2f\n", funcionario->salario);
}

void enfileirar(int filaEscolhida, FilaCircular* filacircular, FilaEstatica* filaestatica, FilaDinamica* filadinamica, Funcionario funcionario){
  if(filaEscolhida == 1) enfileirarFC(filacircular, funcionario);
  else if(filaEscolhida == 2) enfileirarFE(filaestatica, funcionario);
  else if(filaEscolhida == 3) enfileirarFD(filadinamica, funcionario);
  else printf("Fila invalida.\n");
}

Funcionario* desinfileirar(int filaEscolhida, FilaCircular* filacircular, FilaEstatica* filaestatica, FilaDinamica* filadinamica){
  if(filaEscolhida == 1) return desinfileirarFC(filacircular);
  else if(filaEscolhida == 2) return desinfileirarFE(filaestatica);
  else if(filaEscolhida == 3) return desinfileirarFD(filadinamica);
  else return NULL;
}

Funcionario* consultar(int filaEscolhida, FilaCircular* filacircular, FilaEstatica* filaestatica, FilaDinamica* filadinamica){
  if(filaEscolhida == 1) return consultarFC(filacircular);
  else if(filaEscolhida == 2) return consultarFE(filaestatica);
  else if(filaEscolhida == 3) return consultarFD(filadinamica);
  else return NULL;
}

void alterar(int filaEscolhida, FilaCircular* filacircular, FilaEstatica* filaestatica, FilaDinamica* filadinamica, Funcionario funcionario){
  if(filaEscolhida == 1) alterarFC(filacircular, funcionario);
  else if(filaEscolhida == 2) alterarFE(filaestatica, funcionario);
  else if(filaEscolhida == 3) alterarFD(filadinamica, funcionario);
  else printf("Fila invalida.\n");
}

void verificarVazia(int filaEscolhida, FilaCircular* filacircular, FilaEstatica* filaestatica, FilaDinamica* filadinamica){
  if(filaEscolhida == 1 && vaziaFC(filacircular)) printf("Fila vazia.\n");
  else if(filaEscolhida == 2 && vaziaFE(filaestatica)) printf("Fila vazia.\n");
  else if(filaEscolhida == 3 && vaziaFD(filadinamica)) printf("Fila vazia.\n");
  else printf("Fila nao esta vazia.\n");
}

void verificarCheia(int filaEscolhida, FilaCircular* filacircular, FilaEstatica* filaestatica){
  if(filaEscolhida == 1 && cheiaFC(filacircular)) printf("Fila cheia.\n");
  else if(filaEscolhida == 2 && cheiaFE(filaestatica)) printf("Fila cheia.\n");
  else if(filaEscolhida == 3) printf("Fila dinamica nao possui limite fixo.\n");
  else printf("Fila nao esta cheia.\n");
}

int main(){
  int tamanho, filaEscolhida, opcao;
  Funcionario funcionario;
  Funcionario* funcionarioAtual;

  printf("Digite o tamanho das filas estatica e circular: ");
  scanf("%d", &tamanho);

  FilaCircular* filacircular = criarFC(tamanho);
  FilaEstatica* filaestatica = criarFE(tamanho);
  FilaDinamica* filadinamica = criarFD();

  if(filacircular == NULL || filaestatica == NULL || filadinamica == NULL){
    printf("Erro ao criar filas.\n");
    destruirFC(filacircular);
    destruirFE(filaestatica);
    destruirFD(filadinamica);
    return 1;
  }

  do{
    menuPrincipal();
    scanf("%d", &filaEscolhida);

    if(filaEscolhida != 0){
      do{
        menuOperacoes();
        scanf("%d", &opcao);

        switch(opcao){
          case 1:
            printf("Nome: ");
            scanf(" %99[^\n]", funcionario.nome);
            printf("CPF: ");
            scanf(" %14[^\n]", funcionario.cpf);
            printf("Salario: ");
            scanf("%f", &funcionario.salario);

            enfileirar(filaEscolhida, filacircular, filaestatica, filadinamica, funcionario);
            break;

          case 2:
            funcionarioAtual = desinfileirar(filaEscolhida, filacircular, filaestatica, filadinamica);

            if(funcionarioAtual != NULL){
              printf("\nFuncionario removido:\n");
              imprimirFuncionario(funcionarioAtual);
            }
            break;

          case 3:
            funcionarioAtual = consultar(filaEscolhida, filacircular, filaestatica, filadinamica);

            if(funcionarioAtual != NULL){
              printf("\nFuncionario no inicio:\n");
              imprimirFuncionario(funcionarioAtual);
            }
            break;

          case 4:
            printf("Nome: ");
            scanf(" %99[^\n]", funcionario.nome);
            printf("CPF: ");
            scanf(" %14[^\n]", funcionario.cpf);
            printf("Salario: ");
            scanf("%f", &funcionario.salario);

            alterar(filaEscolhida, filacircular, filaestatica, filadinamica, funcionario);
            break;

          case 5:
            verificarVazia(filaEscolhida, filacircular, filaestatica, filadinamica);
            break;

          case 6:
            verificarCheia(filaEscolhida, filacircular, filaestatica);
            break;

          case 0:
            break;

          default:
            printf("Opcao invalida.\n");
        }
      }while(opcao != 0);
    }
  }while(filaEscolhida != 0);

  destruirFC(filacircular);
  destruirFE(filaestatica);
  destruirFD(filadinamica);
  return 0;
}
