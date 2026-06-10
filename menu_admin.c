#include "samsatq.h"

void tampilkanMenuAdmin(void) {
    printf("\n========================================\n");
    printf("              MENU ADMIN\n");
    printf("========================================\n");
    printf("1. Panggil Antrian\n");
    printf("2. Riwayat Layanan Hari Ini\n");
    printf("3. Laporan Statistik Waktu Tunggu\n");
    printf("4. Cari Riwayat\n");
    printf("5. Ekspor Data ke TXT\n");
    printf("6. Cari Data Antrian\n");
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

            case 4: {
                int nomor;
                printf("\n========================================\n");
                printf("     CARI RIWAYAT VIA BST\n");
                printf("========================================\n");
                printf("Masukkan Nomor Antrian: ");

                if (scanf("%d", &nomor) != 1) {
                    while (getchar() != '\n');
                    printf("Input tidak valid!\n");
                    break;
                }
                
                NodeBST *hasil = cariNomorBST(rootBST, nomor);
                if (hasil == NULL) {
                    printf("Nomor antrian tidak ditemukan di riwayat.\n");
                } else {
                    printf("\n===== DATA DITEMUKAN (BST) =====\n");
                    printf("Nomor Antrian : %d\n", hasil->data.nomorAntrian);
                    printf("Nama          : %s\n", hasil->data.nama);
                    printf("NIK           : %s\n", hasil->data.nik);
                    printf("Waktu Tunggu  : %d menit\n", hasil->data.waktuTunggu);
                    printf("================================\n");
                }
                break;
            }
            
            case 5:
            eksporDataKeTXT();
            break;

            case 6: {
                int modeNIK;
                char kunci[50];
                
                printf("\n========================================\n");
                printf("         CARI DATA ANTRIAN\n");
                printf("========================================\n");
                printf("1. Cari berdasarkan NIK\n");
                printf("2. Cari berdasarkan Nama\n");
                printf("========================================\n");
                printf("Pilihan Anda: ");

                if (scanf("%d", &modeNIK) != 1) {
                    while (getchar() != '\n');
                    printf("Input tidak valid!\n");
                    break;
                }
                getchar();
                
                if (modeNIK == 1) {
                    printf("Masukkan NIK: ");
                    fgets(kunci, sizeof(kunci), stdin);
                    kunci[strcspn(kunci, "\n")] = '\0';
                    cariWargaBinarySearch(0, kunci, 1);
                } else if (modeNIK == 2) {
                    printf("Masukkan Nama: ");
                    fgets(kunci, sizeof(kunci), stdin);
                    kunci[strcspn(kunci, "\n")] = '\0';
                    cariWargaBinarySearch(0, kunci, 0);
                } else {
                    printf("Pilihan tidak valid!\n");
                }
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