#ifndef AKADEMI_H_INCLUDED
#define AKADEMI_H_INCLUDED
#include <iostream>
#include <string>

#define infoKategori(P) (P)->infoKategori
#define nextKategori(P) (P)->nextKategori
#define prevKategori(P) (P)->prevKategori
#define nextDiv(P) (P)->nextDiv
#define next(temp) (temp)->next
#define infoDivisi(P) (P)->infoDivisi
#define info(Q) (Q)->info
#define first(L) (L).first
#define last(L) (L).last

using namespace std;

//Divisi
struct divisi{
    string namaD;
    string durasi;
    string harga;
    string instruktur;
};

typedef divisi infoD;

//Kategori
struct kategori {
    string namaK;
    string desK;
    bool jenis; 
    struct Divisi;
};

typedef struct elemenDivisi *adr_Divisi;
typedef struct elemenKategori *adr_Kategori;
typedef kategori infoK;

struct elemenKategori{
    infoK infoKategori;
    adr_Kategori nextKategori;
    adr_Kategori prevKategori;
    adr_Divisi nextDiv;
};

struct elemenDivisi{
    infoD infoDivisi;
    adr_Divisi nextDiv;
};

struct List_MLL{
    adr_Kategori first;
    adr_Kategori last;
};

void createList(List_MLL &L);

// untuk elemen kategori
adr_Kategori createNewKategori(infoK data);
void insertKategoriLast(List_MLL &L, adr_Kategori P);
void deleteKategoriLast(List_MLL &L, adr_Kategori &P);
adr_Kategori searchingKategori(List_MLL &L, string jenis);
void printKategori(List_MLL &L);

// Divisi Management
adr_Divisi createNewDivisi(infoD data);
void insertDivisiLast(List_MLL &L, adr_Divisi P);
void deleteDivisiFirst(List_MLL &L, adr_Divisi &P);
void deleteDivisiLast(List_MLL &L, adr_Divisi &P);
//adr_Divisi searchDivisi(adr_Divisi X, string namaDiv, string durasi, string harga, string instruktur); 
void printDivisi(List_MLL &L);

// Add and Remove Divisi to/from Kategori
void addDivisiToKategori(adr_Kategori &K, adr_Divisi P);
void removeDivisiFromKategori(adr_Kategori &K, adr_Divisi &P);

//menampilkan seluruh data kategori bersama divisinya
void showAll(List_MLL L);

void listMenu();

#endif // AKADEMI_H_INCLUDED
