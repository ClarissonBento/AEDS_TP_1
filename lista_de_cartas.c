#include "lista_de_cartas.h"

// --------------------------------------------------------------------------------- //
// Cria uma lista de cartas vazia.
// Essa estrutura vai ser usada na mesa, para o baralho, tableau e outros
// Mudei o nome de "baralho" pra "lista" porque vamos precisar da palavra depois
// ----------------------------------------------------------------------------------//

void ListaVazia__cria(Lista_cartas *lista){
   lista->P_primeiro = (Apontador)malloc(sizeof(Celula));
   lista->P_ultimo = lista->P_primeiro;
   lista->P_primeiro->proximo = NULL;
}

int Tamanho__retorna(Lista_cartas *lista){
    Apontador aux = lista->P_primeiro->proximo;

    int quantidade = 0;
    while (aux != NULL){
        quantidade++;
        aux = aux->proximo;
    }

    return quantidade;
}

int taVazia(Lista_cartas *lista){
    if (lista->P_primeiro = lista->P_ultimo) return 1;
    else return 0;
}

Carta Topo__retorna(Lista_cartas *lista){
    Carta topo;
    topo = lista->P_primeiro->carta;
    return topo;
}

int PosCarta__retorna(Lista_cartas *lista, Carta *carta){
    int pos;
    pos = lista->P_primeiro->proximo;
    return pos;
}

// --------------------------------------------------------------------------------- //
// Aqui preciamos decidir se a inserção vai ser feita no inicio da lista ou no final,
// aparentemente a inserção e remoção no inicio da lista é mais eficiente.
// Vamos conversar sobre essa decisão quando possível, mas por enquanto deixei uma função
// que adiciona no inicio da lista e deixei a no final da lista como comentário.
// ----------------------------------------------------------------------------------//

void Topo__adiciona(Lista_cartas *lista, Carta *carta){

    Celula *nova_celula = (Celula *)malloc(sizeof(Celula));

    // Configura a nova celula
    nova_celula->carta = *carta;
    nova_celula->proximo = lista->P_primeiro;
    
    // Atualiza o ponteiro que mantem o inicio da lista
    lista->P_primeiro = nova_celula;
}

/*void Topo_adiciona(Lista_cartas *lista, Carta *carta){
    lista->P_ultimo->proximo = (Apontador)malloc(sizeof(Celula));
    lista->P_ultimo = lista->P_ultimo->proximo;
    lista->P_ultimo->carta = *carta;
    lista->P_ultimo->proximo = NULL;
}*/

// Remoção no inicio da lista
void Topo__remove(Lista_cartas *lista, Carta *carta){
    // Verifica se a lista está vazia
    if (lista->P_primeiro == NULL || lista->P_primeiro->proximo == NULL) {
        printf("A lista está vazia.\n"); // Tirar isso daqui depois, só pra ficar mais visual caso a gnt teste
        return 0;
    }
    
    // Guarda o elemento do topo
    Celula *celula_removida = lista->P_primeiro->proximo;
    *carta = celula_removida->carta;

    // Atualiza o primeiro elemento da lista
    lista->P_primeiro->proximo = celula_removida->proximo;

    // Libera a memoria da celula removida
    free(celula_removida);
}