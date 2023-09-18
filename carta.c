#include "carta.h"

void Criar_carta(Carta *carta, Naipe naipe, unsigned valor, Posicao posi){
    carta->naipe = naipe;
    carta->valor = valor;
    carta->posi = posi;
}

// FUNÇÕES QUE RETORNAM VALORES (GET)
Naipe Naipe__retorna(Carta *carta){
    return carta->naipe;
}

unsigned Valor__retorna(Carta *carta){
    return carta->valor;
}

Posicao Posicao__retorna(Carta *carta){
    return carta->posi;
}