#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>






struct Sarki{

char sarki_adi[50];
char sanatci[50];
int sure;

struct Sarki *prew;
struct Sarki *next;



};

struct Sarki *baslangic=NULL;
struct Sarki *bitis=NULL;


void sarki_ekle(char *sarki_adi,char *sanatci,int sure);
void sarki_listele();
void sarki_sil(char *compname);
void sarki_cal(struct Sarki *current,int *yari_dolu);
void eylem_belirle(char eylem,struct Sarki **current,int *yari_dolu);
void loop(struct Sarki *current);


void sarki_ekle(char *sarki_adi,char *sanatci,int sure){

struct Sarki *yeni=(struct Sarki*)malloc(sizeof(struct Sarki));
strcpy(yeni->sarki_adi,sarki_adi);
strcpy(yeni->sanatci,sanatci);
yeni->sure=sure;
yeni->next=NULL;
yeni->prew=NULL;

if(baslangic==NULL)
{
    baslangic=yeni;
    bitis=yeni;
    baslangic->next = baslangic;
    baslangic->prew = baslangic;
}
else{
    bitis->next=yeni;
    yeni->prew=bitis;
    yeni->next=baslangic;
    baslangic->prew=yeni;
    bitis=yeni;
}


}

void sarki_listele(){

if(baslangic==NULL)
{
    printf("sarki yok listede");
    return;
}

struct Sarki *temp=baslangic;
int sayac=1;

printf("------------SARKI LISTEMIZ------------\n");

do{
    printf("%d. %s ---- %s ---- %d\n",sayac,temp->sarki_adi,temp->sanatci,temp->sure);

    temp=temp->next;
    sayac++;



}while(temp!=baslangic);


}

void sarki_sil(char *compname){


    if(baslangic==NULL)
{
    printf("sarki yok listede");
    return;
}

struct Sarki *sil=baslangic;

do{

    if(strcmp(compname,sil->sarki_adi)==0)
    {

        break;
    }

    sil=sil->next;


}while(sil!=baslangic);

if(baslangic==sil&&baslangic==bitis)
{
    baslangic=NULL;
    bitis=NULL;


}
else if(sil==baslangic){
    baslangic=baslangic->next;
    baslangic->prew=bitis;
    bitis->next=baslangic;


}
else if(sil==bitis){
    bitis=bitis->prew;
    bitis->next=baslangic;
    baslangic->prew=bitis;

}
else{
    sil->next->prew=sil->prew;
    sil->prew->next=sil->next;

}
printf("\nsarki silme islemi tamamlandi.\n");
free(sil);


}
void eylem_belirle(char eylem,struct Sarki **current,int *yari_dolu)
{




    switch(eylem){
    case 'n':
    case 'N':
        *current=(*current)->next;
        sarki_cal(*current,yari_dolu);

        break;
    case 'p':
    case 'P':
        if(*yari_dolu==0)
        {
            *current=(*current)->prew;
            sarki_cal(*current,yari_dolu);
        }
        else{
            sarki_cal(*current,yari_dolu);
        }
        break;

    case 'l':
    case 'L':
        loop(*current);

        break;

    case 'q':
    case 'Q':

        exit(0);
        break;
    }


}

void sarki_cal(struct Sarki *current,int *yari_dolu){

   for (int i = 1; i <= current->sure; i++) {
    printf("\r%s - %s [%d/%d sn]", current->sarki_adi, current->sanatci, i, current->sure);
    fflush(stdout);
    if(i>=current->sure/2)
    {
        *yari_dolu=1;
    }
    else{
        *yari_dolu=0;
    }
    Sleep(1000);

    if (_kbhit()) {
        char c = getch();
        if (c == 'n' || c == 'p' || c == 'l' || c == 'q') {

                eylem_belirle(c,&current,yari_dolu);


        }
    }
}
}

void loop(struct Sarki *current){

    struct Sarki *temp=current;
printf("\nLoop aktif.\n");
while(1){

    current=temp;
    for (int i = 1; i <= current->sure; i++) {
    printf("\r%s - %s [%d/%d sn] ", current->sarki_adi, current->sanatci, i, current->sure);
    fflush(stdout);
    Sleep(1000);
    if (_kbhit()) {
        char c = getch();

        if(c=='l')
        {
            printf("\nloop kapatildi.\n");
            return;


        }
        else if(c=='q')
        {
            exit(0);
        }
        else if(c=='p'||c=='n')
        {
            break;
        }
        }

    }
}

}







int main()
{
    char name[50];
    char sanatci[50];
    int sure;
    int secim;
    char compname[50];
    do{
        printf("lutfen bir secim yapiniz:\n 1-sarkiekle\n2-sarki listele\n3-sarki sil\n4-listeyi tamamla.");
            scanf("%d",&secim);
        switch(secim){
        case 1:
                printf("eklemek istediginiz sarkinin adini ,sanatci adini,suresini sirayla giriniz:\n");


            printf("sarki adi:\n");
            getchar();
            fgets(name,sizeof(name),stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("sanatci adi:\n");

            fgets(sanatci,sizeof(sanatci),stdin);
            sanatci[strcspn(sanatci, "\n")] = '\0';

            printf("sarki suresi:\n");
            scanf("%d",&sure);
            sarki_ekle(name,sanatci,sure);

            break;
        case 2:
            sarki_listele();

            break;
        case 3:
            printf("listeden cikarilacak sarkinin adini giriniz.");
            getchar();
            fgets(compname,sizeof(compname),stdin);
            compname[strcspn(compname, "\n")] = '\0';



            sarki_sil(compname);

            break;


        case 4:
            printf("listeniz hazir.\n");


            break;



        default:
            printf("yanlis tuslama yaptiniz:\n");
            break;



        }

    }while(secim!=4);


int caliyormu;
struct Sarki *current=baslangic;
int yari_dolu=0;
while(1){
    printf("listenin calmaya baslamasi icin 1e program sonlanmasi icin 0a basin.\n");
scanf("%d",&caliyormu);

if(caliyormu!=0&&caliyormu!=1)
{
    printf("yanlis tuslama yaptiniz tekrar deneyiniz.\n");
}
else if(caliyormu==1)
{

    printf("\nsarki calma islemi basliyor sonraki sarki icin n ye onceki sarki icin p ye loop icin l ye cikmak icin q ya basiniz.\n");

    sarki_cal(current,&yari_dolu);
}
else{
    printf("sarki listesi durduruldu.\n");
    break;
}


}




    return 0;
}
