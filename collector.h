#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

#include <stddef.h>

void* malloc2(size_t size);
void coleta();
void atrib2(void** ptr, void* ptr2);
void dump();

#endif  // GARBAGE_COLLECTOR_H