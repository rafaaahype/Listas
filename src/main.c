#include "../bibliotecas/listaestatica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
	int numFuncionarios;
	printf("Digite o tamanho da lista de funcionarios: ");
	scanf("%d", &numFuncionarios);

	Funcionario *listaFuncionarios = criar_lista(numFuncionarios);

	Funcionario *func = (Funcionario*) malloc(sizeof(Funcionario));

	for(int i=0; i<numFuncionarios; i++){
		listaFuncionarios[i] = *func;
		strcpy(listaFuncionarios[i].nome, "none"); 
	}
	


	// strcpy(func.nome, "jeff");
	// adicionar(listaFuncionarios, func, 0);


	// Funcionario *listaFuncionarios = (Funcionario*) malloc(numFuncionarios * sizeof(Funcionario)); 

	// if(listaFuncionarios){
	// 	for(int i=0; i < numFuncionarios; i++){
	// 		char nome[100], cpf[15];
	// 		float salario;
	// 		printf("Digite o nome do funcionario: ");
	// 		scanf("%s", nome);

	// 		printf("Digite o cpf do funcionario: ");
	// 		scanf("%s", cpf);
			
	// 		printf("Digite o salario do funcionario: ");
	// 		scanf("%f", &salario);

	// 		Funcionario funcionario;
	// 		strcpy(funcionario.nome, nome);
	// 		strcpy(funcionario.cpf, cpf);
	// 		funcionario.salario = salario;

	// 		listaFuncionarios[i] = funcionario;
	// 	}

	// 	for(int i=0; i < numFuncionarios; i++){
	// 		printf("%s \n",listaFuncionarios[i].nome);
	// 		printf("%s \n",listaFuncionarios[i].cpf);
	// 		printf("%.2f \n",listaFuncionarios[i].salario);
	// 	}
	// }
	return 0;
}
