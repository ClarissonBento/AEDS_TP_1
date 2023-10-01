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

int taVazia(Lista_cartas *lista) {
    return lista->p_Primeiro == NULL;
}

// Confere se a lista está vazia primeiro, se não estiver retorna a carta do topo
Carta Topo__retorna(Lista_cartas *lista){
    Carta topo;
    topo = lista->p_Primeiro->carta;
    return topo;
}

int PosCarta__retorna(Lista_cartas *lista, Carta *carta) {
    if (lista == NULL || lista->p_Primeiro == NULL || carta == NULL) {
        // Tratamento de erro se a lista ou a carta forem inválidas
        return nao_definido;
    }

    Apontador atual = lista->p_Primeiro;
    int pos = 0;

    while (atual != NULL) {
        if (Naipe__retorna(&atual->carta) == Naipe__retorna(carta) &&
            Valor__retorna(&atual->carta) == Valor__retorna(carta) &&
            Posicao__retorna(&atual->carta) == Posicao__retorna(carta)) {
            return pos; // Carta encontrada, retorna a posição
        }
        atual = atual->proximo;
        pos++;
    }

    return nao_definido; // Carta não encontrada, retorna -1
}

// --------------------------------------------------------------------------------- //
// Aqui preciamos decidir se a inserção vai ser feita no inicio da lista ou no final,
// aparentemente a inserção e remoção no inicio da lista é mais eficiente.
// Vamos conversar sobre essa decisão quando possível, mas por enquanto deixei uma função
// que adiciona no inicio da lista e deixei a no final da lista como comentário.
// ----------------------------------------------------------------------------------//

void Topo__adiciona(Lista_cartas *lista, Carta *carta) {
    if (lista == NULL) {
        printf("Erro: Lista de cartas não inicializada.\n");
        exit(1);
    }

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

/*--------------------------------------------------------------------------------
Transfere uma quantidade arbitrária de cartas a partir do topo de uma lista, 
para o topo de outra, mantendo a ordem original.
--------------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------------------
Verifica se a quantidade na lista é maior que 1, aloca espaço, 
inicia uma semente aleatoria com srand(),
e faz um loop que realiza o embaralhamento usando o algoritmo de Fisher-Yates.
----------------------------------------------------------------------------------------*/
void ListaCartas__embaralha(Lista_cartas *lista) {
    // Verifica se a lista está vazia ou contém apenas um elemento
    if (taVazia(lista) || lista->p_Primeiro == lista->p_Ultimo) {
        return; // Não há nada para embaralhar
    }

    // Inicializa a semente aleatória com base no tempo atual
    srand(time(NULL));

    int tamanho = Tamanho__retorna(lista);
    Apontador atual = lista->p_Primeiro;
    Apontador ultimo = lista->p_Ultimo;

    // Cria um array temporário para armazenar temporariamente as cartas
    Carta *cartas = (Carta *)malloc(tamanho * sizeof(Carta));
    if (cartas == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para embaralhar as cartas.\n");
        exit(1); // Tratamento de erro
    }

    // Copia as cartas da lista para o array temporário
    int i = 0;
    while (atual != NULL) {
        cartas[i] = atual->carta;
        atual = atual->proximo;
        i++;
    }

    // Aplica o algoritmo de Fisher-Yates para embaralhar as cartas no array
    for (i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = temp;
    }

    // Copia as cartas embaralhadas de volta para a lista
    atual = lista->p_Primeiro;
    i = 0;
    while (atual != NULL) {
        atual->carta = cartas[i];
        atual = atual->proximo;
        i++;
    }

    // Libera a memória alocada para o array temporário
    free(cartas);
}

void ListaCartas__exibe(Lista_cartas *lista) {
    Apontador atual = lista->p_Primeiro->proximo;

    printf("Cartas na lista:\n");

    while (atual != NULL) {
        Carta__exibe(&atual->carta);
        atual = atual->proximo;
    }
}