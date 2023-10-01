#include <stdio.h>
#include "lista_de_cartas.h"
#include "mesa.h"

// Função para inicializar o sistema do jogo de Paciência
//void InicializarJogo(Mesa *mesa) {
    // Inicialize a mesa e o baralho conforme necessário
    //Mesa__Inicializa(mesa);
    //preparar(mesa);
    // Carregue o baralho aleatoriamente ou a partir de um arquivo
    // Implemente essa parte de acordo com sua escolha de interatividade ou modo arquivo
//}

// Função para lidar com a lógica do jogo no modo interativo
void ModoInterativo(Mesa *mesa) {
    int aux,aux1,aux2,aux3,origem,destino,qtd;

    int opcao;
    do {
        // Exiba o estado atual da mesa do jogo
        exibir_mesa(mesa);
        
        // Exiba um menu de opções para o jogador
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
            compra_carta(&mesa->baralho);
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
            scanf("%d",&aux1);
            printf("Para qual coluna deve ir?");
            scanf("%d",&aux2);
            Mover_bases_tableau(mesa,aux1,aux2);
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
    // Inicialize a semente para gerar números aleatórios
    srand(time(NULL));

    // Crie uma variável do tipo Mesa para representar o jogo
    Mesa mesa;
    Mesa__Inicializa(&mesa);
    preparar(&mesa);

    // Inicialize o sistema do jogo de Paciência
    // InicializarJogo(&mesa);

    int modo;
    printf("Escolha o modo de utilizacao (1 para interativo, 2 para arquivo): ");
    scanf("%d", &modo);

    if (modo == 1) {
        // Modo interativo
        ModoInterativo(&mesa);
    } else if (modo == 2) {
        // Modo arquivo (implemente conforme necessário)
        // Carregue o jogo a partir de um arquivo e exiba o estado inicial e final
    } else {
        printf("Modo de utilizacao invalido.\n");
    }

    return 0;
}