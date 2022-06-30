#include "../include/analisador.hpp"

using namespace std;

// variaveis globais para opcoes
char nome_entrada[100];
char nome_saida[100];
int M, S;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr, "analisador\n");
    fprintf(stderr, "\t-I, -i \t(Nome do arquivo de entrada com o texto a ser processado) \n");
    fprintf(stderr, "\t-M, -m \t(Valor da Mediana) \n");
    fprintf(stderr, "\t-S, -s \t(Uso de um algoritmo simples)\n");
    fprintf(stderr, "\t-O, -o \t(endereço do arquivo de saída)\n");
}

void parse_args(int argc, char **argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida
{
    // variaveis externas do getopt
    extern char *optarg;

    // variavel auxiliar
    int c;

    // inicializacao variaveis globais para opcoes
    S = 0;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "I:i:M:m:S:s:O:o:h")) != EOF)
        switch (c)
        {
        case 'I':
            strcpy(nome_entrada, optarg);
            break;
        case 'i':
            strcpy(nome_entrada, optarg);
            break;
        case 'M':
            M = atoi(optarg);
            break;
        case 'm':
            M = atoi(optarg);
            break;
        case 'S':
            S = atoi(optarg);
            break;
        case 's':
            S = atoi(optarg);
            break;
        case 'O':
            strcpy(nome_saida, optarg);
            break;
        case 'o':
            strcpy(nome_saida, optarg);
            break;

        case 'h':
        default:
            uso();
        }

    // verificacao da consistencia das opcoes
    erroAssert(M > 0, "Necessario passar um valor de Mediana");
}

int main(int argc, char **argv)
{
    // Usado para analisar os paramertos passado na linha de comando
    parse_args(argc, argv);

    // Inicia o memlog
    char nome[22] = "./analisador_log.out";
    iniciaMemLog(nome);
    ativaMemLog();

    // Testa se os arquivos de entrada e saida
    FILE *entrada = fopen(nome_entrada, "r");
    erroAssert(entrada != NULL, "Não foi possivel abrir o arquivo");
    fclose(entrada);
    FILE *saida = fopen(nome_saida, "w");
    erroAssert(saida != NULL, "Não foi possivel abrir o arquivo");
    fclose(saida);

    // Chama a funcao resposavel pela execucao do programa
    AnalisaQuickSort(M, nome_entrada, nome_saida, S);

    // finaliza a analise de tempo
    return finalizaMemLog();
}