#ifndef X_H
#define X_H

#include "Canli.h"

struct X{
    Canli super;

    void (*delete_BigX)(struct X*);
};

typedef struct X* BigX;

BigX new_BigX();
bool bigXYerMi(const BigX, const Canli);
void delete_BigX(const BigX);

#endif