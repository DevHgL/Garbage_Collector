#ifndef COLETOR_H
#define COLETOR_H

typedef struct {
    int valor;
    int marcado;
} Objeto;

Objeto* malloc2(int valor);
void coleta();
void atrib2(Objeto* obj1, Objeto* obj2);
void dump();

#endif
