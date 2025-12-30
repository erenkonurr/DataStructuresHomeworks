#include <stdio.h>

#define MAX 10

int main() {
    int dizi[MAX];
    int n = 0;
    int secim, i, eleman, index;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1 - Eleman Ekle\n");
        printf("2 - Eleman Sil\n");
        printf("3 - Diziyi Yazdir\n");
        printf("0 - Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {

        case 1:
            if (n == MAX) {
                printf("Dizi dolu!\n");
                break;
            }

            printf("Eklenecek eleman: ");
            scanf("%d", &eleman);

            printf("Eklenecek index (0-%d): ", n);
            scanf("%d", &index);

            if (index < 0 || index > n) {
                printf("Gecersiz index!\n");
                break;
            }

            for (i = n; i > index; i--) {
                dizi[i] = dizi[i - 1];
            }

            dizi[index] = eleman;
            n++;

            printf("Eleman eklendi.\n");
            break;

        case 2:
            if (n == 0) {
                printf("Dizi bos!\n");
                break;
            }

            printf("Silinecek index (0-%d): ", n - 1);
            scanf("%d", &index);

            if (index < 0 || index >= n) {
                printf("Gecersiz index!\n");
                break;
            }

            for (i = index; i < n - 1; i++) {
                dizi[i] = dizi[i + 1];
            }

            n--;
            printf("Eleman silindi.\n");
            break;

        case 3:
            if (n == 0) {
                printf("Dizi bos.\n");
            } else {
                printf("Dizi: ");
                for (i = 0; i < n; i++)
                    printf("%d ", dizi[i]);
                printf("\n");
            }
            break;

        case 0:
            printf("Programdan cikiliyor...\n");
            return 0;

        default:
            printf("Gecersiz secim!\n");
        }
    }

    return 0;
}
