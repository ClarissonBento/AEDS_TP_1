#ifndef LISTA_DE_CARTAS_H
#define LISTA_DE_CARTAS_H
#include "carta.h"
typedef struct celula* apontador;
//definicao da celula da lista(baralho)
typedef struct celula{
    Carta carta;
    struct celula *Proximo;
}celula;

typedef struct{
    apontador Pprimeiro;
    apontador Pultimo;

}baralho;

void criarBaralho(baralho *b);//inicializa a lista vazia
int retornaTamanho(baralho *b);//retorna o tamanho
int taVazia (baralho* b);// le se está vazio
Carta retornarTopo(baralho *b);//verificar qual carta esta no topo
void retornarPosCarta(baralho *b, Carta *c);//ver posicao de uma carta no baralho
void addTopo(baralho *b);//add carta ao topo
void retiraTopo(baralho *b);//retirar carta do topo
void transfereCartas(baralho *b);//pegar uma determinada quantidade de cartas do tpo e meter em outra lista
baralho embaralhar(baralho *b);
void exibirBaralho(baralho *b);





















#endif