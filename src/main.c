#include <stdio.h>
#include "listaencadeada.h"
#include "listaestatica.h"

int main()
{

    No *lista = criar_lista();
    ListaEstatica listaEst = criar_lista_est();

    int opcao;
    do
    {
        printf("\n1-Cadastrar  2-Listar dinamica  3-Listar estatica");
        printf("  4-Buscar  5-Salvar CSV  6-Carregar CSV  7-Remover  0-Sair\n> ");
        scanf(" %d", &opcao);

        switch (opcao)
        {

        case 1:
        {
            Funcionario f;
            printf("Nome:    ");
            scanf(" %99[^\n]", f.nome);
            printf("CPF:     ");
            scanf("%14s", f.cpf);
            printf("Salario: ");
            scanf("%f", &f.salario);
            lista = add_lista_ordenado(lista, f);
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
        /*ORIGINAL*/
        case 4:
        {
            char cpf[15];
            printf("CPF: ");
            scanf(" %14s", cpf);

            No *encontrado = buscar_funcionario(lista, cpf);
            if (encontrado)
                printf("[Dinamica] Nome: %s | Salario: R$ %.2f\n",encontrado->dados.nome, encontrado->dados.salario);
            else
                printf("[Dinamica] Nao encontrado.\n");

            int pos = buscar_est(&listaEst, cpf);
            if (pos != -1)
                printf("[Estatica] Nome: %s | Salario: R$ %.2f\n",listaEst.dados[pos].nome, listaEst.dados[pos].salario);
            else
                printf("[Estatica] Nao encontrado.\n");
            break;
        }

        case 5:
            salvar_csv(lista, "funcionarios_din.csv"); /* ORIGINAL */
            salvar_csv_est(&listaEst, "funcionarios_est.csv");
            break;

        case 6:
            lista = carregar_csv(lista, "funcionarios_din.csv"); /* ORIGINAL */
            carregar_csv_est(&listaEst, "funcionarios_est.csv");
            break;

        case 7:
        {
            char cpf[15];
            printf("CPF: ");
            scanf("%s", cpf);
            lista = remover_funcionario(lista, cpf);
            remover_est(&listaEst, cpf);
            break;
        }
        }

    } while (opcao != 0);

    lista = liberar_lista(lista); /* ORIGINAL */
    return 0;
}