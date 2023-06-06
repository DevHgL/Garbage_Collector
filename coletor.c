#include <stdio.h>
#include <stdlib.h>
#include "coletor.h"

#define MAX_OBJETOS 100

static Objeto* heap[MAX_OBJETOS];
static int heapSize = 0;

Objeto* malloc2(int valor) {
    Objeto* obj = (Objeto*)malloc(sizeof(Objeto));
    obj->valor = valor;
    obj->marcado = 0;
    heap[heapSize++] = obj;
    return obj;
}

void coleta() {
    for (int i = 0; i < heapSize; i++) {
        if (heap[i]->marcado == 0) {
            free(heap[i]);
            heap[i] = NULL;
        }
    }
}

void atrib2(Objeto* obj1, Objeto* obj2) {
    if (obj1 != NULL && obj2 != NULL) {
        obj1->valor = obj2->valor;
    }
}

void dump() {
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] != NULL) {
            printf("Objeto no endereço %p: valor = %d\n", (void*)heap[i], heap[i]->valor);
        }
    }
}
