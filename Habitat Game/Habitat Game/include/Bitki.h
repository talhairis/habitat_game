#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{
    Canli super;

    void (*delete_Bitki)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Bitki new_Bitki(int, int, int);
bool bitkiYerMi(const Bitki, const Canli);
void delete_Bitki(const Bitki);

#endif