#include "Analisador.hpp"
#include "Execucao.hpp"

using namespace std;

// Realiza da troca de conteudo entre 2 strings
#define Troca_string(A, B)          \
    {                               \
        string string_auxiliar = A; \
        A = B;                      \
        B = string_auxiliar;        \
    }

// Realiza da troca de conteudo entre 2 int
#define Troca_int(A, B)       \
    {                         \
        int int_auxiliar = A; \
        A = B;                \
        B = int_auxiliar;     \
    }

// Atribui um peso a cada letra da palavra de acordo com a nova ordem lexicografica
void AtribuiOrdem(Analisador Analisador[], int qtde_palavras, char Letras[])
{
    // Variaveis auxiliares para tamanho e loops
    int tam, i, j, k;

    // Percorre todas as palavras
    for (i = 0; i < qtde_palavras; i++)
    {
        // Seta o tamanho como o tamanho nominal da palvra atual do loop que sera feitas as operacoes
        tam = Analisador[i].palavra_do_texto.length();

        // Loop que percorre cada letra da palavra
        for (j = 0; j < tam; j++)
        {
            // Loop que percorre o novo alfabeto do inicio ao fim
            for (k = 0; k < 26; k++)
            {
                leMemLog((long int)Analisador[i].palavra_do_texto[j], (long int)sizeof(char), Analisador[i].id);

                // Em caso de um encontro de letras iguais a posicao relativa da letra no vetor é
                // guardada no vetor na posicao relativa dessa letra na palavra
                if (Analisador[i].palavra_do_texto[j] == tolower(Letras[k]))
                {
                    Analisador[i].lexicografica_da_ordem[j] = k;

                    ESCREVEMEMLOG((long int)Analisador[i].lexicografica_da_ordem[j], (long int)sizeof(int), Analisador[i].id);
                }
            }
        }
    }
}

// Faz a conversao da palavra para minusculo, remove os caracteres especias da palavra
void ConverteMinusculo(Analisador Analisador[], int pos_palavra, char palavra_extraida[])
{
    // variaveis auxiliares de tamanho da palavra e para o loop
    int tam, i;

    // Retorna o tamanho total da palvavra
    tam = strlen(palavra_extraida);

    leMemLog((long int)Analisador[pos_palavra].palavra_do_texto[tam - 1], (long int)Analisador[pos_palavra].palavra_do_texto.length() * sizeof(char), Analisador[pos_palavra].id);

    // Em caso de haver um caracter especial diferente de '-' na palavra de acordo com sua posicação na tabela ASCII
    // if ((palavra_extraida[tam - 1] > 0 && palavra_extraida[tam - 1] < 48) ||
    //     (palavra_extraida[tam - 1] > 57 && palavra_extraida[tam - 1] < 65) ||
    //     (palavra_extraida[tam - 1] > 90 && palavra_extraida[tam - 1] < 97) ||
    //     (palavra_extraida[tam - 1] > 122))
    // {
    //     palavra_extraida[tam - 1] = 0;
    // }

    // Variavel auxiliar para guardar a conversao da palavra para minusculo
    char resultado[tam];

    for (i = 0; i <= tam; i++)
    {
        // Converte cada letra da palavra para minusculo
        resultado[i] = tolower(palavra_extraida[i]);
    }

    // Atribui a palavra com todas as letras minusculas para ela mesmo
    Analisador[pos_palavra].palavra_do_texto = resultado;
    ESCREVEMEMLOG((long int)Analisador[pos_palavra].palavra_do_texto[0], (long int)Analisador[pos_palavra].palavra_do_texto.length() * sizeof(char), Analisador[pos_palavra].id);
}

// Realiza a busca da repeticao da palavra
void BuscaRepeticao(Analisador Analisador[], int qtde_palavras)
{
    // Variavel que define a quantidade de vezes em que a palavra aparece no texto
    int reps = 0;

    // Loop que compara as palavras e em caso de encontrar uma correspondencia incrementa a variavel exclusiva para isso
    for (int i = 0; i < qtde_palavras; i++)
    {
        reps = 0;
        for (int j = 0; j < qtde_palavras; j++)
        {
            leMemLog((long int)Analisador[i].palavra_do_texto[0], (long int)Analisador[i].palavra_do_texto.length() * sizeof(char), Analisador[i].id);
            leMemLog((long int)Analisador[j].palavra_do_texto[0], (long int)Analisador[j].palavra_do_texto.length() * sizeof(char), Analisador[j].id);

            if (Analisador[i].palavra_do_texto == Analisador[j].palavra_do_texto && Analisador[j].contado != -1)
            {
                reps++;
                Analisador[j].contado = -1;

                ESCREVEMEMLOG((long int)Analisador[j].contado, (long int)sizeof(int), Analisador[j].id);
            }
        }
        Analisador[i].repeticoes = reps;

        ESCREVEMEMLOG((long int)Analisador[i].repeticoes, (long int)sizeof(int), Analisador[i].id);
    }
}

