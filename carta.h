#ifndef CARTA_H
#define CARTA_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



typedef enum {COPAS, ESPADADAS, OUROS, PAUS} Naipe;

typedef enum {CIMA, BAIXO} Posicao;

typedef struct 
{
    int v;//valor da carta
    struct valor *p;//ponteiro pro proximo valor
    int valores;//quantidade para o tamanho da lista encadeada que vai armazenar os 13 valores
}val;

//unsigned valor[13] = {'A',2,3,4,5,6,7,8,9,10,'J','Q','K'};

// Naipe e valor são const
typedef struct {
    Naipe naipe;
    val valor;
    Posicao posi;
}Carta;

void Criar_carta(Carta *carta, Naipe naipe, val valor, Posicao posi);

Naipe Naipe__retorna(Carta *carta);
val Valor__retorna(Carta *carta);
Posicao Posicao__retorna(Carta *carta);
int seqNaipe_retorna(Carta *c1,Carta *c2);
int seqAlt_retorna(Carta *c1, Carta *c2);
void exibe_carta(Carta *c);
void inicializar_valor(val *v,int *valores);


#endif