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
void CarregarBaralho(Lista_cartas *lista, Carta *cartas, int num_cartas);
void preparar(Mesa *mesa);

Carta compra_carta(Lista_cartas *lista);
int verificar_vitoria(Mesa *mesa);
void Descarte_para_bases(Mesa *mesa);
void Descarte_para_tableau(Mesa *mesa,int indice_tb);
void Mover_tableau_bases(Mesa *m,int indice);
void Mover_bases_tableau(Mesa *m,int indice_base,int indice_tableau);
void Mover_entre_colunas(Mesa *mesa,int indice_col_origem, int indice_col_destino,int qtd);//pilha da qual vai ser extraida, quantidade de cartas a ser extraidas e o destino
void exibir_mesa(Mesa *mesa);

#endif