#ifndef MESA_H
#define MESA_H

#include "carta.h"
#include "lista_de_cartas.h"

typedef struct {
    Lista_cartas baralho;
    Lista_cartas descarte;
    Lista_cartas bases[4];
    Lista_cartas tableau[7];
    int pontos;
}Mesa;

//inicializar cada uma das listas da mesa
void Mesa__Inicializa(Mesa *mesa);
void CarregarBaralho_aleatorio(Mesa *mesa);
void CarregarBaralho();
void inserir_baralho(Lista_cartas *lista);
void preparar(Lista_cartas *lista);
//funcao prearar
//funcao vitoria
Carta compra_carta(Lista_cartas *lista);
void descarte_base_mover(Lista_cartas *descarte,Lista_cartas *bases);
void descarte_tableau(Mesa *mesa,int indice_tb);
void tableu_bases(Lista_cartas *tableau, Lista_cartas *bases);
void bases_tableau(Lista_cartas *bases, Lista_cartas *tableau);
void mover_colunas(Lista_cartas *pilha_origem,Lista_cartas *pilha_destino,int qtd);//pilha da qual vai ser extraida, quantidade de cartas a ser extraidas e o destino

#endif