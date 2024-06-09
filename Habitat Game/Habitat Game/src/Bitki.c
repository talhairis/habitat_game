#include "Bitki.h"

Bitki new_Bitki(int canliID, int i, int j){
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));

    this->super = new_Canli('B', canliID, i, j);

    this->super->canliYerMi = &bitkiYerMi;
    this->delete_Bitki = &delete_Bitki;
    return this;
}
bool bitkiYerMi(const Bitki this, const Canli sonraki){
    if((sonraki->getCanliTur(sonraki)) == 'C') return false;
	else if((sonraki->getCanliTur(sonraki)) == 'S') return true;
	else if((sonraki->getCanliTur(sonraki)) == 'P') return true;
	else if((sonraki->getCanliTur(sonraki)) == 'B') {
		if((this->super->getCanliID(this->super)) > (sonraki->getCanliID(sonraki))) return true;
		else if((this->super->getI(this->super)) > (sonraki->getI(sonraki))) return true;
		else if((this->super->getI(this->super)) == (sonraki->getI(sonraki)) && (this->super->getJ(this->super)) > (sonraki->getJ(sonraki))) return true;
		else return false;
	}
	else return true;
}
void delete_Bitki(const Bitki this){
    if(this == NULL) return;
    this->super->delete_Canli(this->super);
    free(this);
}