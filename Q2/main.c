#include <stdio.h>
#include "listaencadeada.h"
#include "listaestatica.h"

int main()
{
   
    Funcionario *lista = criar_lista()
    ListaEstatica listaEst = criar_lista_est();

    int opcao;
    do
    {
        printf("\n1-Cadastrar  2-Listar dinamica  3-Listar estatica");
        printf("  4-Buscar  5-Salvar CSV  6-Carregar CSV  0-Sair\n> ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
      
        case 1:
        {
            Funcionario f;
            printf("Nome:    "); scanf("%s", f.nome);
            printf("CPF:     "); scanf("%s", f.cpf);
            printf("Salario: "); scanf("%f", &f.salario);
            lista = add_lista_ordenado(lista, f); /* ORIGINAL */
            add_lista_est(&listaEst, f);         
            break;
        }
        /*ORIGINAL*/
        case 2:
            imprime_lista(lista);
            break;
    
        case 3:
            imprime_lista_est(&listaEst);
            break;
        /*CÓDIGO ORIGINAL*/
        case 4:
        {
            char cpf[15];
            printf("CPF: "); scanf(" %14s", cpf);
            Funcionario *encontrado = buscar_funcionario(lista, cpf); /* ORIGINAL */
            if (encontrado)
                printf("Nome: %s | Salario: R$ %.2f\n",
                       encontrado->nome, encontrado->salario);
            else
                printf("Nao encontrado.\n");
            break;
        }
   
        case 5:
            salvar_csv(lista, "funcionarios_din.csv");      /* ORIGINAL */
            salvar_csv_est(&listaEst, "funcionarios_est.csv"); /* NOVO */
            break;
     
        case 6:
            lista = carregar_csv(lista, "funcionarios_din.csv");      /* ORIGINAL */
            carregar_csv_est(&listaEst, "funcionarios_est.csv");       /* NOVO */
            break;
        }
    } while (opcao != 0);

    lista = liberar_lista(lista); /* ORIGINAL */
    return 0;
}
