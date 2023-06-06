#include "libgarbage.h"

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
        objects[i] = NULL;
    }
    num_objects = 0;
}

void atrib2(void** ptr, void* value) {
    coleta();
    *ptr = value;
}

void dump() {
    printf("Dumping objects:\n");
    for (int i = 0; i < num_objects; i++) {
        printf("Object %d: %p\n", i, objects[i]);
    }
}
