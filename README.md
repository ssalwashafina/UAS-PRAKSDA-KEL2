<div align="center">

# 🏛️ SamsatQ
### Sistem Antrian Loket Pelayanan Umum pada Kantor SAMSAT

> Implementasi Queue, Linked List, dan Array dengan Bubble Sort, Insertion Sort, dan Traversal Linked List menggunakan bahasa pemrograman C

</div>

---

## 👥 Tim Pengembang — Kelompok 2

| Nama |
|------|
| Aisya Ghaisany |
| Siti Salwa Shafina |
| M. Ihsan Syahni |

**Mata Kuliah:** Praktikum Struktur Data dan Algoritma — Kelas C  
**Semester:** II — 2026  
**Program Studi:** Teknik Informatika  
**Universitas:** Universitas Syiah Kuala

---

## 📌 Deskripsi Proyek

SamsatQ adalah simulasi sistem antrian digital berbasis **Command Line Interface (CLI)** yang dibangun menggunakan bahasa pemrograman C. Sistem ini mengelola antrian warga secara otomatis pada tiga loket layanan SAMSAT:

- 🚗 **Loket Pajak Kendaraan** — estimasi layanan 10 menit per warga
- 📋 **Loket Balik Nama Kendaraan** — estimasi layanan 20 menit per warga
- 📄 **Loket Penerbitan STNK** — estimasi layanan 15 menit per warga

Tujuannya adalah mensimulasikan pengelolaan antrian yang **adil, efisien, dan transparan** berdasarkan prinsip First In First Out (FIFO).

---

## 🏗️ Struktur Data yang Digunakan

| Struktur Data | Variabel Global | Kegunaan |
|---------------|----------------|----------|
| **Queue** | `antrianLoket[3]` | Mengelola antrian aktif warga per loket (FIFO) |
| **Linked List** | `headRiwayat` | Menyimpan riwayat warga yang telah dilayani |
| **Array** | `daftarLoket[3]` | Menyimpan data statis tiga loket layanan |
|**BST** | `rootBST` | Mengindeks riwayat layanan untuk pencarian cepat (O(log n)) |

---

## ⚙️ Algoritma yang Digunakan

| Algoritma | Fungsi | Kegunaan |
|-----------|--------|----------|
| **Insertion Sort** | `insertionSortAntrian()` | Mengurutkan antrian berdasarkan nomor urut setiap kali warga baru masuk |
| **Bubble Sort** | `bubbleSortRiwayat()` | Mengurutkan riwayat layanan berdasarkan waktu tunggu terlama |
| **Traversal Linked List** | `traversalRiwayat()` | Menampilkan seluruh riwayat layanan harian |
| **Binary Search** | `cariWargaBinarySearch()` | Mencari warga dalam antrian aktif berdasarkan NIK/Nama (O(log n)) |
| **BST Search** | `cariNomorBST()` | Mencari riwayat warga berdasarkan nomor antrian (O(log n)) |

---

## 🖥️ Fitur Sistem

### Menu User
- ✅ Ambil nomor antrian (input nama, NIK 16 digit, pilih loket)
- ✅ Tampilkan antrian aktif ketiga loket secara real-time
- ✅ Batalkan nomor antrian berdasarkan nomor yang diinput

### Menu Admin
- ✅ Panggil antrian berikutnya per loket
- ✅ Tampilkan riwayat layanan hari ini
- ✅ Laporan statistik waktu tunggu (diurutkan Bubble Sort)
- ✅ Cari riwayat berdasarkan nomor antrian (BST Search) ← BARU
- ✅ Ekspor data ke file TXT (persistensi data) ← BARU
- ✅ Cari data antrian berdasarkan NIK atau Nama (Binary Search) ← BARU
---

## 📁 Struktur File

```
UAS-PRAKSDA-KEL2/
├── main.c          # Entry point — menu utama (User / Admin / Keluar)
├── samsatq.h       # Header — semua struct, define, dan deklarasi fungsi
├── samsatq.c       # Implementasi semua fungsi inti sistem
├── menu_user.c     # Implementasi menu dan alur interaksi User
├── menu_admin.c    # Implementasi menu dan alur interaksi Admin
├── bst.c           # Implementasi BST (insert, search, traversal, free) ← BARU
├── fileio.c        # Implementasi ekspor & impor data ke file TXT ← BARU
├── search.c        # Implementasi Binary Search pada antrian aktif ← BARU
├── .gitignore      # Ignore *.exe dan *.o
└── README.md       # Dokumentasi proyek
```

---

## 🔧 Struct yang Digunakan

```c
// Data warga pengambil nomor antrian
typedef struct {
    int  nomorAntrian;
    char nama[50];
    char nik[20];
    int  jenisLoket;   // 1=Pajak, 2=BalikNama, 3=STNK
    int  waktuTunggu;  // dalam menit
} Warga;

// Node untuk Queue antrian aktif
typedef struct NodeQueue {
    Warga data;
    struct NodeQueue *next;
} NodeQueue;

// Struktur Queue dengan pointer front, rear, dan jumlah
typedef struct {
    NodeQueue *front;
    NodeQueue *rear;
    int jumlah;
} Queue;

// Node untuk Linked List riwayat layanan
typedef struct NodeRiwayat {
    Warga data;
    struct NodeRiwayat *next;
} NodeRiwayat;

// Data loket (disimpan dalam Array)
typedef struct {
    int  idLoket;
    char namaLoket[30];
    int  statusTersedia;  // 1=tersedia, 0=sibuk
    int  totalDilayani;
} Loket;

// Node untuk Binary Search Tree (BST)
typedef struct NodeBST {
    Warga data;
    struct NodeBST *kiri;
    struct NodeBST *kanan;
} NodeBST;
```

---

## 📊 Daftar Fungsi

