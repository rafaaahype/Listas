#include <stdio.h>
#include "funcionario.h"
#include "filaCircular.h"
#include "filaDinamica.h"
#include "filaEstatica.h"

Funcionario lerFuncionario(){
  Funcionario funcionario;

  printf("Nome do funcionario: ");
  scanf(" %[^\n]", funcionario.nome);

  printf("Cpf do funcionario: ");
  scanf(" %[^\n]", funcionario.cpf);

  printf("Salario do funcionario: ");
  scanf("%f", &funcionario.salario);

  printf("Digite o cargo do funcionario:\n1 - DIRETOR\n2 - COORDENADOR\n3 - FUNCIONARIO\n");
  scanf("%d", &funcionario.cargo);

  return funcionario;
}

void mostrarFuncionario(Funcionario *f){
    if(f != NULL){
        printf("\nFuncionario encontrado:\n");
        printf("CPF: %s\n", f->cpf);
        printf("Nome: %s\n", f->nome);
        printf("Salario: %.2f\n", f->salario);
        printf("Cargo: %.2f\n", f->cargo);

    }
    else{
        printf("Nenhum funcionario encontrado.\n");
    }
}
int main(void){

  int tamanho;

  printf("Informe o tamanho da fila estatica: ");
  scanf("%d", &tamanho);

  FilaEstatica *fe = criarFE(tamanho);

  printf("Informe o tamanho da fila circular: ");
  scanf("%d", &tamanho);

  FilaCircular *fc = criarFC(tamanho);

  FilaDinamica *fd = criarFD();

  int opcao;
  Funcionario funcionario;
  Funcionario *f;

  do{

    printf("\n========== MENU ==========\n");

    printf("\n--- FILA ESTATICA ---\n");
    printf("1  - Enfileirar\n");
    printf("2  - Desenfileirar\n");
    printf("3  - Consultar inicio\n");
    printf("4  - Alterar inicio\n");

    printf("\n--- FILA DINAMICA ---\n");
    printf("5  - Enfileirar\n");
    printf("6  - Desenfileirar\n");
    printf("7  - Consultar inicio\n");
    printf("8  - Alterar inicio\n");

    printf("\n--- FILA CIRCULAR ---\n");
    printf("9  - Enfileirar\n");
    printf("10 - Desenfileirar\n");
    printf("11 - Consultar inicio\n");
    printf("12 - Alterar inicio\n");
    printf("13 - Imprimir fila circular\n");

    printf("\n0  - Sair\n");
    printf("> ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:
        funcionario = lerFuncionario();
        if(enfileirarFE(fe, funcionario))
          printf("Funcionario enfileirado.\n");
        else
          printf("\nFila estatica cheia.\n");
      break;

      case 2:
          f = desinfileirarFE(fe);

          if(f != NULL){
            printf("\nFuncionario removido:\n");
            mostrarFuncionario(f);
          }
          else{
            printf("\nFila estatica vazia.\n");
          }
      break;

      case 3:
        f = consultarFE(fe);
        mostrarFuncionario(f);
      break;

      case 4:
        printf("Informe os novos dados:\n");

        funcionario = lerFuncionario();

        if(alterarFE(fe, funcionario))
          printf("Funcionario alterado.\n");
        else
          printf("\nFila estatica vazia.\n");
      break;

      case 5:
        funcionario = lerFuncionario();

        if(enfileirarFD(fd, funcionario))
          printf("Funcionario enfileirado.\n");
        else
          printf("\nErro ao enfileirar.\n");
      break;

      case 6:
        f = desinfileirarFD(fd);

        if(f != NULL){
          printf("Funcionario removido:\n");
          mostrarFuncionario(f);
        }
        else{
          printf("\nFila dinamica vazia.\n");
        }
      break;

      case 7:
        f = consultarFD(fd);
        mostrarFuncionario(f);
      break;

      case 8:
        printf("Informe os novos dados:\n");

        funcionario = lerFuncionario();

        if(alterarFD(fd, funcionario))
          printf("Funcionario alterado.\n");
        else
          printf("\nFila dinamica vazia.\n");
      break;

      case 9:
        funcionario = lerFuncionario();

        if(enfileirarFC(fc, funcionario))
          printf("Funcionario enfileirado.\n");
        else
          printf("\nFila circular cheia.\n");
      break;

      case 10:
        f = desinfileirarFC(fc);

        if(f != NULL){
          printf("Funcionario removido:\n");
          mostrarFuncionario(f);
        }
        else{
          printf("\nFila circular vazia.\n");
        }
      break;

      case 11:
        f = consultarFC(fc);
        mostrarFuncionario(f);
      break;

      case 12:
        printf("Informe os novos dados:\n");

        funcionario = lerFuncionario();

        if(alterarFC(fc, funcionario))
          printf("Funcionario alterado.\n");
        else
          printf("Fila circular vazia.\n");
      break;

      case 13:
        imprimirFC(fc);
      break;

      case 0:
        printf("Encerrando programa...\n");
      break;

      default:
        printf("Opcao invalida.\n");
    }

  }while(opcao != 0);

  destruirFE(fe);
  destruirFD(fd);
  destruirFC(fc);

  return 0;
}