#include <stdio.h>
#include "lista_de_cartas.h"
#include "mesa.h"
int modo_iterativo(Mesa *m);
void exibir_menu();

int main() {
    int modo;
    Mesa *mesa = (Mesa *)malloc(sizeof(Mesa)); // Aloque memória para a mesa
    if (mesa == NULL) {
        printf("Erro ao alocar memória para a mesa.\n");
        return 1; // Saia do programa com código de erro
    }

    Mesa__Inicializa(mesa);
    preparar(mesa); 
    printf("Digite o modo de jogo: 1 para iterativo e 2 para arquivo.\n");
    scanf("%d",&modo);
    if (modo == 1) {
        modo_iterativo(mesa);
    } else {
        printf("Paisanduuuuu\n");
    }
   
    free(mesa); // Libere a memória alocada para a mesa antes de sair do programa
    return 0;
}

void exibir_menu(){
    printf("\n[Menu]\n");
    printf("1 para Comprar Carta\n");
    printf("2 para Mover do descarte para as bases\n");
    printf("3 para Mover do descarte para o tableau\n");
    printf("4 para Mover do tableau para as bases\n");
    printf("5 para Mover das bases para o tableau\n");
    printf("6 para Mover entre colunas do tableau\n");
    printf("7 para Encerrar\n");
}

int modo_iterativo(Mesa *m){
    int v = verificar_vitoria(m);
    printf("%d",v);
    
    return v; 
}