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

    // Insere as cartas no baralho da mesa
    for (int i = 0; i < 52; i++) {
        Topo__adiciona(&baralho[i], &mesa->baralho.p_Primeiro->carta);
    }

}

void CarregarBaralho(Lista_cartas *lista, Carta *cartas, int num_cartas) {

    while (!taVazia(lista)) {
        Carta carta_removida = Topo__retorna(lista);
        Topo__remove(lista, &carta_removida);
    }

    for (int i = 0; i < num_cartas; i++) {
        Topo__adiciona(lista, &cartas[i]);
    }
}


//compra de cartas
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

// Função para mover uma carta do descarte para uma coluna específica do tableau.
void Descarte_para_tableau(Mesa *mesa, int indice_tableau) {
    // Verifica se o descarte está vazio.
    if (taVazia(&(mesa->descarte))) {
        printf("O descarte está vazio.\n");
        return;
    }

    // Obtém a carta do topo do descarte.
    Carta carta_descartada = Topo__retorna(&(mesa->descarte));

    // Verifica se o índice do tableau é válido.
    if (indice_tableau < 0 || indice_tableau >= 7) {
        printf("Índice de coluna do tableau inválido.\n");
        return;
    }

    // Obtém a coluna do tableau correspondente.
    Lista_cartas *coluna_tableau = &(mesa->tableau[indice_tableau]);

    Carta AUX = Topo__retorna(&coluna_tableau);

    // Verifica se a coluna do tableau está vazia ou se a carta pode ser movida para a coluna.
    if (taVazia(coluna_tableau) || seqAlt_retorna(&carta_descartada, &AUX) == 1) {
        // Remove a carta do topo do descarte.
        Topo__remove(&(mesa->descarte), &carta_descartada);

        // Adiciona a carta à coluna do tableau correspondente.
        Topo__adiciona(coluna_tableau, &carta_descartada);

        printf("Carta movida do descarte para o tableau (coluna %d).\n", indice_tableau);
    } else {
        printf("A carta do descarte não pode ser movida para o tableau (coluna %d).\n", indice_tableau);
    }
}

//mover do tablau para as bases
void tableau_bases(Mesa *mesa, int indice_tableau){
    if(taVazia(&(mesa->tableau[indice_tableau]))){
        printf("essa coluna do tableau esta vazia");
    }else{
        Lista_cartas *coluna_tableau = &(mesa->tableau[indice_tableau]);
        Carta carta_tableau = Topo__retorna(coluna_tableau);
        Lista_cartas *base = &(mesa->bases);
        Carta topo_base=Topo__retorna(&base);
        if(Naipe__retorna(&carta_tableau)==COPAS){
            if(taVazia(&base)|| (&topo_base.naipe == carta_tableau.naipe && //aqui verifica: se a lista tiver vazia,ela pode ser adicionada na base,
            (carta_tableau.valor-topo_base.valor)==1)){                    // e verifica tambem se os naipes e sequencia sao compativeis para adicionar na base
            Topo__adiciona(&base[0],&carta_tableau);
            }
        }
       if(Naipe__retorna(&carta_tableau)==OUROS){
            if(taVazia(&base)|| (&topo_base.naipe == carta_tableau.naipe && 
            (carta_tableau.valor-topo_base.valor)==1)){
            Topo__adiciona(&base[1],&carta_tableau);
            }
        }
       if(Naipe__retorna(&carta_tableau)==PAUS){
            if(taVazia(&base)|| (&topo_base.naipe == carta_tableau.naipe && 
            (carta_tableau.valor-topo_base.valor)==1)){
            Topo__adiciona(&base[3],&carta_tableau);
            }
        }
       if(Naipe__retorna(&carta_tableau)==ESPADAS){
            if(taVazia(&base)|| (&topo_base.naipe == carta_tableau.naipe && 
            (carta_tableau.valor-topo_base.valor)==1)){
            Topo__adiciona(&base[3],&carta_tableau);
            }
        }
    }
}
void bases_tableau(Mesa *mesa,int indice_base,int indice_tableau){
    Lista_cartas *base= &(mesa->bases[indice_base]);
    Lista_cartas *coluna_tableau =&(mesa->tableau[indice_tableau]);
    if(taVazia(&base)){
        printf("A base esta vazia");
    }else{
       Carta carta_base = Topo__retorna(&base);
       Carta carta_tableau = Topo__retorna(coluna_tableau);
       // se ja tiver uma carta na coluna que planejamos mover a carta precisamos conferir
       //se o naipe e a sequencia para essa insercao estejam corretos
    if(!(taVazia(coluna_tableau))){
        if(seqAlt_retorna(&carta_base,&carta_tableau) && seqNaipe_retorna(&carta_base,&carta_tableau)){
        Topo__remove(&base,&carta_base);
        Topo__adiciona(&coluna_tableau,&carta_base);
        }
    }
    //se a coluna tiver vazia creio que pode add qualquer carrta a coluna, nao tenho certeza
    //pois pode ser que seja possivel inicializar a coluna so com um rei mas nao entendo muito de paciencia
    //no mais deixei assim qualquer correcao pode apagar essas linhas de comentario aqui
    Topo__remove(&base,&carta_base);
    Topo__adiciona(&coluna_tableau,&carta_base);
    }
}