void RemoveCaracteres(Analisador Analisador[], int qtde_palavras)
{
    int i, j, k;
    int length;
    // string aux;

    // Loop que faz a escrita dos dados no arquivo
    for (int i = 0; i < qtde_palavras; i++)
    {
        j = 0;
        // // conversao = Analisador[i].palavra_do_texto;

        // // conversao[j] = Analisador[i].palavra_do_texto[k];

        length = Analisador[i].palavra_do_texto.length();

        // if (Analisador[i].palavra_do_texto[k])
        // if ((Analisador[i].palavra_do_texto[k] < 97) || (Analisador[i].palavra_do_texto[k] > 122) && (Analisador[i].palavra_do_texto[k] < 48) || (Analisador[i].palavra_do_texto[k] > 57))
        for (k = 0; k < length; k++)
        {
            if ((Analisador[i].palavra_do_texto[k] > 0 && Analisador[i].palavra_do_texto[k] < 48) ||
                (Analisador[i].palavra_do_texto[k] > 57 && Analisador[i].palavra_do_texto[k] < 65) ||
                (Analisador[i].palavra_do_texto[k] > 90 && Analisador[i].palavra_do_texto[k] < 97) ||
                (Analisador[i].palavra_do_texto[k] > 122))
            {
                // cout << "dsalpçods" << endl;
                // conversao[j] = Analisador[i].palavra_do_texto[k];
                // cout << conversao[j] << endl;
                if (Analisador[i].palavra_do_texto[k + 1] == 0)
                {
                    // cout << "null" << endl;
                    Analisador[i].palavra_do_texto.erase(k);
                }
                else
                {
                    Analisador[i].palavra_do_texto[k] = Analisador[i].palavra_do_texto[k + 1];
                }
                j++;
            }
        }
    }
}
// Realiza a escrita do resultado num arquivo txt
void Saida(Analisador Analisador[], int qtde_palavras, char *nome_saida)
{
    // Abertura do arquivo
    ofstream saida(nome_saida);

    int i, j, k;
    int length;
    string conversao;

    // Loop que faz a escrita dos dados no arquivo
    for (int i = 0; i < qtde_palavras; i++)
    {
        // j = 0;
        // // conversao = Analisador[i].palavra_do_texto;

        // // conversao[j] = Analisador[i].palavra_do_texto[k];

        // length = Analisador[i].palavra_do_texto.length();

        // for (k = 0; k < length; k++)
        // {
        //     // if (Analisador[i].palavra_do_texto[k])
        //     // if ((Analisador[i].palavra_do_texto[k] < 97) || (Analisador[i].palavra_do_texto[k] > 122) && (Analisador[i].palavra_do_texto[k] < 48) || (Analisador[i].palavra_do_texto[k] > 57))
        //     if ((Analisador[i].palavra_do_texto[k] > 0 && Analisador[i].palavra_do_texto[k] < 48) ||
        //         (Analisador[i].palavra_do_texto[k] > 57 && Analisador[i].palavra_do_texto[k] < 65) ||
        //         (Analisador[i].palavra_do_texto[k] > 90 && Analisador[i].palavra_do_texto[k] < 97) ||
        //         (Analisador[i].palavra_do_texto[k] > 122))
        //     {
        //         // cout << "dsalpçods" << endl;
        //         // conversao[j] = Analisador[i].palavra_do_texto[k];
        //         // cout << conversao[j] << endl;
        //         if (Analisador[i].palavra_do_texto[k + 1] == 0)
        //         {
        //             // cout << "null" << endl;
        //             Analisador[i].palavra_do_texto.erase(k);
        //         }
        //         else
        //         {
        //             Analisador[i].palavra_do_texto[k] = Analisador[i].palavra_do_texto[k + 1];
        //         }
        //         j++;
        //     }
        // }

        leMemLog((long int)Analisador[i].repeticoes, (long int)sizeof(int), Analisador[i].id);

        if (Analisador[i].repeticoes > 0)
        {
            saida << Analisador[i].palavra_do_texto << " " << Analisador[i].repeticoes << endl;

            // saida << conversao << " " << Analisador[i].repeticoes << endl;

            leMemLog((long int)Analisador[i].palavra_do_texto[0], (long int)Analisador[i].palavra_do_texto[0] * sizeof(char), Analisador[i].id);
        }
    }

    // Realiza a finalização do conteudo e fecha o arquivo de saida
    saida << "#FIM" << endl;
    saida.close();
}

