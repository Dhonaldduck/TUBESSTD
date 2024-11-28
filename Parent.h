#include <iostream>
using namespace std;
typedef struct elm_Maskapai *adr_Maskapai;
struct elm_Maskapai{
    infotype infoMaskapai;
    adr_Relasi pRelasi;
    adr_Maskapai next;
    adr_Maskapai prev;
};
struct infotype{
    string namaMaskapai;
    string kodeMaskapai;
    string kelasMaskapai;
    int kapasitasPenumpang;
};
struct List_Maskapai{
    adr_Maskapai first;
    adr_Maskapai last;
};
void createListMaskapai(List_Maskapai &Lm);
adr_Maskapai createElmMaskapai(infotype x);
void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P);
void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P);
string findMaskapai(List_Maskapai Lm, string kode);