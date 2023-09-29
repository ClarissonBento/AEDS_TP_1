#include "carta.h"

void Carta__cria(Carta *carta, Naipe naipe, ValorCarta valor, Posicao posicao){
    carta->naipe = naipe;
    carta->valor = valor;
    carta->posicao = posicao;
}

// FUNÇÕES QUE RETORNAM VALORES (GET)
Naipe Naipe__retorna(Carta *carta){
    return carta->naipe;
}

ValorCarta Valor__retorna(Carta *carta){
    return carta->valor;
}

Posicao Posicao__retorna(Carta *carta){
    return carta->posicao;
}

// Função que altera a posicão da carta, se está para baixo, coloca para cima
void Posicao__alterar(Carta *carta){
   if (carta->posicao == BAIXO)
    {
        carta->posicao = CIMA;
    }
}

/*
Verificar sequência de mesmo naipe: recebe duas cartas como parâmetro, e retorna
verdadeiro caso a segunda carta seja adequada como próxima carta numa sequência
de mesmo naipe para a primeira carta. Obs.: se a primeira carta é nula, então o valor
válido para a segunda carta é um Ás;
*/

int seqNaipe_retorna(Carta *c1,Carta *c2){
    if (c1->valor == nao_definido){
        if (c1->valor == AS)
        {
            return 1;
        }
    
    } 
    if(c1->naipe==COPAS && c2->naipe==OUROS 
    || c1->naipe==ESPADAS && c2->naipe==PAUS 
    || c1->naipe==OUROS && c2->naipe==COPAS
    || c1->naipe==PAUS && c2->naipe==ESPADAS
    || c1->naipe==c2->naipe
    )
      {
        return 0;
    }
    else return 1;
}

/*
Verificar sequência alternada: recebe duas cartas como parâmetro, e retorna
verdadeiro caso a segunda carta seja adequada como próxima carta numa sequência
de cores alternadas para a primeira carta. Obs.: se a primeira carta é nula, então o
valor válido para a segunda carta é um Rei;
*/
// Carta 2 tá por cima
int seqAlt_retorna(Carta *c1,Carta *c2){
    while (seqNaipe_retorna(c1,c2))
    {
        if (c1->valor == nao_definido)
        {
        if(c2->valor = K){
            return 1;
        }
           return 0;
        }
        
        if ((c2->valor)-(c1->valor)==1)
        {
            return 1;
        }
        return 0;
        
    }
    
}

void Carta__exibe(Carta *c){
    char *naipes[] = {"Copas", "Espadas", "Ouros", "Paus"};
    char *cards[] = {"0","Ás","2","3","4","5","6","7","8","9","10","Valete","Dama","Rei"};

    if(c->posicao == CIMA)
    {
        printf("%s de %s\n", cards[c->valor], naipes[c->naipe]);

        //printf("O naipe da carta eh: %s\n", naipes[c->naipe]);
        //printf("O valor da carta eh: %i\n",c->valor);
        //printf("Sua posicao eh %d\n",c->posicao);

    } else{
        printf("Carta oculta\n");
    }
    
}