#include "analisador.hpp"
#include "ordenacao.hpp"

void AnalisaQuickSort(int Mediana, char *arquivo_entrada, char *arquivo_saida)
{
    // cout << "QuickSort" << endl;
    Analisador *Analisador_do_arquivo = new Analisador[1000];

    int tipo_de_leitura = 0, posicao_lexicografica = 0, posicao_palavra = 0;
    char Primeira_Palavra[100], Palavra[100], lexicografia[25];

    FILE *entrada = fopen(arquivo_entrada, "r");
    erroAssert(entrada != NULL, "Não foi possivel abrir o arquivo");

    fscanf(entrada, "%s", Primeira_Palavra);
    if (strcmp(Primeira_Palavra, "#TEXTO") == 0)
    {
        tipo_de_leitura = 1;
    }
    else if (strcmp(Primeira_Palavra, "#ORDEM") == 0)
    {
        tipo_de_leitura = 2;
    }

    while (!feof(entrada))
    {

        // leMemLog((long int)jogador[posicao].Cartas_jogador[i]._valor_carta, (long int)sizeof(int), jogador[posicao]._id);
        if (tipo_de_leitura == 1)
        {
            fscanf(entrada, "%s", Palavra);

            if (strcmp(Palavra, "#ORDEM") == 0)
            {
                Analisador_do_arquivo[posicao_palavra].palavra_do_texto = " ";
                Analisador_do_arquivo[posicao_palavra].mediana = Mediana;
                tipo_de_leitura = 2;
            }
            else
            {
                // leMemLog((long int)Palavra, (long int)sizeof(char), posicao_palavra);
                ConverteMinusculo(Analisador_do_arquivo, posicao_palavra, Palavra);
                if (BuscaRepeticao(Analisador_do_arquivo, posicao_palavra, Palavra) == 0)
                {
                    posicao_palavra++;
                }
            }
        }
        else if (tipo_de_leitura == 2)
        {
            fscanf(entrada, "%s", Palavra);

            lexicografia[posicao_lexicografica] = Palavra[0];

            if (strcmp(Palavra, "#TEXTO") == 0)
            {
                tipo_de_leitura = 1;
            }
            posicao_lexicografica++;
        }
    }

    ImprimePalavras(Analisador_do_arquivo, posicao_palavra);
    ImprimeOrdemLexicografica(lexicografia);
    AtribuiOrdem(Analisador_do_arquivo, posicao_palavra, lexicografia);
    // ImprimeOrdemLexicograficadasPalavras(Analisador_do_arquivo, posicao_palavra);

    QuickSort(Analisador_do_arquivo, posicao_palavra);
    // ImprimePsalavras(Analisador_do_arquivo, posicao_palavra);
    // ContaRepeticao(Analisador_do_arquivo, posicao_palavra);
    //     cout << endl;
    EsquemaSaida(Analisador_do_arquivo, posicao_palavra, arquivo_saida);
    fclose(entrada);
}

void AnalisaSimples(int Mediana, char *arquivo_entrada, char *arquivo_saida)
{
    cout << "Selecao" << endl;

    Analisador *Analisador_do_arquivo = new Analisador[1000];

    int tipo_de_leitura = 0, posicao_lexicografica = 0, posicao_palavra = 0;
    char Primeira_Palavra[100], Palavra[100], lexicografia[25];

    FILE *entrada = fopen(arquivo_entrada, "r");
    erroAssert(entrada != NULL, "Não foi possivel abrir o arquivo");

    fscanf(entrada, "%s", Primeira_Palavra);
    if (strcmp(Primeira_Palavra, "#TEXTO") == 0)
    {
        tipo_de_leitura = 1;
    }
    else if (strcmp(Primeira_Palavra, "#ORDEM") == 0)
    {
        tipo_de_leitura = 2;
    }

    while (!feof(entrada))
    {

        // leMemLog((long int)jogador[posicao].Cartas_jogador[i]._valor_carta, (long int)sizeof(int), jogador[posicao]._id);
        if (tipo_de_leitura == 1)
        {
            fscanf(entrada, "%s", Palavra);

            if (strcmp(Palavra, "#ORDEM") == 0)
            {
                Analisador_do_arquivo[posicao_palavra].palavra_do_texto = " ";
                Analisador_do_arquivo[posicao_palavra].mediana = Mediana;
                tipo_de_leitura = 2;
            }
            else
            {
                // leMemLog((long int)Palavra, (long int)sizeof(char), posicao_palavra);
                ConverteMinusculo(Analisador_do_arquivo, posicao_palavra, Palavra);
                if (BuscaRepeticao(Analisador_do_arquivo, posicao_palavra, Palavra) == 0)
                {
                    posicao_palavra++;
                }
            }
        }
        else if (tipo_de_leitura == 2)
        {
            fscanf(entrada, "%s", Palavra);

            lexicografia[posicao_lexicografica] = Palavra[0];

            if (strcmp(Palavra, "#TEXTO") == 0)
            {
                tipo_de_leitura = 1;
            }
            posicao_lexicografica++;
        }
    }

    // ImprimePalavras(Analisador_do_arquivo, posicao_palavra);
    // ImprimeOrdemLexicografica(lexicografia);
    AtribuiOrdem(Analisador_do_arquivo, posicao_palavra, lexicografia);
    // ImprimeOrdemLexicograficadasPalavras(Analisador_do_arquivo, posicao_palavra);

    Insercao(Analisador_do_arquivo, posicao_palavra);
    // Selecao(Analisador_do_arquivo, posicao_palavra);

    EsquemaSaida(Analisador_do_arquivo, posicao_palavra, arquivo_saida);
    fclose(entrada);
}