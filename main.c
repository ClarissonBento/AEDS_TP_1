#include <stdio.h>
#include "lista_de_cartas.h"
#include "mesa.h"

// Função para exibir o menu interativo
//void exibir_menu();
void exibir_menu();
int modo_iterativo();
int main() {
    
    
    int modo;

    // Seleção de modo de utilização: interativo (1) ou por arquivo (2)
    printf("Selecione o modo de utilização\n 1 - Interativo | 2 - Por arquivo: ");
    scanf("%i", &modo);

    if (modo == 1) {
        modo_iterativo();
    }else{

    }

    return 0;
}


int modo_iterativo(){
    int aux,aux1,aux2,aux3,origem,destino,qtd;
    Mesa *mesa;
    Mesa__Inicializa(mesa);
    CarregarBaralho_aleatorio(mesa);
    Lista_cartas *baralho = &(mesa->baralho);
    preparar(mesa);
    
    while (verificar_vitoria(mesa)==0)
    {
       exibir_mesa(mesa);
       int escolha;
       exibir_menu();
       scanf("%d",&escolha); 
       
       switch (escolha) {
                case 1:
                compra_carta(baralho);
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
                return 0;

                default:
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
         if (verificar_vitoria(mesa))
         {
            return 1;
         }
            
       return 0;
    
  



    }
    
    
}





void exibir_menu() {
    printf("\n[Menu]\n");
    printf("1 para Comprar Carta\n");
    printf("2 para Mover do descarte para as bases\n");
    printf("3 para Mover do descarte para o tableau\n");
    printf("4 para Mover do tableau para as bases\n");
    printf("5 para Mover das bases para o tableau\n");
    printf("6 para Mover entre colunas do tableau\n");
    printf("7 para Encerrar\n");
}
/*
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
                compra_carta(&mesa.baralho);
                break;

                case 2:
                Descarte_para_bases(&mesa);
                break;

                case 3:
                int aux;
                printf("Para qual coluna deseja mover? ");
                Descarte_para_tableau(&mesa, aux);
                break;

                case 4:
                //Mover_tableau_bases();
                break;

                case 5:
                //Mover_bases_tableau();
                break;

                case 6:
                //Mover_entre_colunas();
                break;
                    
                case 7:
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


*/