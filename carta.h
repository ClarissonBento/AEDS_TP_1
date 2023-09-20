#ifndef CARTA_H
#define CARTA_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



typedef enum {COPAS, ESPADADAS, OUROS, PAUS} Naipe;

typedef enum {CIMA, BAIXO} Posicao;

typedef enum {
    AS=1,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    J,
    Q,
    K
} ValorCarta;

//unsigned valor[13] = {'A',2,3,4,5,6,7,8,9,10,'J','Q','K'};

// Naipe e valor são const
typedef struct {
    Naipe naipe;
    ValorCarta valor;
    Posicao posi;
}Carta;

void Criar_carta(Carta *carta, Naipe naipe, ValorCarta valor, Posicao posi);

Naipe Naipe__retorna(Carta *carta);
ValorCarta Valor__retorna(Carta *carta);
Posicao Posicao__retorna(Carta *carta);
void alterar_pos(Carta *carta,int pos);
int seqNaipe_retorna(Carta *c1,Carta *c2);
int seqAlt_retorna(Carta *c1, Carta *c2);
void exibe_carta(Carta *c);



#endif