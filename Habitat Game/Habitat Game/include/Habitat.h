#ifndef HABITAT_H
#define HABITAT_H

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "X.h"

typedef enum {
    BITKI_TYPE,
    BOCEK_TYPE,
    SINEK_TYPE,
    PIRE_TYPE,
    BIGX_TYPE,
    HABITAT_ELEMENT_TYPE_COUNT
} HabitatElementType;

typedef struct {
    HabitatElementType type;
    void* object;
    void* superObject;
} HabitatElement;

struct HABITAT{
    HabitatElement* habitatMatrisi;
    int habitatSatir, habitatSutun;

    void (*diziyeYerlestir)(struct HABITAT*);
    void (*anlikMatrisGoster)(struct HABITAT*);
    void (*Aksiyon)(struct HABITAT*);
    void (*delete_Habitat)(struct HABITAT*);
};

typedef struct HABITAT* Habitat;

Habitat new_Habitat();
void diziyeYerlestir(const Habitat);
void anlikMatrisGoster(const Habitat);
void Aksiyon(const Habitat);
void delete_Habitat(const Habitat);

#endif