// Algoritmo Simples usado no trabalho, realiza a selesção da palavra do inicio e faz a troca dos dados
void Selecao(Analisador Analisador[], int final, int inicio)
{
    int i, j, Min;

    for (i = inicio; i < final - 1; i++)
    {
        Min = i;

        for (j = i + 1; j < final; j++)
        {
            if (Analisador[j] < Analisador[Min])
                Min = j;
        }

        // Troca dos dados em caso de mudanca;
        Troca_string(Analisador[i].palavra_do_texto, Analisador[Min].palavra_do_texto);

        ESCREVEMEMLOG((long int)Analisador[i].palavra_do_texto[0], (long int)Analisador[i].palavra_do_texto.length() * sizeof(char), Analisador[i].id);
        ESCREVEMEMLOG((long int)Analisador[Min].palavra_do_texto[0], (long int)Analisador[Min].palavra_do_texto.length() * sizeof(char), Analisador[Min].id);

        for (int teste = 0; teste < 1000; teste++)
        {
            Troca_int(Analisador[i].lexicografica_da_ordem[teste], Analisador[Min].lexicografica_da_ordem[teste]);

            ESCREVEMEMLOG((long int)Analisador[i].lexicografica_da_ordem[teste], (long int)sizeof(int), Analisador[i].id);
            ESCREVEMEMLOG((long int)Analisador[Min].lexicografica_da_ordem[teste], (long int)sizeof(int), Analisador[Min].id);
        }
        Troca_int(Analisador[i].id, Analisador[Min].id);

        ESCREVEMEMLOG((long int)Analisador[i].id, (long int)sizeof(int), Analisador[i].id);
        ESCREVEMEMLOG((long int)Analisador[Min].id, (long int)sizeof(int), Analisador[Min].id);

        Troca_int(Analisador[i].repeticoes, Analisador[Min].repeticoes);

        ESCREVEMEMLOG((long int)Analisador[i].repeticoes, (long int)sizeof(int), Analisador[i].id);
        ESCREVEMEMLOG((long int)Analisador[Min].repeticoes, (long int)sizeof(int), Analisador[Min].id);
    }
}

void Particao(int Esq, int Dir, int *i, int *j, Analisador Analisador[])
{

    int x;
    *i = Esq;
    *j = Dir;

    x = (*i + *j) / 2;

    do
    {
        while (Analisador[x] > Analisador[*i])
        {
            (*i)++;
        }

        while (Analisador[x] < Analisador[*j])
        {
            (*j)--;
        }
        if (*i <= *j)
        {
            // Troca dos dados em caso de mudanca;
            Troca_string(Analisador[*i].palavra_do_texto, Analisador[*j].palavra_do_texto);

            ESCREVEMEMLOG((long int)Analisador[*i].palavra_do_texto[0], (long int)Analisador[*i].palavra_do_texto.length() * sizeof(char), Analisador[*i].id);
            ESCREVEMEMLOG((long int)Analisador[*j].palavra_do_texto[0], (long int)Analisador[*j].palavra_do_texto.length() * sizeof(char), Analisador[*j].id);

            for (int teste = 0; teste < 1000; teste++)
            {
                Troca_int(Analisador[*i].lexicografica_da_ordem[teste], Analisador[*j].lexicografica_da_ordem[teste]);

                ESCREVEMEMLOG((long int)Analisador[*i].lexicografica_da_ordem[teste], (long int)sizeof(int), Analisador[*i].id);
                ESCREVEMEMLOG((long int)Analisador[*j].lexicografica_da_ordem[teste], (long int)sizeof(int), Analisador[*j].id);
            }
            Troca_int(Analisador[*i].id, Analisador[*j].id);

            ESCREVEMEMLOG((long int)Analisador[*i].id, (long int)sizeof(int), Analisador[*i].id);
            ESCREVEMEMLOG((long int)Analisador[*j].id, (long int)sizeof(int), Analisador[*j].id);

            Troca_int(Analisador[*i].repeticoes, Analisador[*j].repeticoes);

            ESCREVEMEMLOG((long int)Analisador[*i].repeticoes, (long int)sizeof(int), Analisador[*i].id);
            ESCREVEMEMLOG((long int)Analisador[*j].repeticoes, (long int)sizeof(int), Analisador[*j].id);

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Analisador Analisador[])
{
    int i, j;

    // Em caso da particao ser menor que o valor passado como arguemento o
    // algoritmo de selecao é chamado ao inves do quick

    if (Dir - Esq < Analisador[Dir].simples)
        Selecao(Analisador, Dir, Esq);

    Particao(Esq, Dir, &i, &j, Analisador);
    if (Esq < j)
        Ordena(Esq, j, Analisador);
    if (i < Dir)
        Ordena(i, Dir, Analisador);
}

void QuickSort(Analisador Analisador[], int n)
{
    Ordena(0, n - 1, Analisador);
}
