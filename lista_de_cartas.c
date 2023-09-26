#include "lista_de_cartas.h"

// --------------------------------------------------------------------------------- //
// Cria uma lista de cartas vazia.
// Essa estrutura vai ser usada na mesa, para o baralho, tableau e outros
// Mudei o nome de "baralho" pra "lista" porque vamos precisar da palavra depois
// ----------------------------------------------------------------------------------//

void ListaVazia__cria(Lista_cartas *lista){
   lista->p_Primeiro = (Apontador)malloc(sizeof(Celula));
   lista->p_Primeiro->proximo = NULL;
   lista->p_Ultimo = lista->p_Primeiro;
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
    if (lista->p_Primeiro == lista->p_Ultimo)
        return 1;
    else
        return 0;
}

Carta Topo__retorna(Lista_cartas *lista){
    Carta topo;
    topo = lista->p_Primeiro->carta;
    return topo;
}

int PosCarta__retorna(Lista_cartas *lista, Carta *carta){
    Apontador atual = lista->p_Primeiro->proximo;
    int pos = 1;
    while (atual != NULL) {
        if (&atual->carta == carta) {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1; // Retorna -1 se a carta não for encontrada
}
// --------------------------------------------------------------------------------- //
// Aqui preciamos decidir se a inserção vai ser feita no inicio da lista ou no final,
// aparentemente a inserção e remoção no inicio da lista é mais eficiente.
// Vamos conversar sobre essa decisão quando possível, mas por enquanto deixei uma função
// que adiciona no inicio da lista e deixei a no final da lista como comentário.
// ----------------------------------------------------------------------------------//

void Topo__adiciona(Lista_cartas *lista, Carta *carta){

    Celula *nova_celula = (Celula *)malloc(sizeof(Celula));

    nova_celula->carta = *carta;
    nova_celula->proximo = lista->p_Primeiro;
    
    // Atualiza o ponteiro que mantem o inicio da lista
    lista->p_Primeiro = nova_celula;
}



// Remoção no inicio da lista
void Topo__remove(Lista_cartas *lista, Carta *carta){

    if (lista->p_Primeiro == NULL || lista->p_Primeiro->proximo == NULL) {
        printf("A lista está vazia.\n"); // Tirar isso daqui depois, só pra ficar mais visual caso a gnt teste
        
    }
    
    Celula *celula_removida = lista->p_Primeiro->proximo;
    *carta = celula_removida->carta;

    lista->p_Primeiro->proximo = celula_removida->proximo;

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

    lista_origem->p_Primeiro->proximo = celula_origem;

    //printf("Transferência de cartas concluída\n");
}

// Função para embaralhar uma lista de cartas
void ListaCartas__embaralha(Lista_cartas *lista) {
    int quantidade = Tamanho__retorna(lista); // Passo 1

    if (quantidade <= 1) {
        return; // Não há cartas suficientes para embaralhar
    }

    // Passo 2: Gere uma ordem aleatória para os índices das cartas
    int *indices = (int *)malloc(quantidade * sizeof(int));
    for (int i = 0; i < quantidade; i++) {
        indices[i] = i;
    }

    srand(time(NULL)); // Inicializa a semente aleatória
    for (int i = quantidade - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    // Passo 3: Reorganize as cartas na lista de acordo com a ordem aleatória
    Celula *cartas_ordenadas = lista->p_Primeiro->proximo;
    Celula *cartas_embaralhadas = NULL;

    for (int i = 0; i < quantidade; i++) {
        int indice = indices[i];
        
        // Encontre a carta com o índice correto na lista original
        while (indice > 0 && cartas_ordenadas != NULL) {
            cartas_ordenadas = cartas_ordenadas->proximo;
            indice--;
        }

        // Adicione a carta na lista de cartas embaralhadas
        if (cartas_ordenadas != NULL) {
            Celula *nova_celula = (Celula *)malloc(sizeof(Celula));
            nova_celula->carta = cartas_ordenadas->carta;
            nova_celula->proximo = cartas_embaralhadas;
            cartas_embaralhadas = nova_celula;
        }
    }

    // Atualize a lista original para conter as cartas embaralhadas
    lista->p_Primeiro->proximo = cartas_embaralhadas;

    // Libere a memória alocada para o array de índices
    free(indices);
}

void ListaCartas__exibe(){

}