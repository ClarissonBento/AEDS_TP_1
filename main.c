#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_de_cartas.h"
#include "mesa.h"

void ModoInterativo(Mesa *mesa) {
    int origem, destino, qtd;
    int opcao;

    do {
        
        exibir_mesa(mesa);

        // exibir um menu de opções para o jogador
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
                compra_carta(mesa, &mesa->baralho);
                break;

            case 2:
                Descarte_para_bases(mesa);
                break;

            case 3:
                printf("Para qual coluna deseja mover? ");
                scanf("%d", &destino);
                Descarte_para_tableau(mesa, destino - 1); 
                break;

            case 4:
                printf("De qual coluna deseja mover? ");
                scanf("%d", &origem);
                Mover_tableau_bases(mesa, origem - 1);
                break;

            case 5:
                printf("De qual base deve ser retirado? ");
                scanf("%d", &origem);
                printf("Para qual coluna deve ir? ");
                scanf("%d", &destino);
                Mover_bases_tableau(mesa, origem - 1, destino - 1);
                break;

            case 6:
                printf("Qual a quantidade de cartas? ");
                scanf("%d", &qtd);
                printf("De qual coluna deseja retirar? ");
                scanf("%d", &origem);
                printf("Para qual coluna deseja mover? ");
                scanf("%d", &destino);
                Mover_entre_colunas(mesa, origem - 1, destino - 1, qtd);
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


int main() {
   
   

    Mesa mesa;
    Mesa__Inicializa(&mesa);
    preparar(&mesa);

    int modo;
    printf("Escolha o modo de utilizacao (1 para interativo, 2 para arquivo): ");
    scanf("%d", &modo);

    if (modo == 1) {
        
        ModoInterativo(&mesa);
    } else if (modo == 2) {
        // Modo arquivo
    }

    return 0;
}