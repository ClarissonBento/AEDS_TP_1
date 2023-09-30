#include <stdio.h>
#include "lista_de_cartas.h"
#include "mesa.h"

// Função para exibir o menu interativo
void exibir_menu();

int main() {
    Mesa mesa;
    Mesa__Inicializa(&mesa);

    int modo;

    // Seleção de modo de utilização: interativo (1) ou por arquivo (2)
    printf("Selecione o modo de utilização\n 1 - Interativo | 2 - Por arquivo: ");
    scanf("%i", &modo);

    if (modo == 1) {
        // Inicialização do modo interativo com baralho aleatório
        CarregarBaralho_aleatorio(&mesa);
        preparar(&mesa);

        while (true) {
            exibir_mesa(&mesa);
            exibir_menu();

            int escolha;
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    break;
                case 5:
                    
                    break;
                case 6:
                    // Encerra o programa
                    printf("O programa foi encerrado.\n");
                    return 0;
                default:
                    printf("Opção inválida. Tente novamente.\n");
                    break;
            }

            // Verifique a condição de vitória
            if (verificar_vitoria(&mesa)) {
                exibir_mesa(&mesa);
                printf("Parabéns, você venceu o jogo!\n");
                break;
            }
        }
    } else if (modo == 2) {
        // Implemente o modo por arquivo
        // Leia o caminho do arquivo, carregue o baralho e execute as operações
        // Exiba o estado inicial e final do jogo e se a vitória foi alcançada
    } else {
        printf("Modo de utilização inválido. Encerrando o programa.\n");
    }

    return 0;
}

void exibir_menu() {
    printf("\n[Menu]\n");
    printf("1- Comprar Carta\n");
    printf("2- Mover do descarte para as bases\n");
    printf("3- Mover do descarte para o tableau\n");
    printf("4- Mover do tableau para as bases\n");
    printf("5- Mover das bases para o tableau\n");
    printf("6- Mover entre colunas do tableau\n");
}