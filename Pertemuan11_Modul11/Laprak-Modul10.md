# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
A. Pengertian Multi-Linked List
   Multi-linked list adalah linked list yang dimodifikasi sehingga setiap node memiliki lebih dari satu pointer/tautan (bukan hanya pointer ke next saja), yang bisa digunakan untuk menghubungkan node ke berbagai relasi atau struktur lain. Ini membuatnya cocok untuk merepresentasikan data yang terkait dalam hierarki atau struktur bertingkat seperti “list of lists” (satu parent yang punya banyak child) atau data dengan beberapa urutan logis sekaligus.

Secara umum:
- Setiap node tetap menyimpan data utama.
- Setiap node memiliki beberapa pointer yang masing-masing menunjuk ke node lain sesuai tujuan struktur (misalnya ke   next, child, atau urutan lain).
- Dengan struktur ini, kamu bisa menelusuri data lebih dari satu cara berdasarkan hubungan yang berbeda dalam satu struktur data.

B. Ciri-Ciri dan Struktur Data
   Multi-linked list memiliki:
   - Data field — menyimpan isi data utama.
   - Beberapa pointer/link — masing-masing menuju node lain berdasarkan hubungan yang didefinisikan (misalnya pointer ke next dalam satu list, pointer ke child list lain, dll).
   - Tidak hanya linear — karena pointer bisa menunjuk ke sub list atau ke urutan lain, sehingga bisa membentuk struktur bertahap atau bertingkat (hierarchical)

C. Macam-Macam Multi-Linked List
1. Multi-linked list dasar
   Node punya lebih dari satu pointer berdasarkan logika aplikasi (misalnya pointer ke next dan pointer ke child).
2. Multilevel Linked List
   Setiap node punya:
  > pointer ke next pada level yang sama
  > pointer ke child (sub-list) pada tingkat di bawahnya
  > Sehingga struktur bisa seperti linked list di dalam linked list.
3. Nested (Linked List of Linked Lists)
   Struktur dimana setiap node pada list utama menyimpan list lain sebagai anaknya, sering dipakai untuk merepresentasi hubungan 1 ke banyak.
4. Doubly Linked List sebagai kasus khusus
   Secara teknis juga termasuk jenis multi-linked karena setiap node punya dua pointer (prev dan next).

D. Kelebihan / Manfaat Multi-Linked List
1. Mempermudah representasi hubungan data yang kompleks (misalnya satu parent dengan banyak child). 
2. Lebih fleksibel ketika data memiliki lebih dari satu urutan atau jalur penelusuran (misalnya multilevel atau list of  lists). 
3. Mengurangi duplikasi karena satu node bisa terhubung melalui banyak pointer tanpa harus menyalin data.[1]
    
### A. Guided<br/>
...
#### 1. Guided1
#### 2. Guided2

### B. Unguided<br/>
...
#### 1. Unguided 1
#### 2. Unguided 2
#### 3. Unguided 3

## Guided 

### 1. Guided1
#### multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```
#### multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>

using namespace std;


typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    string idMakanan
    string namaMakanan;
    NodeChild next;
    NodeChild prev;

};

struct listAnak{
    NodeChild first;
    NodeChild last;
};

