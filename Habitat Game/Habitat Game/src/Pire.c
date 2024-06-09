#include "Pire.h"

Pire new_Pire(int canliID, int i, int j){
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));

    this->superBocek = new_BocekAlt('P', canliID, i, j);

    this->superBocek->super->canliYerMi = &pireYerMi;
    this->delete_Pire = &delete_Pire;
    return this;
}
bool pireYerMi(const Pire this, const Canli sonraki){
    if((sonraki->getCanliTur(sonraki)) == 'B' || (sonraki->getCanliTur(sonraki)) == 'C' || (sonraki->getCanliTur(sonraki)) == 'S') return false;
	else if((sonraki->getCanliTur(sonraki)) == 'P') {
		if((this->superBocek->super->getCanliID(this->superBocek->super)) > (sonraki->getCanliID(sonraki))) return true;
		else if((this->superBocek->super->getI(this->superBocek->super)) > (sonraki->getI(sonraki))) return true;
		else if((this->superBocek->super->getI(this->superBocek->super)) == (sonraki->getI(sonraki)) && (this->superBocek->super->getJ(this->superBocek->super)) > (sonraki->getJ(sonraki))) return true;
		else return false;
	}
	else return true;
}
void delete_Pire(const Pire this){
    if(this == NULL) return;
    this->superBocek->delete_Bocek(this->superBocek);
    free(this);
}