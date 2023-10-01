#include <stdio.h>
#include "lista_de_cartas.h"
#include "mesa.h"

// Função para inicializar o sistema do jogo de Paciência
void InicializarJogo(Mesa *mesa) {
    Mesa__Inicializa(mesa);
    preparar(mesa);
}

// Função para lidar com a lógica do jogo no modo interativo
void ModoInterativo(Mesa *mesa) {
    int aux,aux1,origem,destino,qtd;

    Carta AUX;

    int opcao;
    do {
        exibir_mesa(mesa);
        
        printf("\nEscolha uma opcao:\n");
        printf("1. Comprar uma carta\n");
        printf("2. Mover do descarte para as bases\n");
        printf("3. Mover do descarte para o tableau\n");
        printf("4. Mover do tableu para as bases\n");
        printf("5. Mover das bases para o tableau\n");
        printf("6. Mover entre colunas do tableau\n");
        printf("7. Encerrar o jogo\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            AUX = compra_carta(&mesa->baralho); 
            Topo__adiciona(&(mesa->descarte), &AUX);
            break;

            case 2:
            Descarte_para_bases(mesa);
            break;

            case 3:
            printf("Para qual coluna deseja mover? ");
            scanf("%d",&aux);
            Descarte_para_tableau(mesa, aux);
            break;

            case 4:
            printf("De qual coluna deseja mover?");
            scanf("%d",&aux);
            Mover_tableau_bases(mesa,aux);
            break;

            case 5:
            printf("De qual base deve ser retirado?");
            scanf("%d",&aux);
            printf("Para qual coluna deve ir?");
            scanf("%d",&aux1);
            Mover_bases_tableau(mesa,aux,aux1);
            break;

            case 6:
            printf("Qual a quantidade de cartas?");
            scanf("%d",&qtd);
            printf("De qual coluna deseja retirar?");
            scanf("%d",&origem);
            printf("Para qual coluna deseja mover?");
            scanf("%d",&destino);
            Mover_entre_colunas(mesa,origem,destino,qtd);
            break;
            case 7:
            printf("O programa foi encerrado.\n");
            break;

            default:
            printf("Opção inválida. Tente novamente.\n");
            break;
    }


    } while (opcao != 7 && !verificar_vitoria(mesa));

    if (verificar_vitoria(mesa)) {
        printf("\nParabéns! Você venceu o jogo!\n");
    } else {
        printf("\nO jogo foi encerrado.\n");
    }
}

// Função principal
int main() {

    srand(time(NULL));

    Mesa mesa;

    InicializarJogo(&mesa);

    int modo;
    printf("Escolha o modo de utilizacao (1 para interativo, 2 para arquivo): ");
    scanf("%d", &modo);

    if (modo == 1) {
        // Modo interativo
        ModoInterativo(&mesa);
    } else if (modo == 2) {
        // Modo arquivo 
        // Carregar o jogo a partir de um arquivo
    } else {
        printf("Modo de utilizacao invalido.\n");
    }

    return 0;
}