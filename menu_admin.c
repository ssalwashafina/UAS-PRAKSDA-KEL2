#include "samsatq.h"

void tampilkanMenuAdmin(void) {
    printf("\n========================================\n");
    printf("              MENU ADMIN\n");
    printf("========================================\n");
    printf("1. Panggil Antrian\n");
    printf("2. Riwayat Layanan Hari Ini\n");
    printf("3. Laporan Statistik Waktu Tunggu\n");
    printf("0. Kembali\n");
    printf("========================================\n");
    printf("Pilihan Anda : ");
}

void jalankanMenuAdmin(void) {
    int pilihan;

    do {
        tampilkanMenuAdmin();
        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            printf("\nPilihan tidak valid!\n");
            continue;
        }

        switch (pilihan) {

            case 1: {
                int idLoket;

                printf("\n========================================\n");
                printf("           PILIH LOKET\n");
                printf("========================================\n");
                printf("1. Pajak Kendaraan\n");
                printf("2. Balik Nama Kendaraan\n");
                printf("3. Penerbitan STNK\n");
                printf("0. Kembali\n");
                printf("========================================\n");
                printf("Pilihan Anda : ");
                if (scanf("%d", &idLoket) != 1) {
                    while (getchar() != '\n');
                    printf("Pilihan tidak valid!\n");
                    break;
                }

                if (idLoket == 0) {
                    break;
                }

                if (idLoket < 1 || idLoket > 3) {
                    printf("Pilihan loket tidak valid!\n");
                    break;
                }

                panggilAntrian(idLoket);
                break;
            }

            case 2:
            printf("\n========================================\n");
            printf("       RIWAYAT LAYANAN HARI INI\n");
            printf("========================================\n");
            
            traversalRiwayat(headRiwayat);
            break;

            case 3:
            printf("\n========================================\n");
            printf("    LAPORAN STATISTIK WAKTU TUNGGU\n");
            printf("========================================\n");
            
            bubbleSortRiwayat(headRiwayat);
            traversalRiwayat(headRiwayat);
            break;

            case 0:
            printf("Kembali ke Menu Utama\n");
            break;

            default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);
}
