#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char nome[50];
	char cpf[13];
	float salario;
} FuncionarioDinamico;

FuncionarioDinamico* criarLista(int tamanho);
void adicionarFuncionario(FuncionarioDinamico *lista,int quantFuncio,char nome[50],char cpf[13], float salario);
void removerFuncionario(FuncionarioDinamico **lista,int *quantFuncio,int *quantEspaco,char nome[50]);
void exibirListaFuncionarios(FuncionarioDinamico *lista, int quantidadeDeFuncio);
#endif
