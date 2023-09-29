#include "mesa.h"

void Mesa__Inicializa(Mesa *mesa) {

    ListaVazia__cria(&mesa->baralho);
    ListaVazia__cria(&mesa->descarte);
    
    for (int i = 0; i < 4; i++) {
        ListaVazia__cria(&mesa->bases[i]);
    }
    
    for (int i = 0; i < 7; i++) {
        ListaVazia__cria(&mesa->tableau[i]);
    }
    
    mesa->pontos = 0;
}

void CarregarBaralho_aleatorio(Mesa *mesa) {
    Lista_cartas *baralho;
    
    int i = 0;
    for (int naipe = 0; naipe < 4; naipe++) {
        for (int valor = 1; valor <= 13; valor++) {
            baralho[i].p_Primeiro->carta.naipe = naipe;
            baralho[i].p_Primeiro->carta.valor = valor;
            i++;
        }
    }

    // Embaralhando
    ListaCartas__embaralha(&baralho);

    for (int i = 0; i < 52; i++) {
        inserir_carta(&mesa->baralho, baralho[i]);
    }
}
Carta compra_carta(Lista_cartas *lista){
   Carta c = lista->p_Primeiro->carta;
   return c;
}