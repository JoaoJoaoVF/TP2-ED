#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include <cstring>
#include "../include/analisador.hpp"
#include "../include/memlog.h"
#include "../include/msgassert.h"
using namespace std;

class Analisador
{
public:
    string palavra_do_texto;
    int lexicografica_da_ordem[1000];
    int mediana;
    int id;
    int repeticoes = 1;
    int simples = 0;

    bool operator<(Analisador Analisador)
    {
        int i = 0, a = 0, b = 0;

        a = this->palavra_do_texto.length();
        b = Analisador.palavra_do_texto.length();

        while (a >= 0 && b >= 0)
        {
            if (this->lexicografica_da_ordem[i] == Analisador.lexicografica_da_ordem[i])
            {
                i++;
            }
            else if (this->lexicografica_da_ordem[i] > Analisador.lexicografica_da_ordem[i])
            {
                return false;
            }
            else if (this->lexicografica_da_ordem[i] < Analisador.lexicografica_da_ordem[i])
            {
                return true;
            }
            else if (a < 0 && b > 0)
            {
                return false;
            }
            else if (b < 0 && a > 0)
            {
                return true;
            }
            a--;
            b--;
        }
    }

    bool operator>(Analisador Analisador)
    {
        int i = 0, a = 0, b = 0;
        a = this->palavra_do_texto.length();
        b = Analisador.palavra_do_texto.length();
        while (a >= 0 && b >= 0)
        {
            if (this->lexicografica_da_ordem[i] == Analisador.lexicografica_da_ordem[i])
            {
                i++;
            }
            else
            {
                if (this->lexicografica_da_ordem[i] < Analisador.lexicografica_da_ordem[i])
                {
                    return false;
                }
                else if (this->lexicografica_da_ordem[i] > Analisador.lexicografica_da_ordem[i])
                {
                    return true;
                }
                else if (a < 0 && b > 0)
                {
                    return false;
                }
                else if (b < 0 && a > 0)
                {
                    return true;
                }
            }
            a--;
            b--;
        }
    }
};

void ImprimePalavras(Analisador Analisador[], int qtde_palavras);
void ImprimeOrdemLexicograficadasPalavras(Analisador Analisador[], int qtde_palavras);
void ImprimeOrdemLexicografica(char Letras[]);
void AtribuiOrdem(Analisador Analisador[], int qtde_palavras, char Letras[]);
void ConverteMinusculo(Analisador Analisador[], int qtde_palavras, char palavra_extraida[]);
int BuscaRepeticao(Analisador Analisador[], int qtde_palavras, string palavra_extraida);
int EncontraIndiceLexicografico(Analisador *Analisador, int pos_a, int pos_b);
void Particao(char Esq, char Dir, int *i, int *j, Analisador *Analisador);
void QuickSort(Analisador *Analisador, int n);
void Ordena(int Esq, int Dir, Analisador *Analisador);
void ContaRepeticao(Analisador Analisador[], int qtde_palavras);
void Selecao(Analisador Analisador[], int qtde_palavras, int final, int inicio);
void Insercao(Analisador Analisador[], int qtde_palavras, int final, int inicio);
void EsquemaSaida(Analisador Analisador[], int qtde_palavras, char *nome_saida);
