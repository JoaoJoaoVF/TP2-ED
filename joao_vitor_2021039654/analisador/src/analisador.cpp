#include "../include/analisador.hpp"
#include "../include/ordenacao.hpp"

void AnalisaQuickSort(int Mediana, char *arquivo_entrada, char *arquivo_saida, int Simples)
{
    cout << "QuickSort" << endl;
    // Cria um operador de classe analisador e aloca a quantiade maxima de elementos possiveis
    Analisador *Analisador_do_arquivo = new Analisador[10000];

    // cria e inicializa variaves uteis durante o programa
    int tipo_de_leitura = 0, posicao_lexicografica = 0, posicao_palavra = 0;
    char Primeira_Palavra[100], Palavra[100], lexicografia[25];

    // Realiza a abertura do arquivo que contem os dados de entrada
    FILE *entrada = fopen(arquivo_entrada, "r");
    erroAssert(entrada != NULL, "Não foi possivel abrir o arquivo");

    // Realiza a leitura da primeira palavra do texto
    fscanf(entrada, "%s", Primeira_Palavra);

    // Caso essa palavra seja o a nova ordem alfabetica seta o tipo de leitura como 1,
    // caso seja o texto o tipo de leitura sera 2
    if (strcmp(Primeira_Palavra, "#TEXTO") == 0)
    {
        tipo_de_leitura = 1;
    }
    else if (strcmp(Primeira_Palavra, "#ORDEM") == 0)
    {
        tipo_de_leitura = 2;
    }

    // Realiza a leitura dos dados ate o aquivo acabar
    while (!feof(entrada))
    {

        // leMemLog((long int)jogador[posicao].Cartas_jogador[i]._valor_carta, (long int)sizeof(int), jogador[posicao]._id);

        // No caso da leitura inicial ser #TEXTO
        if (tipo_de_leitura == 1)
        {
            // Realiza a leitura da palavra
            fscanf(entrada, "%s", Palavra);

            // Atribui o valor da mediana, o valor da partição de ordencação e o id da palavra
            // Analisador_do_arquivo[posicao_palavra].mediana = Mediana;
            Analisador_do_arquivo[posicao_palavra].simples = Simples;
            Analisador_do_arquivo[posicao_palavra].id = posicao_palavra;
            // cout << Analisador_do_arquivo[posicao_palavra].simples << endl;

            if (strcmp(Palavra, "#ORDEM") == 0)
            {
                // Quando o bloco #ORDEM é encontrado troca o tipo de leitura para 2
                tipo_de_leitura = 2;
            }
            else
            {
                leMemLog((long int)Palavra, (long int)sizeof(char), posicao_palavra);
                // Chama a funcao para tratar da palavra lida
                ConverteMinusculo(Analisador_do_arquivo, posicao_palavra, Palavra);

                // Chama a funcao para analisar se ha repeticao caso nao haja a posicao da palavra não é incrementada
                if (BuscaRepeticao(Analisador_do_arquivo, posicao_palavra, Palavra) == 0)
                {
                    posicao_palavra++;
                }
            }
        }
        else if (tipo_de_leitura == 2)
        {
            // Realiza a leitura do caracter da ordem lexicografica nova
            fscanf(entrada, "%s", Palavra);

            // Coloca a letra na sua nova posicao no alfabeto novo
            lexicografia[posicao_lexicografica] = Palavra[0];

            if (strcmp(Palavra, "#TEXTO") == 0)
            {
                // Quando o bloco #TEXTO é encontrado troca o tipo de leitura para 1
                tipo_de_leitura = 1;
            }

            // Incrementa a posicao lexicografica
            posicao_lexicografica++;
        }
    }
    // cout << posicao_palavra << endl;
    // Chama as funcoes necessarias para o resto da execucao do programa

    // ImprimePalavras(Analisador_do_arquivo, posicao_palavra);
    // ImprimeOrdemLexicografica(lexicografia);
    AtribuiOrdem(Analisador_do_arquivo, posicao_palavra, lexicografia);
    // ImprimeOrdemLexicograficadasPalavras(Analisador_do_arquivo, posicao_palavra);
    // cout << posicao_palavra / (Mediana * 2) << endl;
    int b = 0, c = posicao_palavra / Mediana, d = 0;
    for (int a = 0; a < posicao_palavra; a++)
    {
        b++;
        if (b == Mediana)
        {
            QuickSort(Analisador_do_arquivo, a + 1);
            // cout << a << endl;
            b = 0;
            d++;
        }
        else if (c == d)
        {
            QuickSort(Analisador_do_arquivo, posicao_palavra);
            // cout << c << " " << d << endl;
        }
    }
    QuickSort(Analisador_do_arquivo, posicao_palavra);
    // QuickSort(Analisador_do_arquivo, posicao_palavra);
    // QuickSort(Analisador_do_arquivo, posicao_palavra);
    // QuickSort(Analisador_do_arquivo, posicao_palavra);
    // QuickSort(Analisador_do_arquivo, posicao_palavra);
    // QuickSort(Analisador_do_arquivo, posicao_palavra);
    // ImprimePsalavras(Analisador_do_arquivo, posicao_palavra);
    // ContaRepeticao(Analisador_do_arquivo, posicao_palavra);
    //     cout << endl;
    EsquemaSaida(Analisador_do_arquivo, posicao_palavra, arquivo_saida);

    // Realiza o fechamento do arquivo de entrada
    fclose(entrada);
}
