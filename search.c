#include "samsatq.h"
#include <string.h>

static int salinKeArray(Queue *queue, Warga *arr, int maks) {
    NodeQueue *cur = queue->front;
    int i = 0;
    while (cur != NULL && i < maks) {
        arr[i++] = cur->data;
        cur = cur->next;
    }
    return i;
}

static void sortArrayByNIK(Warga *arr, int n) {
    int i, j;
    Warga kunci;
    for (i = 1; i < n; i++) {
        kunci = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j].nik, kunci.nik) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

static void sortArrayByNama(Warga *arr, int n) {
    int i, j;
    Warga kunci;
    for (i = 1; i < n; i++) {
        kunci = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j].nama, kunci.nama) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

static int binarySearchNIK(Warga *arr, int n, char *nik) {
    int kiri = 0, kanan = n - 1, tengah, cmp;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        cmp = strcmp(arr[tengah].nik, nik);
        if (cmp == 0) return tengah;
        if (cmp < 0)  kiri  = tengah + 1;
        else          kanan = tengah - 1;
    }
    return -1;
}

static int binarySearchNama(Warga *arr, int n, char *nama) {
    int kiri = 0, kanan = n - 1, tengah, cmp;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        cmp = strcmp(arr[tengah].nama, nama);
        if (cmp == 0) return tengah;
        if (cmp < 0)  kiri  = tengah + 1;
        else          kanan = tengah - 1;
    }
    return -1;
}

void cariWargaBinarySearch(int idLoket, char *kunci, int modeNIK) {
    Warga arr[200];
    int n = 0, hasil, i, mulai, selesai;

    if (idLoket == 0) {
        mulai  = 0;
        selesai = JUMLAH_LOKET;
    } else {
        mulai  = idLoket - 1;
        selesai = idLoket;
    }

    for (i = mulai; i < selesai; i++) {
        n += salinKeArray(&antrianLoket[i], arr + n, 200 - n);
    }

    if (n == 0) {
        printf("Semua antrian kosong.\n");
        return;
    }

    if (modeNIK) {
        sortArrayByNIK(arr, n);
        hasil = binarySearchNIK(arr, n, kunci);
    } else {
        sortArrayByNama(arr, n);
        hasil = binarySearchNama(arr, n, kunci);
    }

    if (hasil == -1) {
        printf("Data tidak ditemukan.\n");
        return;
    }

    printf("\n===== DATA DITEMUKAN =====\n");
    printf("Nomor Antrian : %d\n", arr[hasil].nomorAntrian);
    printf("Nama          : %s\n", arr[hasil].nama);
    printf("NIK           : %s\n", arr[hasil].nik);
    printf("Estimasi      : %d menit\n", arr[hasil].waktuTunggu);

    switch (arr[hasil].jenisLoket) {
        case LOKET_PAJAK:
            printf("Loket         : Pajak Kendaraan\n");
            break;
        case LOKET_BALIK_NAMA:
            printf("Loket         : Balik Nama Kendaraan\n");
            break;
        case LOKET_STNK:
            printf("Loket         : Penerbitan STNK\n");
            break;
    }

    printf("==========================\n");
}