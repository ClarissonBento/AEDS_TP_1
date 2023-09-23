#ifndef CARTA_H
#define CARTA_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef enum {COPAS, ESPADADAS, OUROS, PAUS} Naipe;

// bool posicao;
typedef enum {BAIXO, CIMA} Posicao; // Baixo = 0, Cima = 1

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

// Naipe e valor devem ser valores constantes
typedef struct {
    Naipe naipe;
    ValorCarta valor;
    Posicao posicao;
}Carta;

// Cabeçalho de funções
// ----------------------------------------------------------------------------------//
void Carta__cria(Carta *carta, Naipe naipe, ValorCarta valor, Posicao posicao);
Naipe Naipe__retorna(Carta *carta);
ValorCarta Valor__retorna(Carta *carta);
Posicao Posicao__retorna(Carta *carta);
void Posicao__alterar(Carta *carta);
int seqNaipe_retorna(Carta *c1,Carta *c2);
int seqAlt_retorna(Carta *c1, Carta *c2);
void exibe_carta(Carta *c);
// ----------------------------------------------------------------------------------//

#endif