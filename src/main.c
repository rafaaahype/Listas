#include "../bibliotecas/listaestatica.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct {
	char nome[100];
	char cpf[15];
	float salario;
} Funcionario;

int main(void){
	Funcionario *f = (Funcionario*) malloc(sizeof(Funcionario));
	if(f){
		f->salario=3;
		printf("%.2f\n",f->salario);
		free(f);
	}
	return 0;
}
