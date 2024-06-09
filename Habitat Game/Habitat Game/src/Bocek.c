#include "Bocek.h"

Bocek new_Bocek(int canliID, int i, int j){
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));

    this->super = new_Canli('C', canliID, i, j);

    this->super->canliYerMi = &bocekYerMi;
    this->delete_Bocek = &delete_Bocek;
    return this;
}
Bocek new_BocekAlt(char canliTur, int canliID, int i, int j){
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));

    this->super = new_Canli(canliTur, canliID, i, j);

    this->delete_Bocek = &delete_Bocek;
    return this;
}
bool bocekYerMi(const Bocek this, const Canli sonraki){
    if((sonraki->getCanliTur(sonraki)) == 'S') return false;
	else if((sonraki->getCanliTur(sonraki)) == 'B') return true;
	else if((sonraki->getCanliTur(sonraki)) == 'P') return true;
	else if((sonraki->getCanliTur(sonraki)) == 'C') {
		if((this->super->getCanliID(this->super)) > (sonraki->getCanliID(sonraki))) return true;
		else if((this->super->getI(this->super)) > (sonraki->getI(sonraki))) return true;
		else if((this->super->getI(this->super)) == (sonraki->getI(sonraki)) && (this->super->getJ(this->super)) > (sonraki->getJ(sonraki))) return true;
		else return false;
	}
	else return true;
}
void delete_Bocek(const Bocek this){
    if(this == NULL) return;
    this->super->delete_Canli(this->super);
    free(this);
}