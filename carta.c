#include "carta.h"

Criar_carta(Carta *carta, Naipe naipe, unsigned valor, Posicao posi){
    carta->naipe = naipe;
    carta->valor = valor;
    carta->posi = posi;
}


// FUNÇÕES QUE RETORNAM VALORES (GET)
Naipe__retorna(Carta *carta){
    return carta->naipe;
}

Valor__retorna(Carta *carta){
    return carta->valor;
}

Posicao__retorna(Carta *carta){
    return carta->posi;
}