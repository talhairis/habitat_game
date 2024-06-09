#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef enum {
    false = 0,
    true = 1
} bool;

struct CANLI{
    char canliTur;
    int canliID;
    int i,j;

    char (*getCanliTur)(struct CANLI*);
    void (*setCanliTur)(struct CANLI*, char);
    int (*getCanliID)(struct CANLI*);
    int (*getI)(struct CANLI*);
    int (*getJ)(struct CANLI*);
    bool (*canliYerMi)();//abstarct
    char* (*gorunum)(struct CANLI*);
    void (*delete_Canli)(struct CANLI*);
};

typedef struct CANLI* Canli;

Canli new_Canli(char, int, int, int);
char getCanliTur(const Canli);
void setCanliTur(const Canli, char);
int getCanliID(const Canli);
int getI(const Canli);
int getJ(const Canli);
char* gorunum(const Canli);
void delete_Canli(const Canli);

#endif