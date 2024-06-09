#include "Habitat.h"

int getElemanSayisi(){
    const char *dosyaYolu = "./Veri.txt";
    int elemanSayisi = 0;

    FILE *dosya = fopen(dosyaYolu, "r");
    if (dosya == NULL) {
        perror("Dosya açma hatası");
        return -1;
    }

    char satir[1000];
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        char *token = strtok(satir, " ");
        while (token != NULL) {
            elemanSayisi++;
            token = strtok(NULL, " ");
        }
    }

    fclose(dosya);

    return elemanSayisi;
}
Habitat new_Habitat(){
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));

    this->habitatMatrisi = malloc(getElemanSayisi() * sizeof(HabitatElement));

    printf("Eleman Sayisi: %d", getElemanSayisi());

    this->diziyeYerlestir = &diziyeYerlestir;
    this->anlikMatrisGoster = &anlikMatrisGoster;
    this->Aksiyon = &Aksiyon;
    this->delete_Habitat = &delete_Habitat;
    return this;
}
void diziyeYerlestir(const Habitat this) {
    char* dosyaYolu = "./Veri.txt";
    int satirSayisi = 0;

    FILE* dosya = fopen(dosyaYolu, "r");
    if (dosya == NULL) {
        perror("Dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    int elemanSayisi = 0;
    char satir[1000];
    while (fgets(satir, 1000, dosya) != NULL) {
        char* eleman = strtok(satir, " ");
        int satirdaKac = 0;
        while (eleman != NULL) {
            int deger = atoi(eleman);
            if (1 <= deger && deger <= 9) {
                Bitki b = new_Bitki(deger, satirSayisi, satirdaKac);
                this->habitatMatrisi[elemanSayisi].type = BITKI_TYPE;
                this->habitatMatrisi[elemanSayisi].object = b;
                this->habitatMatrisi[elemanSayisi].superObject = b->super;
            } else if (10 <= deger && deger <= 20) {
                Bocek c = new_Bocek(deger, satirSayisi, satirdaKac);
                this->habitatMatrisi[elemanSayisi].type = BOCEK_TYPE;
                this->habitatMatrisi[elemanSayisi].object = c;
                this->habitatMatrisi[elemanSayisi].superObject = c->super;
            } else if (21 <= deger && deger <= 50) {
                Sinek s = new_Sinek(deger, satirSayisi, satirdaKac);
                this->habitatMatrisi[elemanSayisi].type = SINEK_TYPE;
                this->habitatMatrisi[elemanSayisi].object = s;
                this->habitatMatrisi[elemanSayisi].superObject = s->superBocek->super;
            } else if (51 <= deger && deger <= 99) {
                Pire p = new_Pire(deger, satirSayisi, satirdaKac);
                this->habitatMatrisi[elemanSayisi].type = PIRE_TYPE;
                this->habitatMatrisi[elemanSayisi].object = p;
                this->habitatMatrisi[elemanSayisi].superObject = p->superBocek->super;
            } else {
                BigX dead = new_BigX();
                this->habitatMatrisi[elemanSayisi].type = BIGX_TYPE;
                this->habitatMatrisi[elemanSayisi].object = dead;
                this->habitatMatrisi[elemanSayisi].superObject = dead->super;
            }
            eleman = strtok(NULL, " ");
            satirdaKac++;
            elemanSayisi++;
        }
        satirSayisi++;
    }

    fclose(dosya);
    this->habitatSatir = satirSayisi;
    this->habitatSutun = elemanSayisi / satirSayisi;
}
void anlikMatrisGoster(const Habitat this){
    for(int i = 0; i < this->habitatSatir; i++){
        for(int j = 0; j < this->habitatSutun; j++){
            int index = j + i * this->habitatSutun;
            printf("%c ", ((Canli) (this->habitatMatrisi[index].superObject))->getCanliTur((Canli) (this->habitatMatrisi[index].superObject)));
        }
        printf("\n");
    }
    printf("\n");
}
void Aksiyon(const Habitat this) {
    int i = 0;
    int m = 1;
    bool check;
    char* str;

    do {
        void* object = this->habitatMatrisi[i].object;
        void* superObject = this->habitatMatrisi[i].superObject;
        Canli asilCanli = (Canli)superObject;

        check = false;
        for (m; m < getElemanSayisi(); m++) {
            void* yedekObject = this->habitatMatrisi[m].object;
            void* yedekSuperObject = this->habitatMatrisi[m].superObject;
            Canli yedekCanli = (Canli)yedekSuperObject;

            if (asilCanli->canliYerMi(object, yedekCanli)) {

                yedekCanli->setCanliTur(yedekCanli, 'X');
                this->anlikMatrisGoster(this);
            } 
            else {
                asilCanli->setCanliTur(asilCanli, 'X');
                this->anlikMatrisGoster(this);
                i = m;
                m++;
                check = true;
                break;
            }
        }
    } while (check);
    void* superObject = this->habitatMatrisi[i].superObject;
    Canli asilCanli = (Canli)superObject;
    printf("%s", asilCanli->gorunum(asilCanli));
}
void delete_Habitat(const Habitat this){
    if(this == NULL) return;
    if(this->habitatMatrisi != NULL) {
        for(int i = 0; i < getElemanSayisi(); i++) {
            void* object = this->habitatMatrisi[i].object;
            if (this->habitatMatrisi[i].type == BITKI_TYPE) {
                //printf("Habitatin %d.si bitki", i);
                //char* str = ((Bitki) object)->super->gorunum(((Bitki) object)->super);
                //printf("%s\n\n", str);
                ((Bitki) object)->delete_Bitki((Bitki) object);
            } 
            else if (this->habitatMatrisi[i].type == BOCEK_TYPE) {
                //printf("Habitatin %d.si bocek", i);
                //char* str = ((Bocek) object)->super->gorunum(((Bocek) object)->super);
                //printf("%s\n\n", str);
                ((Bocek) object)->delete_Bocek((Bocek) object);
            } 
            else if (this->habitatMatrisi[i].type == SINEK_TYPE) {
                //printf("Habitatin %d.si sinek", i);
                //char* str = ((Sinek) object)->superBocek->super->gorunum(((Sinek) object)->superBocek->super);
                //printf("%s\n\n", str);
                ((Sinek) object)->delete_Sinek((Sinek) object);
            } 
            else if (this->habitatMatrisi[i].type == PIRE_TYPE) {
                //printf("Habitatin %d.si pire", i);
                //char* str = ((Pire) object)->superBocek->super->gorunum(((Pire) object)->superBocek->super);
                //printf("%s\n\n", str);
                ((Pire) object)->delete_Pire((Pire) object);
            } 
            else if (this->habitatMatrisi[i].type == BIGX_TYPE) {
                //char* str = ((BigX) object)->super->gorunum(((BigX) object)->super);
                //printf("%s\n\n", str);
                ((BigX) object)->delete_BigX((BigX) object);
            } 
            else {
                printf("Unrecognized object type: %d\n", this->habitatMatrisi[i].type);
            }
        }
        free(this->habitatMatrisi);
    }
    else{
        printf("Habitat bos!");
    }
    free(this);
}