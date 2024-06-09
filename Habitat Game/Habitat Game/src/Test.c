#include "Habitat.h"

int main(){
    Habitat h = new_Habitat();
    h->diziyeYerlestir(h);
    printf("\n------------\nAnlik Matris Goster\n\n");
    //h->anlikMatrisGoster(h);
    printf("\nHerhangi bir tusa basin!\n");
    getchar();
    printf("\n------------\nAksiyon\n\n");
    h->Aksiyon(h);
    printf("\n------------\nHabitat Sil\n\n");
    h->delete_Habitat(h);
    printf("Habitat silindi!");
    printf("\n------------\n");
    return 0 ;
}