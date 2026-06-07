#include "samsatq.h"

Queue antrianLoket[JUMLAH_LOKET];
Loket daftarLoket[JUMLAH_LOKET];
NodeRiwayat *headRiwayat = NULL;
int nomorAntrianGlobal = 1;

void inisialisasiSistem(void) {
    int i;
    for (i = 0; i < JUMLAH_LOKET; i++) {
        antrianLoket[i].front  = NULL;
        antrianLoket[i].rear   = NULL;
        antrianLoket[i].jumlah = 0;
    }
 
    daftarLoket[0].idLoket       = LOKET_PAJAK;
    strcpy(daftarLoket[0].namaLoket, "Loket Pajak Kendaraan");
    daftarLoket[0].statusTersedia = 1;
    daftarLoket[0].totalDilayani  = 0;
 
    daftarLoket[1].idLoket       = LOKET_BALIK_NAMA;
    strcpy(daftarLoket[1].namaLoket, "Loket Balik Nama");
    daftarLoket[1].statusTersedia = 1;
    daftarLoket[1].totalDilayani  = 0;
 
    daftarLoket[2].idLoket       = LOKET_STNK;
    strcpy(daftarLoket[2].namaLoket, "Loket Penerbitan STNK");
    daftarLoket[2].statusTersedia = 1;
    daftarLoket[2].totalDilayani  = 0;
 
    headRiwayat        = NULL;
    nomorAntrianGlobal = 1;
}

int isQueueEmpty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, Warga warga) {
    NodeQueue *buatNode;
    buatNode = (NodeQueue*) malloc(sizeof(NodeQueue));

    if (buatNode == NULL) {
        printf("Gagal Mengalokasikan Memori!\n");
        return;
    }

    buatNode->data = warga;
    buatNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = buatNode;
        queue->rear = buatNode;
    } else {
        queue->rear->next = buatNode;
        queue->rear = buatNode;
    }

    queue->jumlah++;
}

Warga dequeue(Queue *queue) {
    Warga wargaKosong = {0};

    if (isQueueEmpty(queue)) {
        printf("Antrian Kosong!\n");
        return wargaKosong;
    }

    NodeQueue *temp = queue->front;
    Warga warga = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->jumlah--;
    return warga;
}

int hitungEstimasi(int idLoket, int posisi) {

    switch (idLoket) {
        case LOKET_PAJAK:
        return posisi * ESTIMASI_PAJAK;

        case LOKET_BALIK_NAMA:
        return posisi * ESTIMASI_BALIK_NAMA;

        case LOKET_STNK:
        return posisi * ESTIMASI_STNK;

        default:
        return 0;
    }
}

void ambilNomorAntrian(void) {
    Warga warga;
    int valid, i;

    printf("\n========================================\n");
    printf("            AMBIL NOMOR ANTRIAN\n");
    printf("========================================\n");
    printf("1. Pajak Kendaraan\n");
    printf("2. Balik Nama Kendaraan\n");
    printf("3. Penerbitan STNK\n");
    printf("0. Kembali\n");
    printf("========================================\n");
    printf("Pilihan Anda : ");
    scanf("%d", &warga.jenisLoket);

    if (warga.jenisLoket == 0) {
        return;
    }

    if (warga.jenisLoket < 1 || warga.jenisLoket > 3) {
        printf("Pilihan Loket Tidak Valid!\n");
        return;
    }

    getchar(); 

    printf("Masukkan Nama Lengkap: ");
    fgets(warga.nama, sizeof(warga.nama), stdin);
    warga.nama[strcspn(warga.nama, "\n")] = '\0';

    do {
        valid = 1;

        printf("Masukkan NIK (16 Digit): ");
        fgets(warga.nik, sizeof(warga.nik), stdin);
        warga.nik[strcspn(warga.nik, "\n")] = '\0';

        if (strlen(warga.nik) != 16) {
            valid = 0;
        } else {
            for (i = 0; i < 16; i++) {
                if (warga.nik[i] < '0' || warga.nik[i] > '9') {
                    valid = 0;
                    break;
                }
            }
        }

        if (!valid) {
            printf("NIK Harus Terdiri dari 16 Digit Angka!\n");
        }
    } while (!valid);

    warga.nomorAntrian = nomorAntrianGlobal++;
    warga.waktuTunggu = hitungEstimasi(warga.jenisLoket, antrianLoket[warga.jenisLoket - 1].jumlah);

    enqueue(&antrianLoket[warga.jenisLoket - 1], warga);

    printf("=========================================\n");
    printf("            NOMOR ANTRIAN ANDA\n");
    printf("=========================================\n");
    printf("Nomor Antrian : %d\n", warga.nomorAntrian);
    printf("Nama          : %s\n", warga.nama);

    switch (warga.jenisLoket) {

        case LOKET_PAJAK:
        printf("Layanan: Pajak Kendaraan\n");
        break;

        case LOKET_BALIK_NAMA:
        printf("Layanan: Balik Nama Kendaraan\n");
        break;

        case LOKET_STNK:
        printf("Layanan: Penerbitan STNK\n");
        break;
    }

    printf("Estimasi Waktu Tunggu: %d Menit\n", warga.waktuTunggu);
    printf("=========================================\n");
}

