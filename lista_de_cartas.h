#ifndef LISTA_DE_CARTAS_H
#define LISTA_DE_CARTAS_H

#include "carta.h"

typedef struct celula *Apontador;
// Definicao da celula da lista de cartas

typedef struct celula{
    Carta carta;
    struct celula *proximo;
}Celula;

typedef struct{
    Apontador P_primeiro;
    Apontador P_ultimo;
}Lista_cartas;

// Cabeçalho de funções
// ----------------------------------------------------------------------------------//
void ListaVazia__cria(Lista_cartas *lista);
int Tamanho__retorna(Lista_cartas *lista);
int taVazia(Lista_cartas *lista);
Carta Topo__retorna(Lista_cartas *lista);
int PosCarta__retorna(Lista_cartas *lista, Carta *carta);
void Topo_adiciona(Lista_cartas *lista, Carta *carta);
void Topo__remove(Lista_cartas *lista, Carta *carta);
// ----------------------------------------------------------------------------------//

#endif