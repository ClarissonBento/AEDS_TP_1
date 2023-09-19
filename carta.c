#include "carta.h"
void inicializar_valor(val *valor,int *valores){
    char buffer[64];
    valores= valor->valores;
    val *v2;
    for(int i=0;i<valores;i++){
        valor->v=(val*)malloc(sizeof(val));
        scanf(" %[^\n]", buffer);
        valor->v=buffer;
        valor->p=v2->p;
        if (v2->p==valor->p)
        {
            v2->p==NULL;
        }
        

    }

}

void Criar_carta(Carta *carta, Naipe naipe, val valor, Posicao posi){
    carta->naipe = naipe;
    carta->valor = valor;
    carta->posi = posi;
}

// FUNÇÕES QUE RETORNAM VALORES (GET)
Naipe Naipe__retorna(Carta *carta){
    return carta->naipe;
}

val Valor__retorna(Carta *carta){
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
int seqNaipe_retorna(Carta *c1,Carta *c2){
    
    if(c1->naipe==COPAS && c2->naipe==OUROS 
    || c1->naipe==ESPADADAS && c2->naipe==PAUS 
    || c1->naipe==OUROS && c2->naipe==COPAS
    || c1->naipe==PAUS && c2->naipe==ESPADADAS
    || c1->naipe==c2->naipe
   // || c1->naipe == NULL && c2->valor == 'A')//mesmo problema de acesso ao valor das cartas criadas
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
int seqAlt_retorna(Carta *c1,Carta *c2){
    while (seqNaipe_retorna(c1,c2))
    {
       // if (*c1->valor->v < *c2->valor->v)//como acessar os valores das cartas criadas
        {
            return 1;
        }
        return 0;
        
    }
    
}
void exibe_carta(Carta *c){
    if(c->posi=="CIMA"){
    printf("O naipe da carta eh: %s\n",c->naipe);
    printf("O valor da carta eh: %s\n",c->valor);
    printf("Sua posicao eh %s\n",c->posi);
    }
}
