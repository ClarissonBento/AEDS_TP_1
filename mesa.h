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
void inicializa inicializa_tableau(Lista_cartas *lista[7]);//sera q tem q inicializar tudo em uma so funcao?

#endif