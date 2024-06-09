#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{
    Canli super;

    void (*delete_Bocek)(struct BOCEK*);
};

typedef struct BOCEK* Bocek;

Bocek new_Bocek(int, int, int);
Bocek new_BocekAlt(char, int, int, int);
bool bocekYerMi(const Bocek, const Canli);
void delete_Bocek(const Bocek);

#endif