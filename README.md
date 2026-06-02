<div align="center">
  
# 🏛️ SamsatQ
### Sistem Antrian Loket Pelayanan Umum pada Kantor SAMSAT

> Implementasi Queue, Linked List, dan Array dengan Bubble Sort, Insertion Sort, dan Traversal Linked List menggunakan bahasa pemrograman C
---
</div>

## 👥 Tim Pengembang — Kelompok 2

| Nama | NPM | Peran |
|------|-----|-------|
| Aisya Ghaisany | 250810701100029 | Algorithm Analyst |
| Siti Salwa Shafina | 250810701100055 | Future Planner |
| M. Rafli Afrizal | 250810701100075 | Project Lead |
| M. Ihsan Syahni | 250810701100109 | System Designer |

**Mata Kuliah:** Praktikum Struktur Data dan Algoritma — Kelas C  
**Semester:** II — 2026  
**Program Studi:** Teknik Informatika  
**Universitas:** Universitas Syiah Kuala

---

## 📌 Deskripsi Proyek

SamsatQ adalah simulasi sistem antrian digital berbasis **Command Line Interface (CLI)** yang dibangun menggunakan bahasa pemrograman C. Sistem ini mengelola antrian warga secara otomatis pada tiga loket layanan SAMSAT:

- 🚗 Loket Pajak Kendaraan
- 📋 Loket Balik Nama Kendaraan  
- 📄 Loket Penerbitan STNK

Tujuannya adalah mensimulasikan pengelolaan antrian yang **adil, efisien, dan transparan** berdasarkan prinsip First In First Out (FIFO).

---

## 🏗️ Struktur Data yang Digunakan

| Struktur Data | Kegunaan |
|---------------|----------|
| **Queue** | Mengelola antrian aktif warga per loket (FIFO) |
| **Linked List** | Menyimpan riwayat warga yang telah dilayani |
| **Array** | Menyimpan data statis tiga loket layanan |

---

## ⚙️ Algoritma yang Digunakan

| Algoritma | Kegunaan |
|-----------|----------|
| **Insertion Sort** | Mengurutkan antrian berdasarkan nomor urut |
| **Bubble Sort** | Mengurutkan riwayat layanan berdasarkan waktu tunggu terlama |
| **Traversal Linked List** | Menampilkan seluruh riwayat layanan harian |

---

## 🖥️ Fitur Sistem

- ✅ Ambil nomor antrian (input nama, NIK, pilih loket)
- ✅ Panggil antrian berikutnya per loket
- ✅ Tampilkan antrian aktif secara real-time
- ✅ Simpan riwayat warga yang telah dilayani
- ✅ Tampilkan riwayat layanan harian
- ✅ Laporan statistik waktu tunggu
- ✅ Batalkan antrian jika warga tidak hadir saat dipanggil

---

## 📁 File

```
UAS-PRAKSDA-KEL2/
│
├── main.c              # File utama program
├── Samsatq.h           # 
├── Makefile            # 
├── samsatq.c           # 
└── README.md           # Dokumentasi proyek
```

## 🚀 Cara Menjalankan Program

### Prasyarat
- GCC Compiler (MinGW untuk Windows / GCC untuk Linux/Mac)
- Terminal / Command Prompt

### Langkah Kompilasi

```bash
# Clone repository
git clone https://github.com/ssalwashafina/UAS-PRAKSDA-KEL2.git

# Masuk ke direktori project
cd UAS-PRAKSDA-KEL2

# Kompilasi program
gcc main.c -o samsatq

# Jalankan program
./samsatq
```

### Untuk Windows

```bash
gcc main.c -o samsatq.exe
samsatq.exe
```

---

## 📋 Tampilan Menu Program

```
╔══════════════════════════════════════════╗
║         SISTEM ANTRIAN SAMSAT            ║
║               SamsatQ                    ║
╠══════════════════════════════════════════╣
║  1. Ambil Nomor Antrian                  ║
║  2. Panggil Antrian Berikutnya           ║
║  3. Tampilkan Antrian Saat Ini           ║
║  4. Riwayat Layanan Hari Ini             ║
║  5. Laporan Statistik Waktu Tunggu       ║
║  6. Batalkan Nomor Antrian               ║
║  0. Keluar                               ║
╚══════════════════════════════════════════╝
```

---

## 🗂️ Arsitektur Sistem

```
INPUT              PROSES                    OUTPUT
──────────         ──────────────────────    ──────────────────────
Pilihan Menu  ───► Enqueue                ──► Tampilkan Nomor Antrian
Input Warga        Insertion Sort             Tampilkan Antrian Aktif
Pilih Loket        Dequeue                    Tampilkan Riwayat Layanan
                   Batal Antrian              Tampilkan Total Dilayani
                   Linked List                Tampilkan Warga Batal
                   Bubble Sort
```

---

## 📊 Kompleksitas Algoritma

| Operasi | Kompleksitas Waktu | Keterangan |
|---------|-------------------|------------|
| Enqueue | O(1) | Tambah ke belakang antrian |
| Dequeue | O(1) | Ambil dari depan antrian |
| Insertion Sort | O(n) best case | Data antrian hampir terurut |
| Bubble Sort | O(n²) | Dijalankan sekali saat laporan |
| Traversal | O(n) | Kunjungi semua node riwayat |
| Batal Antrian | O(n) | Cari node di tengah antrian |
