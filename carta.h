#ifndef CARTA_H
#define CARTA_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {COPAS, ESPADADAS, OUROS, PAUS} Naipe;

typedef enum {CIMA, BAIXO} Posicao;

unsigned valor = {'A',2,3,4,5,6,7,8,9,10,'J','Q','K'};

// Naipe e valor são const
typedef struct {
    Naipe naipe;
    unsigned valor;
    Posicao posi;
}Carta;

Criar_carta(Carta *carta, Naipe naipe, unsigned valor, Posicao posi);
Naipe__retorna(Carta *carta);
Valor__retorna(Carta *carta);
Posicao__retorna(Carta *carta);

#endif