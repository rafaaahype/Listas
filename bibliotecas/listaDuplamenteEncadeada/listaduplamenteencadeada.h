#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

struct funcionario{
  char nome[100];
	char cpf[15];
	float salario;
  struct funcionario* ant;
  struct funcionario* prox;
};
typedef struct funcionario Funcionario;
Funcionario* criar_lista(void);
Funcionario* buscar_funcionario(Funcionario* lista, const char cpfFunc[]);
Funcionario* add_lista(Funcionario* lista, Funcionario funcionario);
Funcionario* add_lista_ordenado(Funcionario* lista, Funcionario funcionario);
void imprime_lista(Funcionario* lista);
Funcionario* remover_funcionario(Funcionario* lista, const char cpfFunc[]);
int lista_vazia(Funcionario* lista);
Funcionario* liberar_lista(Funcionario* lista);

#endif
