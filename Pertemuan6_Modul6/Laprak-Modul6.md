# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIANPERTAMA)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
 Doubly Linked list adalah linked list yang masing–masing elemennya memiliki 2 successor, yaitu
 successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen
 sesudahnya (next).
 Doubly linked list juga menggunakan dua buah successor utama yang terdapat pada list,yaitu first
 (successor yang menunjuk elemen pertama) dan last (susesor yang menunjuk elemen terakhir list).
 Komponen-komponen dalam Doubly linked list:
 1. First:pointer pada list yang menunjuk pada elemen pertama list.
 2. Last:pointer pada list yang menunjuk pada elemen terakhir list.
 3. Next:pointer pada elemen sebagai successor yang menunjuk pada elemen didepannya.
 4. Prev:pointer pada elemen sebagai successor yang menunjuk pada elemen dibelakangnya.[1]

Operasi Umum dalam Daftar Tertaut Ganda:
Traversal : Menampilkan Elemen Daftar Tertaut
Penyisipan : Di Awal , Di Akhir dan Di Posisi Tertentu
Penghapusan : Dari Awal , Dari Akhir dan Dari Posisi Tertentu[2]

Keuntungan dari Double Linked List
- Penelusuran Dua Arah - Anda dapat menelusuri maju (menggunakan next) dan mundur (menggunakan prev).
- Penghapusan Efisien - Diberikan petunjuk ke suatu simpul, Anda dapat menghapusnya dalam waktu O(1) (tidak perlu         melintasi dari kepala), karena Anda dapat memperbarui prev dan next.
- Pemasangan di Kedua Ujung - Pemasangan di kepala atau ekor efisien karena Anda dapat memperbarui kedua arah dengan mudah.
- Fitur Deque/Navigasi yang Mudah Diimplementasikan - Berguna untuk membatalkan/mengulang, riwayat penelusuran, dan navigasi daftar putar musik, yang memerlukan gerakan maju dan mundur.[2]

Kerugian dari Doubly Linked List
- Memori Ekstra Per Node - Setiap node membutuhkan penunjuk tambahan (prev), membuat DLL lebih memakan memori daripada daftar tertaut tunggal.
- Implementasi yang Lebih Kompleks - Baik prev maupun next harus ditangani dengan hati-hati selama penyisipan dan penghapusan, yang meningkatkan kemungkinan kesalahan (tautan rusak, masalah penunjuk nol)
- Operasi Lebih Lambat Akibat Overhead - Manipulasi penunjuk tambahan selama penyisipan/penghapusan menyebabkan overhead yang sedikit lebih besar dibandingkan dengan daftar tertaut tunggal.
- Tidak Ramah-Cache - Seperti daftar tertaut tunggal, node tersebar dalam memori, sehingga penelusuran mungkin lebih lambat dibandingkan dengan array karena lokalitas referensi yang buruk. [2]

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
#### listmakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){ // jika node prev tidak kosongan maka
            if(nodePrev == List.last){ 
                insertLast(List, nodeBaru);
            } else {// jika bukan node akhir
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {//nodePrev==Nil
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){//jika kosong
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){//jika tidak kosong
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

//double linkedlist perulangan bisa dari first dan last
//kalau singly linked list itu hanya dari first aja

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);//get line fungsinya bisa masukin lebih dari satu kata
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);//bisa nyimpan lebih dari suku kata(ex: jeruk manis != jeruk aja)
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}
// after after prev
// before before next
void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){ //update sebelum node next
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}

```
#### listmakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
#### main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);// nasi rames = nah itu gunanya dari getline
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}

```
Program dibuat untuk menampilkan aritmatika ketika user memasukkan 2 angka program akan menampilkan output aritmatika dalm bentuk penjumlahan, pengurangan, perkalian, pembagian, dan sisa hasil bagi 

### 2. Guided2

#### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok         // kalau next sekali" doang brrti pake linear
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

```
#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 

```
#### main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program dibuat untuk menampilkan aritmatika ketika user memasukkan 2 angka program akan menampilkan output aritmatika dalm bentuk penjumlahan, pengurangan, perkalian, pembagian, dan sisa hasil bagi 



## Unguided 

