#ifndef CARTA_H
#define CARTA_H

#include <stdio.h>

typedef enum {COPAS, ESPADADAS, OUROS, PAUS} Naipe;

typedef struct {
    const Naipe naipe;

}Carta;

#endif