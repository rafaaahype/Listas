#include "../bibliotecas/listadinamica.h"
#include <stdlib.h>
#include <string.h>

int quantidadeDeFuncionarios=0;
int quantidadeDeEspacos=1;

int main(void){
	FuncionarioDinamico *listaFuncionarios = criarLista(quantidadeDeEspacos);
	do{	
		printf("O que você deseja fazer?\n");
		printf("1- Adicionar Funcionário\n");
		printf("2- Remover Funcionário\n");
		printf("3- Exibir Lista de Funcionários\n");
		printf("4- Sair do programa.\n");
		int opcao; scanf("%d",&opcao);
		switch(opcao){
			case 1:
			if(quantidadeDeFuncionarios>=quantidadeDeEspacos){
				FuncionarioDinamico *teste = 
					realloc(listaFuncionarios, (quantidadeDeEspacos+1)*sizeof(FuncionarioDinamico));
				if(teste!=NULL){
					quantidadeDeEspacos++;
					listaFuncionarios = teste;
				}else{
					puts("DEU UM PROBLEMA NA REALOCAÇÃO DE MEMÓRIA ;(");
					free(listaFuncionarios);
					return 1;
				}
			}
				printf("Digite o nome do Funcionário: ");
				char nomefuncio[50]; scanf("%49s",nomefuncio);
				printf("Digite o CPF do Funcionário: ");
				char cpffuncio[13]; scanf("%12s",cpffuncio);
				printf("Digite o Salário do Funcionário: ");
				float salariofuncio; scanf("%f",&salariofuncio);
				adicionarFuncionario(listaFuncionarios,quantidadeDeFuncionarios, 
						nomefuncio,cpffuncio,salariofuncio);
				quantidadeDeFuncionarios++;
				printf("Funcionário adicionado com sucesso! :D\n\n\n");	
			break;

			case 2:
   				printf("Digite o nome do Funcionário que deseja remover: ");
    			char nomefuncioRemov[50]; scanf("%49s", nomefuncioRemov);
				removerFuncionario(&listaFuncionarios,&quantidadeDeFuncionarios,&quantidadeDeEspacos,nomefuncioRemov);
    		break;
			
			case 3:
				printf("LISTA DE FUNCIONÁRIOS: \n");
				exibirListaFuncionarios(listaFuncionarios, quantidadeDeFuncionarios);
				printf("\n\n");
			break;
			
			case 4:
				printf("\nFIM DA EXECUÇÃO.\n");
				free(listaFuncionarios);
				return 0;
			break;
		}
	}while(1);
	return 0;
}