#ifndef MESA_H
#define MESA_H

#include "lista_de_cartas.h"

typedef struct {
    Lista_cartas baralho;
    Lista_cartas descarte;
    Lista_cartas bases[4];
    Lista_cartas tableau[7];
    int pontos;
}Mesa;
//inicializar cada uma das listas da mesa
void inicializa_baralho(Lista_cartas *lista);
void inicializa_descarte(Lista_cartas *lista);
void inicializa_bases(Lista_cartas *lista[4]);
void inicializa_tableau(Lista_cartas *lista[7]);//sera q tem q inicializar tudo em uma so funcao?
void carregar_baralho(Lista_cartas *lista);
void inserir_baralho(Lista_cartas *lista);
void preparar(Lista_cartas *lista);
//funcao prearar
//funcao vitoria
void comprar_carta(Lista_cartas *lista);
void descarte_base_mover(Lista_cartas *descarte,Lista_cartas *bases);
void descarte_tableau(Lista_cartas *descarte, Lista_cartas *tableau);
void tableu_bases(Lista_cartas *tableau, Lista_cartas *bases);
void bases_tableau(Lista_cartas *bases, Lista_cartas *tableau);
void mover_colunas(Lista_cartas *pilha_origem,Lista_cartas *pilha_destino,int qtd);//pilha da qual vai ser extraida, quantidade de cartas a ser extraidas e o destino
#endif