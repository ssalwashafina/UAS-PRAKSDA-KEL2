#include "samsatq.h"

void tampilkanMenuUser(void) {
    printf("\n========================================\n");
    printf("               MENU USER\n");
    printf("========================================\n");
    printf("1. Ambil Nomor Antrian\n");
    printf("2. Tampilkan Antrian Saat Ini\n");
    printf("3. Batalkan Antrian\n");
    printf("0. Kembali\n");
    printf("========================================\n");
    printf("Pilihan Anda : ");
}

void jalankanMenuUser(void) {
    int pilihan;

    do {
        tampilkanMenuUser();
        scanf("%d", &pilihan);

        switch (pilihan) {

            case 1:
            ambilNomorAntrian();
            break;
            
            case 2:
            printf("\n========================================\n");
            printf("             ANTRIAN SAAT INI\n");
            printf("========================================\n");
            printf("\n===== ANTRIAN PAJAK =====\n");
            tampilkanAntrian(&antrianLoket[0]);
            printf("\n===== ANTRIAN BALIK NAMA =====\n");
            tampilkanAntrian(&antrianLoket[1]);
            printf("\n===== ANTRIAN STNK =====\n");
            tampilkanAntrian(&antrianLoket[2]);
            break;

            case 3: {
                int loket;
                int nomor;
                
                printf("\n========================================\n");
                printf("          BATALKAN ANTRIAN\n");
                printf("========================================\n");
                printf("1. Pajak Kendaraan\n");
                printf("2. Balik Nama Kendaraan\n");
                printf("3. Penerbitan STNK\n");
                printf("0. Kembali\n");
                printf("========================================\n");
                printf("Pilihan Anda: ");
                scanf("%d", &loket);

                if (loket == 0) {
                    break;
                }

                if (loket < 1 || loket > 3) {
                    printf("Pilihan loket tidak valid!\n");
                    break;
                } 

                printf("Masukkan nomor antrian yang dibatalkan: ");
                scanf("%d", &nomor);
                batalAntrian(&antrianLoket[loket - 1], nomor);
                break;
            }

            case 0:
            printf("Kembali ke Menu Utama\n");
            break;

            default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);
}