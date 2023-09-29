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
    ListaCartas__embaralha(baralho);

   
}

Carta compra_carta(Lista_cartas *lista){
    if(taVazia(lista)){
        printf("Nao e possivel comprar cartas pois o baralho acabou");
        return;
    }
    else {
   Carta c = lista->p_Primeiro->carta;
   lista->p_Primeiro=lista->p_Primeiro->proximo;
   return c;
    }


}
void descarte_tableau(Mesa *mesa,int indice_tb){
    Carta c;
   

}