#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

#include <stddef.h>

typedef struct memoria {
    int contagemReferencia;
    void *endereco;
    struct memoria *proximo;
} Heap;

extern Heap *listaMemoria; // Vetor do objeto Heap

void *malloc2(size_t tamanho);
void coleta();
void atrib2(void **destino, void *origem);
void dump();

#endif  // GARBAGE_COLLECTOR_H
