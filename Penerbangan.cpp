#include <iostream>
#include "Tubes.h"
using namespace std;

void createListMaskapai(List_Maskapai &Lm){
    Lm.first = NULL;
    Lm.last = NULL;
}

void createListRelation(List_Relation &Rt){
    Rt.first = NULL;
}

adr_Maskapai createElmMaskapai(infotype x){
    adr_Maskapai P = new elm_Maskapai;
    P -> infoMaskapai = x;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

adr_relasi newElementRelation(infotype x){
    adr_relasi p = new elm_Relation;
    p->infoRelation = x;
    p->next = NULL;
    return p;
}

void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P){
    if (Lm.first != NULL && Lm.last != NULL){
        P -> prev = Lm.last;
        Lm.last -> next = P;
        Lm.last = P;
    }else{
        Lm.first = P;
        Lm.last = P;
    }
}

void insertRelasi(List_Relation &Rt, adr_relasi P) {
    if (P != NULL) {
           P->next = Rt.first;
           Rt.first = P;
           cout << "Relasi berhasil ditambahkan di awal list." << endl;
       } else {
           cout << "Elemen yang dimasukkan adalah NULL." << endl;
       }
   }

void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P){
    P = Lm.last;
    if (Lm.first != Lm.last){
        Lm.last = P -> prev;
        P -> prev = NULL;
        Lm.last -> next = NULL;
    }else{
        Lm.first = NULL;
        Lm.last = NULL;
    }
}

void deleteRelation(List_Relation &RT, adr_relasi P){
    if (RT.first != nullptr) {
        P = RT.first;
        RT.first = RT.first->next;
        P->next = nullptr;
        cout << "Relasi pertama telah dihapus." << endl;
    } else {
        cout << "List Relasi kosong, tidak ada yang dapat dihapus." << endl;
    }
}

string findMaskapai(List_Maskapai Lm, string kode){
    adr_Maskapai P;
    P = Lm.first;
    while(P -> next != NULL){
        if(P -> infoMaskapai.kodeMaskapai == kode){
            return P -> infoMaskapai.namaMaskapai;
        }
        P = P -> next;
    }
}

bool findRelasi(List_Relation Rt, adr_rutePenerbangan P, adr_Maskapai Q) {
    adr_relasi temp = Rt.first;
    while (temp != nullptr) {
        if (temp->rutePenerbangan == P && temp->adr_Maskapai == Q) {
            cout << "Relasi ditemukan antara Rute Penerbangan dan Maskapai." << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Relasi tidak ditemukan." << endl;
    return false;
}
void showMaskapai(List_Maskapai Lm){
    adr_Maskapai P;
    P = Lm.first;
    while(P != NULL){
        cout << "Nama Maskapai: " << P -> infoMaskapai.namaMaskapai << endl;
        cout << "Kode Maskapai: " << P -> infoMaskapai.kodeMaskapai << endl;
        cout << "Jenis Kelas Maskapai: " << P -> infoMaskapai.kelasMaskapai << endl;
        cout << "Kapasitas Penumpang: " <<  P -> infoMaskapai.kapasitasPenumpang << endl;
        P = P -> next;
    }
}
