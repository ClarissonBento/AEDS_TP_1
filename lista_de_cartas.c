#include "lista_de_cartas.h"
//criar o baralho vazio
void criarBaralho(baralho *b){
   b->Pprimeiro=(apontador)malloc(sizeof(celula));
   b->Pultimo=b->Pprimeiro;
   b->Pprimeiro->Proximo=NULL;

}
int retornaTamanho(baralho *b){
    apontador aux = b->Pprimeiro->Proximo;
    int quantidade = 0;
    while (aux!=NULL){
        quantidade++;
        aux = aux->Proximo;
    }
    return quantidade;
}
int taVazia(baralho *b){
    if ( b->Pprimeiro=b->Pultimo)
    {
        return 1;

    }
    else return 0;
    
    
    
}
Carta retornarTopo(baralho *b){
    Carta topo;
    topo=b->Pprimeiro->carta;
    return topo;
}
int retornarPosCarta(baralho *b,Carta *carta){
    int pos;
    pos = b->Pprimeiro->Proximo;
    return pos;

}

  

