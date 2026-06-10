#include "samsatq.h"

NodeBST *rootBST = NULL;

NodeBST* insertBST(NodeBST *root, Warga warga) {
    NodeBST *nodeBaru;

    if (root == NULL) {
        nodeBaru = (NodeBST*) malloc(sizeof(NodeBST));
        if (nodeBaru == NULL) {
            printf("Gagal mengalokasikan memori BST!\n");
            return NULL;
        }
        nodeBaru->data  = warga;
        nodeBaru->kiri  = NULL;
        nodeBaru->kanan = NULL;
        return nodeBaru;
    }

    if (warga.nomorAntrian < root->data.nomorAntrian) {
        root->kiri  = insertBST(root->kiri, warga);
    } else if (warga.nomorAntrian > root->data.nomorAntrian) {
        root->kanan = insertBST(root->kanan, warga);
    }

    return root;
}

NodeBST* cariNomorBST(NodeBST *root, int nomorAntrian) {
    if (root == NULL) {
        return NULL;
    }

    if (nomorAntrian == root->data.nomorAntrian) {
        return root;
    }

    if (nomorAntrian < root->data.nomorAntrian) {
        return cariNomorBST(root->kiri, nomorAntrian);
    }

    return cariNomorBST(root->kanan, nomorAntrian);
}

void tampilkanBSTInorder(NodeBST *root) {
    if (root == NULL) return;

    tampilkanBSTInorder(root->kiri);

    printf("Nomor Antrian : %d\n", root->data.nomorAntrian);
    printf("Nama          : %s\n", root->data.nama);
    printf("NIK           : %s\n", root->data.nik);
    printf("Waktu Tunggu  : %d menit\n", root->data.waktuTunggu);
    printf("----------------------------------------\n");

    tampilkanBSTInorder(root->kanan);
}

void bebaskanBST(NodeBST *root) {
    if (root == NULL) return;
    bebaskanBST(root->kiri);
    bebaskanBST(root->kanan);
    free(root);
}