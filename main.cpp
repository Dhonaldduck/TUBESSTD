#include <iostream>
#include "mll2.h"
using namespace std;

int main()
{
        List_Maskapai LM;
        List_Relasi RL;
        List_Rute LR;
        adr_Maskapai m;
        adr_Relasi r;
        adr_Rute p, Q;
        infotypeMaskapai Maskapai;
        infotypeRute rutePenerbangan;

        createListMaskapai(LM);
        createListRelasi(RL);
        createListRute(LR);

        int pilihan;
        do{
        cout << "================================================" << endl;
        cout << "          SISTEM MANAJEMEN PENERBANGAN          " << endl;
        cout << "================================================" << endl;
        cout << "1. MASKAPAI PENERBANGAN" << endl;
        cout << "2. RUTE PENERBANGAN" << endl;
        cout << "3. RELASI" <<endl;
        cout << "4. Exit" << endl;
        cout << "================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;

        if(pilihan == 1){
            int subPilihan;
            do{
            cout << "================================================" << endl;
            cout << "              MASKAPAI PENERBANGAN              " << endl;
            cout << "================================================" << endl;
            cout << "1. Tambah Maskapai" << endl;
            cout << "2. Hapus Maskapai" << endl;
            cout << "3. Cari Maskapai" << endl;
            cout << "4. Tampilkan Maskapai" << endl;
            cout << "5. Kembali ke Menu Utama" << endl;
            cout << "================================================" << endl;
            cout << "Masukkan pilihan: ";
            cin >> subPilihan;
            cout << endl;
            if(subPilihan == 1){
                cout << "Masukkan Nama Maskapai: ";
                cin >> Maskapai.namaMaskapai;
                cout << "Masukkan Kode Maskapai: ";
                cin >> Maskapai.kodeMaskapai;
                cout << "Masukkan Kelas Maskapai: ";
                cin >> Maskapai.kelasMaskapai;
                cout << "Masukkan Kapasitas Penumpang: ";
                cin >> Maskapai.kapasitasPenumpang;
                m = newElmMaskapai(Maskapai);
                insert_Maskapai(LM, m);
                cout << "Maskapai berhasil ditambahkan." << endl;
            }else if(subPilihan == 2){
                string kodeMaskapai;
                cout << "Masukkan kode maskapai yang mau dihapus: ";
                cin >> kodeMaskapai;
                m = find_Maskapai(LM, kodeMaskapai);
                if(m != NULL){
                    delete_Maskapai(LM, m);
                    cout << "Maskapai dengan kode " << kodeMaskapai << " berhasil dihapus!" << endl;
                }else{
                    cout << "Maskapai dengan kode "<< kodeMaskapai << " tidak ditemukan." << endl;
                }
            }else if(subPilihan == 3){
                string kodeMaskapai;
                cout << "Masukkan kode maskapai yang dicari: ";
                cin >> kodeMaskapai;
                m = find_Maskapai(LM, kodeMaskapai);
                if(m != NULL){
                    cout << "Nama Maskapai: " << m->infoMaskapai.namaMaskapai << endl;
                    cout << "Kode Maskapai: " << m->infoMaskapai.kodeMaskapai << endl;
                    cout << "Jenis Kelas Maskapai: " << m->infoMaskapai.kelasMaskapai << endl;
                    cout << "Kapasitas Penumpang: " << m->infoMaskapai.kapasitasPenumpang << endl;
                }else{
                    cout << "Maskapai tidak ditemukan." << endl;
                }
            }else if(subPilihan == 4){
                show_DataMaskapai(LM);
            }else if(subPilihan == 5){
                cout << "Kembali ke menu utama" << endl;
            }else{
                cout << "Pilihan tidak valid" << endl;
            }
        }while(subPilihan != 5);
    }else if(pilihan == 2){
            int subPilihan;
            do{
            cout << "================================================" << endl;
            cout << "                RUTE PENERBANGAN                " << endl;
            cout << "================================================" << endl;
            cout << "1. Tambah Rute" << endl;
            cout << "2. Hapus Rute" << endl;
            cout << "3. Cari Rute" << endl;
            cout << "4. Tampilkan Rute" << endl;
            cout << "5. Kembali ke Menu Utama" << endl;
            cout << "================================================" << endl;
            cout << "Masukkan pilihan: ";
            cin >> subPilihan;
            cout << endl;
            if(subPilihan == 1){
                cout << "Masukkan Kota Asal: ";
                cin >> rutePenerbangan.kota_asal;
                cout << "Masukkan Kota Tujuan: ";
                cin >> rutePenerbangan.kota_tujuan;
                cout << "Masukkan Kode Penerbangan: ";
                cin >> rutePenerbangan.kode_penerbangan;
                cout << "Masukkan Jumlah Penumpang: ";
                cin >> rutePenerbangan.jumlah_penumpang;
                p = newElementRute(rutePenerbangan);
                insert_RutePenerbangan(LR, p);
                cout << "Rute berhasil ditambahkan." << endl;
            }else if(subPilihan == 2){
                string kodeRute;
                cout << "Masukkan Kode Rute: ";
                cin >> kodeRute;
                p = find_Rute(LR, kodeRute);
                if(p != NULL){
                    delete_Rute(LR, p);
                    cout << "Rute dengan kode " << kodeRute << " berhasil dihapus!" << endl;
                }else{
                    cout << "Rute dengan kode penerbangan " << kodeRute << " tidak ditemukan." << endl;
                }
            }else if(subPilihan == 3){
                string kodeRute;
                cout << "Masukkan kode rute yang dicari: ";
                cin >> kodeRute;
                p = find_Rute(LR, kodeRute);
                if(p != NULL){
                    cout << "Kota asal: " << p->infoRute.kota_asal << endl;
                    cout << "Kota tujuan: " << p->infoRute.kota_tujuan << endl;
                    cout << "Kode penerbangan: " << p->infoRute.kode_penerbangan << endl;
                    cout << "Jumlah penumpang: " << p->infoRute.jumlah_penumpang << endl;
                }else{
                    cout << "Rute tidak ditemukan." << endl;
                }
            }else if(subPilihan == 4){
                show_DataRute(LR);
            }else if(subPilihan == 5){
                cout << "Kembali ke menu utama" << endl;
            }else{
                cout << "Pilihan tidak valid" << endl;
            }
        }while(subPilihan != 5);
    }else if(pilihan == 3){
            int subPilihan;
            do{
            cout << "================================================" << endl;
            cout << "                      RELASI                    " << endl;
            cout << "================================================" << endl;
            cout << "1. Tambah Relasi" << endl;
            cout << "2. Hapus Relasi" << endl;
            cout << "3. Cari Relasi" << endl;
            cout << "4. Tampilkan Data Rute dari Maskapai Tertentu " << endl;
            cout << "5. Tampilkan Data Maskapai dari Rute Tertentu" << endl;
            cout << "6. Tampilan Data Maskapai dan Relasinya" << endl;
            cout << "7. Tampilkan Data Rute dan Relasinya" << endl;
            cout << "8. Hitung Relasi Maskapai" << endl;
            cout << "9. Hitung Relasi Rute" << endl;
            cout << "10. Hitung Rute Tidak Berelasi" << endl;
            cout << "11. Edit Relasi dari Maskapai" << endl;
            cout << "12. Kembali ke Menu Utama" << endl;
            cout << "================================================" << endl;
            cout << "Masukkan pilihan: ";
            cin >> subPilihan;
            cout << endl;

            if(subPilihan == 1){
                string kodeMaskapai, kodeRute;
                cout << "Masukkan kode maskapai: ";
                cin >> kodeMaskapai;
                cout << "Masukkan kode rute: ";
                cin >> kodeRute;
                m = find_Maskapai(LM, kodeMaskapai);
                p = find_Rute(LR, kodeRute);

                if(m != NULL && p != NULL){
                    r = newElmRelation();
                    r->parent = m;
                    r->child = p;
                    insert_Relasi(RL, r);
                }else{
                    cout << "Maskapai atau rute tidak ditemukan." << endl;
                }
            }else if(subPilihan == 2){
                string kodeMaskapai, kodeRute;
                cout << "Masukkan kode maskapai: ";
                cin >> kodeMaskapai;
                cout << "Masukkan kode rute: ";
                cin >> kodeRute;

                m = find_Maskapai(LM, kodeMaskapai);
                p = find_Rute(LR, kodeRute);
                r = find_Relation(RL, m, p);
                if(r != NULL){
                    delete_Relation(RL, r);
                    cout << "Relasi antara maskapai " << kodeMaskapai << " dan rute" << kodeRute << " berhasil dihapus." << endl;
                }else{
                    cout << "Relasi tidak ditemukan." << endl;
                }

            }else if(subPilihan == 3){
                string kodeMaskapai, kodeRute;
                cout << "Masukkan kode maskapai: ";
                cin >> kodeMaskapai;
                cout << "Masukkan kode rute: ";
                cin >> kodeRute;

                m = find_Maskapai(LM, kodeMaskapai);
                p = find_Rute(LR, kodeRute);
                r = find_Relation(RL, m, p);
                if(m != NULL && p != NULL){
                    if(r != NULL){
                        cout << "Relasi antara maskapai "<< m->infoMaskapai.namaMaskapai
                        << " dan rute dari " << p->infoRute.kota_asal
                        << " ke "<< p->infoRute.kota_tujuan << " ditemukan." << endl;
                    }else{
                        cout << "Tidak ada relasi antara maskapai " << m->infoMaskapai.namaMaskapai
                        << " dan rute dari " << p->infoRute.kota_asal
                        << " ke "<< p->infoRute.kota_tujuan << "." << endl;
                    }
                }
            }else if(subPilihan == 4){
                string kodeMaskapai;
                cout << "Masukkan kode maskapai: ";
                cin >> kodeMaskapai;

                m = find_Maskapai(LM, kodeMaskapai);
                if(m != NULL){
                    show_RuteFromMaskapai(RL, m);
                }else{
                    cout << "Maskapai tidak ditemukan." << endl;
                }
            }else if(subPilihan == 5){
                string kodeRute;
                cout << "Masukkan kode rute: ";
                cin >> kodeRute;

                p = find_Rute(LR, kodeRute);
                if(p != NULL){
                    show_MaskapaiFromRute(RL, p);
                }else{
                    cout << "Rute tidak ditemukan." << endl;
                }
            }else if(subPilihan == 6){
                showAll_RelasiMaskapai(LM, RL);
            }else if(subPilihan == 7){
                showAll_RelasiRute(LR, RL);
            }else if(subPilihan == 8){
                string kodeMaskapai;
                cout << "Masukkan kode maskapai: ";
                cin >> kodeMaskapai;
                m = find_Maskapai(LM, kodeMaskapai);

                if(m != NULL){
                    int jumlah = count_RelasiMaskapai(RL, m);
                    cout << "Jumlah relasi maskapai " << kodeMaskapai << ": " << jumlah << endl;
                }else{
                    cout << "Maskapai tidak ditemukan." << endl;
                }
            }else if(subPilihan == 9){
                string kodeRute;
                cout << "Masukkan kode rute: ";
                cin >> kodeRute;
                p = find_Rute(LR, kodeRute);

                if(p != NULL){
                    int jumlah = count_RelasiRute(RL, p);
                    cout << "Jumlah relasi rute penerbangan " << kodeRute << ": " << jumlah << endl;
                }else{
                    cout << "Rute tidak ditemukan." << endl;
                }
            }else if(subPilihan == 10){
                int jumlah = count_RuteDontHaveRelasi(RL, LR);
                cout << "Jumlah rute yang tidak memiliki relasi adalah: " << jumlah << endl;
            }else if(subPilihan == 11){
                string kodeMaskapai, kodeRuteSaatIni, kodeRuteBaru;
                cout << "Masukkan kode maskapai: ";
                cin >> kodeMaskapai;
                cout << "Masukkan kode rute saat ini: ";
                cin >> kodeRuteSaatIni;
                cout << "Masukkan kode rute baru: ";
                cin >> kodeRuteBaru;

                m = find_Maskapai(LM, kodeMaskapai);
                p = find_Rute(LR, kodeRuteSaatIni);
                Q = find_Rute(LR, kodeRuteBaru);

                if(m != NULL && p != NULL && Q != NULL){
                    edit_RuteFromMaskapaiTertentu(RL, m, p, Q);
                }else{
                    cout << "Maskapai atau rute tidak ditemukan." << endl;
                }
            }else if(subPilihan == 12){
                cout << "Kembali ke menu utama." << endl;
            }else{
                cout << "Pilihan tidak valid." << endl;
            }
            }while(subPilihan != 12);
        }else if(pilihan == 4){
            cout << "THANK YOU! " << endl;
        }else{
            cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
    }while(pilihan != 4);
    return 0;
}
