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

void adrRute(List_Rute &LR, adr_Rute p){
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
void delete_First(List_Rute &LR, adr_Rute p){
    if(LR.first == NULL){
        LR.first = NULL;
    }else if(LR.first->next == LR.first){
        LR.first = NULL;
    }else{
        p = LR.first;
        LR.first = p->next;
        p->next = NULL;
    }
}
void delete_After(List_Rute &LR, adr_Rute p, adr_Rute prec){
    if(LR.first == NULL){
        LR.first = NULL;
    }else if(LR.first->next == LR.first){
        LR.first == NULL;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}
void delete_Last(List_Rute &LR, adr_Rute p){
    if(LR.first == NULL){
        LR.first = NULL;
    }else if(LR.first->next == LR.first){
        LR.first == NULL;
    }else{
        adr_Rute Q = LR.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        p = Q->next;
        Q->next = NULL;
    }
}
void delete_Rute(List_Rute &LR, adr_Rute p){
    adr_Rute prec;
    if(LR.first == NULL){
         cout << "Data kosong" << endl;
    }else if(p == LR.first){
         delete_First(LR, p);
    }else if(p->next == NULL){
         delete_Last(LR, p);
    }else{
         delete_After(LR, p, prec);
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

void showAll_Rute(List_Rute LR){
    adr_Rute p;
    if(LR.first == NULL){
        cout << "Data Kosong" << endl;
    }else{
       p = LR.first;
       while(p != NULL){
            cout << "Kota asal: " << p->infoRute.kota_asal << endl;
            cout << "Kota tujuan: " << p->infoRute.kota_tujuan << endl;
            cout << "Kode penerbangan: " << p->infoRute.kode_penerbangan << endl;
            cout << "Jumlah penumpang: " << p->infoRute.jumlah_penumpang << endl;
            p = p->next;
       }
    }
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

void showRute_FromMaskapai(List_Relation &RT, adr_Maskapai m){
    adr_relasi r = RT.first;
    while(r != NULL){
        if(r->parent == m){
            cout << "Rute: " << endl;
            cout << "Kota asal: " << r->child->infoRute.kota_asal << endl;
            cout << "Kota tujuan: " << r->child->infoRute.kota_tujuan << endl;
            cout << "Kode penerbangan: " << r->child->infoRute.kode_penerbangan << endl;
            cout << "Jumlah penumpang: " << r->child->infoRute.jumlah_penumpang << endl;
        }
        r = r->next;
    }
}

void showAll_Data(List_Maskapai LM, List_Rute LR){
    adr_Maskapai m = LM.first;
    while(m != NULL){
        cout << "Maskapai: " << endl;
        cout << "Nama maskapai: " << m->info.namaMaskapai << endl;
        cout << "Kode Masakapai: " << m->info.kodeMaskapai << endl;
        cout << "Kelas penerbangan: " << m->info.kelasMaskapai << endl;
        cout << "Kapasitas penumpang: " << m->info.kapasitasPenumpang << endl;
        m = m->next;
    }
    cout << "\nRute Penerbangan:\n" << endl;
    showAll_Rute(LR);
}

int count_RuteDontHaveRelasi(List_Relation RT, List_Rute LR){
    int count = 0;
    adr_Rute p = LR.first;
    while(p != NULL){
        bool relasi = false;
        adr_relasi Q = RT.first;
        while(Q != NULL){
            if(Q->child == p){
                relasi = true;
            }
            Q = Q->next;
        }
        if(!relasi){
            count++;
        }
     p = p->next;
    }
   return count;
}

void countRelationMaskapai(List_Relasi &Rt, adr_Maskapai P) {
    int count = 0;
    adr_relasi temp = Rt.first;

    while (temp != NULL) {
        if (temp->parent == P) { 
            count++;
        }
        temp = temp->next;
    }
    cout << "Jumlah relasi yang dimiliki oleh Maskapai " << P->infoMaskapai.namaMaskapai << " : " << count << endl;
}

void countRelationRute(List_Relasi &Rt, adr_Rute P) {
    int count = 0;
    adr_relasi temp = Rt.first;

    while (temp != NULL) {
        if (temp->child == P) {  
            count++;
        }
        temp = temp->next;
    }
    cout << "Jumlah relasi yang dimiliki oleh Rute " << P->infoRute.kode_penerbangan << " : " << count << endl;
}

void edit_Maskapai(List_Relation &RT, adr_Maskapai m, adr_Rute p){
    if(m != NULL){
        cout << "Edit Maskapai: " << m->info.namaMaskapai << endl;
        cout << "Masukkan data baru:\n";
        cout << "Nama Maskapai: ";
        cin >> m->info.namaMaskapai;
        cout << "Kode Maskapai: ";
        cin >> m->info.kodeMaskapai;
        cout << "Kelas Maskapai: ";
        cin >> m->info.kelasMaskapai;
        cout << "Kapasitas Penumpang: ";
        cin >> m->info.kapasitasPenumpang;
    }
}
