#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

#include <stddef.h> // para a utilização do size-t

void* malloc2(size_t size);
void coleta();
void atrib2(void** ptrX, void* ptrY);
void dump();

#endif  // GARBAGE_COLLECTOR_H