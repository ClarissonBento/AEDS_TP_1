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

/* ------------------------------------------------------------------------------------
VERIFICA UMA SEQUENCIA DE MESMO NAIPE >>> PARA AS BASES <<<

Recebe duas cartas como parâmetro, e retorna verdadeiro caso a segunda carta seja 
adequada como próxima carta numa sequência de mesmo naipe para a primeira carta. 
Obs: se a primeira carta é nula, então o valor válido para a segunda carta é um Ás.
--------------------------------------------------------------------------------------*/

bool SeqBase_retorna(Carta *c1, Carta *c2) {
    // Verificar se a primeira carta é nula
    if (c1 == NULL) {
        return (c2->valor == AS); // A segunda carta deve ser um Ás
    }

    if (Naipe__retorna(c1) != Naipe__retorna(c2)) {
        return false; // Os naipes não são iguais
    }

    // Tem que ser apenas +1 maior
    return (Valor__retorna(c2) == (Valor__retorna(c1) + 1));
}

/* ------------------------------------------------------------------------------------
VERIFICA SEQUENCIA E NAIPE >>> PARA O TABLEAU <<<

Recebe duas cartas como parâmetro, e retorna verdadeiro caso a segunda carta seja 
adequada como próxima carta numa sequência de cores alternadas para a primeira carta.
Obs: se a primeira carta é nula, então o valor válido para a segunda carta é um Rei
CARTA 2 TÁ POR CIMA
--------------------------------------------------------------------------------------*/

bool SeqTableau_retorna(Carta *c1, Carta *c2) {
    // Verificar se a primeira carta é nula
    if (c1 == NULL) {
        return (Valor__retorna(c2) == K); // A segunda carta deve ser um Rei
    }

    // Verificar se as cores são diferentes
    bool cores_alternadas = (Naipe__retorna(c1) == COPAS || Naipe__retorna(c1) == OUROS) !=
                            (Naipe__retorna(c2) == COPAS || Naipe__retorna(c2) == OUROS);

    // Tem que ser apenas -1 menor
    return (cores_alternadas && (Valor__retorna(c2) == Valor__retorna(c1) - 1));
}

/* ------------------------------------------------------------------------------------
EXIBE UMA ÚNICA CARTA
Exibe uma carta com naipe e valor se ela estiver virada pra cima,
se estiver virada pra baixo exibe "Carta Oculta"
--------------------------------------------------------------------------------------*/

void Carta__exibe(Carta *c){
    char *naipes[] = {"Copas", "Espadas", "Ouros", "Paus"};
    char *cards[] = {"0","Ás","2","3","4","5","6","7","8","9","10","Valete","Dama","Rei"};

    if(c->posicao == CIMA) printf("%s de %s\n", cards[c->valor], naipes[c->naipe]);
    else printf("Carta oculta\n");
    
}