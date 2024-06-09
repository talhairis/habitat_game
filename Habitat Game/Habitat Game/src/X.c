#include "X.h"

BigX new_BigX(){
    BigX this;
    this = (BigX)malloc(sizeof(struct X));

    this->super = new_Canli('X', 0, -1, -1);

    this->super->canliYerMi = &bigXYerMi;
    this->delete_BigX = &delete_BigX;
    return this;
}
bool bigXYerMi(const BigX this, const Canli sonraki){
    return false;
}
void delete_BigX(const BigX this){
    if(this == NULL) return;
    this->super->delete_Canli(this->super);
    free(this);
}