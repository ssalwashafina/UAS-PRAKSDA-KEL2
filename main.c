#include "samsatq.h"
int main () {
    int pilihan;

    do{
        printf("\n========================================\n");
        printf("          SISTEM ANTRIAN SAMSAT             ");
        printf("\n========================================\n");
        printf("1. Ambil Nomor Antrian\n");
        printf("2. Panggil Antrian Berikutnya\n");
        printf("3. Tampilkan Antrian Saat Ini\n");
        printf("4. Riwayat Layanan Hari Ini\n");
        printf("5. Laporan Statistik Waktu Tunggu\n");
        printf("6. Batalkan Antrian\n");
        printf("0. Keluar\n");
        printf("========================================\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            printf("\nMENU AMBIL NOMOR ANTRIAN\n");
            int layanan;

            printf("\n=========================================\n");
            printf("           PILIH JENIS LAYANAN              \n");
            printf("=========================================\n");
            printf("1. Loket Pajak Kendaraan\n");
            printf("2. Loket Balik Nama Kendaraan\n");
            printf("3. Loket Penerbitan STNK\n");
            printf("0. Kembali\n");
            printf("=========================================\n");
            printf("Pilihan Anda: ");
            scanf("%d", &layanan);

            break;

            case 2:
            printf("\nMENU PANGGIL ANTRIAN BERIKUTNYA\n");
            break;

            case 3:
            printf("\nMENU TAMPILKAN ANTRIAN SAAT INI\n");
            break;

            case 4:
            printf("\nMENU RIWAYAT LAYANAN HARI INI\n");
            break;

            case 5:
            printf("\nMENU LAPORAN STATISTIK WAKTU TUNGGU\n");
            break;

            case 6:
            printf("\nMENU BATALKAN ANTRIAN\n");
            break;

            case 0:
            printf("Terima Kasih Telah Menggunakan SamsatQ!\n");
            break;

            default:
            printf("Pilihan tidak valid. Silahkan coba lagi!\n");
        }


        } while (pilihan != 0);

        return 0;
}