| Fungsi | File | Deskripsi |
|--------|------|-----------|
| `inisialisasiSistem()` | samsatq.c | Inisialisasi semua Queue, Array loket, dan variabel global |
| `enqueue()` | samsatq.c | Tambah warga ke belakang antrian — O(1) |
| `dequeue()` | samsatq.c | Ambil warga dari depan antrian — O(1) |
| `isQueueEmpty()` | samsatq.c | Cek apakah antrian kosong |
| `ambilNomorAntrian()` | samsatq.c | Input data warga, validasi NIK, lalu enqueue ke loket |
| `tampilkanAntrian()` | samsatq.c | Traversal Queue dan tampilkan seluruh antrian aktif |
| `batalAntrian()` | samsatq.c | Hapus warga dari antrian berdasarkan nomor antrian — O(n) |
| `panggilAntrian()` | samsatq.c | Dequeue warga terdepan dan simpan ke riwayat |
| `insertionSortAntrian()` | samsatq.c | Urutkan antrian berdasarkan nomor urut — O(n) best case |
| `tambahRiwayat()` | samsatq.c | Insert node baru ke Linked List riwayat |
| `traversalRiwayat()` | samsatq.c | Tampilkan seluruh isi Linked List riwayat |
| `bubbleSortRiwayat()` | samsatq.c | Urutkan riwayat berdasarkan waktu tunggu — O(n²) |
| `hitungEstimasi()` | samsatq.c | Hitung estimasi waktu tunggu berdasarkan posisi antrian |
| `bebaskanMemori()` | samsatq.c | Bebaskan semua memori dinamis saat program selesai |
| `jalankanMenuUser()` | menu_user.c | Loop menu interaksi warga |
| `jalankanMenuAdmin()` | menu_admin.c | Loop menu interaksi petugas |
| `insertBST()` | bst.c | Sisipkan data warga ke BST — O(log n) rata-rata |
| `cariNomorBST()` | bst.c | Cari warga dalam BST berdasarkan nomor antrian — O(log n) |
| `tampilkanBSTInorder()` | bst.c | Traversal inorder BST (menampilkan data terurut) |
| `bebaskanBST()` | bst.c | Bebaskan seluruh memori BST |
| `cariWargaBinarySearch()` | search.c | Cari warga dalam antrian aktif dengan Binary Search — O(log n) |
| `eksporDataKeTXT()` | fileio.c | Simpan semua data (antrian + riwayat) ke file data_samsatq.txt |
| `imporDataDariTXT()` | fileio.c | Baca dan pulihkan data dari file saat program start |

---

## 🚀 Cara Menjalankan Program

### Prasyarat
- GCC Compiler (MinGW untuk Windows / GCC untuk Linux/Mac)
- Terminal / Command Prompt / Git Bash

### Clone Repository

```bash
git clone https://github.com/ssalwashafina/UAS-PRAKSDA-KEL2.git
cd UAS-PRAKSDA-KEL2
```

### Kompilasi Manual

```bash
# Linux / Mac
gcc main.c samsatq.c menu_user.c menu_admin.c bst.c fileio.c search.c -o samsatq
./samsatq
```

```bash
# Windows
gcc main.c samsatq.c menu_user.c menu_admin.c bst.c fileio.c search.c -o samsatq.exe
samsatq.exe
```

---

## 📋 Tampilan Program

### Menu Utama
```
========================================
         SISTEM ANTRIAN SAMSAT
========================================
1. Menu User
2. Menu Admin
0. Keluar
========================================
Pilihan Anda :
```

### Menu User
```
========================================
               MENU USER
========================================
1. Ambil Nomor Antrian
2. Tampilkan Antrian Saat Ini
3. Batalkan Antrian
0. Kembali
========================================
```

### Menu Admin
```
========================================
              MENU ADMIN
========================================
1. Panggil Antrian
2. Riwayat Layanan Hari Ini
3. Laporan Statistik Waktu Tunggu
4. Cari Riwayat (BST)
5. Ekspor Data ke TXT
6. Cari Data Antrian (Binary Search)
7. Kembali
========================================
```

---

## 📊 Kompleksitas Algoritma

| Operasi | Kompleksitas Waktu | Keterangan |
|---------|-------------------|------------|
| Enqueue | O(1) | Tambah ke belakang antrian |
| Dequeue | O(1) | Ambil dari depan antrian |
| Insertion Sort | O(n) best case | Data antrian hampir terurut |
| Bubble Sort | O(n²) | Dijalankan sekali saat laporan diminta |
| Traversal Riwayat | O(n) | Kunjungi semua node Linked List |
| Batal Antrian | O(n) | Cari node di posisi mana pun dalam Queue |
| BST Insert | O(log n) rata-rata | Menyisipkan data ke BST ← BARU |
| BST Search | O(log n) rata-rata | Mencari data di BST ← BARU |
| Binary Search	| O(log n) | Mencari data di array terurut ← BARU |


---

## 🗂️ Arsitektur Sistem

```
INPUT                          PROSES                                    OUTPUT
─────────────────              ───────────────────────────              ──────────────────────────
Pilihan Menu              ──►  Enqueue (tambah warga)               ──► Tampilkan Nomor Antrian
Input Data Warga               Dequeue (panggil warga)                  Tampilkan Antrian Aktif
Pilih Jenis Loket              Batal Antrian                            Tampilkan Riwayat Layanan
Nomor Antrian (cari)           Tambah Riwayat (Linked List)             Laporan Statistik (Bubble Sort)
NIK / Nama (cari)              Bubble Sort (riwayat)                    Hasil Pencarian BST
                               BST Insert / Search                      Hasil Pencarian Binary Search
                               Binary Search (array)                    Konfirmasi Ekspor Data
                               File I/O (ekspor/impor)
