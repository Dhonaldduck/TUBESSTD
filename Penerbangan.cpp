#include <iostream>
using namespace std;
#include "Penerbangan.h"


void createListMaskapai(List_Maskapai &Lm){
    Lm.first = NULL;
    Lm.last = NULL;
}

void createListRute(List_Rute &LR){
    LR.first = NULL;
}

bool isEmptyRute(List_Rute LR){
    return LR.first == NULL;
}

adr_Maskapai createElmMaskapai(infotypeMaskapai x){
    adr_Maskapai P = new elm_Maskapai;
    P -> infoMaskapai = x;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

adr_Rute newElementRute(infotypeRute x){
    adr_Rute p = new elm_Rute;
    p->infoRute = x;
    p->next = NULL;
    return p;
}

adr_relasi createElmRelation(adr_Rute child){
    adr_relasi P = new elm_Relation;
    P->child = child;
    P->next = NULL;
    return P;
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

void addRute(List_Rute &LR, adr_Rute p){
    adr_Rute Q;
    if(isEmptyRute(LR)){
        LR.first = p;
    }else{
        Q = LR.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = p;
    }
}

void insertRelation(adr_Maskapai P, adr_Rute child) {
    adr_relasi R = createElmRelation( child);
    if (P -> pRelasi == NULL) {
        P ->pRelasi = R;
    } else {
        adr_relasi temp = P ->pRelasi;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = R;
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

void deleteRute(List_Rute &LR, adr_Rute p){
    if(isEmptyRute(LR)){
        LR.first = NULL;
    }else if(LR.first->next == LR.first){
        LR.first = NULL;
    }else{
        p = LR.first;
        LR.first = p->next;
        p->next = NULL;
    }
}

void deleteRelation( adr_Maskapai P, adr_Rute child) {
    if (P -> pRelasi!= NULL) {
        adr_relasi temp = P ->pRelasi;
        adr_relasi prev = NULL;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp ->next = prev;
        temp -> next = NULL;
    }
}

adr_Maskapai findMaskapai(List_Maskapai Lm, string kode){
    adr_Maskapai P;
    P = Lm.first;
    while(P -> next != NULL){
        if(P -> infoMaskapai.kodeMaskapai == kode){
            return P;
        }
        P = P -> next;
    }
}

adr_Rute findRute(List_Rute LR, infotypeRute x){
    adr_Rute p;
    p = LR.first;
    while(p != NULL){
            if(p->infoRute.kode_penerbangan == x){
                return p;
            }
            p = p->next;
       }
    return NULL;
}

adr_relasi findRelation(adr_Maskapai P, adr_Rute child) {
    adr_relasi temp = P -> pRelasi;
    while (temp != NULL) {
        if (temp->child == child) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
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

void printInfoRute(List_Rute LR){
    adr_Rute p;
    if(isEmptyRute(LR)){
        cout << "Data Kosong" << endl;
    }else{
       p = LR.first;
       while(p->next != LR.first){
        cout << "Kota asal keberangkatan: "<< p->infoRute.kota_asal <<
            ", Kota tujuan keberangkatan: "<< p->infoRute.kota_tujuan <<
            ", Kode penerbangan: "<< p->infoRute.kode_penerbangan <<
            ", Jumlah penumpang: "<< p->infoRute.jumlah_penumpang << endl;
            p = p->next;
       }
        cout << "Kota asal keberangkatan: "<< p->infoRute.kota_asal <<
            ", Kota tujuan keberangkatan: "<< p->infoRute.kota_tujuan <<
            ", Kode penerbangan: "<< p->infoRute.kode_penerbangan <<
            ", Jumlah penumpang: "<< p->infoRute.jumlah_penumpang << endl;
    }
    cout << endl;
}
void show_RutefromMaskapai(adr_Maskapai p, List_Maskapai Lm){
    string kode;
    cin >> kode;
    p = findMaskapai(Lm,kode);
    adr_relasi q = p -> pRelasi;
    while(q != NULL){
        cout << "Rute" << q->child->infoRute.kode_penerbangan;
        cout << "Asal" << q->child->infoRute.kota_asal;
        cout << "Tujuan" << q->child->infoRute.kota_tujuan;
        cout << "Jumlah Penumpang" << q->child->infoRute.jumlah_penumpang;
        q = q ->next;
    }
}
void show_MaskapaifromRute(List_Maskapai Lm, adr_Maskapai p){
    adr_Maskapai temp = Lm.first;
    while(temp != NULL){
        adr_relasi r = temp -> pRelasi;
        while(r != NULL){
            if(r ->child->infoRute.kode_penerbangan == p->infoMaskapai.kodeMaskapai){
                cout << temp ->infoMaskapai.namaMaskapai;
            }
            r = r ->next;
        }
        temp = temp -> next;
    }
}
