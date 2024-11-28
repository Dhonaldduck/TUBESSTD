#include <iostream>
#include "Tubes.h"
using namespace std;
void createListMaskapai(List_Maskapai &Lm){
    Lm.first = NULL;
    Lm.last = NULL;
}
adr_Maskapai createElmMaskapai(infotype x){
    adr_Maskapai P = new elm_Maskapai;
    P -> infoMaskapai = x;
    P -> next = NULL;
    P -> prev = NULL;
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