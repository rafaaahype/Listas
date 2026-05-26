#include <stdio.h>
#include "matriz.h"

int main(void)
{
    int linhas, colunas;
    printf("Informe a ordem da matriz\n");
    printf("Linhas: ");
    scanf("%d", &linhas);
    printf("Colunas: ");
    scanf("%d", &colunas);
    Matriz *m = dimensionarMatriz(linhas, colunas);

    int opcao, linha, coluna;

    do
    {
        printf("\n1-Preencher  2-Exibir  3-Buscar  4-Adicionar  5-Remover  6-Somar  7-Zerar  0-Sair\n> ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            preencherMatriz(m);
            break;
        case 2:
            exibirMatriz(m);
            break;
        case 3:
            printf("Linha: ");
            scanf("%d", &linha);
            printf("Coluna: ");
            scanf("%d", &coluna);
            printf("Valor: %.2f\n", buscarElementoMatriz(m, linha, coluna));
            break;
        case 4:
        {
            float valor;
            printf("Linha: ");
            scanf("%d", &linha);
            printf("Coluna: ");
            scanf("%d", &coluna);
            printf("Valor: ");
            scanf("%f", &valor);
            adicionarElementoMatriz(m, valor, linha, coluna);
            break;
        }
        case 5:
            printf("Linha: ");
            scanf("%d", &linha);
            printf("Coluna: ");
            scanf("%d", &coluna);
            removerElementoMatriz(m, linha, coluna);
            break;
        case 6:
        {
            printf("Informe a segunda matriz\n");
            printf("Linhas: ");
            scanf("%d", &linhas);
            printf("Colunas: ");
            scanf("%d", &colunas);
            Matriz *b = dimensionarMatriz(linhas, colunas);
            preencherMatriz(b);
            Matriz *soma = somarMatrizes(m, b);
            if (soma)
            {
                printf("Resultado:\n");
                exibirMatriz(soma);
                destruirMatriz(soma);
            }
            destruirMatriz(b);
            break;
        }
        case 7:
            zerarMatriz(m);
            printf("Matriz zerada.\n");
            break;
        }

    } while (opcao != 0);

    destruirMatriz(m);
    return 0;
}