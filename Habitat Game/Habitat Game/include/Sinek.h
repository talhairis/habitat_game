#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK{
    Bocek superBocek;

    void (*delete_Sinek)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Sinek new_Sinek(int, int, int);
bool sinekYerMi(const Sinek, const Canli);
void delete_Sinek(const Sinek);

#endif