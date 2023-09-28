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
    Apontador p_Primeiro;
    Apontador p_Ultimo;
}Lista_cartas;

// Cabeçalho de funções
// ----------------------------------------------------------------------------------//
void ListaVazia__cria(Lista_cartas *lista);
int Tamanho__retorna(Lista_cartas *lista);
int taVazia(Lista_cartas *lista);
Carta Topo__retorna(Lista_cartas *lista);
int PosCarta__retorna(Lista_cartas *lista, Carta *carta);
void Topo__adiciona(Lista_cartas *lista, Carta *carta);
void Topo__remove(Lista_cartas *lista, Carta *carta);
void Cartas__transfere(Lista_cartas *lista_origem, Lista_cartas *lista_destino, int quantidade);
void ListaCartas__embaralha(Lista_cartas *lista);
void ListaCartas__exibe(Lista_cartas *lista);
// ----------------------------------------------------------------------------------//

#endif