# <h1 align="center">Laporan Praktikum Modul 4 - SINGLE LINKED LIST (Bagian Pertama)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

<p align="justify">

## Dasar Teori
Pengertian Linked List
   Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara
sekuensial, saling bersambungan, dinamis dan terbatas adalah senarai berkait (linked list).
Suatu senarai berkait (linked list) adalah suatu simpul (node) yang dikaitkan dengan simpul yang
lain dalam suatu urutan tertentu. Suatu simpul dapat berbentuk suatu struktur atau class.
Simpul harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Secara
teori, linked list adalah sejumlah node yang dihubungkan secara linier dengan bantuan
pointer.

Operasi-operasi Linked List
 Insert
    Istilah Insert berarti menambahkan sebuah simpul baru ke dalam suatu linked list.
 IsEmpty
    Fungsi ini menentukan apakah linked list kosong atau tidak.
 Find First
    Fungsi ini mencari elemen pertama dari linked list.
 Find Next
    Fungsi ini mencari elemen sesudah elemen yang ditunjuk now.
 Retrieve
    Fungsi ini mengambil elemen yang ditunjuk oleh now. Elemen tersebut lalu
    dikembalikan oleh fungsi.
 Update
    Fungsi ini mengubah elemen yang ditunjuk oleh now dengan isi dari sesuatu.
 Delete Now
    Fungsi ini menghapus elemen yang ditunjuk oleh now. Jika yang dihapus adalah
    elemen pertama dari linked list (head), head akan berpindah ke elemen berikutnya.
 Delete Head
    Fungsi ini menghapus elemen yang ditunjuk head. Head berpindah ke elemen
    sesudahnya.
 Clear
    Fungsi ini menghapus linked list yang sudah ada. Fungsi ini wajib dilakukan bila
    anda ingin mengakhiri program yang menggunakan linked list. Jika anda
    melakukannya, data-data yang dialokasikan ke memori pada program sebelumnya
    akan tetap tertinggal di dalam memori. [1]

</p>

### A. Guided<br/>
...
#### 1. Guided1-Hello
#### 2. Guided2-aritmatika
#### 3. Guided3-Percabangan
#### 4. Guided4-Perulangan 
#### 5. Guided5-Struct

### B. Unguided<br/>
...
#### 1. Unguided 1
#### 2. Unguided 2
#### 3. Unguided 3

## Guided 

### 1. Guided1-Hello
#### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

```
#### list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

```
#### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Merupakan program linked list C++ untuk mengelola data mahasiswa. Program ini terbagi dalam tiga file: header file untuk deklarasi struct dan fungsi, file implementasi operasi linked list seperti insert dan print, serta file main yang menunjukkan cara penggunaan dengan contoh data beberapa mahasiswa.

### 2. Guided2

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

```
#### list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
#### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini dibuat untuk mengelola data mahasiswa menggunakan linked list. Bisa digunakan untuk menambah data di depan, tengah, atau belakang list. Bisa juga untuk menghapus data satu per satu atau hapus semua sekaligus. Kemudian juga bisa digunakan untuk melihat jumlah data yang ada dan menampilkan semua data mahasiswanya.


## Unguided 

### 1. Unguided 1
Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```C++
source code unguided 1
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Elmlist {
    infotype info;
    Elmlist *next;
};

typedef Elmlist* address;

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address p);
void printInfo(List L);

#endif
```
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file 
“Singlylist.cpp”
```C++
source kode
#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address p = new Elmlist;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertLast(List &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void printInfo(List L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}
```
Kemudian buat program utama didalam file “main.cpp” 
```C++
Source Kode
#include "SinglyList.h"

int main() {
    List L;
    address p;

    createList(L);

    p = alokasi(9);
    insertLast(L, p);

    p = alokasi(12);
    insertLast(L, p);

    p = alokasi(8);
    insertLast(L, p);

    p = alokasi(0);
    insertLast(L, p);

    p = alokasi(2);
    insertLast(L, p);

    printInfo(L);

    return 0;
}

```
### Output Unguided 1 :

#### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan4_Modul4/Unguided1/xOutput_Unguided1_Modul4.png)

Jadi, Program ini dibuat untuk mempelajari implementasi linked list sederhana menggunakan bahasa C++. Program ini memungkinkan pengguna untuk menambahkan data ke dalam list, menghapus data, serta menampilkan isi list. Struktur program dibagi menjadi beberapa file, yaitu list.h untuk deklarasi fungsi dan struktur, list.cpp untuk implementasi fungsi, dan main.cpp sebagai program utama untuk menjalankan seluruh proses pengelolaan list.

### 2. Unguided 2
Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan 
jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh 
node menggunakan deleteList().
```C++
source code singlylisth
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Elmlist {
    infotype info;
    Elmlist *next;
};

typedef Elmlist* address;

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address p);
void printInfo(List L);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, infotype x);
int nbList(List L);
void deleteList(List &L);

#endif

```C++
source kode singlylistcpp
#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address p = new Elmlist;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertLast(List &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void printInfo(List L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        address p = L.first;
        L.first = p->next;
        delete p;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            address q = L.first;
            address p = NULL;
            while (q->next != NULL) {
                p = q;
                q = q->next;
            }
            p->next = NULL;
            delete q;
        }
    }
}

void deleteAfter(List &L, infotype x) {
    address q = L.first;
    while (q != NULL && q->next != NULL) {
        if (q->next->info == x) {
            address p = q->next;
            q->next = p->next;
            delete p;
            break;
        }
        q = q->next;
    }
}

int nbList(List L) {
    int n = 0;
    address p = L.first;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}

void deleteList(List &L) {
    address p;
    while (L.first != NULL) {
        p = L.first;
        L.first = L.first->next;
        delete p;
    }
}
```C++
source kode maincpp
#include "SinglyList.h"

int main() {
    List L;
    address p;

    createList(L);

    p = alokasi(9);  insertLast(L, p);
    p = alokasi(12); insertLast(L, p);
    p = alokasi(8);  insertLast(L, p);
    p = alokasi(0);  insertLast(L, p);
    p = alokasi(2);  insertLast(L, p);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, 8); 
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

#### Output 2
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan4_Modul4/Unguided2/xOutput_Unguided2_Modul4.png)

penjelasan unguided 2
Program ini dibuat untuk mengelola data bertipe integer menggunakan struktur Singly Linked List. Program dapat menambahkan elemen di akhir list, menampilkan seluruh isi list, serta menghapus elemen pertama, terakhir, atau elemen tertentu di tengah list. Selain itu, program juga dapat menghitung jumlah node yang ada dan menghapus seluruh list secara keseluruhan.

## Kesimpulan
Program ini menunjukkan bagaimana cara mengelola data secara dinamis menggunakan struktur Singly Linked List. Dengan memanfaatkan pointer, program dapat menambah, menampilkan, dan menghapus data tanpa batasan ukuran tetap seperti pada array. Hal ini membuktikan bahwa linked list lebih fleksibel untuk pengelolaan data yang jumlahnya dapat berubah-ubah.

## Referensi
[1] Universitas Negeri Malang. (2016). Modul praktikum algoritma & struktur data: Modul 6 — Singly & double linked list. Jurusan Teknik Elektro, Universitas Negeri Malang.
