#include "mesa.h"

void Mesa__Inicializa(Mesa *mesa) {

    ListaVazia__cria(&mesa->baralho); // perfeito
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
    Lista_cartas baralho; // Cria uma lista para o baralho
    Carta carta;

    // Inicializa o baralho
    ListaVazia__cria(&baralho);

    int i = 0;
    for (int naipe = COPAS; naipe <= PAUS; naipe++) {
        for (ValorCarta valor = AS; valor <= K; valor++) {
            Carta__cria(&carta, naipe, valor, BAIXO); // Cria uma carta com o naipe, valor e posição
            Topo__adiciona(&baralho, &carta); // Adiciona a carta ao baralho
        }
    }

    // Embaralhando o baralho
    ListaCartas__embaralha(&baralho);

    // Insere as cartas no baralho da mesa
    while (!taVazia(&baralho)) {
        Carta carta = Topo__retorna(&baralho);
        Topo__adiciona(&mesa->baralho, &carta);
        Topo__remove(&baralho, &carta);
    }
}

void CarregarBaralho(Lista_cartas *lista, Carta *cartas, int num_cartas) {
    // Limpa a lista atual, se houver cartas nela
    while (!taVazia(lista)) {
        Carta carta_removida = Topo__retorna(lista);
        Topo__remove(lista, &carta_removida);
    }

    // Adiciona as novas cartas à lista
    for (int i = 0; i < num_cartas; i++) {
        Topo__adiciona(lista, &cartas[i]);
    }
}

void preparar(Mesa *mesa) {
    CarregarBaralho_aleatorio(mesa);
    Lista_cartas *baralho = &(mesa->baralho);

    // Inicialize bases vazias
    for (int i = 0; i < 4; i++) {
        Lista_cartas *bases = &(mesa->bases[i]);
        ListaVazia__cria(bases);
    }

    // Inicialize o tableau
    for (int i = 0; i < 7; i++) {
        Lista_cartas *coluna_tableau = &(mesa->tableau[i]);

        // Distribua as cartas no tableau de acordo com o número da coluna
        for (int num_cartas_coluna = 0; num_cartas_coluna <= i + 1; num_cartas_coluna++) {
            if (taVazia(baralho)) {
                printf("Baralho vazio. Não há cartas suficientes para o tableau.\n");
                return; // Encerre a função se o baralho estiver vazio
            }

            Carta c;
            
            c = Topo__retorna(baralho);
            
            Posicao__alterar(&c); // Vire a carta para cima
            Topo__remove(baralho, &c);

            // A primeira carta em cada coluna do tableau está virada para cima, o resto para baixo
            if (num_cartas_coluna == i) {
                Posicao__alterar(&c); // Vire a carta para cima
            }

            Topo__adiciona(coluna_tableau, &c);
        }
    }
}

int verificar_vitoria(Mesa *mesa) {
    int cartas_base = 0, total = 0;

    for (int i = 0; i < 4; i++) {
        Lista_cartas *base = &(mesa->bases[i]);
        cartas_base = Tamanho__retorna(base);
        total += cartas_base;

        if (cartas_base != 13) {
            printf("A base %d está incompleta (%d cartas).\n", i, cartas_base);
        }
    }

    if (total == 52) {
        printf("Parabéns! Você venceu o jogo!\n");
        return 1;
    } else {
        return 0;
    }
}

void exibir_mesa(Mesa *mesa) {
    printf("BARALHO\n");
    ListaCartas__exibe(&(mesa->baralho));
    printf("\n");

    printf("DESCARTE\n");
    ListaCartas__exibe(&(mesa->descarte));
    printf("\n");

    printf("COLUNAS DO TABLEAU:\n");
    for (int i = 0; i < 7; i++) {
        printf("COLUNA %d ", i+1);
        Lista_cartas *coluna_tableau = &(mesa->tableau[i]);
        ListaCartas__exibe(coluna_tableau);
        printf("\n");
    }

    printf("BASES DO TABLEAU\n");
    for (int i = 0; i < 4; i++) {
        printf("BASE %d ", i+1);
        Lista_cartas *base = &(mesa->bases[i]);
        ListaCartas__exibe(base);
        printf("\n");
    }

    printf("PONTUAÇÃO: %d\n", mesa->pontos);
}

//compra de cartas
Carta compra_carta(Lista_cartas *lista) {
    if (taVazia(lista)) {
        printf("Não é possível comprar cartas, pois o baralho acabou.\n");
        //caso o baralho esteja vazio, retornar uma carta nula
        Carta carta_vazia;
        carta_vazia.naipe = nao_definido;
        carta_vazia.valor = nao_definido;
        carta_vazia.posicao = nao_definido;
        return carta_vazia;
    } else {
        Carta c = lista->p_Primeiro->carta;
        lista->p_Primeiro = lista->p_Primeiro->proximo;
        return c;
    }
}

void Descarte_para_bases(Mesa *mesa) {
    Lista_cartas *descarte = &(mesa->descarte);

    if (taVazia(descarte)) {
        printf("O descarte está vazio.\n");
        return;
    }

    Carta carta_descarte = Topo__retorna(descarte);
    Naipe naipe_descarte = Naipe__retorna(&carta_descarte);

    // Verifique se a carta é um Ás (AS)
    if (Valor__retorna(&carta_descarte) == AS) {
        Lista_cartas *base_correspondente = &(mesa->bases[naipe_descarte]);

        // Verifique se a base correspondente está vazia
        if (taVazia(base_correspondente)) {
            Topo__remove(descarte, &carta_descarte);
            Topo__adiciona(base_correspondente, &carta_descarte);
            printf("Movido um Ás para a base correspondente.\n");
        } else {
            printf("A base correspondente não está vazia.\n");
        }
    } else {
        printf("A carta do descarte não é um Ás (AS).\n");
    }
}

