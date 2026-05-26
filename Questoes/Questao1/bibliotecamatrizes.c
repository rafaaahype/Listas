#include "bibliotecamatrizes.h"

void dimensionarMatriz(float vetor[], int linhas, int colunas)
{
    vetor[0] = linhas;
    vetor[1] = colunas;
}

void preencherMatriz(float vetor[])
{
    for (int linha = 1; linha <= (int)vetor[0]; linha++)
    {
        for (int coluna = 1; coluna <= (int)vetor[1]; coluna++)
        {
            printf("Digite um elemento %dx%d: ", linha, coluna);
            float elemento;
            scanf("%f", &elemento);
            adicionarElementoMatriz(vetor, elemento, linha, coluna);
        }
    }
}

void anularMatriz(float vetor[])
{
    for (int linha = 1; linha <= (int)vetor[0]; linha++)
    {
        for (int coluna = 1; coluna <= (int)vetor[1]; coluna++)
        {
            removerElementoMatriz(vetor, linha, coluna);
        }
    }
}

void exibirMatriz(float vetor[])
{
    for (int linha = 1; linha <= (int)vetor[0]; linha++)
    {
        for (int coluna = 1; coluna <= (int)vetor[1]; coluna++)
        {
            printf("%6.2f ", buscarElementoMatriz(vetor, linha, coluna));
        }
        putchar('\n');
    }
}

void adicionarElementoMatriz(float vetor[], float elemento, int linha, int coluna)
{
    vetor[2 + (linha - 1) * (int)vetor[1] + (coluna - 1)] = elemento;
}

void removerElementoMatriz(float vetor[], int linha, int coluna)
{
    vetor[2 + (linha - 1) * (int)vetor[1] + (coluna - 1)] = 0;
}

float buscarElementoMatriz(float vetor[], int linha, int coluna)
{

    return vetor[2 + (linha - 1) * (int)vetor[1] + (coluna - 1)];
}

void somarMatrizes(float vetorA[], float vetorB[], float vetorC[])
{
    if (vetorA[0] != vetorB[0] || vetorA[1] != vetorB[1])
    {
        puts("Não é possível efetuar a soma dessas matrizes. A ordem é diferente.");
        return;
    }
    for (int linha = 1; linha <= vetorA[0]; linha++)
    {
        for (int coluna = 1; coluna <= vetorA[1]; coluna++)
        {
            adicionarElementoMatriz(vetorC, buscarElementoMatriz(vetorA, linha, coluna) + buscarElementoMatriz(vetorB, linha, coluna), linha, coluna);
        }
    }
}
void subtrairMatriz(float vetorA[], float vetorB[], float vetorC[])
{
    if (vetorA[0] != vetorB[0] || vetorA[1] != vetorB[1])
    {
        puts("Não é possível efetuar a soma dessas matrizes. A ordem é diferente.");
        return;
    }
    for (int linha = 1; linha <= vetorA[0]; linha++)
    {
        for (int coluna = 1; coluna <= vetorA[1]; coluna++)
        {
            adicionarElementoMatriz(vetorC, buscarElementoMatriz(vetorA, linha, coluna) - buscarElementoMatriz(vetorB, linha, coluna), linha, coluna);
        }
    }
}

// Funções de teste
void criarCopia(float vetor[], float vetorCopia[])
{
    for (int linha = 1; linha <= (int)vetor[0]; linha++)
    {
        for (int coluna = 1; coluna <= (int)vetor[1]; coluna++)
        {
            adicionarElementoMatriz(vetorCopia, buscarElementoMatriz(vetor, linha, coluna), linha, coluna);
        }
    }
}

void matrizTransposta(float vetor[], float vetorTransposto[])
{
    for (int linha = 1; linha <= (int)vetor[0]; linha++)
    {
        for (int coluna = 1; coluna <= (int)vetor[1]; coluna++)
        {
            adicionarElementoMatriz(vetorTransposto, buscarElementoMatriz(vetor, coluna, linha), linha, coluna);
        }
    }
}

