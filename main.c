#include <stdio.h>
#include "libgarbage.h"

int main() {
    int* ptr1 = malloc2(sizeof(int));
    int* ptr2 = malloc2(sizeof(int));
    
    atrib2((void**)&ptr1, NULL);
    atrib2((void**)&ptr2, NULL);
    
    dump();
    
    coleta();
    
    dump();
    
    return 0;
}
