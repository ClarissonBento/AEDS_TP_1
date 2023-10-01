#include <stdio.h>
#include "lista_de_cartas.h"
#include "mesa.h"

// Função para inicializar o sistema do jogo de Paciência
void InicializarJogo(Mesa *mesa) {
    // Inicialize a mesa e o baralho conforme necessário
    Mesa__Inicializa(mesa);
    // Carregue o baralho aleatoriamente ou a partir de um arquivo
    // Implemente essa parte de acordo com sua escolha de interatividade ou modo arquivo
}

// Função para lidar com a lógica do jogo no modo interativo
void ModoInterativo(Mesa *mesa) {
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

        // Implemente a lógica para cada opção escolhida pelo jogador

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

    // Inicialize o sistema do jogo de Paciência
    InicializarJogo(&mesa);

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