#include "samsatq.h"

int main() {
    int pilihan;

    inisialisasiSistem();

    do {
        printf("\n========================================\n");
        printf("         SISTEM ANTRIAN SAMSAT\n");
        printf("========================================\n");
        printf("1. Menu User\n");
        printf("2. Menu Admin\n");
        printf("0. Keluar\n");
        printf("========================================\n");
        printf("Pilihan Anda : ");
        
         if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            printf("\nPilihan tidak valid!\n");
            continue;
        }

        switch (pilihan) {
            case 1:
                jalankanMenuUser();
                break;

            case 2:
                jalankanMenuAdmin();
                break;

            case 0:
                printf("\nTerima kasih telah menggunakan SamsatQ!\n");
                break;

            default:
                printf("\nPilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    bebaskanMemori();

    return 0;
}