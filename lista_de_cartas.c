#include "lista_de_cartas.h"
//criar o baralho vazio
void criarBaralho(baralho *b){
    b->Pprimeiro= (apontador)malloc(sizeof(baralho));
    b->Pultimo=b->Pprimeiro;
    b->Pultimo->Proximo=NULL;
}
int retornaTamanho(baralho *b){
    int tam=0;
    apontador aux = b->Pprimeiro->Proximo;
    int quantidade = 0;
    while (aux!=NULL){
        quantidade++;
        aux = aux->Proximo;
    }
    return tam;
}
/*int taVazia(baralho *b){
    if (b->Proximo == NULL)
    {
        return 0;
    }
    else return 1;
    
}/*
/*Carta retornarTopo(baralho *b){
    Carta topo = *(b->Pprimeiro);
    return topo;
}
retornarPosCarta(baralho *b,Carta *carta){


}*/

  /* void RetornaPosCarta(baralho *b, int posi){
        apontador aux = baralho->Pprimeiro->Pproximo
    
    
    
    }*/

