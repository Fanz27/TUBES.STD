#include <iostream>
#include "akademi.h"

using namespace std;

void createList(List_MLL &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createListDivisi(List_MLL &L){
    first(L) = NULL;
}

adr_Kategori createNewKategori(infoK data){
    adr_Kategori P = new elemenKategori;
    infoKategori(P) = data;
    nextKategori(P) = NULL;
    prevKategori(P) = NULL;
    nextDiv(P) = NULL;
    return P;
}

void insertKategoriLast(List_MLL &L, adr_Kategori P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        nextKategori(P) = NULL;
        prevKategori(P) = NULL;
    } else {
        adr_Kategori temp = last(L);
        nextKategori(temp) = P;
        prevKategori(P) = temp;
        nextKategori(P) = NULL;
        last(L) = P;
    }

}
void deleteKategoriLast(List_MLL &L, adr_Kategori &P, adr_Kategori prec){
    if (first(L) == NULL) {
        cout << "Data kosong tidak bisa dihapus" << endl;
        P = NULL;
    } else if (first(L) == last(L)) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        adr_Kategori temp = first(L);
        adr_Kategori prec = NULL;
        while (nextKategori(temp)!= NULL) {
            prec = temp;
            temp = nextKategori(temp);
        }
        P = temp;
        nextKategori(prec) = NULL;
    }
}
void printKategori(List_MLL &L){
    adr_Kategori P = first(L);
    while (P != NULL) {
        cout << infoKategori(P).namaK << " ";
        cout << infoKategori(P).desK << " ";
        cout << infoKategori(P).jenis << " ";
        P = nextKategori(P);
    }
    cout << endl;
}

adr_Divisi createNewDivisi(infoD data){
    adr_Divisi Q = new elemenDivisi;
    infoDivisi(Q) = data;
    nextDiv(Q) = NULL;
    return Q;
}
void insertDivisiLast(List_MLL &L, adr_Divisi P){
    adr_Kategori K = last(L);
    if (nextDiv(K) == NULL){
        nextDiv(K) = P;
    } else {
        adr_Divisi Q = nextDiv(K);
        while (nextDiv(Q) != NULL) {
            Q = nextDiv(Q);
        }
        nextDiv(Q) = P;
    }
}
void deleteDivisiFirst(List_MLL &L, adr_Divisi P) {
    if (nextDiv(last(L)) == NULL) {
        P = NULL;
    } else {
        P = nextDiv(last(L));
        nextDiv(last(L))= nextDiv(P);
        nextDiv(P) = NULL;
    }
}
void deleteDivisiLast(List_MLL &L, adr_Divisi &P) {
   adr_Kategori currentKategori = first(L);
    while (currentKategori != nullptr) {
        if (nextDiv(currentKategori) != NULL) {
            adr_Divisi temp = nextDiv(currentKategori);
            adr_Divisi prev = NULL;

            while (nextDiv(temp) != NULL) {
                prev = temp;
                temp = nextDiv(temp);
            }

            P = temp;
            if (prev != NULL) {
                nextDiv(prev) = NULL;
            } else {
                nextDiv(currentKategori) = NULL;
            }
            return;
        }
        currentKategori = currentKategori->nextKategori;
    }
    P = NULL;
}
void printDivisi(List_MLL &L){
    adr_Kategori P = first(L);
    while (P != NULL) {
        adr_Divisi Q = nextDiv(P);
        cout << "  Divisi for Kategori: " << infoKategori(P).namaK << endl;
        while (Q != nullptr) {
            cout << "    Divisi: " << infoDivisi(Q).namaD << endl;
            cout << "    Durasi: " << infoDivisi(Q).durasi << endl;
            cout << "    Harga: " << infoDivisi(Q).harga << endl;
            cout << "    Istruktur: " << infoDivisi(Q).instruktur << endl;
            Q = nextDiv(Q);
        }
        P = nextKategori(P);
    }
}

void addDivisiToKategori(adr_Kategori &K, adr_Divisi P){
    if (nextDiv(K) == NULL){
        nextDiv(K) = P;
    } else {
        adr_Divisi Q = nextDiv(K);
        while (nextDiv(K) != NULL) {
            Q = nextDiv(Q);
        }
        nextDiv(Q) = P;
    }

}
void removeDivisiFromKategori(adr_Kategori &K, adr_Divisi &P){
    if (nextDiv(K) == NULL) {
        cout << "Data Kosong Tidak Dapat Dihapus" << endl;
        P = NULL;
    } else {
        adr_Divisi Q = nextDiv(K);
        if (Q == P) {
            nextDiv(K) = nextDiv(Q);
            nextDiv(Q) = NULL;
            P = Q;
        } else {
            adr_Divisi prev = NULL;
            while (Q != NULL && Q != P) {
                prev = Q;
                Q = nextDiv(Q);
            }
            if (Q == NULL) {
                cout << "Divisi Tidak Ditemukan" << endl;
                P = NULL;
            } else {
                //prev->nextDiv(Q) = nextDiv(Q) {
                    nextDiv(Q) = NULL;
                    P = Q;
                //}
            }

        }
    }

}

void showAll(List_MLL L){
    adr_Kategori P = first(L);
    while (P != NULL){
        cout << "kategori  : " << infoKategori(P).namaK << endl;
        cout << "Deskripsi : " << infoKategori(P).desK << endl;
        cout << "kategori  : " << infoKategori(P).jenis << endl;
        adr_Divisi Q = nextDiv(P);
        while (Q != NULL){
                cout << "Divisi     : " << infoDivisi(Q).durasi << endl;
                // cout << "Durasi     : " << infoDivisi(P).durasi << endl;
                // cout << "Harga      : " << infoDivisi(P).harga << endl;
                // cout << "Instruktur : " << infoDivisi(P).instruktur << endl;
                Q = nextDiv(Q);
        }
        P = nextKategori(P);
    }
}