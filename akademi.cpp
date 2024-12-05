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
    info(P) = data;
    next(P) = NULL;
    last(P) = NULL;

    return P;
}

void insertKategoriLast(List_MLL &L, adr_Kategori P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        nextKategori(P) = NULL;
        prev(P) = NULL;
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
    } else if {
       P = first(L);
       first(L) = NULL;
    } else {
        adr_Kategori temp = first(L);
        adr_Kategori prec = NULL;
        while (next(temp)!= NULL) {
            prec = temp;
            temp = next(temp);
        }
        P = temp;
        next(prec) = NULL;
    }
}
void printKategori(List_MLL &L){
    
}

adr_Divisi createNewDivisi(infoD data){
    adr_Divisi Q = new elemenDivisi;
    info(Q) = data;
    first(Q) = NULL;
    next(Q) = NULL;

    return Q;
}
void insertDivisiLast(listDivisi &L, adr_Divisi P){
    
}
void deleteDivisiFirst(listDivisi &L, adr_Divisi &P){

}
void deleteDivisiLast(listDivisi &L, adr_Divisi &P){

}
void printDivisi(listDivisi &L){

}

void addDivisiToKategori(adr_Kategori &K, adr_Divisi P){

}
void removeDivisiFromKategori(adr_Kategori &K, adr_Divisi &P){

}

void showAll(List_MLL &L){
    adr_Kategori P = first(L);
    while (P != NULL){
        cout << "kategori  : " << infoKategori(P).namaK << endl;
        cout << "Deskripsi : " << infoKategori(P).desK << endl;
        cout << "kategori  : " << infoKategori(P).jenis << endl;
        adr_Divisi = nextDiv(P);
        while (Q != NULL){
                cout << "Divisi     : " << infoDivisi(P).namaD << endl;
                cout << "Durasi     : " << infoDivisi(P).durasi << endl;
                cout << "Harga      : " << infoDivisi(P).harga << endl;
                cout << "Instruktur : " << infoDivisi(P).instruktur << endl;
                Q = nextDiv(Q);
        }
        P = nextKategori(P);
    }
}