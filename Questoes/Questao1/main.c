#include "matriz.h"
#include "funcionario.h"
#include "filaCircular.h"
#include "filaDinamica.h"
#include "filaEstatica.h"
#include "pilhadinamica.h"
#include "pilha.h" //Essa é a versão estática

void questao1(){
  int linhas, colunas;
  printf("Informe a ordem da matriz\n");
  printf("Linhas: ");
  scanf("%d", &linhas);
  printf("Colunas: ");
  scanf("%d", &colunas);
  Matriz *m = dimensionarMatriz(linhas, colunas);

  int opcao, linha, coluna;

  do
  {
      printf("\n1-Preencher  2-Exibir  3-Buscar  4-Adicionar  5-Remover  6-Somar  7-Zerar  0-Sair\n> ");
      scanf(" %d", &opcao);

      switch (opcao)
      {
      case 1:
          preencherMatriz(m);
          break;
      case 2:
          exibirMatriz(m);
          break;
      case 3:
          printf("Linha: ");
          scanf("%d", &linha);
          printf("Coluna: ");
          scanf("%d", &coluna);
          printf("Valor: %.2f\n", buscarElementoMatriz(m, linha, coluna));
          break;
      case 4:
      {
          float valor;
          printf("Linha: ");
          scanf("%d", &linha);
          printf("Coluna: ");
          scanf("%d", &coluna);
          printf("Valor: ");
          scanf("%f", &valor);
          adicionarElementoMatriz(m, valor, linha, coluna);
          break;
      }
      case 5:
          printf("Linha: ");
          scanf("%d", &linha);
          printf("Coluna: ");
          scanf("%d", &coluna);
          removerElementoMatriz(m, linha, coluna);
          break;
      case 6:
      {
          printf("Informe a segunda matriz\n");
          printf("Linhas: ");
          scanf("%d", &linhas);
          printf("Colunas: ");
          scanf("%d", &colunas);
          Matriz *b = dimensionarMatriz(linhas, colunas);
          preencherMatriz(b);
          Matriz *soma = somarMatrizes(m, b);
          if (soma)
          {
              printf("Resultado:\n");
              exibirMatriz(soma);
              destruirMatriz(soma);
          }
          destruirMatriz(b);
          break;
      }
      case 7:
          zerarMatriz(m);
          printf("Matriz zerada.\n");
          break;
      }

  } while (opcao != 0);

  destruirMatriz(m);
}

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

void questao2(){

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
}

void questao3(){
  Pilha* pilha_estatica = cria();
	PilhaDinamica* pilha_dinamica = cria_dinamica();
	int opcao;
	do{
		printf("\tDigite 1 para empilhar na pilha estatica\n");
		printf("\tDigite 2 para desempilhar na pilha estatica\n");
		printf("\tDigite 3 para exibir a pilha estatica\n");
		printf("\tDigite 4 para empilhar na pilha dinamica\n");
		printf("\tDigite 5 para desempilhar na pilha dinamica\n");
		printf("\tDigite 6 para exibir a pilha dinamica\n");
		printf("\tDigite 7 para sair!!!\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("Digite um numero para empilhar: ");
				float num; scanf("%f",&num);
				empilhar(pilha_estatica, num);
			break;
			case 2:
				desempilhar(pilha_estatica);
				printf("O elemento do topo foi desempilhado.\n");
			break;
			case 3:
				imprime(pilha_estatica);
			break;
			case 4:
				printf("Digite um numero para empilhar: ");
				float numD; scanf("%f",&numD);
				empilhar_dinamicamente(pilha_dinamica, numD);
			break;
			case 5:
				desempilhar_dinamicamente(pilha_dinamica);
				printf("O elemento do topo foi desempilhado.\n");
			break;
			case 6:
				imprime_dinamica(pilha_dinamica);
			break;
			case 7: puts("Finalizando execução."); break;
			default: puts("Esse comando nao existe");
		}
	}while(opcao!=7);
	libera(pilha_estatica); libera_dinamica(pilha_dinamica);
}

int main(){
  int opcao;
  printf("ESCOLHA A ALTERNATIVA:\n1 - MATRIZES\n2 - FILAS\n3 - PILHAS\nDIGITE A QUESTAO: ");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    questao1();
    break;
  case 2:
    questao2();
    break;
  case 3:
    questao3();
    break;
  default:
    break;
  }
  return 0;
}
