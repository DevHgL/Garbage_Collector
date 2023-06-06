#include "collector.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_OBJECTS 100

static void* objects[MAX_OBJECTS];
static int num_objects = 0;

void* malloc2(size_t size) {
    void* ptr = malloc(size);
    if (ptr != NULL) {
        objects[num_objects++] = ptr;
    }
    return ptr;
}

void coleta() {
    for (int i = 0; i < num_objects; i++) {
        free(objects[i]);
    }
    num_objects = 0;
}

void atrib2(void** ptr, void* new_ptr) {
    for (int i = 0; i < num_objects; i++) {
        if (objects[i] == *ptr) {
            objects[i] = new_ptr;
            break;
        }
    }
    *ptr = new_ptr;
}

void dump() {
    printf("Objetos alocados: %d\n", num_objects);
    for (int i = 0; i < num_objects; i++) {
        printf("Endereco: %p\n", objects[i]);
    }
}
