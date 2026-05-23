# Listas em C

Projeto de Estrutura de Dados com implementacoes de filas em C usando o tipo
`Funcionario` como dado armazenado. O repositorio contem tres variacoes de fila:
estatica, dinamica e circular. O programa principal demonstra a fila circular
como uma fila de impressao com prioridade por cargo.

## Objetivo

O objetivo do projeto e praticar estruturas lineares do tipo fila, mostrando
diferentes formas de armazenamento:

- `FilaEstatica`: usa um vetor alocado com tamanho fixo e desloca os elementos
  quando remove o primeiro item.
- `FilaDinamica`: usa nos encadeados, crescendo conforme novos elementos sao
  inseridos.
- `FilaCircular`: usa um vetor fixo com indices circulares e, neste projeto,
  mantem os funcionarios ordenados por prioridade de cargo.

## Estrutura do projeto

```text
.
├── Makefile
├── README.md
├── src
│   ├── main.c
│   └── libs
│       ├── Funcionario
│       │   └── funcionario.h
│       └── Filas
│           ├── Circular
│           │   ├── filaCircular.c
│           │   └── filaCircular.h
│           ├── Dinamica
│           │   ├── filaDinamica.c
│           │   └── filaDinamica.h
│           └── Estatica
│               ├── filaEstatica.c
│               └── filaEstatica.h
└── output
    └── main
```

O diretorio `output` e criado automaticamente pelo `Makefile` durante a
compilacao.

## Modelo de dados

O arquivo `src/libs/Funcionario/funcionario.h` define o tipo usado pelas filas:

```c
typedef enum cargo {
  DIRETOR = 1,
  COORDENADOR = 2,
  FUNCIONARIO = 3
} Cargo;

typedef struct funcionario {
  char nome[100];
  char cpf[15];
  float salario;
  Cargo cargo;
} Funcionario;
```

A prioridade da fila circular e baseada no valor numerico do cargo. Quanto menor
o valor, maior a prioridade:

| Cargo | Valor | Prioridade |
| --- | ---: | --- |
| `DIRETOR` | `1` | Mais alta |
| `COORDENADOR` | `2` | Intermediaria |
| `FUNCIONARIO` | `3` | Mais baixa |

## Fila circular

A fila circular esta em:

- `src/libs/Filas/Circular/filaCircular.h`
- `src/libs/Filas/Circular/filaCircular.c`

Ela armazena os funcionarios em um vetor flexivel dentro da propria estrutura:

```c
struct filacircular {
  int tamanho, inicio, fim, quantidade;
  Funcionario funcionarioRemovido;
  Funcionario funcionarios[];
};
```

### Como funciona

- `inicio` aponta para o primeiro elemento logico da fila.
- `fim` aponta para a ultima posicao ocupada.
- `quantidade` guarda quantos funcionarios existem na fila.
- `tamanho` e a capacidade maxima definida na criacao.
- Os indices sao calculados com modulo (`% tamanho`), permitindo que a fila
  reutilize posicoes do vetor quando o inicio avanca.

No momento de enfileirar, a funcao `enfileirarFC` nao apenas adiciona no fim:
ela procura a posicao correta de acordo com o cargo do funcionario. Assim, a
fila permanece ordenada por prioridade.

Exemplo: se a fila contem funcionarios comuns e um diretor e inserido, o diretor
e colocado antes dos funcionarios com prioridade menor.

### Funcoes disponiveis

| Funcao | Descricao |
| --- | --- |
| `criarFC(int tamanho)` | Cria uma fila circular com capacidade fixa. |
| `vaziaFC(FilaCircular* fila)` | Retorna verdadeiro se a fila estiver vazia. |
| `cheiaFC(FilaCircular* fila)` | Retorna verdadeiro se a fila estiver cheia. |
| `enfileirarFC(FilaCircular* fila, Funcionario funcionario)` | Insere um funcionario mantendo a ordem de prioridade. |
| `desinfileirarFC(FilaCircular* fila)` | Remove e retorna o primeiro funcionario da fila. |
| `consultarFC(FilaCircular* fila)` | Retorna o primeiro funcionario sem remover. |
| `alterarFC(FilaCircular* fila, Funcionario funcionario)` | Altera os dados do primeiro funcionario. |
| `imprimirFC(FilaCircular* fila)` | Imprime a fila atual com cargo e prioridade. |
| `destruirFC(FilaCircular* fila)` | Libera a memoria alocada pela fila. |

## Fila estatica

A fila estatica esta em:

- `src/libs/Filas/Estatica/filaEstatica.h`
- `src/libs/Filas/Estatica/filaEstatica.c`

Ela tambem usa um vetor com tamanho fixo, mas funciona de forma linear. Os novos
elementos entram no final do vetor e a remocao sempre acontece no indice `0`.
Quando um elemento e removido, todos os demais sao deslocados uma posicao para a
esquerda.

