#include <iostream>
using namespace std;
#include "Tubes.h"


void createListMaskapai(List_Maskapai &Lm){
    Lm.first = NULL;
    Lm.last = NULL;
}

void createListRute(List_Rute &LR){
    LR.first = NULL;
}

void createListRelation(List_Relation &Rt){
    Rt.first = NULL;
}

bool isEmptyRute(List_Rute LR){
    return LR.first == NULL;
}

adr_Maskapai createElmMaskapai(infotype_Maskapai x){
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

adr_relasi createElmRelation(adr_Maskapai parent, adr_Rute child){
    adr_relasi P = new elm_Relation;
    P->parent = parent;
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

void insertRelation(List_Relation &Rt, adr_Maskapai parent, adr_Rute child) {
    adr_relasi P = createElmRelation(parent, child);
    if (Rt.first == NULL) {
        Rt.first = P;
    } else {
        adr_relasi temp = Rt.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
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

void deleteRelation(List_Relation &Rt, adr_Maskapai parent, adr_Rute child) {
    if (Rt.first != NULL) {
        adr_relasi temp = Rt.first;
        adr_relasi prev = NULL;
        while (temp != NULL && (temp->parent != parent || temp->child != child)) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            if (prev == NULL) {
                Rt.first = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
        }
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

adr_relasi findRelation(List_Relation Rt, adr_Maskapai parent, adr_Rute child) {
    adr_relasi temp = Rt.first;
    while (temp != NULL) {
        if (temp->parent == parent && temp->child == child) {
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

void showRelations(List_Relation Rt) {
    adr_relasi temp = Rt.first;
    while (temp != NULL) {
        cout << "Maskapai: " << temp->parent->infoMaskapai.namaMaskapai
             << " | Rute: " << temp->child->infoRute.kode_penerbangan
             << " | Asal: " << temp->child->infoRute.kota_asal
             << " | Tujuan: " << temp->child->infoRute.kota_tujuan << endl;
        temp = temp->next;
    }
}