void tampilkanAntrian(Queue *queue) {
     NodeQueue *current;

    if (isQueueEmpty(queue)) {
        printf("Antrian kosong.\n");
        return;
    }

    current = queue->front;

    while (current != NULL) {
        printf("Nomor Antrian : %d\n", current->data.nomorAntrian);
        printf("Nama          : %s\n", current->data.nama);
        printf("NIK           : %s\n", current->data.nik);
        printf("Estimasi      : %d menit\n", current->data.waktuTunggu);
        printf("----------------------------------------\n");

        current = current->next;
    }
}

void batalAntrian(Queue *queue, int nomorAntrian) {
    NodeQueue *current, *prev;

    if (isQueueEmpty(queue)) {
        printf("Antrian kosong.\n");
        return;
    }

    current = queue->front;
    prev = NULL;

    while (current != NULL &&
           current->data.nomorAntrian != nomorAntrian) {

        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Nomor Antrian Tidak Ditemukan!\n");
        return;
    }

    if (prev == NULL) {
        queue->front = current->next;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }
    } else {
        prev->next = current->next;

        if (current == queue->rear) {
            queue->rear = prev;
        }
    }

    free(current);
    queue->jumlah--;

    printf("Nomor Antrian %d Berhasil Dibatalkan.\n",
           nomorAntrian);
}

void tambahRiwayat(Warga warga) {
    NodeRiwayat *nodeBaru;
    NodeRiwayat *current;

    nodeBaru = (NodeRiwayat*) malloc(sizeof(NodeRiwayat));

    if (nodeBaru == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }

    nodeBaru->data = warga;
    nodeBaru->next = NULL;

    if (headRiwayat == NULL) {
        headRiwayat = nodeBaru;
    } else {
        current = headRiwayat;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = nodeBaru;
    }
}

void panggilAntrian(int idLoket) {
    Warga warga;

    if (idLoket < 1 || idLoket > 3) {
        printf("Loket tidak valid!\n");
        return;
    }

    warga = dequeue(&antrianLoket[idLoket - 1]);

    if (warga.nomorAntrian == 0) {
        return;
    }

    printf("\n========================================\n");
    printf("         WARGA SEDANG DILAYANI\n");
    printf("========================================\n");
    printf("Nomor Antrian : %d\n", warga.nomorAntrian);
    printf("Nama          : %s\n", warga.nama);
    printf("NIK           : %s\n", warga.nik);

    switch (idLoket) {

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

    printf("========================================\n");

    tambahRiwayat(warga);

    daftarLoket[idLoket - 1].totalDilayani++;
}

void traversalRiwayat(NodeRiwayat *head) {
    NodeRiwayat *current;

    if (head == NULL) {
        printf("Belum ada riwayat layanan.\n");
        return;
    }

    current = head;

    while (current != NULL) {
        printf("Nomor Antrian : %d\n",
               current->data.nomorAntrian);
        printf("Nama          : %s\n",
               current->data.nama);
        printf("NIK           : %s\n",
               current->data.nik);
        printf("Waktu Tunggu  : %d menit\n",
               current->data.waktuTunggu);
        printf("----------------------------------------\n");

        current = current->next;
    }
}
