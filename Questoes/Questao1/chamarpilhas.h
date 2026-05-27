#ifndef CHAMARPILHAS_H_INCLUDED
#define CHAMARPILHAS_H_INCLUDED

#include "pilhadinamica.h"
#include "pilha.h"

void chamarPilhas(){
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
			case 7: puts("Finalizando execução.");
			default: puts("Esse comando nao existe");
		}
	}while(opcao!=7);
	libera(pilha_estatica); libera_dinamica(pilha_dinamica);
}

#endif
