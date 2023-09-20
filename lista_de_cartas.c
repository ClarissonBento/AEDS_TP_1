#include "lista_de_cartas.h"
//criar o baralho vazio
void criarBaralho(baralho *b){
    b->Pprimeiro= (apontador)malloc(sizeof(baralho));
    b->Pultimo=b->Pprimeiro;
    b->prox=NULL;
}
int retornaTamanho(baralho *b){
    int tam=0;
    while (b->prox!=NULL)
    {
        tam++;
    }
    return tam;
}
int taVazia(baralho *b){
    if (b->prox==NULL)
    {
        return 0;
    }
    else return 1;
    
}
/*Carta retornarTopo(baralho *b){
    Carta topo = *(b->Pprimeiro);
    return topo;
}
retornarPosCarta(baralho *b,Carta *carta){


}*/