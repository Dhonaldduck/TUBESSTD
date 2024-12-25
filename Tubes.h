#ifndef MLL2_H_INCLUDED
#define MLL2_H_INCLUDED
#include <iostream>

using namespace std;

struct Maskapai{
    string namaMaskapai;
    string kodeMaskapai;
    string kelasMaskapai;
    int kapasitasPenumpang;
};
struct rutePenerbangan {
    string kota_asal;
    string kota_tujuan;
    string kode_penerbangan;
    int jumlah_penumpang;

};

typedef Maskapai infotypeMaskapai;
typedef rutePenerbangan infotypeRute;

typedef struct elm_Maskapai *adr_Maskapai;
typedef struct elm_Rute *adr_Rute;
typedef struct elm_Relation* adr_Relasi;

struct elm_Maskapai{
    infotypeMaskapai infoMaskapai;
    adr_Maskapai next;
    adr_Maskapai prev;
};
struct elm_Rute {
    infotypeRute infoRute;
    adr_Rute next;
};
struct elm_Relation {
    adr_Relasi next;
    adr_Maskapai parent;
    adr_Rute child;
};

struct List_Maskapai{
    adr_Maskapai first;
    adr_Maskapai last;
};
struct List_Rute{
    adr_Rute first;
};
struct List_Relasi{
    adr_Relasi first;
};

void createListMaskapai(List_Maskapai &LM);
void createListRute(List_Rute &LR);
void createListRelasi(List_Relasi &RL);
adr_Maskapai newElmMaskapai(infotypeMaskapai x);
adr_Rute newElementRute(infotypeRute x);
adr_Relasi newElmRelation();
void insert_Maskapai(List_Maskapai &LM, adr_Maskapai m);
void insert_RutePenerbangan(List_Rute &LR, adr_Rute p);
void insert_Relasi(List_Relasi &RL, adr_Relasi r);
void delete_Maskapai(List_Maskapai &LM, adr_Maskapai m);
void delete_Rute(List_Rute &LR, adr_Rute p);
void delete_Relation(List_Relasi &RL, adr_Relasi r);
adr_Maskapai find_Maskapai(List_Maskapai LM, string kode);
adr_Rute find_Rute(List_Rute LR, string kode);
adr_Relasi find_Relation(List_Relasi RL, adr_Maskapai m, adr_Rute p);
void show_DataMaskapai(List_Maskapai LM);
void show_DataRute(List_Rute LR);
void show_RuteFromMaskapai(List_Relasi RL, adr_Maskapai m);
void show_MaskapaiFromRute(List_Relasi RL, adr_Rute p);
void showAll_RelasiMaskapai(List_Maskapai LM, List_Relasi RL);
void showAll_RelasiRute(List_Rute LR, List_Relasi RL);
int count_RelasiMaskapai(List_Relasi RL, adr_Maskapai m);
int count_RelasiRute(List_Relasi RL, adr_Rute p);
int count_RuteDontHaveRelasi(List_Relasi RL, List_Rute LR);
void edit_RuteFromMaskapaiTertentu(List_Relasi &RL, adr_Maskapai m, adr_Rute p, adr_Rute Q);
#endif // MLL2_H_INCLUDED
