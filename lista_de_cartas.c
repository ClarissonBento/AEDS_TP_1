#include "lista_de_cartas.h"

// --------------------------------------------------------------------------------- //
// Cria uma lista de cartas vazia.
// Essa estrutura vai ser usada na mesa, para o baralho, tableau e outros
// Mudei o nome de "baralho" pra "lista" porque vamos precisar da palavra depois
// ----------------------------------------------------------------------------------//

void ListaVazia__cria(Lista_cartas *lista){
   lista->p_Primeiro = (Apontador)malloc(sizeof(Celula));
   lista->p_Ultimo = lista->p_Primeiro;
   lista->p_Primeiro->proximo = NULL;
}

int Tamanho__retorna(Lista_cartas *lista){
    Apontador aux = lista->p_Primeiro->proximo;

    int quantidade = 0;
    while (aux != NULL){
        quantidade++;
        aux = aux->proximo;
    }

    return quantidade;
}

int taVazia(Lista_cartas *lista){
    if (lista->p_Primeiro = lista->p_Ultimo) return 1;
    else return 0;
}

Carta Topo__retorna(Lista_cartas *lista){
    Carta topo;
    topo = lista->p_Primeiro->carta;
    return topo;
}

int PosCarta__retorna(Lista_cartas *lista, Carta *carta){
    int pos;
    pos = lista->p_Primeiro->proximo;
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
    nova_celula->proximo = lista->p_Primeiro;
    
    // Atualiza o ponteiro que mantem o inicio da lista
    lista->p_Primeiro = nova_celula;
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
    if (lista->p_Primeiro == NULL || lista->p_Primeiro->proximo == NULL) {
        printf("A lista está vazia.\n"); // Tirar isso daqui depois, só pra ficar mais visual caso a gnt teste
        return 0;
    }
    
    // Guarda o elemento do topo
    Celula *celula_removida = lista->p_Primeiro->proximo;
    *carta = celula_removida->carta;

    // Atualiza o primeiro elemento da lista
    lista->p_Primeiro->proximo = celula_removida->proximo;

    // Libera a memoria da celula removida
    free(celula_removida);
}

// Não sei se isso tá certo KKKKKKK
void Cartas__transfere(Lista_cartas *lista_origem, Lista_cartas *lista_destino, int quantidade) {

    if (lista_origem->p_Primeiro->proximo == NULL || quantidade <= 0) {
        printf("Falhou com sucesso.\n");
        return 0;
    }

    Celula *celula_origem = lista_origem->p_Primeiro->proximo;
    Celula *celula_destino = lista_destino->p_Primeiro;

    while (celula_origem != NULL && celula_origem->proximo != NULL) {
        celula_origem = celula_origem->proximo;
    }

    // Transfere as cartas da lista de origem para a lista de destino
    for (int i = 0; i < quantidade && celula_origem != NULL; i++) {
        Celula *nova_celula = (Celula *)malloc(sizeof(Celula));
        nova_celula->carta = celula_origem->carta;
        nova_celula->proximo = lista_destino->p_Primeiro->proximo;
        lista_destino->p_Primeiro->proximo = nova_celula;

        if (celula_origem->proximo != NULL) {
            celula_origem = celula_origem->proximo;
        }
    }

    // Atualiza o ponteiro da lista de origem para apontar para o nó após o último transferido
    lista_origem->p_Primeiro->proximo = celula_origem;

    //printf("Transferência de cartas concluída\n");
}