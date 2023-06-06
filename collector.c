#include "collector.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_OBJETOS 100

static void* objetos[MAX_OBJETOS];
static int num_objetos = 0;

void* malloc2(size_t size) {
    void* ptr = malloc(size);
    if (ptr != NULL) {
        objetos[num_objetos++] = ptr;
    }
    return ptr;
}

void coleta() {
    for (int i = 0; i < num_objetos; i++) {
        free(objetos[i]);
    }
    num_objetos = 0;
}

void atrib2(void** ptrX, void* ptrY) {
    for (int i = 0; i < num_objetos; i++) {
        if (objetos[i] == *ptrX) {
            objetos[i] = ptrY;
            break;
        }
    }
    *ptrX = ptrY;
}

void dump() {
    printf("Objetos alocados: %d\n", num_objetos);
    for (int i = 0; i < num_objetos; i++) {
        printf("Endereco: %p\n", objetos[i]);
    }
}