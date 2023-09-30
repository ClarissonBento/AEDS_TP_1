#include <stdio.h>
#include "lista_de_cartas.h"

int main(){

    Carta carta_1;
    Carta__cria(&carta_1, OUROS, 7, BAIXO);
    Carta__exibe(&carta_1);

    printf("\nVou virar a carta = ");
    Posicao__alterar(&carta_1);
    Carta__exibe(&carta_1);

    // botando outra carta

    Carta carta_2;
    Carta__cria(&carta_2, ESPADAS, 6, CIMA);
    Carta__exibe(&carta_2);

    if (SeqBase_retorna(&carta_1, &carta_2) == 1) printf("Entra na base\n");
    else printf("\nNão entra na base\n");

    if (SeqTableau_retorna(&carta_2, &carta_1) == 1) printf("\nEntra no tableau\n");
    else printf("\nNão entra no tableau\n");
    
    
    return 0;
}