struct NodeParent{
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk{
    NodeParent first;
    NodeParent last;
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Anak);

NodeParent alokasiNodeParent(string idKAtegoriMakanan, string namaKategoriMakanan);

void dealokasiNodeParent(NodeParent &nodeInduk);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(ListInduk &LInduk, NodeParent nodePrev);

void insertLastChild(listAnak &LAnak, ModeChild nodeBaruChild);
void deleteAfterChild(liatAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDcari);

void printStrukturMLL(listInduk &LInduk);

#endif
```
#### main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}

```
Guided1 menerapkan struktur Multi Link List (MLL) untuk menghubungkan data kategori makanan sebagai node induk dengan data makanan sebagai node anak. Setiap node induk memiliki list anak sendiri sehingga satu kategori dapat menampung banyak data makanan. Struktur ini memungkinkan proses penambahan, penghapusan, pencarian, dan penampilan data dilakukan secara terpisah namun tetap saling terhubung.

## Unguided 
### 1. Unguided 
1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”. Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”. Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk
dari multi linked listnya.
2. Tambahkan prosedur searchHewanByEkor(input/output LParent :
listParent, input tail : Boolean) yang digunakan untuk melakukan operasi
SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan
menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil
prosedur tersebut pada main.cpp.
3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list
child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan
memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked
listnya berubah menjadi seperi ini :

#### MultiLL.h
``` C++
#ifndef MULTILL_H
#define MULTILL_H


#include <iostream>
#include <string>
using namespace std;


struct golonganHewan {
string idGolongan;
string namaGolongan;
};


struct dataHewan {
string idHewan;
string namaHewan;
string habitat;
bool ekor;
float bobot;
};


typedef struct nodeChild *NodeChild;
typedef struct nodeParent *NodeParent;


struct nodeChild {
dataHewan isidata;
NodeChild next;
NodeChild prev;
};


struct listChild {
NodeChild first;
NodeChild last;
};


struct nodeParent {
golonganHewan isidata;
NodeParent next;
NodeParent prev;
listChild L_Child;
};


struct listParent {
NodeParent first;
NodeParent last;
};


bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);


void createListParent(listParent &LParent);
void createListChild(listChild &LChild);


NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);


void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);


void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);


void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);


void deleteListChild(listChild &LChild);
void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```
#### MultiLL.cpp
```C++
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

```
#### main.cpp
```C++
#include "MultiLL.h"

int main() {
listParent LP;
createListParent(LP);


NodeParent G1 = allocNodeParent("G001", "Aves");
NodeParent G2 = allocNodeParent("G002", "Mamalia");
NodeParent G3 = allocNodeParent("G003", "Pisces");
NodeParent G4 = allocNodeParent("G004", "Amfibi");
NodeParent G5 = allocNodeParent("G005", "Reptil");


insertLastParent(LP, G1);
insertLastParent(LP, G2);
insertLastParent(LP, G3);
insertLastParent(LP, G4);
insertLastParent(LP, G5);


insertLastChild(G1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
insertLastChild(G1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));


insertLastChild(G2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
insertLastChild(G2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
insertLastChild(G2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));


insertLastChild(G4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

//no.3
// Hapus parent G004 (Amfibi)
NodeParent P = LP.first;
// Cari node G003 (sebelum G004)
while (P != NULL && P->isidata.idGolongan != "G003") {
    P = P->next;
}

if (P != NULL) {
    deleteAfterParent(LP, P);
}

cout << endl << "SETELAH DELETE G004" << endl << endl;
//

printMLLStructure(LP);
return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan11_Modul11/unguided1/un01.png)
(https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan11_Modul11/unguided1/un001.png)

Program ini menerapakn Multi Linked List (MLL) untuk mengelola data golongan hewan dan data hewan yang saling berhubungan, di mana satu golongan dapat memiliki lebih dari satu hewan. Data golongan hewan disimpan sebagai parent, sedangkan data hewan ditambahkan sebagai child ke dalam golongan yang sesuai menggunakan operasi insert. Dengan struktur MLL ini, penambahan data hewan dapat dilakukan tanpa mengganggu data golongan lain, dan setiap hewan tetap terhubung dengan golongannya masing-masing. 

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan11_Modul11/unguided1/un02.png)

penjelasan unguided 2
Prosedur searchHewanByEkor digunakan untuk melakukan operasi pencarian data hewan pada struktur Multi Linked List berdasarkan atribut ekor. Proses pencarian dilakukan dengan menelusuri setiap node parent (golongan hewan), kemudian dilanjutkan dengan menelusuri list child pada masing-masing parent untuk mencari hewan yang memiliki nilai ekor = FALSE. Jika data ditemukan, maka informasi hewan beserta golongan tempat hewan tersebut berada akan ditampilkan.

### 3. Unguided 3
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan11_Modul11/unguided1/imageun03.png)

penjelasan unguided 3
Pada operasi delete ini, program menghapus node parent dengan ID G004 (Amfibi) yang berada di tengah list parent menggunakan prosedur deleteAfterParent, yaitu dengan terlebih dahulu menentukan node parent sebelumnya. Saat node parent G004 dihapus, prosedur deleteListChild secara otomatis dijalankan sehingga seluruh data child yang dimiliki oleh G004 juga ikut terhapus.

## Kesimpulan
Dari program yang dibuat, dapat dilihat bahwa Multi Linked List (MLL) digunakan untuk menghubungkan data golongan hewan dengan data hewan di dalamnya. Setiap golongan menyimpan beberapa hewan sesuai kategorinya, sehingga data jadi lebih rapi dan mudah dikelola. Dengan struktur ini, penambahan, pencarian, dan penghapusan data bisa dilakukan dengan jelas tanpa mengganggu data lain yang tidak berkaitan.

## Referensi
[1] Wisesty, U. N., Nurrahmi, H., Yunanto, P. E., Rismala, R., & Sthevanie, F. (2025). STRUKTUR DATA MENGGUNAKAN C++.   PENERBIT KBM INDONESIA.
