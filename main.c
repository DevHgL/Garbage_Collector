#include "collector.h"
#include <stdio.h>

int main() {
    printf("Antes da alocacao:\n");
    dump();

    int* ptr1 = malloc2(sizeof(int));
    *ptr1 = 10;

    char* ptr2 = malloc2(sizeof(char));
    *ptr2 = 'a';

    printf("Apos alocacao:\n");
    dump();

    int* ptr3 = malloc2(sizeof(int));
    *ptr3 = 20;

    atrib2((void**)&ptr1, ptr3);

    printf("Apos atribuicao.\n");
    dump();

    coleta();

    printf("Apos coleta.\n");
    dump();

    return 0;
}
