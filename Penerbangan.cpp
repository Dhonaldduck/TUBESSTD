#include <iostream>
#include "Tubes.h"

using namespace std;

void createListMaskapai(List_Maskapai &LM){
    LM.first = NULL;
    LM.last = NULL;
}
void createListRute(List_Rute &LR){
    LR.first = NULL;
}
void createListRelasi(List_Relasi &RL){
    RL.first = NULL;
}
adr_Maskapai newElmMaskapai(infotypeMaskapai x){
    adr_Maskapai m = new elm_Maskapai;
    m->infoMaskapai = x;
    m->next = NULL;
    m->prev = NULL;
    return m;
}
adr_Rute newElementRute(infotypeRute x){
    adr_Rute p = new elm_Rute;
    p->infoRute = x;
    p->next = NULL;
    return p;
}
adr_Relasi newElmRelation(){
    adr_Relasi r = new elm_Relation;
    r->parent = NULL;
    r->child = NULL;
    r->next = NULL;
    return r;
}
void insert_Maskapai(List_Maskapai &LM, adr_Maskapai m){
    if(LM.first != NULL && LM.last != NULL){
        m->prev = LM.last;
        LM.last->next = m;
        LM.last = m;
    }else{
        LM.first = m;
        LM.last = m;
    }
}
void insert_RutePenerbangan(List_Rute &LR, adr_Rute p){
    if(LR.first == NULL){
        LR.first = p;
    }else{
        adr_Rute Q = LR.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = p;
    }
}
void insert_Relasi(List_Relasi &RL, adr_Relasi r){
    if(r->parent == NULL || r->child == NULL){
        cout << "Maskapai atau rute tidak valid." << endl;
        return;
    }
    adr_Relasi Q = RL.first;
    while(Q != NULL){
        if(Q->parent == r->parent && Q->child == r->child){
            cout << "Relasi antara maskapai dan rute ini sudah ada." << endl;
            return;
        }
        Q = Q->next;
    }

    if(RL.first == NULL){
        RL.first = r;
    }else{
        adr_Relasi R = RL.first;
        while(R->next != NULL){
            R = R->next;
        }
        R->next = r;
    }
    cout << "Relasi berhasil ditambahkan." << endl;
}
void delete_Maskapai(List_Maskapai &LM, adr_Maskapai m){
    m = LM.last;
    if (LM.first != LM.last){
        LM.last = m -> prev;
        m -> prev = NULL;
        LM.last -> next = NULL;
    }else{
        LM.first = NULL;
        LM.last = NULL;
    }
}
void delete_Rute(List_Rute &LR, adr_Rute p){
    if(p == NULL || LR.first == NULL) return;
    if(p == LR.first){
        LR.first = p->next;
    }else{
        adr_Rute prec = LR.first;
        while(prec->next != p && prec->next != NULL){
            prec = prec->next;
        }
        if(prec->next == p){
            prec->next = p->next;
        }
    }
    delete p;
}
void delete_Relation(List_Relasi &RL, adr_Relasi r){
    if(RL.first == NULL){
        return;
    }else if(RL.first ==  r){
        RL.first = r->next;
    }else{
        adr_Relasi S = RL.first;
        while(S->next != r && S->next != NULL){
            S = S->next;
        }
        if(S->next == r){
            S->next = r->next;
        }
    }
    delete r;
}
adr_Maskapai find_Maskapai(List_Maskapai LM, string kode){
    if(LM.first == NULL){
        cout << "Maskapai kosong." << endl;
        return NULL;
    }
    adr_Maskapai m = LM.first;
    while(m != NULL){
        if(m->infoMaskapai.kodeMaskapai == kode){
            return m;
        }
        m = m->next;
    }
    return NULL;
}
adr_Rute find_Rute(List_Rute LR, string kode){
    if(LR.first == NULL){
        cout << "Rute kosong.";
        return NULL;
    }
    adr_Rute p = LR.first;
    while(p != NULL){
        if(p->infoRute.kode_penerbangan == kode){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
adr_Relasi find_Relation(List_Relasi RL, adr_Maskapai m, adr_Rute p){
    if(RL.first == NULL){
        cout << "List relasi kosong." << endl;
        return NULL;
    }
    if(m == NULL || p == NULL){
        cout << "Maskapai atau rute tidak valid." << endl;
        return NULL;
    }
    adr_Relasi r = RL.first;
    while(r != NULL){
        if(r->parent == m && r->child == p){
            return r;
        }
        r = r->next;
    }
    return NULL;
}
void show_DataMaskapai(List_Maskapai LM){
    if(LM.first == NULL){
        cout << "Data maskapai kosong." << endl;
    }
    adr_Maskapai m;
    m = LM.first;
    while(m != NULL){
        cout << "Nama Maskapai: " << m -> infoMaskapai.namaMaskapai << endl;
        cout << "Kode Maskapai: " << m -> infoMaskapai.kodeMaskapai << endl;
        cout << "Jenis Kelas Maskapai: " << m -> infoMaskapai.kelasMaskapai << endl;
        cout << "Kapasitas Penumpang: " <<  m -> infoMaskapai.kapasitasPenumpang << endl;
        cout << endl;
        m = m -> next;
    }
}
void show_DataRute(List_Rute LR){
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
            cout << endl;
            p = p->next;
       }
    }
}
void show_RuteFromMaskapai(List_Relasi RL, adr_Maskapai m){
    if(m == NULL){
        cout << "Maskapai kosong." << endl;
        return;
    }
    bool berelasi = false;
    adr_Relasi r = RL.first;

    cout << "Daftar rute yang berelasi dengan maskapai berkode " << m->infoMaskapai.kodeMaskapai << ":";
    cout << endl;
    while(r != NULL){
        if(r->parent == m){
            berelasi = true;
            adr_Rute p = r->child;
            if(p != NULL){
                cout << "Kota asal: " << p->infoRute.kota_asal << endl;
                cout << "Kota tujuan: " << p->infoRute.kota_tujuan << endl;
                cout << "Kode penerbangan: " << p->infoRute.kode_penerbangan << endl;
                cout << "Jumlah penumpang: " << p->infoRute.jumlah_penumpang << endl;
                cout << endl;
            }
        }
        r = r->next;
    }
    if(!berelasi){
        cout << "Tidak ada maskapai yang berelasi." << endl;
    }
}
void show_MaskapaiFromRute(List_Relasi RL, adr_Rute p){
    if(p == NULL){
        cout << "Rute penerbangan kosong." << endl;
        return;
    }
    bool berelasi = false;
    adr_Relasi r = RL.first;
    cout << "Daftar maskapai yang berelasi dengan rute berkode " << p->infoRute.kode_penerbangan << ":";
    cout << endl;
    while(r != NULL){
        if(r->child == p){
            berelasi = true;
            adr_Maskapai m = r->parent;
            if(m != NULL){
                cout << "Nama Maskapai: " << m -> infoMaskapai.namaMaskapai << endl;
                cout << "Kode Maskapai: " << m -> infoMaskapai.kodeMaskapai << endl;
                cout << "Jenis Kelas Maskapai: " << m -> infoMaskapai.kelasMaskapai << endl;
                cout << "Kapasitas Penumpang: " <<  m -> infoMaskapai.kapasitasPenumpang << endl;
                cout << endl;
            }
        }
        r = r->next;
    }
    if(!berelasi){
        cout << "Tidak ada rute yang berelasi." << endl;
    }
}
void showAll_RelasiMaskapai(List_Maskapai LM, List_Relasi RL){
    if(LM.first == NULL){
        cout << "Maskapai kosong." << endl;
        return;
    }
    adr_Maskapai m = LM.first;
    cout << "DAFTAR RELASI MASKAPAI DENGAN RUTE PENERBANGAN: " << endl;
    while(m != NULL){
        cout << "MASKAPAI:" ;
        cout << endl;
        cout << "Nama Maskapai: " << m -> infoMaskapai.namaMaskapai << endl;
        cout << "Kode Maskapai: " << m -> infoMaskapai.kodeMaskapai << endl;
        cout << "Jenis Kelas Maskapai: " << m -> infoMaskapai.kelasMaskapai << endl;
        cout << "Kapasitas Penumpang: " <<  m -> infoMaskapai.kapasitasPenumpang << endl;\

        adr_Relasi r = RL.first;
        bool berelasi = false;
        while(r != NULL){
            if(r->parent == m){
                berelasi = true;
                adr_Rute p = r->child;
                if(p != NULL){
                    cout << "DAFTAR RUTE PENERBANGAN: ";
                    cout << endl;
                    cout << "Kota asal: " << p->infoRute.kota_asal << endl;
                    cout << "Kota tujuan: " << p->infoRute.kota_tujuan << endl;
                    cout << "Kode penerbangan: " << p->infoRute.kode_penerbangan << endl;
                    cout << "Jumlah penumpang: " << p->infoRute.jumlah_penumpang << endl;
                }
            }
            r = r->next;
        }
        if(!berelasi){
            cout << "Tidak ada rute yang berelasi dengan maskapai ini. " << endl;
        }
        m = m->next;
        cout << endl;
    }
}
void showAll_RelasiRute(List_Rute LR, List_Relasi RL){
    if(LR.first == NULL){
        cout << "Rute kosong." << endl;
        return;
    }
    adr_Rute p = LR.first;
    cout << "DAFTAR RELASI RUTE PENERBANGAN DENGAN MASKAPAI: " << endl;
    while(p != NULL){
        cout << "RUTE PENERBANGAN: ";
        cout << endl;
        cout << "Kota asal: " << p->infoRute.kota_asal << endl;
        cout << "Kota tujuan: " << p->infoRute.kota_tujuan << endl;
        cout << "Kode penerbangan: " << p->infoRute.kode_penerbangan << endl;
        cout << "Jumlah penumpang: " << p->infoRute.jumlah_penumpang << endl;

        adr_Relasi r = RL.first;
        bool berelasi = false;
        while(r != NULL){
            if(r->child == p){
                berelasi = true;
                adr_Maskapai m = r->parent;
                if(m != NULL){
                    cout << "DAFTAR MASKAPAI:";
                    cout << endl;
                    cout << "Nama Maskapai: " << m -> infoMaskapai.namaMaskapai << endl;
                    cout << "Kode Maskapai: " << m -> infoMaskapai.kodeMaskapai << endl;
                    cout << "Jenis Kelas Maskapai: " << m -> infoMaskapai.kelasMaskapai << endl;
                    cout << "Kapasitas Penumpang: " <<  m -> infoMaskapai.kapasitasPenumpang << endl;
                }
            }
            r = r->next;
        }
        if(!berelasi){
            cout << "Tidak ada maskapai yang berelasi dengan rute ini." << endl;
        }
        p = p->next;
        cout << endl;
    }
}
int count_RelasiMaskapai(List_Relasi RL, adr_Maskapai m){
    int count = 0;
    adr_Relasi r = RL.first;
    while(r != NULL){
        if(r->parent == m){
            count++;
        }
        r = r->next;
    }
    return count;
}
int count_RelasiRute(List_Relasi RL, adr_Rute p){
    int count = 0;
    adr_Relasi r = RL.first;
    while(r != NULL){
        if(r->child == p){
            count++;
        }
        r = r->next;
    }
    return count;
}
int count_RuteDontHaveRelasi(List_Relasi RL, List_Rute LR){
    int count = 0;
    adr_Rute p = LR.first;
    while(p != NULL){
        bool hasRelasi = false;
        adr_Relasi r = RL.first;
        while(r != NULL){
            if(r->child == p){
                hasRelasi = true;
            }
            r = r->next;
        }
        if(!hasRelasi){
            count++;
        }
        p = p->next;
    }
    return count;
}
void edit_RuteFromMaskapaiTertentu(List_Relasi &RL, adr_Maskapai m, adr_Rute p, adr_Rute Q){
    adr_Relasi r = RL.first;
    bool berelasi = false;
    while(r != NULL){
        if(r->parent == m && r->child == p){
            r->child = Q;
            berelasi = true;
            cout << "Relasi maskapai " << m->infoMaskapai.kodeMaskapai
            << " berhasil diubah dari rute " << p->infoRute.kode_penerbangan << " ke rute " << Q->infoRute.kode_penerbangan << endl;
        }
        r = r->next;
    }
    if(!berelasi){
        cout << "Relasi antara maskapai " << m->infoMaskapai.kodeMaskapai
        << "dan rute " << p->infoRute.kode_penerbangan << " tidak ditemukan." << endl;
    }
}


