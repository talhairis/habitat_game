#include "Sinek.h"

Sinek new_Sinek(int canliID, int i, int j){
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));

    this->superBocek = new_BocekAlt('S', canliID, i, j);

    this->superBocek->super->canliYerMi = &sinekYerMi;
    this->delete_Sinek = &delete_Sinek;
    return this;
}
bool sinekYerMi(const Sinek this, const Canli sonraki){
    if((sonraki->getCanliTur(sonraki)) == 'B') return false;
	else if((sonraki->getCanliTur(sonraki)) == 'C') return true;
	else if((sonraki->getCanliTur(sonraki)) == 'P') return true;
	else if((sonraki->getCanliTur(sonraki)) == 'S') {
		if((this->superBocek->super->getCanliID(this->superBocek->super)) > (sonraki->getCanliID(sonraki))) return true;
		else if((this->superBocek->super->getI(this->superBocek->super)) > (sonraki->getI(sonraki))) return true;
		else if((this->superBocek->super->getI(this->superBocek->super)) == (sonraki->getI(sonraki)) && (this->superBocek->super->getJ(this->superBocek->super)) > (sonraki->getJ(sonraki))) return true;
		else return false;
	}
	else return true;
}
void delete_Sinek(const Sinek this){
    if(this == NULL) return;
    this->superBocek->delete_Bocek(this->superBocek);
    free(this);
}