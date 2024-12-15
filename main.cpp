#include <iostream>
#include "Penerbangan.h"
using namespace std;

int main() {
    List_Maskapai LM;
    List_Rute LR;
    createListMaskapai(LM);
    createListRute(LR);
    int choice;
    cout << "\nMenu Utama:" << endl;
    cout << "1. Tambah Maskapai" << endl;
    cout << "2. Tambah Rute" << endl;
    cout << "3. Cari Maskapai" << endl;
    cout << "4. Cari Rute" << endl;
    cout << "5. Tambah Relasi Maskapai dan Rute" << endl;
    cout << "6. Hapus Maskapai" << endl;
    cout << "7. Hapus Rute" << endl;
    cout << "8. Tampilkan Maskapai" << endl;
    cout << "9. Tampilkan Rute" << endl;
    cout << "10. Tampilkan Rute dari Maskapai" << endl;
    cout << "11. Tampilkan Maskapai dari Rute" << endl;
    cout << "12. Tampilkan setiap Rute dan Maskapainya" << endl;
    cout << "13. Tampilkan setiap data Maskapai dan Relasinya" << endl;
    cout << "14. Hitung Relasi Maskapai" << endl;
    cout << "15. Hitung Relasi Rute" << endl;
    cout << "16. Hitung Rute yang tidak memiliki Relasi" << endl;
    cout << "17. Edit Rute dari Maskapai" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu (0-15): ";
    cin >> choice;

        switch (choice) {
            case 1: {
                // Menambahkan Maskapai
                infotypeMaskapai maskapai;
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
                infotypeRute rute;
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
            case 3:{
                //Mencari Maskapai
                string kodeMaskapai;
                cin >> kodeMaskapai;
                findMaskapai(LM,kodeMaskapai);
                break;
            }
            case 4:{
                //Mencari Rute
                string kodeRute;
                cin >> kodeRute;
                findRute(LR,kodeRute);
                break;
            }

            case 5: {
                // Menambahkan Relasi antara Maskapai dan Rute
                string kodeMaskapai,kodeRute;
                cout << "Masukkan Kode Maskapai: ";
                cin >> kodeMaskapai;
                adr_Maskapai maskapaiRelasi = findMaskapai(LM, kodeMaskapai);
                cout << "Masukkan Kode Penerbangan: ";
                cin >> kodeRute;
                adr_Rute ruteRelasi = findRute(LR, kodeRute);
                
                if (maskapaiRelasi != NULL && ruteRelasi != NULL) {
                    insertRelation(maskapaiRelasi, ruteRelasi);
                    cout << "Relasi berhasil ditambahkan!" << endl;
                } else {
                    cout << "Maskapai atau Rute tidak ditemukan!" << endl;
                }
                break;
            }

            case 6: {
                // Menghapus Maskapai
                adr_Maskapai p;
                deleteMaskapai(LM,p);
                break;
            }

            case 7: {
                // Menghapus Rute
                cout << "Masukkan Kode Penerbangan yang akan dihapus: ";
                string kodeRute;
                adr_Rute prec;
                cin >> kodeRute;
                adr_Rute ruteDelete = findRute(LR, {kodeRute});
                if (ruteDelete == LR.first) {
                    delete_First(LR, ruteDelete);
                    cout << "Rute berhasil dihapus!" << endl;
                } else if (ruteDelete ->next == NULL){
                    delete_Last(LR,ruteDelete);
                    cout << "Rute berhasil dihapus!" << endl;
                }else if(ruteDelete != LR.first && ruteDelete ->next != NULL){
                    delete_After(LR,prec,ruteDelete);
                    cout << "Rute berhasil dihapus!" << endl;
                }else{
                    cout << "Rute tidak ditemukan!" << endl;
                }
                break;
            }

            case 8: {
                // Menampilkan Maskapai
                showMaskapai(LM);
                break;
            }

            case 9: {
                // Menampilkan Rute
                showRute(LR);
                break;
            }

            case 10: {
                // Menampilkan Rute dari Maskapai
               adr_Maskapai P;
               show_RutefromMaskapai(P,LM);
                break;
            }

            case 11: {
                // Menampilkan Maskapai dari Rute
                adr_Maskapai P;
                show_MaskapaifromRute(LM,P);
                break;
            }

            case 12: {
                // Menampilkan setiap Rute beserta Maskapainya
                show_MaskapaiAndRute(LM, LR);
                break;
            }

            case 13: {
                // Menampilkan seluruh Maskapai dan Relasinya
                adr_Rute P;
                showAllDataRelasi(LM,P);
                break;
            }

            case 14: {
                // Menghitung Relasi Maskapai
                adr_Maskapai P;
               countRelationMaskapai(LM,P);
                break;
            }

            case 15: {
                // Menghitung Relasi Rute
                adr_Rute P;
                countRelationRute(LM,P);
                break;
            }

            case 16: {
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

    }

