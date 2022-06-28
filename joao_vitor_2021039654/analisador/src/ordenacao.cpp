#include "../include/ordenacao.hpp"
#include "../include/analisador.hpp"

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

// Faz a conversao da palavra para minusculo, remove os caracteres especias da palavra
void ConverteMinusculo(Analisador Analisador[], int qtde_palavras, char palavra_extraida[])
{
    // variaveis auxiliares de tamanho da palavra e para o loop
    int tam, i;

    // Retorna o tamanho total da palvavra
    tam = strlen(palavra_extraida);

    // Em caso de haver um caracter especial diferente de '-' na palavra de acordo com sua posicação na tabela ASCII
    if (palavra_extraida[tam - 1] < 65 && palavra_extraida[tam - 1] != 45)
    {
        palavra_extraida[tam - 1] = 0;
    }
    // else if (palavra_extraida[tam - 1] == 45)
    // {
    //     cout << "aslkçjsalkfhjlksafjkhsalfjlkh" << endl;
    //     palavra_extraida[tam - 1] = 0;
    // }

    // Variavel auxiliar para guardar a conversao da palavra para minusculo
    char resultado[tam];

    for (i = 0; i <= tam; i++)
    { // Converte cada letra da palavra para minusculo
        resultado[i] = tolower(palavra_extraida[i]);
    }
    // Atribui a palavra com todas as letras minusculas para ela mesmo
    Analisador[qtde_palavras].palavra_do_texto = resultado;
}

// Realiza a busca da repeticao da palavra
int BuscaRepeticao(Analisador Analisador[], int qtde_palavras, string palavra_buscada)
{
    // Variavel que define a quantidade de vezes em que a palavra aparece no texto
    int encontrou = 0;

    // Loop que compara as palavras e em caso de encontrar uma correspondencia incrementa a variavel exclusiva para isso
    for (int i = 0; i < qtde_palavras; i++)
    {
        if (Analisador[i].palavra_do_texto == palavra_buscada)
        {
            Analisador[i].repeticoes++;
            encontrou++;
        }
    }

    // Retorna a quantidade de repeticoes da palavra no texto
    return encontrou;
}

void ImprimePalavras(Analisador Analisador[], int qtde_palavras)
{
    for (int i = 0; i < qtde_palavras; i++)
    {
        cout << Analisador[i].palavra_do_texto << " ";
    }
    // cout << endl;
}

// Realiza a escrita do resultado num arquivo txt
void EsquemaSaida(Analisador Analisador[], int qtde_palavras, char *nome_saida)
{
    // Abertura do arquivo
    ofstream saida(nome_saida);

    // Loop que faz a escrita dos dados no arquivo
    for (int i = 0; i < qtde_palavras; i++)
    {
        saida << Analisador[i].palavra_do_texto << " " << Analisador[i].repeticoes << endl;
    }

    // Realiza a finalização do conteudo e fecha o arquivo de saida
    saida << "#FIM" << endl;
    saida.close();

    for (int i = 0; i < qtde_palavras; i++)
    {
        cout << Analisador[i].palavra_do_texto << " " << Analisador[i].repeticoes << endl;
    }

    cout << "#FIM" << endl;
}

void ImprimeOrdemLexicografica(char Letras[])
{
    for (int i = 0; i < 26; i++)
    {
        cout << Letras[i] << " ";
    }
    cout << endl;
}

void ImprimeOrdemLexicograficadasPalavras(Analisador Analisador[], int qtde_palavras)
{

    int tam = 0, j, i;
    for (i = 0; i < qtde_palavras; i++)
    {
        tam = Analisador[i].palavra_do_texto.length();
        cout << Analisador[i].palavra_do_texto << " ";
        for (j = 0; j < tam; j++)
        {
            cout << Analisador[i].lexicografica_da_ordem[j] << " ";
        }
        cout << endl;
    }
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
                // Em caso de um encontro de letras iguais a posicao relativa da letra no vetor é
                // guardada no vetor na posicao relativa dessa letra na palavra
                if (Analisador[i].palavra_do_texto[j] == tolower(Letras[k]))
                {
                    Analisador[i].lexicografica_da_ordem[j] = k;
                }
            }
        }
    }
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
        for (int teste = 0; teste < 30; teste++)
        {
            Troca_int(Analisador[i].lexicografica_da_ordem[teste], Analisador[Min].lexicografica_da_ordem[teste]);
        }
        Troca_int(Analisador[i].id, Analisador[Min].id);
        Troca_int(Analisador[i].repeticoes, Analisador[Min].repeticoes);
    }
}

void Insercao(Analisador Analisador_palavras[], int final, int inicio)
{
    // cout << "SDDSFDSFDSDSF" << endl;
    int i, j;
    Analisador aux;
    for (i = inicio; i < final; i++)
    {
        aux = Analisador_palavras[i];
        j = i - 1;
        while ((j >= 0) && (aux < Analisador_palavras[j]))
        {
            Analisador_palavras[j + 1] = Analisador_palavras[j];
            j--;
        }
        Analisador_palavras[j + 1] = aux;
    }
}

void Particao(int Esq, int Dir,
              int *i, int *j, Analisador Analisador[])
{

    int x;
    *i = Esq;
    *j = Dir;

    if (Analisador[*i].mediana > 0)
    {
        x = Analisador[*i].mediana;
    }
    else
    {
        x = (*i + *j) / 2; /* obtem o pivo x */
    }

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
            Troca_string(Analisador[*i].palavra_do_texto, Analisador[*j].palavra_do_texto);
            for (int teste = 0; teste < 30; teste++)
            {
                Troca_int(Analisador[*i].lexicografica_da_ordem[teste], Analisador[*j].lexicografica_da_ordem[teste]);
            }
            Troca_int(Analisador[*i].id, Analisador[*j].id);
            Troca_int(Analisador[*i].repeticoes, Analisador[*j].repeticoes);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Analisador Analisador[])
{
    int i, j;

    // Em caso da particao ser menor que o valor passado como arguemento o algoritmo de selecao é chamado ao inves do quick
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
