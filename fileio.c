#include "samsatq.h"

void eksporDataKeTXT(void) {
    FILE *file;
    int i;
    NodeQueue *cur;
    NodeRiwayat *curR;

    file = fopen("data_samsatq.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk ekspor!\n");
        return;
    }
    
    fprintf(file, "NOMOR_GLOBAL %d\n", nomorAntrianGlobal);
    
    for (i = 0; i < JUMLAH_LOKET; i++) {
        cur = antrianLoket[i].front;
        while (cur != NULL) {
            fprintf(file, "ANTRIAN %d %d %s %d\n",
                cur->data.nomorAntrian,
                cur->data.jenisLoket,
                cur->data.nik,
                cur->data.waktuTunggu);

            fprintf(file, "NAMA %d %s\n",
                cur->data.nomorAntrian,
                cur->data.nama);
            cur = cur->next;
        }
    }

    curR = headRiwayat;
    while (curR != NULL) {
        fprintf(file, "RIWAYAT %d %d %s %d\n",
            curR->data.nomorAntrian,
            curR->data.jenisLoket,
            curR->data.nik,
            curR->data.waktuTunggu);
        fprintf(file, "NAMAR %d %s\n",
            curR->data.nomorAntrian,
            curR->data.nama);
        curR = curR->next;
    }

    fclose(file);
    printf("Data berhasil diekspor ke data_samsatq.txt\n");
}

void imporDataDariTXT(void) {
    FILE *file;
    char baris[300];
    char tag[20];

    file = fopen("data_samsatq.txt", "r");
    if (file == NULL) {
        return;
    }

    Warga tempAntrian[200];
    Warga tempRiwayat[200];
    int jumlahAntrian = 0, jumlahRiwayat = 0;
    int idx;

    while (fgets(baris, sizeof(baris), file)) {
        baris[strcspn(baris, "\n")] = '\0';

        sscanf(baris, "%s", tag);

        if (strcmp(tag, "NOMOR_GLOBAL") == 0) {
            sscanf(baris, "%s %d", tag, &nomorAntrianGlobal);

        } else if (strcmp(tag, "ANTRIAN") == 0) {
            Warga w = {0};
            sscanf(baris, "%s %d %d %s %d",
                tag,
                &w.nomorAntrian,
                &w.jenisLoket,
                w.nik,
                &w.waktuTunggu);
            tempAntrian[jumlahAntrian++] = w;

        } else if (strcmp(tag, "NAMA") == 0) {
            int nomor;
            char nama[50];
            sscanf(baris, "%s %d", tag, &nomor);
            char *posNama = baris;
            int spasi = 0;
            while (*posNama && spasi < 2) {
                if (*posNama == ' ') spasi++;
                posNama++;
            }
            strncpy(nama, posNama, sizeof(nama) - 1);
            /* Cocokkan ke tempAntrian */
            for (idx = 0; idx < jumlahAntrian; idx++) {
                if (tempAntrian[idx].nomorAntrian == nomor) {
                    strncpy(tempAntrian[idx].nama, nama,
                            sizeof(tempAntrian[idx].nama) - 1);
                    break;
                }
            }

        } else if (strcmp(tag, "RIWAYAT") == 0) {
            Warga w = {0};
            sscanf(baris, "%s %d %d %s %d",
                tag,
                &w.nomorAntrian,
                &w.jenisLoket,
                w.nik,
                &w.waktuTunggu);
            tempRiwayat[jumlahRiwayat++] = w;

        } else if (strcmp(tag, "NAMAR") == 0) {
            int nomor;
            char nama[50];
            sscanf(baris, "%s %d", tag, &nomor);
            char *posNama = baris;
            int spasi = 0;
            while (*posNama && spasi < 2) {
                if (*posNama == ' ') spasi++;
                posNama++;
            }
            strncpy(nama, posNama, sizeof(nama) - 1);
            for (idx = 0; idx < jumlahRiwayat; idx++) {
                if (tempRiwayat[idx].nomorAntrian == nomor) {
                    strncpy(tempRiwayat[idx].nama, nama,
                            sizeof(tempRiwayat[idx].nama) - 1);
                    break;
                }
            }
        }
    }

    fclose(file);

    for (idx = 0; idx < jumlahAntrian; idx++) {
        int loketIdx = tempAntrian[idx].jenisLoket - 1;
        if (loketIdx >= 0 && loketIdx < JUMLAH_LOKET) {
            enqueue(&antrianLoket[loketIdx], tempAntrian[idx]);
        }
    }

    for (idx = 0; idx < jumlahRiwayat; idx++) {
        tambahRiwayat(tempRiwayat[idx]);
        daftarLoket[tempRiwayat[idx].jenisLoket - 1].totalDilayani++;
    }
}