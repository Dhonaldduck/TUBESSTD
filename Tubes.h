#include <iostream>
using namespace std;

struct elm_Maskapai{
    infotype infoMaskapai;
    adr_Relasi pRelasi;
    adr_Maskapai next;
    adr_Maskapai prev;
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

typedef struct elm_Maskapai *adr_Maskapai;
typedef struct elm_Relation* adr_relasi;

struct List_Maskapai{
    adr_Maskapai first;
    adr_Maskapai last;
};

struct List_Relation {
    adr_relasi first;
};

void createListMaskapai(List_Maskapai &Lm);
void createListRelation(List_Relation &Rt);
adr_Maskapai createElmMaskapai(infotype x);
adr_relasi newElementRelation(infotype x);
void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P);
void insertRelasi(List_Relation &Rt, adr_relasi P);
void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P);
void deleteRelation(List_Relation &Rt, adr_relasi P)
string findMaskapai(List_Maskapai Lm, string kode);
bool findRelasi(List_Relation RT, adr_rutePenerbangan P, adr_Maskapai Q);
void showMaskapai(List_Maskapai Lm);
