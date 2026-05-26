#include "calc.h"
#include "pilha.h"
#include "string.h"

struct calc{
	char f[21];
	Pilha* p;
};

Calc* cria_calc(char* formato){
	Calc* c = (Calc*)malloc(sizeof(Calc));
	strcpy(c->f,formato);
	c->p = cria();
	return c;
}

void operando(Calc* c, float v){
	empilhar(c->p,v);
	printf(c->f,v);
}

void operador(Calc* c, char op){
	float v1, v2, v;

	if(vazia(c->p)) v2 = 0;
	else v2 = desempilhar(c->p);
	if(vazia(c->p)) v1 = 0;
	else v1 = desempilhar(c->p);

	switch(op){
		case '+': v = v1+v2; break;
		case '-': v = v1-v2; break;
		case '*': v = v1*v2; break;
		case '/': v = v1/v2; break;
	}

	empilhar(c->p,v);

	printf(c->f,v);
}

void libera_calc (Calc* c){
	libera(c->p);
	free(c);
}
