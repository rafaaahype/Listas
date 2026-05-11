#include "listadinamica.h"

FuncionarioDinamico* criarLista(int tamanho){
	return (FuncionarioDinamico*)malloc(tamanho*sizeof(FuncionarioDinamico));
}

void adicionarFuncionario(FuncionarioDinamico *lista, int quantFuncio, char *nome, char *cpf, float salario){
	strcpy(lista[quantFuncio].nome, nome);
	strcpy(lista[quantFuncio].cpf, cpf);
    lista[quantFuncio].salario = salario;
}

void removerFuncionario(FuncionarioDinamico **lista,int *quantFuncio,int *quantEspaco,char nome[50]){
    int posicao = -1;

    for(int i = 0; i < *quantFuncio; i++){
        if(strcmp((*lista)[i].nome, nome) == 0){
            posicao = i;
            break;
        }
    }

    if(posicao == -1){
        puts("Não achamos o Funcionário que deseja remover. ;p\n");
        return;
    }

    for(int i = posicao; i < (*quantFuncio) - 1; i++){
        (*lista)[i] = (*lista)[i + 1];
    }

    (*quantFuncio)--;

    int novoTamanho = (*quantFuncio > 0) ? *quantFuncio : 1;

    if(novoTamanho < *quantEspaco){
        FuncionarioDinamico *teste =
            realloc(*lista, novoTamanho * sizeof(FuncionarioDinamico));

        if(teste != NULL){
            *lista = teste;
            *quantEspaco = novoTamanho;
        }
    }

    puts("Funcionário removido com sucesso!");
}

void exibirListaFuncionarios(FuncionarioDinamico *lista, int quantidadeDeFuncio){
	for(int i=0; i<quantidadeDeFuncio; i++)
		printf("Nome: %s| CPF: %s| Salario: %.2f\n",lista[i].nome,lista[i].cpf,lista[i].salario);
}
