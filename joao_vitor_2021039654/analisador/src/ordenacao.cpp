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

void ConverteMinusculo(Analisador Analisador[], int qtde_palavras, char palavra_extraida[])
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

    Analisador[qtde_palavras].palavra_do_texto = resultado;
    Analisador[qtde_palavras].id = qtde_palavras;
}

int BuscaRepeticao(Analisador Analisador[], int qtde_palavras, string palavra_buscada)
{
    int encontrou = 0;
    for (int i = 0; i < qtde_palavras; i++)
    {
        if (Analisador[i].palavra_do_texto == palavra_buscada)
        {
            Analisador[i].repeticoes++;
            encontrou++;
        }
    }
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
void EsquemaSaida(Analisador Analisador[], int qtde_palavras, char *nome_saida)
{

    ofstream saida(nome_saida);
    for (int i = 0; i < qtde_palavras; i++)
    {
        saida << Analisador[i].palavra_do_texto << " " << Analisador[i].repeticoes << endl;
    }

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

void AtribuiOrdem(Analisador Analisador[], int qtde_palavras, char Letras[])
{
    int tam, i, j, k;

    for (i = 0; i < qtde_palavras; i++)
    {

        tam = Analisador[i].palavra_do_texto.length();

        for (j = 0; j < tam; j++)
        {
            for (k = 0; k < 26; k++)
            {

                if (Analisador[i].palavra_do_texto[j] == tolower(Letras[k]))
                {
                    Analisador[i].lexicografica_da_ordem[j] = k;
                }
            }
        }
    }
}

void Particao(int Esq, int Dir,
              int *i, int *j, Analisador Analisador[])
{

    int x;
    *i = Esq;
    *j = Dir;

    if (Analisador->mediana > 0)
    {
        x = Analisador->mediana;
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

// void ContaRepeticao(Analisador Analisador[], int qtde_palavras)
// {
//     int aux;
//     for (int i = 0; i < qtde_palavras; i++)
//     {
//         for (int j = i; j < qtde_palavras; j++)
//         {
//             if (Analisador[i].palavra_do_texto == Analisador[j].palavra_do_texto)
//             {
//                 Analisador[i].repeticoes++;
//                 // Analisador[j].palavra_do_texto = " ";
//             }
//         }
//         if (Analisador[i].repeticoes > 0)
//             cout << Analisador[i].palavra_do_texto << " " << Analisador[i].repeticoes << endl;
//         // i = aux;
//         // cout << Analisador[i].palavra_do_texto << " ";
//     }
//     // for (int x = 0; x < count; i++)
//     // {
//     //     /* code */
//     // }
//     // cout << endl;
// }

void Selecao(Analisador Analisador[], int n)
{
    int i, j, Min;
    for (i = 0; i < n - 1; i++)
    {
        Min = i;
        for (j = i + 1; j < n; j++)
        {
            if (Analisador[j] < Analisador[Min])
                Min = j;
        }
        // Troca(v[i], v[Min]);
        Troca_string(Analisador[i].palavra_do_texto, Analisador[Min].palavra_do_texto);
        for (int teste = 0; teste < 30; teste++)
        {
            Troca_int(Analisador[i].lexicografica_da_ordem[teste], Analisador[Min].lexicografica_da_ordem[teste]);
        }
        Troca_int(Analisador[i].id, Analisador[Min].id);
        Troca_int(Analisador[i].repeticoes, Analisador[Min].repeticoes);
    }
}

void Insercao(Analisador Analisador_palavras[], int n)
{
    int i, j;
    Analisador aux;
    for (i = 1; i < n; i++)
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