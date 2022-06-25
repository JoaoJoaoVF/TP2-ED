#include "ordenacao.hpp"
#include "analisador.hpp"

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

void ConverteMinusculo(Analisador Analisador_aux[], int pos_palavra, char palavra_extraida[])
{
    int tam, i;
    tam = strlen(palavra_extraida);

    if (palavra_extraida[tam - 1] < 65)
    {
        palavra_extraida[tam - 1] = 0;
    }

    char resultado[tam];
    for (i = 0; i <= tam; i++)
    {
        resultado[i] = tolower(palavra_extraida[i]);
    }

    Analisador_aux[pos_palavra].palavra_do_texto = resultado;
    Analisador_aux[pos_palavra].id = pos_palavra;
}

void ImprimePalavras(Analisador Analisador_aux[], int qtde_palavras)
{
    for (int i = 0; i < qtde_palavras; i++)
    {
        cout << Analisador_aux[i].palavra_do_texto << " ";
    }
    cout << endl;
}

void ImprimeOrdemLexicografica(char Letras[])
{
    for (int i = 0; i < 26; i++)
    {
        cout << Letras[i] << " ";
    }
    cout << endl;
}

void ImprimeOrdemLexicograficadasPalavras(Analisador Analisador_aux[], int qtde_palavras)
{

    int tam = 0, j, i;
    for (i = 0; i < qtde_palavras; i++)
    {
        tam = Analisador_aux[i].palavra_do_texto.size();
        cout << Analisador_aux[i].palavra_do_texto << " ";
        for (j = 0; j < tam; j++)
        {
            cout << Analisador_aux[i].lexicografica_da_ordem[j] << " ";
        }
        cout << endl;
    }
}

void AtribuiOrdem(Analisador Analisador_aux[], int qtde_palavras, char Letras[])
{
    int tam, i, j, k;

    for (i = 0; i < qtde_palavras; i++)
    {

        tam = Analisador_aux[i].palavra_do_texto.size();

        for (j = 0; j < tam; j++)
        {
            for (k = 0; k < 26; k++)
            {

                if (Analisador_aux[i].palavra_do_texto[j] == tolower(Letras[k]))
                {
                    Analisador_aux[i].lexicografica_da_ordem[j] = k;
                }
            }
        }
    }
}

void Particao(int Esq, int Dir,
              int *i, int *j, Analisador Analisador_aux[])
{

    int x;
    *i = Esq;
    *j = Dir;

    if (Analisador_aux->mediana > 0)
    {
        x = Analisador_aux->mediana;
    }
    else
    {
        x = (*i + *j) / 2; /* obtem o pivo x */
    }

    do
    {
        while (Analisador_aux[x] > Analisador_aux[*i])
        {
            (*i)++;
        }

        while (Analisador_aux[x] < Analisador_aux[*j])
        {
            (*j)--;
        }
        if (*i <= *j)
        {
            Troca_string(Analisador_aux[*i].palavra_do_texto, Analisador_aux[*j].palavra_do_texto);
            for (int teste = 0; teste < 30; teste++)
            {
                Troca_int(Analisador_aux[*i].lexicografica_da_ordem[teste], Analisador_aux[*j].lexicografica_da_ordem[teste]);
            }
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Analisador Analisador_aux[])
{
    int i, j;
    Particao(Esq, Dir, &i, &j, Analisador_aux);
    if (Esq < j)
        Ordena(Esq, j, Analisador_aux);
    if (i < Dir)
        Ordena(i, Dir, Analisador_aux);
}

void QuickSort(Analisador Analisador_aux[], int n)
{
    Ordena(0, n - 1, Analisador_aux);
}