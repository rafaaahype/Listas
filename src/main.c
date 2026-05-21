#include "../bibliotecas/pilha.h"

int main(void){
	Pilha* teste = cria();
	empilhar(teste, 10);
	imprime(teste);
	libera(teste);
	return 0;
}
