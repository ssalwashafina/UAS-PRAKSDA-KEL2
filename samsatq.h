#ifndef SAMSATQ_H
#define SAMSATQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JUMLAH_LOKET 3

#define LOKET_PAJAK 1
#define LOKET_BALIK_NAMA 2
#define LOKET_STNK 3

#define ESTIMASI_PAJAK 10
#define ESTIMASI_BALIK_NAMA 20
#define ESTIMASI_STNK 15

typedef struct {
    int nomorAntrian;
    char nama[50];
    char nik[20];
    int jenisLoket; //1 = pajak, 2 = balik nama, 3 = STNK
    int waktuTunggu; //dalam menit
} Warga;

typedef struct NodeQueue {
    Warga data;
    struct NodeQueue *next;
} NodeQueue;

typedef struct {
    NodeQueue *front;
    NodeQueue *rear;
    int jumlah;
} Queue;

typedef struct NodeRiwayat {
    Warga data;
    struct NodeRiwayat *next;
} NodeRiwayat;

typedef struct {
    int idLoket;
    char namaLoket[30];
    int statusTersedia; //1 = tersedia, 0 = sibuk
    int totalDilayani;
} Loket;

extern Queue antrianLoket[JUMLAH_LOKET]; //antrian per loket
extern Loket daftarLoket[JUMLAH_LOKET]; //data loket (array)
extern NodeRiwayat *headRiwayat; //head linked list
extern int nomorAntrianGlobal; //counter nomor urut antrian

void inisialisasiSistem(void);
void enqueue(Queue *queue, Warga warga);
Warga dequeue(Queue *queue);
int isQueueEmpty(Queue *queue);
void tampilkanAntrian(Queue *queue);
void insertionSortAntrian(Queue *queue);
void bubbleSortRiwayat (NodeRiwayat *head);
void tambahRiwayat(Warga warga);
void traversalRiwayat(NodeRiwayat *head);
void ambilNomorAntrian(void);
void batalAntrian(Queue *queue, int nomorAntrian);
void panggilAntrian(int idLoket);
void bebaskanMemori(void);
int hitungEstimasi(int idLoket, int posisi);
void tampilkanMenuUtama(void);
void tampilkanMenuUser(void);
void tampilkanMenuAdmin(void);
void jalankanMenuUser(void);
void jalankanMenuAdmin(void);

#endif