### 1. Unguided 1
BUatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut
```C++
source code unguided 1
#include <iostream>

using namespace std;

int main(){
    float angka1, angka2, penjumlahan, pengurangan, perkalian, pembagian;
    cout << "Masukkan Angka 1: ";
    cin >> angka1;
    cout << "Masukkan Angka 2: ";
    cin >> angka2;

    penjumlahan = angka1 + angka2;
    pengurangan = angka1 - angka2;
    perkalian = angka1*angka2;
    pembagian = angka1/angka2;

    cout<<"Penjumlahan: "<< penjumlahan <<endl;
    cout<<"Pengurangan: "<< pengurangan <<endl;
    cout<<"Perkalian: "<< perkalian <<endl;
    cout<<"Pembagian: "<< pembagian <<endl;

}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan1_Modul1/Unguided11_Modul1.png)

Jadi, program ini adalah program yang menerima inputan angka bertipe float kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut

### 2. Unguided 2
Buatlah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan diinputkan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
source code unguided 2
#include <iostream>
using namespace std;

int main() {
    string huruf[101] = {
        "nol", "hurufsatu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas",
        "dua puluh", "dua puluh satu", "dua puluh dua", "dua puluh tiga", "dua puluh empat", "dua puluh lima", "dua puluh enam", "dua puluh tujuh", "dua puluh delapan", "dua puluh sembilan",
        "tiga puluh", "tiga puluh satu", "tiga puluh dua", "tiga puluh tiga", "tiga puluh empat", "tiga puluh lima", "tiga puluh enam", "tiga puluh tujuh", "tiga puluh delapan", "tiga puluh sembilan",
        "empat puluh", "empat puluh satu", "empat puluh dua", "empat puluh tiga", "empat puluh empat", "empat puluh lima", "empat puluh enam", "empat puluh tujuh", "empat puluh delapan", "empat puluh sembilan",
        "lima puluh", "lima puluh satu", "lima puluh dua", "lima puluh tiga", "lima puluh empat", "lima puluh lima", "lima puluh enam", "lima puluh tujuh", "lima puluh delapan", "lima puluh sembilan",
        "enam puluh", "enam puluh satu", "enam puluh dua", "enam puluh tiga", "enam puluh empat", "enam puluh lima", "enam puluh enam", "enam puluh tujuh", "enam puluh delapan", "enam puluh sembilan",
        "tujuh puluh", "tujuh puluh satu", "tujuh puluh dua", "tujuh puluh tiga", "tujuh puluh empat", "tujuh puluh lima", "tujuh puluh enam", "tujuh puluh tujuh", "tujuh puluh delapan", "tujuh puluh sembilan",
        "delapan puluh", "delapan puluh satu", "delapan puluh dua", "delapan puluh tiga", "delapan puluh empat", "delapan puluh lima", "delapan puluh enam", "delapan puluh tujuh", "delapan puluh delapan", "delapan puluh sembilan",
        "sembilan puluh", "sembilan puluh satu", "sembilan puluh dua", "sembilan puluh tiga", "sembilan puluh empat", "sembilan puluh lima", "sembilan puluh enam", "sembilan puluh tujuh", "sembilan puluh delapan", "sembilan puluh sembilan", "seratus"
    };

    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    cout << angka << ":" << huruf[angka] << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan1_Modul1/Unguided21_Modul1.png)

penjelasan unguided 2
Program adalah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Program diatas dibuat dengan menggunakan array.

### 3. Unguided 3
Berikan program yang dapat memberikan input dan output sbb
321*123
 21*12
  1*1
   *

```C++
source code unguided 3
#include <iostream>

using namespace std;

int main(){
	int tinggi = 3;
	
	for (int i = tinggi; i >=0; i--){
		for (int j = 0; j < tinggi-i; j++) {
			cout <<" ";
		}
		for(int s=i;s>=1;s--){
			cout<<s;
		}
		cout << "*";

		for(int s=1; s<=i; s++){
			cout<<s;
			}
		cout<< endl;
			
	}
	}
	

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan1_Modul1/Unguided31_Modul1.png)

penjelasan unguided 3
Program diatas adalah program yang ketika dijalankan langsung mengeluarkan output. Program menggunakan peneran perulangan for

## Kesimpulan
Dari program program diatas dapat disimpulkan bahwa bahasa C++ dalam tipe data hampir sama saja dengan bahasa pemrograman lainnya, baik dari segi struktur maupun logika. Misalnya, penggunaan variabel, operator, serta struktur kontrol seperti if-else, switch case, dan perulangan (for, while, do-while). Hal ini membuat C++ relatif mudah dipahami oleh pemula yang sudah mengenal bahasa lain, karena konsep dasarnya tetap sama yaitu menerima input, mengolah data, dan menampilkan output sesuai kebutuhan.

## Referensi
[1] Ma’arif, A. (2022). Dasar Pemrograman Bahasa C++. Yogyakarta: Universitas Ahmad Dahlan.

[2] R. D. Setiyawan, “Makalah peluang dan kombinatorika,” Google Drive, [Online]. Available: https://share.google/qaHRejBPTJz5h5zQx.[Accessed: 1 Nov. 2025].
