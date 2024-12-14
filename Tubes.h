#ifndef Header_h
#define Header_h

#include <iostream>
using namespace std;

typedef struct elm_Maskapai *adr_Maskapai;
typedef struct elm_Rute *adr_Rute;
typedef struct elm_Relation* adr_relasi;

struct elm_Maskapai{
    infotypeMaskapai infoMaskapai;
    adr_relasi pRelasi;
    adr_Maskapai next;
    adr_Maskapai prev;
};
struct elm_Rute {
    infotypeRute infoRute;
    adr_Rute next;
};
struct elm_Relation {
    adr_Rute child;
    adr_relasi next;
};

struct infoMaskapai{
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

struct List_Maskapai{
    adr_Maskapai first;
    adr_Maskapai last;
};
struct List_Rute{
    adr_Rute first;
};
typedef infoMaskapai infotypeMaskapai;
typedef rutePenerbangan infotypeRute;

void createListMaskapai(List_Maskapai &Lm);
void createListRute(List_Rute &LR);
adr_Maskapai createElmMaskapai(infotypeMaskapai x);
adr_Rute newElementRute(infotypeRute x);
adr_relasi createElmRelation(adr_Maskapai parent, adr_Rute child);
void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P);
void addRute(List_Rute &LR, adr_Rute p);
void insertRelation(adr_Maskapai P, adr_Rute child);
void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P);
void deleteFirst(List_Rute &LR, adr_Rute p);
void deleteRute(List_Rute &LR, adr_Rute p);
void deleteRelation( adr_Maskapai P, adr_Rute child);
adr_Maskapai findMaskapai(List_Maskapai Lm, string kode);
adr_Rute findRute(List_Rute LR, infotypeRute x);
adr_relasi findRelation(adr_Maskapai P, adr_Rute child);
void showMaskapai(List_Maskapai Lm);
void showRute(List_Rute LR);
void show_RutefromMaskapai(adr_Maskapai p, List_Maskapai Lm);
void show_MaskapaifromRute(List_Maskapai Lm, adr_Maskapai P);
void show_AllData(List_Maskapai LM, List_Rute LR);
int count_RuteDontHaveRelasi
void edit_RuteFromMaskapai(List_Maskapai LM, List_Rute LR, string kodeMaskapai, string kodeRute);

#endif /* Header_h */
