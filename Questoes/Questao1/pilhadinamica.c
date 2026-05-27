#include "pilhadinamica.h"

struct no {
	float info;
	struct no* prox;
};

struct pilhadinamica {
	No* prim;
};

int vazia_dinamica(PilhaDinamica* p){
	return (p->prim==NULL);
}

PilhaDinamica* cria_dinamica(void){
	PilhaDinamica* p = (PilhaDinamica*)malloc(sizeof(PilhaDinamica));
	p->prim = NULL;
	return p;
}

No* ins_ini (No* l, float v){
	No* p = (No*)malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

No* ret_ini(No* l){
	No* p = l->prox;
	free(l);
	return p;
}

void empilhar_dinamicamente(PilhaDinamica* p, float v){
	p->prim = ins_ini(p->prim,v);
}

float desempilhar_dinamicamente(PilhaDinamica* p){
	float v;
	if(vazia_dinamica(p)){
		printf("Pilha vazia.\n");
		exit(1);
	}
	v = p->prim->info;
	p->prim = ret_ini(p->prim);
	return v;
}

void libera_dinamica(PilhaDinamica* p){
	No* q = p->prim;
	while (q!=NULL){
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

void imprime_dinamica(PilhaDinamica* p){
	No* q;
	for(q=p->prim; q!=NULL; q=q->prox)
		printf("%f\n",q->info);
}
