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


#endif