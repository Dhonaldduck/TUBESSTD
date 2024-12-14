#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    List_Maskapai LM;
    List_Rute LR;
    createListMaskapai(LM);
    createListRute(LR);
    
    int choice;
    string kodeMaskapai, kodeRute;
    infotypeMaskapai maskapai;
    infotypeRute rute;

    do {
        // Menu Utama
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Maskapai" << endl;
        cout << "2. Tambah Rute" << endl;
        cout << "3. Tambah Relasi Maskapai dan Rute" << endl;
        cout << "4. Hapus Maskapai" << endl;
        cout << "5. Hapus Rute" << endl;
        cout << "6. Tampilkan Maskapai" << endl;
        cout << "7. Tampilkan Rute" << endl;
        cout << "8. Tampilkan Rute dari Maskapai" << endl;
        cout << "9. Tampilkan Maskapai dari Rute" << endl;
        cout << "10. Tampilkan Maskapai dan Rute" << endl;
        cout << "11. Edit Rute dari Maskapai" << endl;
        cout << "12. Hitung Relasi Maskapai" << endl;
        cout << "13. Hitung Relasi Rute" << endl;
        cout << "14. Hitung Rute yang tidak memiliki Relasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu (0-14): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Menambahkan Maskapai
                cout << "Masukkan Nama Maskapai: ";
                cin >> maskapai.namaMaskapai;
                cout << "Masukkan Kode Maskapai: ";
                cin >> maskapai.kodeMaskapai;
                cout << "Masukkan Kelas Maskapai: ";
                cin >> maskapai.kelasMaskapai;
                cout << "Masukkan Kapasitas Penumpang: ";
                cin >> maskapai.kapasitasPenumpang;
                
                adr_Maskapai m = createElmMaskapai(maskapai);
                insertMaskapai(LM, m);
                cout << "Maskapai berhasil ditambahkan!" << endl;
                break;
            }

            case 2: {
                // Menambahkan Rute
                cout << "Masukkan Kota Asal: ";
                cin >> rute.kota_asal;
                cout << "Masukkan Kota Tujuan: ";
                cin >> rute.kota_tujuan;
                cout << "Masukkan Kode Penerbangan: ";
                cin >> rute.kode_penerbangan;
                cout << "Masukkan Jumlah Penumpang: ";
                cin >> rute.jumlah_penumpang;

                adr_Rute r = newElementRute(rute);
                insertRute(LR, r);
                cout << "Rute berhasil ditambahkan!" << endl;
                break;
            }

            case 3: {
                // Menambahkan Relasi antara Maskapai dan Rute
                cout << "Masukkan Kode Maskapai: ";
                cin >> kodeMaskapai;
                adr_Maskapai maskapaiRelasi = findMaskapai(LM, kodeMaskapai);
                cout << "Masukkan Kode Penerbangan: ";
                cin >> kodeRute;
                adr_Rute ruteRelasi = findRute(LR, {kodeRute});
                
                if (maskapaiRelasi != NULL && ruteRelasi != NULL) {
                    insertRelation(maskapaiRelasi, ruteRelasi);
                    cout << "Relasi berhasil ditambahkan!" << endl;
                } else {
                    cout << "Maskapai atau Rute tidak ditemukan!" << endl;
                }
                break;
            }

            case 4: {
                // Menghapus Maskapai
                cout << "Masukkan Kode Maskapai yang akan dihapus: ";
                cin >> kodeMaskapai;
                adr_Maskapai maskapaiDelete = findMaskapai(LM, kodeMaskapai);
                if (maskapaiDelete != NULL) {
                    deleteMaskapai(LM, maskapaiDelete);
                    cout << "Maskapai berhasil dihapus!" << endl;
                } else {
                    cout << "Maskapai tidak ditemukan!" << endl;
                }
                break;
            }

            case 5: {
                // Menghapus Rute
                cout << "Masukkan Kode Penerbangan yang akan dihapus: ";
                cin >> kodeRute;
                adr_Rute ruteDelete = findRute(LR, {kodeRute});
                if (ruteDelete != NULL) {
                    deleteRute(LR, ruteDelete);
                    cout << "Rute berhasil dihapus!" << endl;
                } else {
                    cout << "Rute tidak ditemukan!" << endl;
                }
                break;
            }

            case 6: {
                // Menampilkan Maskapai
                showMaskapai(LM);
                break;
            }

            case 7: {
                // Menampilkan Rute
                showRute(LR);
                break;
            }

            case 8: {
                // Menampilkan Rute dari Maskapai
                cout << "Masukkan Kode Maskapai: ";
                cin >> kodeMaskapai;
                adr_Maskapai maskapaiShow = findMaskapai(LM, kodeMaskapai);
                if (maskapaiShow != NULL) {
                    show_RutefromMaskapai(maskapaiShow);
                } else {
                    cout << "Maskapai tidak ditemukan!" << endl;
                }
                break;
            }

            case 9: {
                // Menampilkan Maskapai dari Rute
                cout << "Masukkan Kode Penerbangan: ";
                cin >> kodeRute;
                adr_Rute ruteShow = findRute(LR, {kodeRute});
                if (ruteShow != NULL) {
                    show_MaskapaifromRute(LM, ruteShow);
                } else {
                    cout << "Rute tidak ditemukan!" << endl;
                }
                break;
            }

            case 10: {
                // Menampilkan Maskapai dan Rute
                show_MaskapaiAndRute(LM, LR);
                break;
            }

            case 11: {
                // Mengedit Rute dari Maskapai
                cout << "Masukkan Kode Maskapai: ";
                cin >> kodeMaskapai;
                cout << "Masukkan Kode Rute: ";
                cin >> kodeRute;
                edit_RuteFromMaskapai(LM, LR, kodeMaskapai, kodeRute);
                break;
            }

            case 12: {
                // Menghitung Relasi Maskapai
                cout << "Masukkan Kode Maskapai: ";
                cin >> kodeMaskapai;
                adr_Maskapai maskapaiCount = findMaskapai(LM, kodeMaskapai);
                if (maskapaiCount != NULL) {
                    countRelationMaskapai(LM, maskapaiCount);
                } else {
                    cout << "Maskapai tidak ditemukan!" << endl;
                }
                break;
            }

            case 13: {
                // Menghitung Relasi Rute
                cout << "Masukkan Kode Penerbangan: ";
                cin >> kodeRute;
                adr_Rute ruteCount = findRute(LR, {kodeRute});
                if (ruteCount != NULL) {
                    countRelationRute(LM, ruteCount);
                } else {
                    cout << "Rute tidak ditemukan!" << endl;
                }
                break;
            }

            case 14: {
                // Menghitung Rute yang tidak memiliki Relasi
                int count = count_RuteDontHaveRelasi(LM, LR);
                cout << "Jumlah rute yang tidak memiliki relasi: " << count << endl;
                break;
            }

            case 0:
                cout << "Keluar dari program..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
