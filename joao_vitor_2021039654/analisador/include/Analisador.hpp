#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include <cstring>
#include "Execucao.hpp"
#include "memlog.h"
#include "msgassert.h"
using namespace std;

class Analisador
{
public:
    string palavra_do_texto;
    int lexicografica_da_ordem[1000];
    int id;
    int repeticoes;
    int simples = 0;
    int contado = 0;

    bool operator<(Analisador Analisador)
    {
        // Variaveis utilizadas
        int i = 0, a = 0, b = 0;

        // Seta o a e b, para o tamanho das strings analisadas
        a = this->palavra_do_texto.length();
        b = Analisador.palavra_do_texto.length();

        // Realiza o ate que as duas palavras acabem
        while (a >= 0 && b >= 0)
        {
            // Em caso das duas letras das palavras serem ighuais na mesma posicao a proxima letra é analisada
            if (this->lexicografica_da_ordem[i] == Analisador.lexicografica_da_ordem[i])
            {
                i++;
            }
            else
            {
                // Caso a letra da palavra "a" venha depois no alfabeto do que a "b" retorna que a comparacao abaixo é falsa
                if (this->lexicografica_da_ordem[i] > Analisador.lexicografica_da_ordem[i])
                {
                    return false;
                }
                // Caso a letra da palavra "a" venha antes no alfabeto do que a "b" retorna que a comparacao abaixo é verdadeira
                else if (this->lexicografica_da_ordem[i] < Analisador.lexicografica_da_ordem[i])
                {
                    return true;
                }
                // Caso a palavra "a" tenha acabado e "b" nao retorna falso
                else if (a < 0 && b > 0)
                {
                    return false;
                }
                // Caso a palavra "b" tenha acabado e a "a" nao retorna verdadeiro
                else if (b < 0 && a > 0)
                {
                    return true;
                }
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
                // Caso a letra da palavra "b" venha depois no alfabeto do que a "a" retorna que a comparacao abaixo é falsa
                if (this->lexicografica_da_ordem[i] < Analisador.lexicografica_da_ordem[i])
                {
                    return false;
                }
                // Caso a letra da palavra "b" venha antes no alfabeto do que a "a" retorna que a comparacao abaixo é verdadeira
                else if (this->lexicografica_da_ordem[i] > Analisador.lexicografica_da_ordem[i])
                {
                    return true;
                }
                // Caso a palavra "a" tenha acabado e "b" nao retorna falso
                else if (a < 0 && b > 0)
                {
                    return false;
                }
                // Caso a palavra "b" tenha acabado e a "a" nao retorna verdadeiro
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
void ConverteMinusculo(Analisador Analisador[], int pos_palavra, char palavra_extraida[]);
void BuscaRepeticao(Analisador Analisador[], int qtde_palavras);

void Selecao(Analisador Analisador[], int final, int inicio);
void Saida(Analisador Analisador[], int qtde_palavras, char *nome_saida);

void Particao(char Esq, char Dir, int *i, int *j, Analisador *Analisador);
void QuickSort(Analisador *Analisador, int n);
void Ordena(int Esq, int Dir, Analisador *Analisador);