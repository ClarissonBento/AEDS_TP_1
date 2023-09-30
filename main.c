#include <stdio.h>
#include "lista_de_cartas.h"
#include "mesa.h"

int main(){
Mesa *mesa;
Mesa__Inicializa(&mesa);
CarregarBaralho_aleatorio(&mesa);
exibir_mesa(&mesa);


    return 0;
}