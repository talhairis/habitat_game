#include "Canli.h"

int intToStringLength(int deger){
    char degerStr[5];
    sprintf(degerStr, "%d", deger);
    int uzunluk = strlen(degerStr);
    return uzunluk;
}
Canli new_Canli(char canliTur, int canliID, int i, int j){
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));

    this->canliTur = canliTur;
    this->canliID = canliID;
    this->i = i;
    this->j = j;

    this->getCanliTur = &getCanliTur;
    this->setCanliTur = &setCanliTur;
    this->getCanliID = &getCanliID;
    this->getI = &getI;
    this->getJ = &getJ;
    this->gorunum = &gorunum;
    this->delete_Canli = &delete_Canli;
    return this;
}
char getCanliTur(const Canli this){
    return this->canliTur;
}
void setCanliTur(const Canli this, char newTur){
    this->canliTur = newTur;
}
int getCanliID(const Canli this){
    return this->canliID;
}
int getI(const Canli this){
    return this->i;
}
int getJ(const Canli this){
    return this->j;
}
char* gorunum(const Canli this){
    int toplamUzunluk = 18;
    toplamUzunluk += intToStringLength(this->getI(this));
    toplamUzunluk += intToStringLength(this->getJ(this));
    char *str = (char*)malloc(sizeof(char) * toplamUzunluk + 1);

    sprintf(str, "\nKazanan: %c :  (%d,%d)", this->getCanliTur(this), this->getI(this), this->getJ(this));
    //printf("%s\n", str);
    return str;
}
void delete_Canli(const Canli this){
    if(this == NULL) return;
    free(this);
}