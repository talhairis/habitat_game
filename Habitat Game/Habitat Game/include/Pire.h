#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE{
    Bocek superBocek;

    void (*delete_Pire)(struct PIRE*);
};

typedef struct PIRE* Pire;

Pire new_Pire(int, int, int);
bool pireYerMi(const Pire, const Canli);
void delete_Pire(const Pire);

#endif