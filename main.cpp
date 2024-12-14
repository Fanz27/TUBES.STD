#include <iostream>
#include "akademi.h"

using namespace std;

void showMainMenu() {
    cout << "==== Main Menu ====" << endl;
    cout << "1. Create new Kategori" << endl;
    cout << "2. Create new Divisi" << endl;
    cout << "3. Add Divisi to Kategori" << endl;
    cout << "4. Delete Divisi from Kategori" << endl;
    cout << "5. Print all Categories and Divisis" << endl;
    cout << "6. Delete last Divisi" << endl;
    cout << "7. Show All Data" << endl;
    cout << "8. Exit" << endl;
    cout << "====================" << endl;
    cout << "Choose an option: ";
}

int main() {
    List_MLL list;
    createList(list);  // Create an empty list for Categories
    int choice;

    while (true) {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Create a new Kategori
                infoK data;
                cout << "Enter Kategori name: ";
                cin >> data.namaK;
                cout << "Enter Kategori description: ";
                cin >> data.desK;
                cout << "Enter Kategori type (0/1): ";
                cin >> data.jenis;
                adr_Kategori newKategori = createNewKategori(data);
                insertKategoriLast(list, newKategori);
                cout << "Kategori created successfully!" << endl;
                break;
            }
            case 2: {
                // Create a new Divisi
                infoD data;
                cout << "Enter Divisi name: ";
                cin >> data.namaD;
                cout << "Enter Divisi duration: ";
                cin >> data.durasi;
                cout << "Enter Divisi price: ";
                cin >> data.harga;
                cout << "Enter Instruktur name: ";
                cin >> data.instruktur;
                adr_Divisi newDivisi = createNewDivisi(data);
                insertDivisiLast(list, newDivisi);
                cout << "Divisi created successfully!" << endl;
                break;
            }
            case 3: {
                // Add Divisi to Kategori
                string kategoriName;
                cout << "Enter Kategori name to add Divisi: ";
                cin >> kategoriName;
                adr_Kategori K = first(list);
                while (K != NULL && infoKategori(K).namaK != kategoriName) {
                    K = nextKategori(K);
                }
                if (K != NULL) {
                    infoD data;
                    cout << "Enter Divisi name: ";
                    cin >> data.namaD;
                    cout << "Enter Divisi duration: ";
                    cin >> data.durasi;
                    cout << "Enter Divisi price: ";
                    cin >> data.harga;
                    cout << "Enter Instruktur name: ";
                    cin >> data.instruktur;
                    adr_Divisi newDivisi = createNewDivisi(data);
                    addDivisiToKategori(K, newDivisi);
                    cout << "Divisi added to Kategori successfully!" << endl;
                } else {
                    cout << "Kategori not found!" << endl;
                }
                break;
            }
            case 4: {
                // Delete Divisi from Kategori
                string kategoriName;
                cout << "Enter Kategori name to delete Divisi: ";
                cin >> kategoriName;
                adr_Kategori K = first(list);
                while (K != NULL && infoKategori(K).namaK != kategoriName) {
                    K = nextKategori(K);
                }
                if (K != NULL) {
                    string divisiName;
                    cout << "Enter Divisi name to delete: ";
                    cin >> divisiName;
                    adr_Divisi D = nextDiv(K);
                    while (D != NULL && infoDivisi(D).namaD != divisiName) {
                        D = nextDiv(D);
                    }
                    if (D != NULL) {
                        removeDivisiFromKategori(K, D);
                        cout << "Divisi removed successfully!" << endl;
                    } else {
                        cout << "Divisi not found!" << endl;
                    }
                } else {
                    cout << "Kategori not found!" << endl;
                }
                break;
            }
            case 5: {
                // Print all Categories and Divisis
                printKategori(list);
                break;
            }
            case 6: {
                // Delete last Divisi
                adr_Divisi P;
                deleteDivisiLast(list, P);
                cout << "Last Divisi deleted!" << endl;
                break;
            }
            case 7: {
                // Show all data (Categories and their Divisis)
                showAll(list);
                break;
            }
            case 8: {
                // Exit the program
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid option! Please choose a valid option." << endl;
                break;
            }
        }
    }
    return 0;
}
