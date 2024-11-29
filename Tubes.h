#include <iostream>
using namespace std;

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
    infotype infoRelation;
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

typedef struct elm_Maskapai *adr_Maskapai;
typedef struct elm_Rute *adr_Rute;
typedef struct elm_Relation* adr_relasi;

struct List_Maskapai{
    adr_Maskapai first;
    adr_Maskapai last;
};
struct List_Rute{
    adr_Rute first;
};

struct List_Relation {
    adr_relasi first;
};
typedef rutePenerbangan infotypeRute;


void createListMaskapai(List_Maskapai &Lm);
void createListRute(List_Rute &LR);
void createListRelation(List_Relation &Rt);
bool isEmptyRute(List_Rute LR);
adr_Maskapai createElmMaskapai(infotype x);
adr_Rute newElementRute(infotypeRute x);
adr_relasi newElementRelation(infotype x);
void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P);
void addRute(List_Rute &LR, adr_Rute p);
void insertRelasi(List_Relation &Rt, adr_relasi P);
void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P);
void deleteRute(List_Rute &LR, adr_Rute p);
void deleteRelation(List_Relation &Rt, adr_relasi P)
string findMaskapai(List_Maskapai Lm, string kode);
bool findRelasi(List_Relation RT, adr_rutePenerbangan P, adr_Maskapai Q);
void showMaskapai(List_Maskapai Lm);
void printInfoRute(List_Rute LR);
