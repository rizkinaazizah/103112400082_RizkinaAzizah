#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
LParent.first = NULL;
LParent.last = NULL;
}

void createListChild(listChild &LChild) {
LChild.first = NULL;
LChild.last = NULL;
}


NodeParent allocNodeParent(string idGol, string namaGol) {
NodeParent P = new nodeParent;
P->isidata.idGolongan = idGol;
P->isidata.namaGolongan = namaGol;
P->next = NULL;
P->prev = NULL;
createListChild(P->L_Child);
return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
NodeChild C = new nodeChild;
C->isidata.idHewan = idHwn;
C->isidata.namaHewan = namaHwn;
C->isidata.habitat = habitat;
C->isidata.ekor = tail;
C->isidata.bobot = weight;
C->next = NULL;
C->prev = NULL;
return C;
}


void deallocNodeParent(NodeParent &NParent) {
delete NParent;
NParent = NULL;
}


void deallocNodeChild(NodeChild &NChild) {
delete NChild;
NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
if (isEmptyParent(LParent)) {
LParent.first = LParent.last = newNParent;
} else {
newNParent->next = LParent.first;
LParent.first->prev = newNParent;
LParent.first = newNParent;
}
}


void insertLastParent(listParent &LParent, NodeParent newNParent) {
if (isEmptyParent(LParent)) {
LParent.first = LParent.last = newNParent;
} else {
newNParent->prev = LParent.last;
LParent.last->next = newNParent;
LParent.last = newNParent;
}
}

void deleteFirstParent(listParent &LParent) {
if (!isEmptyParent(LParent)) {
NodeParent P = LParent.first;
if (LParent.first == LParent.last) {
LParent.first = LParent.last = NULL;
} else {
LParent.first = P->next;
LParent.first->prev = NULL;
}
deleteListChild(P->L_Child);
deallocNodeParent(P);
}
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
if (NPrev != NULL && NPrev->next != NULL) {
NodeParent P = NPrev->next;
NPrev->next = P->next;
if (P->next != NULL)
P->next->prev = NPrev;
else
LParent.last = NPrev;
deleteListChild(P->L_Child);
deallocNodeParent(P);
}
}


void insertFirstChild(listChild &LChild, NodeChild newNChild) {
if (isEmptyChild(LChild)) {
LChild.first = LChild.last = newNChild;
} else {
newNChild->next = LChild.first;
LChild.first->prev = newNChild;
LChild.first = newNChild;
}
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
if (isEmptyChild(LChild)) {
LChild.first = LChild.last = newNChild;
} else {
newNChild->prev = LChild.last;
LChild.last->next = newNChild;
LChild.last = newNChild;
}
}


void deleteFirstChild(listChild &LChild) {
if (!isEmptyChild(LChild)) {
NodeChild C = LChild.first;
if (LChild.first == LChild.last) {
LChild.first = LChild.last = NULL;
} else {
LChild.first = C->next;
LChild.first->prev = NULL;
}
deallocNodeChild(C);
}
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
if (NPrev != NULL && NPrev->next != NULL) {
NodeChild C = NPrev->next;
NPrev->next = C->next;
if (C->next != NULL)
C->next->prev = NPrev;
else
LChild.last = NPrev;
deallocNodeChild(C);
}
}


void deleteListChild(listChild &LChild) {
while (!isEmptyChild(LChild)) {
deleteFirstChild(LChild);
}
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "-- (tidak ada child) --" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int noChild = 1;
            while (C != NULL) {
                cout << "-- Child " << noChild << " --" << endl;
                cout << "ID Hewan   : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat    : " << C->isidata.habitat << endl;
                cout << "Ekor       : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "Bobot      : " << C->isidata.bobot << endl;
                C = C->next;
                noChild++;
            }
        }

        cout << "---------------------" << endl << endl;
        P = P->next;
        noParent++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int posParent = 1;
    bool found = false;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                found = true;

                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan << " pada :" << endl << endl;

                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "Bobot : " << C->isidata.bobot << endl << endl;

                cout << "----- Data Parent -----" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "-----------------------" << endl << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }

    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
}
