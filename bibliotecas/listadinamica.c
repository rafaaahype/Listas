#include "listadinamica.h"

FuncionarioDinamico* criarLista(int tamanho){
	return (FuncionarioDinamico*)malloc(tamanho*sizeof(FuncionarioDinamico));
}

void adicionarFuncionario(FuncionarioDinamico *lista, int quantFuncio, char *nome, char *cpf, float salario){
	strcpy(lista[quantFuncio].nome, nome);
	strcpy(lista[quantFuncio].cpf, cpf);
    	lista[quantFuncio].salario = salario;
}

void exibirListaFuncionarios(FuncionarioDinamico *lista, int quantidadeDeFuncio){
	for(int i=0; i<quantidadeDeFuncio; i++)
		printf("Nome: %s| CPF: %s| Salario: %.2f\n",lista[i].nome,lista[i].cpf,lista[i].salario);
}
