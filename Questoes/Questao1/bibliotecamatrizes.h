#ifndef BIBLIOTECAMATRIZES_H_INCLUDED
#define BIBLIOTECAMATRIZES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

float buscarElementoMatriz(float vetor[], int linha, int coluna);
void adicionarElementoMatriz(float vetor[], float elemento, int linha, int coluna);
void removerElementoMatriz(float vetor[], int linha, int coluna);
void dimensionarMatriz(float vetor[], int linhas, int colunas);
void criarCopia(float vetor[], float vetorCopia[]);
void matrizTransposta(float vetor[], float vetorTransposto[]);
void multiplicarMatriz(float vetorA[], float vetorB[], float vetorC[]);
int contarSaidas(float vet[], int cidade);
int contarEntradas(float vet[],int cidade);
void cidadesIsoladas(float vet[]);
void semSaidaComEntrada(float vet[]);
void preencherMatriz(float vetor[]);
void exibirMatriz(float vetor[]);
int matrizIdentidade(float vetor[]);
int matrizInversa(float vetorA[], float vetorB[]);
void comSaidaSemEntrada(float vetor[]);
void cidadeMaisEntradas(float vetor[]);
void relacionarCidades(float vetor[], int cidade);
void saidasParaK(float vetor[], int k);
void verificaRoteiro(float vetor[], int roteiro[], int m);

#endif
