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