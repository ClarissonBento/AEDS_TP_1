#include <stdio.h>
#include "lista_de_cartas.h"

int main(){

    Carta carta_1;
    Carta__cria(&carta_1, COPAS, 13, BAIXO);
    Carta__exibe(&carta_1);

    printf("\nVou virar a carta = ");
    Posicao__alterar(&carta_1);
    Carta__exibe(&carta_1);

    // botando outra carta

    Carta carta_2;
    Carta__cria(&carta_2, PAUS, 6, CIMA);
    Carta__exibe(&carta_2);

    if (seqNaipe_retorna(&carta_1, &carta_2) == 1) printf("Naipes de cores diferentes\n");
    else printf("\nCores iguais\n");

    if (seqAlt_retorna(&carta_1, &carta_2) == 1) printf("\nAdição permitida\n");
    else printf("\nMovimento não permitido\n");
    
    
    return 0;
}