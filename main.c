#include <stdio.h>
#include "coletor.h"

int main() {
    Objeto* obj1 = malloc2(10);
    Objeto* obj2 = malloc2(20);

    printf("Antes da atribuição de valor:\n");
    dump();

    atrib2(obj1, obj2);
    obj2->marcado = 1;

    printf("\nApós a atribuição de valor:\n");
    dump();

    printf("\nRealizando a coleta de lixo...\n");
    coleta();

    printf("\nApós a coleta de lixo:\n");
    dump();

    return 0;
}
