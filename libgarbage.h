#ifndef LIBGARBAGE_H
#define LIBGARBAGE_H

#include <stdlib.h>

void* malloc2(size_t size);
void coleta();
void atrib2(void** ptr, void* value);
void dump();

#endif  // LIBGARBAGE_H
