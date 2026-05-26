#include "pilha.h"

struct pilha {
	int n;
	float vet[MAX];
};

Pilha* cria(void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->n=0;
	return p;
}

void empilhar(Pilha* p, float v){
	if(p->n==MAX){
		printf("Nao cabe mais nada na pilha");
		exit(1);
	}
	p->vet[p->n] = v;
	p->n++;
}

float desempilhar(Pilha* p){
	float v;
	if(vazia(p)){
		printf("Nao tem nada na pilha\n");
		exit(1);
	}
	v = p->vet[p->n-1];
	p->n--;
	return v;
}

int vazia(Pilha* p){
	return (p->n==0);
}

void libera(Pilha* p){
	free(p);
}

void imprime(Pilha* p){
	for(int i=p->n-1; i>=0; i--) printf("%.2f\n",p->vet[i]);
}