// Função para mover uma carta do descarte para uma coluna específica do tableau.
void Descarte_para_tableau(Mesa *mesa, int indice_tb) {
    // Verifique se o índice do tableau é válido (0 a 6)
    if (indice_tb < 0 || indice_tb > 6) {
        printf("Índice do tableau inválido.\n");
        return;
    }

    Lista_cartas *descarte = &(mesa->descarte);
    Lista_cartas *tableau = &(mesa->tableau[indice_tb]);

    // Verifique se o descarte e o tableau estão vazios
    if (taVazia(descarte) || Tamanho__retorna(tableau) >= 13) {
        printf("Operação inválida: descarte vazio ou tableau cheio.\n");
        return;
    }

    // Obtenha a carta do topo do descarte
    Carta carta = Topo__retorna(descarte);

    // Verifique se a carta pode ser movida para o tableau
    if (Tamanho__retorna(tableau) == 0 && Valor__retorna(&carta) == 13) {
        // Apenas o Rei pode ser colocado em uma coluna vazia do tableau
        Topo__remove(descarte, &carta);
        Topo__adiciona(tableau, &carta);
    } else if (Tamanho__retorna(tableau) > 0) {
        Carta carta_tableau = Topo__retorna(tableau);

        // Verifique se a carta do descarte pode ser colocada sobre a carta do tableau
        if (SeqTableau_retorna(&carta_tableau, &carta)) {
            Topo__remove(descarte, &carta);
            Topo__adiciona(tableau, &carta);
        } else {
            printf("Movimento inválido: a carta do descarte não pode ser colocada sobre a carta do tableau.\n");
        }
    } else {
        printf("Movimento inválido: a carta do descarte não pode ser colocada no tableau.\n");
    }
}

void Mover_tableau_bases(Mesa *mesa, int indice_tableau) {
    if (taVazia(&(mesa->tableau[indice_tableau]))) {
        printf("Esta coluna do tableau está vazia.\n");
        return;
    }

    Lista_cartas *coluna_tableau = &(mesa->tableau[indice_tableau]);
    Carta carta_tableau = Topo__retorna(coluna_tableau);
    
    // Determinar a lista de bases correspondente ao naipe da carta do tableau
    Lista_cartas *base = NULL;
    switch (Naipe__retorna(&carta_tableau)) {
        case COPAS:
            base = &(mesa->bases[0]);
            break;
        case OUROS:
            base = &(mesa->bases[1]);
            break;
        case PAUS:
            base = &(mesa->bases[2]);
            break;
        case ESPADAS:
            base = &(mesa->bases[3]);
            break;
        default:
            printf("Naipe inválido.\n");
            return;
    }

    // Verificar se a base está vazia ou se a carta pode ser adicionada
    Carta topo_base = Topo__retorna(base);
    if (taVazia(base) || (Naipe__retorna(&topo_base) == Naipe__retorna(&carta_tableau) &&
        (carta_tableau.valor - topo_base.valor) == 1)) {
        Topo__adiciona(base, &carta_tableau);
        Topo__remove(coluna_tableau, &carta_tableau);
    } else {
        printf("Movimento inválido: a carta do tableau não pode ser movida para a base.\n");
    }
}

void Mover_bases_tableau(Mesa *mesa, int indice_base, int indice_tableau) {
    Lista_cartas *base = &(mesa->bases[indice_base]);
    Lista_cartas *coluna_tableau = &(mesa->tableau[indice_tableau]);

    if (taVazia(base)) {
        printf("A base está vazia.\n");
        return;
    }
    Carta c1= Topo__retorna(base);
    Carta c2= Topo__retorna(coluna_tableau);
    if (taVazia(coluna_tableau) || (SeqBase_retorna(&c1,&c2) && SeqTableau_retorna(&c1,&c2))) {
        Carta carta_base = Topo__retorna(base);
        Topo__remove(base, &carta_base);
        Topo__adiciona(coluna_tableau, &carta_base);
        printf("Movido de base %d para tableau %d.\n", indice_base, indice_tableau);
    } else if (Topo__retorna(base).valor == K && taVazia(coluna_tableau)) {
        Carta carta_base = Topo__retorna(base);
        Topo__remove(base, &carta_base);
        Topo__adiciona(coluna_tableau, &carta_base);
        printf("Movido um Rei de base %d para tableau %d.\n", indice_base, indice_tableau);
    } else {
        printf("Movimento inválido de base %d para tableau %d.\n", indice_base, indice_tableau);
    }
}

void Mover_entre_colunas(Mesa *mesa,int indice_col_origem, int indice_col_destino,int qtd){
    Lista_cartas *coluna_origem = &(mesa->tableau[indice_col_origem]);
    Lista_cartas *coluna_destino = &(mesa->tableau[indice_col_destino]);
    Carta carta_origem = Topo__retorna(coluna_origem);
    Carta carta_destino = Topo__retorna(coluna_destino);


    if(SeqTableau_retorna(&carta_origem,&carta_destino)){
        Cartas__transfere(coluna_origem,coluna_destino,qtd);
    }
    else printf("Nao eh possivel colocar essas cartas nessa coluna");
    
}