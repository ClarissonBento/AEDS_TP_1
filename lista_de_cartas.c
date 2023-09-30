#include "lista_de_cartas.h"

// --------------------------------------------------------------------------------- //
// Cria uma lista de cartas vazia.
// Essa estrutura vai ser usada na mesa, para o baralho, tableau e outros
// Mudei o nome de "baralho" pra "lista" porque vamos precisar da palavra depois
// ----------------------------------------------------------------------------------//

void ListaVazia__cria(Lista_cartas *lista) {
    lista->p_Primeiro = NULL;
    lista->p_Ultimo = NULL;
}

// Usa um laço para percorrer a lista até o apontador atual ser nulo e então encerra
int Tamanho__retorna(Lista_cartas *lista) {
    Apontador atual = lista->p_Primeiro;
    int tamanho = 0;

    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }

    return tamanho;
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

void Topo__adiciona(Lista_cartas *lista, Carta *carta) {
    Apontador nova_celula = (Apontador)malloc(sizeof(Celula));

    if (nova_celula == NULL) {
        printf("Erro ao alocar memória para a célula.\n");
        exit(1);
    }

    nova_celula->carta = *carta;
    nova_celula->proximo = lista->p_Primeiro;

    if (lista->p_Ultimo == NULL) {
        lista->p_Ultimo = nova_celula;
    }

    lista->p_Primeiro = nova_celula;
}



// Remoção no inicio da lista
void Topo__remove(Lista_cartas *lista, Carta *carta) {
    if (lista->p_Primeiro == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Apontador celula_removida = lista->p_Primeiro;
    *carta = celula_removida->carta;

    lista->p_Primeiro = celula_removida->proximo;

    free(celula_removida);
}

// Não sei se isso tá certo KKKKKKK
void Cartas__transfere(Lista_cartas *lista_origem, Lista_cartas *lista_destino, int quantidade) {
    if (lista_origem->p_Primeiro == NULL || quantidade <= 0) {
        printf("Falhou com sucesso.\n");
        return;
    }

    Apontador celula_origem = lista_origem->p_Primeiro;

    for (int i = 0; i < quantidade && celula_origem != NULL; i++) {
        Apontador nova_celula = (Apontador)malloc(sizeof(Celula));

        if (nova_celula == NULL) {
            printf("Erro ao alocar memória para a célula.\n");
            exit(1);
        }

        nova_celula->carta = celula_origem->carta;
        nova_celula->proximo = lista_destino->p_Primeiro;

        lista_destino->p_Primeiro = nova_celula;

        Apontador celula_removida = celula_origem;
        celula_origem = celula_origem->proximo;

        free(celula_removida);
    }

    lista_origem->p_Primeiro = celula_origem;
}

// Função para embaralhar uma lista de cartas
void ListaCartas__embaralha(Lista_cartas *lista) {
    int quantidade = Tamanho__retorna(lista);
    if (quantidade <= 1) {
        return;
    }

    int *indices = (int *)malloc(quantidade * sizeof(int));
    for (int i = 0; i < quantidade; i++) {
        indices[i] = i;
    }

    srand(time(NULL));
    for (int i = quantidade - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    Celula *cartas_ordenadas = lista->p_Primeiro->proximo;
    Celula *cartas_embaralhadas = NULL;

    for (int i = 0; i < quantidade; i++) {
        int indice = indices[i];
        
        while (indice > 0 && cartas_ordenadas != NULL) {
            cartas_ordenadas = cartas_ordenadas->proximo;
            indice--;
        }

        if (cartas_ordenadas != NULL) {
            Celula *nova_celula = (Celula *)malloc(sizeof(Celula));
            nova_celula->carta = cartas_ordenadas->carta;
            nova_celula->proximo = cartas_embaralhadas;
            cartas_embaralhadas = nova_celula;
        }
    }

    lista->p_Primeiro->proximo = cartas_embaralhadas;

    free(indices);
}

void ListaCartas__exibe(Lista_cartas *lista) {
    Apontador atual = lista->p_Primeiro->proximo;

    printf("Cartas na lista:\n");

    while (atual != NULL) {
        Carta__exibe(&atual->carta);
        atual = atual->proximo;
    }
}