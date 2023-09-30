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
            Carta__cria(&carta, naipe, valor, CIMA); // Cria uma carta com o naipe, valor e posição
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
    // Embaralhe o baralho
    ListaCartas__embaralha(&mesa->baralho);

    // Distribua as cartas para o tableau
    for (int i = 0; i < 7; i++) {
        Lista_cartas *coluna_tableau = &(mesa->tableau[i]);
        while (i >= num_cartas_coluna) {
            Carta c;
            c = Topo__retorna(&baralho);
            Topo__adiciona(coluna_tableau, &c);
            num_cartas_coluna++;
        }
    }
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

/*
// Função para mover uma carta do descarte para uma coluna específica do tableau.
void Descarte_para_tableau(Mesa *mesa, int indice_tableau) {

    if (taVazia(&(mesa->descarte))) {
        printf("O descarte está vazio.\n");
        return;
    }

    Carta carta_descartada = Topo__retorna(&(mesa->descarte));

    if (indice_tableau < 0 || indice_tableau >= 7) {
        printf("Índice de coluna do tableau inválido.\n");
        return;
    }

    Lista_cartas *coluna_tableau = &(mesa->tableau[indice_tableau]);

    Carta AUX = Topo__retorna(&coluna_tableau);

    if (taVazia(coluna_tableau) || seqAlt_retorna(&carta_descartada, &AUX) == 1) {
        Topo__remove(&(mesa->descarte), &carta_descartada);
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
    if(carta_base.valor==K){
        Topo__remove(&base,&carta_base);
        Topo__adiciona(&coluna_tableau,&carta_base);
    }else{
    printf("Somente eh posivel adicionar um rei a colunas vazias");
    }
    }
}
void mover_colunas(Mesa *mesa,int indice_col_origem, int indice_col_destino,int qtd){
    Lista_cartas *coluna_origem = &(mesa->tableau[indice_col_origem]);
    Lista_cartas *coluna_destino = &(mesa->tableau[indice_col_destino]);
    Carta carta_origem = Topo__retorna(coluna_origem);
    Carta carta_destino = Topo__retorna(coluna_destino);


    if(SeqTableau_retorna(&carta_origem,&carta_destino)){
        Cartas__transfere(&coluna_origem,&coluna_destino,qtd);
    }
    else printf("Nao eh possivel colocar essas cartas nessa coluna");


}

int verificar_vitoria(Mesa *mesa){
    int cartas_base=0,total=0;
  
     for (int i = 0; i < 4; i++) {
        Lista_cartas *base = &(mesa->bases[i]);
        cartas_base = Tamanho__retorna(&base[i]);
        total+=cartas_base;
        if(cartas_base!=13){
            printf("A condicao de vitoria ainda nao foi alcancada, pois a base %d esta incompleta\n",i);
            
        }
    }
    if(total==52){
        printf("parabens");
        return true;
    }else return false;
    
}

void exibir_mesa(Mesa *mesa){
    printf("BARALHO\n");
    ListaCartas__exibe(&mesa->baralho);
    printf("\n");
    printf("DESCARTE\n");
    ListaCartas__exibe(&mesa->descarte);
    printf("\n");
    printf("COLUNAS DO TABLEAU:\n");
    for(int i=0;i<7;i++){
        printf("COLUNA %d\n",i);
       Lista_cartas *coluna_tableau = &(mesa->tableau[i]);
       while (&coluna_tableau->p_Primeiro->carta!=NULL)
       {
            Carta *c= &coluna_tableau->p_Primeiro->carta;
            printf("%d-%d ",c->valor,c->naipe);
            coluna_tableau->p_Primeiro= coluna_tableau->p_Primeiro->proximo;
            
       }
       printf("\n");
    }
   printf("BASES DO TABLEAU\n");
   for(int i=0;i<4;i++){
        printf("BASE %d\n",i);
       Lista_cartas *base = &(mesa->bases[i]);
       while (&base->p_Primeiro->carta!=NULL)
       {
            Carta *c= &base->p_Primeiro->carta;
            printf("%d-%d ",c->valor,c->naipe);
            base->p_Primeiro= base->p_Primeiro->proximo;
            
       }
       printf("\n");
    }

}
*/