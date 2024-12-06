#ifndef Header_h
#define Header_h

#include <iostream>
using namespace std;

typedef struct elm_Maskapai *adr_Maskapai;
typedef struct elm_Rute *adr_Rute;
typedef struct elm_Relation* adr_relasi;

struct elm_Maskapai{
    infotype infoMaskapai;
    adr_Relasi pRelasi;
    adr_Maskapai next;
    adr_Maskapai prev;
};
struct elm_Rute {
    infotypeRute infoRute;
    adr_Rute next;
};
struct elm_Relation {
    adr_Maskapai parent;
    adr_Rute child;
    adr_relasi next;
};

struct infotype_Maskapai{
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
struct List_Relation{
    adr_relasi first;
};

typedef rutePenerbangan infotypeRute;

void createListMaskapai(List_Maskapai &Lm);
void createListRute(List_Rute &LR);
void createListRelation(List_Relation &Rt);
bool isEmptyRute(List_Rute LR);
adr_Maskapai createElmMaskapai(infotype x);
adr_Rute newElementRute(infotypeRute x);
adr_relasi createElmRelation(adr_Maskapai parent, adr_Rute child);
void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P);
void addRute(List_Rute &LR, adr_Rute p);
void insertRelation(List_Relation &Rt, adr_Maskapai parent, adr_Rute child);
void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P);
void deleteRute(List_Rute &LR, adr_Rute p);
void deleteRelation(List_Relation &Rt, adr_Maskapai parent, adr_Rute child);
string findMaskapai(List_Maskapai Lm, string kode);
adr_Rute findRute(List_Rute LR, infotypeRute x);
adr_relasi findRelation(List_Relation Rt, adr_Maskapai parent, adr_Rute child);
void showMaskapai(List_Maskapai Lm);
void printInfoRute(List_Rute LR);
void showRelations(List_Relation Rt);
void countRelationMaskapai(List_Relasi &Rt, adr_Maskapai P);
void countRelationChild(List_Relasi &Rt, adr_Rute P);

#endif /* Header_h */
