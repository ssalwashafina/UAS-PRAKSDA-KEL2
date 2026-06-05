
#include "samsatq.h"

Queue antrianLoket[JUMLAH_LOKET];
Loket daftarLoket[JUMLAH_LOKET];
NodeRiwayat *headRiwayat = NULL;
int nomorAntrianGlobal = 1;

void inisialisasiSistem(void) {

}
int i;

for(i = 0; i < JUMLAH_LOKET; i++) {
    antrianLoket[i].front = NULL;
    antrianLoket[i].rear = NULL;
    antrianLoket[i].jumlah = 0;
}

daftarLoket[0].idLoket = LOKET_PAJAK;
strcpy(daftarLoket[0].namaLoket, "Pajak Kendaraan");
daftarLoket[0].statusTersedia = 1;
daftarLoket[0].totalDilayani = 0;

daftarLoket[1].idLoket = LOKET_BALIK_NAMA;
strcpy(daftarLoket[1].namaLoket, "Balik Nama");
daftarLoket[1].statusTersedia = 1;
daftarLoket[1].totalDilayani = 0;

daftarLoket[2].idLoket = LOKET_STNK;
strcpy(daftarLoket[2].namaLoket, "Penerbitan STNK");
daftarLoket[2].statusTersedia = 1;
daftarLoket[2].totalDilayani = 0;
}