### Funcoes disponiveis

| Funcao | Descricao |
| --- | --- |
| `criarFE(int tamanho)` | Cria uma fila estatica com capacidade fixa. |
| `vaziaFE(FilaEstatica* fila)` | Verifica se a fila esta vazia. |
| `cheiaFE(FilaEstatica* fila)` | Verifica se a fila esta cheia. |
| `enfileirarFE(FilaEstatica* fila, Funcionario funcionario)` | Insere um funcionario no final da fila. |
| `desinfileirarFE(FilaEstatica* fila)` | Remove o primeiro funcionario e desloca os demais. |
| `consultarFE(FilaEstatica* fila)` | Consulta o primeiro funcionario sem remover. |
| `alterarFE(FilaEstatica* fila, Funcionario funcionario)` | Altera os dados do primeiro funcionario. |
| `destruirFE(FilaEstatica* fila)` | Libera a memoria da fila. |

## Fila dinamica

A fila dinamica esta em:

- `src/libs/Filas/Dinamica/filaDinamica.h`
- `src/libs/Filas/Dinamica/filaDinamica.c`

Ela usa alocacao dinamica com nos encadeados. Cada no armazena um `Funcionario`
e um ponteiro para o proximo no.

```c
struct nofiladinamica {
  Funcionario funcionario;
  struct nofiladinamica* proximo;
};
```

Essa implementacao nao tem capacidade maxima definida na criacao. O limite
pratico passa a ser a memoria disponivel.

### Funcoes disponiveis

| Funcao | Descricao |
| --- | --- |
| `criarFD()` | Cria uma fila dinamica vazia. |
| `vaziaFD(FilaDinamica* fila)` | Verifica se a fila esta vazia. |
| `enfileirarFD(FilaDinamica* fila, Funcionario funcionario)` | Cria um novo no e insere no final da fila. |
| `desinfileirarFD(FilaDinamica* fila)` | Remove o no do inicio da fila. |
| `consultarFD(FilaDinamica* fila)` | Consulta o primeiro funcionario sem remover. |
| `alterarFD(FilaDinamica* fila, Funcionario funcionario)` | Altera os dados do primeiro funcionario. |
| `destruirFD(FilaDinamica* fila)` | Remove todos os nos e libera a fila. |

## Funcionamento do programa principal

O arquivo `src/main.c` demonstra o uso da `FilaCircular`.

Fluxo executado:

1. Cria uma fila circular chamada `spooler` com capacidade para 10 funcionarios.
2. Cria cinco funcionarios com nome, CPF, salario e cargo.
3. Insere os funcionarios na fila com `enfileirarFC`.
4. Imprime a fila ordenada por prioridade.
5. Remove os funcionarios um por um com `desinfileirarFC`.
6. Exibe o nome de cada funcionario removido como se o documento tivesse sido
   impresso.
7. Libera a memoria com `destruirFC`.

Como a prioridade e definida pelo cargo, a ordem final de impressao fica:

1. Diretores
2. Coordenadores
3. Funcionarios comuns

## Como compilar

Requisitos:

- GCC
- Make

Para compilar:

```bash
make
```

O executavel sera gerado em:

```text
output/main
```

## Como executar

Para compilar e executar usando o alvo do `Makefile`:

```bash
make run
```

Ou, depois de compilar:

```bash
./output/main
```

## Saida esperada

Com os dados atuais do `main.c`, a saida e:

```text
FILA DE IMPRESSAO:
1. Bruno - Diretor - prioridade 1
2. Diego - Diretor - prioridade 1
3. Carla - Coordenador - prioridade 2
4. Ana - Funcionario - prioridade 3
5. Elisa - Funcionario - prioridade 3

Imprimindo documentos:
Impresso: Bruno
Impresso: Diego
Impresso: Carla
Impresso: Ana
Impresso: Elisa
```

## Limpeza dos arquivos gerados

Para remover o diretorio `output` e o executavel compilado:

```bash
make clean
```

## Observacoes importantes

- As funcoes de remocao retornam ponteiros para `funcionarioRemovido`, um campo
  interno da estrutura da fila. Esse ponteiro deve ser usado antes da proxima
  remocao, pois o valor pode ser sobrescrito.
- A fila estatica e a fila circular possuem capacidade fixa definida na criacao.
- A fila dinamica cresce conforme necessario, alocando um novo no para cada
  insercao.
- As funcoes imprimem mensagens de erro quando a operacao nao pode ser feita,
  como consultar uma fila vazia ou inserir em uma fila cheia.
- Sempre chame a funcao `destruir*` correspondente depois de terminar de usar
  uma fila, para liberar a memoria alocada.

## Licenca

Este projeto possui um arquivo `LICENSE` na raiz do repositorio.
