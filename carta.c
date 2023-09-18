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
/*
Verificar sequência de mesmo naipe: recebe duas cartas como parâmetro, e retorna
verdadeiro caso a segunda carta seja adequada como próxima carta numa sequência
de mesmo naipe para a primeira carta. Obs.: se a primeira carta é nula, então o valor
válido para a segunda carta é um Ás;
*/
int seq_retorna(Carta *c1,Carta *c2){
    if(c1->naipe==COPAS && c2->naipe==OUROS 
    || c1->naipe==ESPADADAS && c2->naipe==PAUS 
    || c1->naipe==OUROS && c2->naipe==COPAS
    || c1->naipe==PAUS && c2->naipe==ESPADADAS
    || c1->naipe==c2->naipe)
    {
        return 0;
    }
    else return 1;

}