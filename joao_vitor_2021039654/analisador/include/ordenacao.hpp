#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include "analisador.hpp"
#include "memlog.h"
#include "msgassert.h"
using namespace std;

class Analisador
{
public:
    string palavra_do_texto;
    int lexicografica_da_ordem[50];
    int mediana;
    int id;

    bool operator>(Analisador Analisador_aux)
    {
        int i = 0, a = 0, b = 0;

        a = this->palavra_do_texto.size();
        b = Analisador_aux.palavra_do_texto.size();

        while (a >= 0 && b >= 0)
        {
            if (this->lexicografica_da_ordem[i] == Analisador_aux.lexicografica_da_ordem[i])
            {
                i++;
            }
            else if (this->lexicografica_da_ordem[i] < Analisador_aux.lexicografica_da_ordem[i])
            {
                return 0;
            }
            else
            {
                return 1;
            }
            a--;
            b--;
        }
    }

    bool operator<(Analisador Analisador_aux)
    {
        int i = 0, a = 0, b = 0;
        a = this->palavra_do_texto.size();
        b = Analisador_aux.palavra_do_texto.size();

        while (a >= 0 && b >= 0)
        {
            while (this->lexicografica_da_ordem[i] == Analisador_aux.lexicografica_da_ordem[i])
            {
                i++;
            }
            if (this->lexicografica_da_ordem[i] > Analisador_aux.lexicografica_da_ordem[i])
            {
                return 0;
            }
            else
            {
                return 1;
            }
            a--;
            b--;
        }
    }
};

void ImprimePalavras(Analisador Analisador_aux[], int qtde_palavras);
void ImprimeOrdemLexicograficadasPalavras(Analisador Analisador_aux[], int qtde_palavras);
void ImprimeOrdemLexicografica(char Letras[]);
void AtribuiOrdem(Analisador Analisador_aux[], int qtde_palavras, char Letras[]);
void ConverteMinusculo(Analisador Analisador_aux[], int pos_palavra, char palavra_extraida[]);
int EncontraIndiceLexicografico(Analisador *Analisador_aux, int pos_a, int pos_b);
void Particao(char Esq, char Dir, int *i, int *j, Analisador *Analisador_aux);
void QuickSort(Analisador *Analisador_aux, int n);
void Ordena(int Esq, int Dir, Analisador *Analisador_aux);