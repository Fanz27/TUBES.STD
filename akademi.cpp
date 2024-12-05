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
    createList(L);
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_Kategori temp = first(L);
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = P;
    }

}
void deleteKategoriLast(List_MLL &L, adr_Kategori &P, adr_Kategori prec){
    insertKategoriLast(L, P);
    if (insertKategoriLast(L, P) == NULL) {
        cout << "Data kosong tidak bisa dihapus" << endl;
    } else {
        prec = infoKategori;
        P = next(prec);
        next(prec) = next(P);
        next(P) = NULL;
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
