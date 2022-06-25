#include "analisador.hpp"
/*
// definicoes de operacoes a serem testadas
#define QUICKSORT 1
#define SIMPLES 2

// variaveis globais para opcoes
static int opescolhida;
char nome_entrada[100];
char nome_saida[100];
int Mediana;
char aux[10];

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
    opescolhida = 1;
    nome_entrada[0] = 0;
    nome_saida[0] = 0;
    Mediana = -1;
    aux[0] = ' ';

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "smtp:I:i:M:m:S:s:O:o")) != EOF)
        switch (c)
        {
        case 'I':
            strcpy(nome_entrada, optarg);
            break;
        case 'i':
            strcpy(nome_entrada, optarg);
            break;
        case 'M':
            strcpy(aux, optarg);
            Mediana = stoi(aux);
            break;
        case 'm':
            strcpy(aux, optarg);
            Mediana = stoi(aux);
            break;
        case 'S':
            avisoAssert(opescolhida == -1, "Mais de uma operacao escolhida");
            opescolhida = SIMPLES;
            break;
        case 's':
            avisoAssert(opescolhida == -1, "Mais de uma operacao escolhida");
            opescolhida = SIMPLES;
            break;
        case 'O':
            strcpy(nome_saida, optarg);
            break;
        case 'o':
            strcpy(nome_saida, optarg);
            break;
        default:
            uso();
            exit(1);
        }
    // verificacao da consistencia das opcoes
    erroAssert(opescolhida > 0, "analisador - necessario escolher operacao");
}

int main(int argc, char **argv)
{
    parse_args(argc, argv);

    char nome[100] = "./analisador_log.out";
    iniciaMemLog(nome);
    ativaMemLog();
    switch (opescolhida)
    {
    case QUICKSORT:
        AnalisaQuickSort(Mediana);
    case SIMPLES:
        AnalisaSimples(Mediana);
    }
    return finalizaMemLog();
    return 0;
}
*/
int main()
{
    int Mediana = 0;

    char nome[100] = "./analisador_log.out";
    iniciaMemLog(nome);
    ativaMemLog();

    AnalisaQuickSort(Mediana);

    return finalizaMemLog();
    return 0;
}