int matrizIdentidade(float vetor[])
{
    for (int linha = 1; linha <= vetor[0]; linha++)
    {
        for (int coluna = 1; coluna <= vetor[0]; coluna++)
        {
            if (linha == coluna)
            {
                if (buscarElementoMatriz(vetor, linha, coluna) != 1)
                    return 0;
            }
            else if (buscarElementoMatriz(vetor, linha, coluna) != 0)
                return 0;
        }
    }
    return 1;
}
void multiplicarMatriz(float vetorA[], float vetorB[], float vetorC[])
{
    if (vetorA[1] != vetorB[0])
    {
        puts("É impossível realizar essa multiplicação.");
        return;
    }

    float vetorCopia[2 + (int)vetorB[0] * (int)vetorB[1]];
    dimensionarMatriz(vetorCopia, (int)vetorB[0], (int)vetorB[1]);
    matrizTransposta(vetorB, vetorCopia);

    for (int linha = 1; linha <= vetorA[0]; linha++)
    {
        for (int coluna = 1; coluna <= vetorB[1]; coluna++)
        {
            float resultado = 0;
            for (int i = 1; i <= vetorA[1]; i++)
            {
                resultado += buscarElementoMatriz(vetorA, linha, i) * buscarElementoMatriz(vetorCopia, coluna, i);
            }
            adicionarElementoMatriz(vetorC, resultado, linha, coluna);
        }
    }
}
int matrizInversa(float vetorA[], float vetorB[]){
    float vetorCopia[2 + (int)vetorB[0] * (int)vetorB[1]];
    dimensionarMatriz(vetorCopia, (int)vetorB[0], (int)vetorB[1]);

    multiplicarMatriz(vetorA, vetorB, vetorCopia);
    return matrizIdentidade(vetorCopia);
}


int contarSaidas(float vetor[], int cidade) {
    int saidas = 0;
    for (int j = 1; j <= (int)vetor[0]; j++)
        if (j != cidade && (int)buscarElementoMatriz(vetor, cidade, j) == 1)
            saidas++;
    return saidas;
}

// mesma coisa de contar as saides
//A coluna representa todas as estradad qye chegam naquela cidade


int contarEntradas(float vetor[], int cidade) {
    int entradas = 0;
    for (int i = 1; i <= (int)vetor[0]; i++)
        if (i != cidade && (int)buscarElementoMatriz(vetor, i, cidade) == 1)
            entradas++;
    return entradas;
}

void cidadesIsoladas(float vetor[]) {
    int encontrou = 0;
    for (int c = 1; c <= (int)vetor[0]; c++) {
        if (contarSaidas(vetor, c) == 0 && contarEntradas(vetor, c) == 0) {
            printf("QUESTAO 1 - i = Cidade %d isolada\n", c - 1);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("QUESTAO 1 - i = Nenhuma cidade isolada.\n");
}

void semSaidaComEntrada(float vetor[]) {
    int encontrou = 0;
    for (int c = 1; c <= (int)vetor[0]; c++) {
        if (contarSaidas(vetor, c) == 0 && contarEntradas(vetor, c) > 0) {
            printf("QUESTAO 1 - ii = Cidade %d\n", c - 1);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("QUESTAO 1 - ii = Nenhuma cidade sem saida e com entrada.\n");
}

void comSaidaSemEntrada(float vetor[]) {
    int encontrou = 0;
    for (int c = 1; c <= (int)vetor[0]; c++) {
        if (contarSaidas(vetor, c) > 0 && contarEntradas(vetor, c) == 0) {
            printf("QUESTAO 1 - iii = Cidade %d\n", c - 1);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("QUESTAO 1 - iii = Nenhuma cidade com saida e sem entrada.\n");
}

void cidadeMaisEntradas(float vetor[]) {
    int qtd = 0;  // guarda o maior numero de entradas encontrado ate agora
    int qual = 1; // guarda qual cidade tem esse maior numero

    for (int c = 1; c <= (int)vetor[0]; c++) { // percorre todas as cidades
        if (contarEntradas(vetor, c) > qtd) {   // se essa cidade tem mais entradas que o max atual
            qtd = contarEntradas(vetor, c);      // atualiza o max
            qual = c;                            // atualiza qual cidade é essa
        }
    }
    printf("QUESTAO 1 - iv = Cidade %d com mais entradas\n", qual - 1);
}

void relacionarCidades(float vetor[], int cidade){
    for(int linha=1; linha<=(int)vetor[0];linha++){
        if(buscarElementoMatriz(vetor, linha, cidade) == 1) printf("%d", linha);
    }
}

void saidasParaK(float vetor[], int k) {
    int kBase = k + 1; 
    int encontrou = 0;
    printf("QUESTAO 1 - v = Cidades com saida direta para cidade %d: ", k);
    for (int i = 1; i <= (int)vetor[0]; i++) {
        if (i != kBase && (int)buscarElementoMatriz(vetor, i, kBase) == 1) {
            printf("Cidade %d  ", i - 1);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("Nenhuma.");
    printf("\n");
}

void verificaRoteiro(float vetor[], int roteiro[], int m) {
    printf("QUESTAO 1 - vi = ");
    for (int i = 0; i < m - 1; i++) {
        int orig = roteiro[i] + 1;      
        int dest = roteiro[i + 1] + 1;
        if ((int)buscarElementoMatriz(vetor, orig, dest) == 0) {
            printf("IMPOSSIVEL: nao ha estrada de %d para %d.\n",
                   roteiro[i], roteiro[i + 1]);
            return;
        }
    }
    printf("POSSIVEL!\n");
}

