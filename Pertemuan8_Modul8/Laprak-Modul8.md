# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
 Queue (antrian) adalah barisan elemen apabila ditambah maka penambahannya berada di posisi belakang(rear) dan jika dilakukan pengambilan elemen dilakukan di elemen paling depan (front). Oleh karena itu, queue bersifat FIFO (first in first out)[1] Penalarannya penggunaan  algoritma  FIFO  ini  dimaksudkan agar urutan antrian pasien tetap pada urutan yang benar tanpa  merubah  urutan  yang  sudah  ada.  Penerapan algoritma  ini  membuat  tidak  mungkin  pasien  dapat melakukan  kecurangan terhadap  antrian  yang  dapat menimbulkan   masalah   yang   sama   seperti   ketika antrian dijalankan secara offlineatau luring.[2]

 Operasi-operasi dasar dari sebuah queue adalah:
 1. Enqueue : proses penambahan atau memasukkan satu elemen di belakang
 2. Dequeue : proses pengembalian atau mengeluarkan satu elemen di posisi depan[1]

 Queue dapat dibuat dengan menggunakan: Linear Array dan Circular Array[2]

 1. Linear Queue 
    Elemen ditambahkan di ujung belakang dan dihapus dari depan. Masalahnya, ruang yang kosong di depan tidak bisa digunakan kembali setelah elemen dikeluarkan.
 2. Circular Queue
    Merupakan pengembangan dari linear queue. Indeks akan kembali ke awal ketika mencapai akhir array jika ada ruang kosong — efisien dalam memanfaatkan memori
 Contoh Penggunaan Queue dalam Dunia Nyata
 Sistem Operasi: Scheduler CPU menggunakan queue untuk menangani proses yang menunggu giliran eksekusi.
 Jaringan Komputer: Paket data disimpan dalam queue sebelum dikirim ke tujuan.
 Pemrosesan Pesan: Sistem messaging seperti Kafka atau RabbitMQ menggunakan queue untuk menyimpan dan memproses     antrian  pesan.
 Customer Support: Antrean pengguna yang menghubungi layanan pelanggan dikelola dengan queue.
 Multithreading: Queue digunakan untuk berbagi data antara proses/threads agar tidak bentrok (thread-safe queue).[3]

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
#### Queue.cpp
```C++
    return nodeBaru;
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;

};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi (int angka);
void alokasi (queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```
#### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int mai(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createQueue(Q);

    nodeA = alokasi(1);
    nodeA = alokasi(2);
    nodeA = alokasi(3);
    nodeA = alokasi(4);
    nodeA = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);

    cout<<endl;

    cout<<"---Queue setelah enQueue---"<<endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout<<"---Queue setelah deQueue 2 kali---"<< endl;
    viewQueue(Q);
    cout<<endl;

    updateQueue(Q,2);
    updateQueue(Q,1);
    updateQueue(Q,4);
    cout<<endl;

    cout<<"---Queue Setelah Update---"<<endl;
    viewQueue(Q);
    cout<<endl;

    searchData(Q,4);
    searchData(Q,9);

    return 0;
}

```
Guided1 mengimplementasikan Queue berbasis linked list, yang memungkinkan penambahan data di bagian belakang (enqueue) dan penghapusan data di bagian depan (dequeue) secara efisien. Queue disusun dari node yang saling terhubung sehingga tidak memerlukan pergeseran elemen seperti pada array.

### 2. Guided2

#### Queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {//buat que kosong
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0 //nge return true kalau dah penuh
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {//ngeluarin data ujung kepala
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}

```
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5 //isi  mkasimal array

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;//melihat isi que

};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x); //tambah
int dequeue(Queue &Q);//hapus
void printInfo(Queue Q);
#endif

```
#### main.cpp
```C++
#include<iostream>
#include"queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout<<"\nEnqueue 3 Elemen"<<endl;
    enqueue(Q,5);
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);

    cout<<"\nDequeue 1 Elemen"<<endl;
    cout<<"Elemen keluar:"<<dequeue(Q)<<endl;
    printInfo(Q);

    cout << "\nDequeue 2 Elemen"<<endl;
    cout << "Elemen keluar:"<<dequeue(Q)<<endl;
    cout << "Elemen keluar:"<<dequeue(Q)<<endl;
    printInfo(Q);

    return 0;
}
```
penjelasan guided2
mengimplementasikan ADT Queue menggunakan array dengan mekanisme circular, di mana posisi head dan tail akan berputar kembali ke indeks awal ketika mencapai batas array. Pendekatan ini membuat penggunaan memori menjadi lebih efisien karena seluruh elemen array dapat dimanfaatkan tanpa perlu melakukan penggeseran data. 

## Unguided 
 Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
 Type infotype: integer
 Type Queue: <
    info : array [5] of infotype {index array dalam C++
    dimulai dari 0}
    head, tail : integer
 >
 procedure CreateQueue (input/output Q: Queue)
 function isEmptyQueue (Q: Queue) → boolean
 function isFullQueue (Q: Queue) → boolean
 procedure enqueue (input/output Q: Queue, input x: infotype)
 function dequeue (input/output Q: Queue) → infotype
 procedure printInfo (input Q: Queue)
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5 //isi  mkasimal array

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;//melihat isi que

};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x); //tambah
int dequeue(Queue &Q);//hapus
void printInfo(Queue Q);
#endif

```
#### main.cpp
```C++
#include<iostream>
#include"queue.h"

using namespace std;

int main(){
    cout << "Hello Word"<< endl;
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout<<"----------------------"<<endl;
    cout<<"H - T \t  | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5);//insert
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);
    dequeue(Q);printInfo(Q);
    enqueue(Q,4);printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```
### 1. Unguided 1
 Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
 queue Alternatif 1 (head diam, tail bergerak).
```C++
source code unguided 1
```
#### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0;
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE;
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[0] = x;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }

    Q.count++;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[0];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        for (int i = 0; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--; 
    }

    Q.count--;
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "   | ";

    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = 0; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan8_Modul8/unguided1/imageun1.png)

Implementasi ini menjaga head selalu di posisi awal array (indeks 0), yang berarti operasi dequeue memerlukan pergeseran (shifting) semua elemen yang tersisa satu posisi ke kiri untuk menempati posisi kosong di depan. Sementara itu, enqueue selalu menambahkan elemen di ujung antrian dan memajukan tail hingga array penuh. Kelemahannya adalah biaya komputasi yang tinggi untuk setiap operasi dequeue karena adanya proses pergeseran.

### 2. Unguided 2
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 2 (head bergerak, tail bergerak).

```C++
source code unguided 2
```
#### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
    Q.count++;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];

    // Head maju
    if (Q.head == Q.tail) {
        // Jika elemen tinggal satu → reset ke empty state
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }

    Q.count--;
    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "-1 - -1 | empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }

    cout << endl;
}

```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan8_Modul8/unguided2/imageun2.png)

penjelasan unguided 2
Pada model ini, baik head maupun tail akan terus bergerak maju seiring dengan operasi dequeue dan enqueue. Dequeue dilakukan di posisi head, lalu head dimajukan, sedangkan enqueue dilakukan di posisi tail, lalu tail dimajukan. Keuntungannya adalah cepat karena tidak ada pergeseran elemen, namun kerugian fatalnya adalah tidak efisiennya pemakaian memori, karena antrian akan segera dianggap penuh ketika tail mencapai batas akhir array, meskipun banyak ruang kosong tersisa di awal array (sebelum posisi head).

### 3. Unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 3 (head dan tail berputar)
```C++
source code unguided 3
```
#### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0;
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE;
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    Q.info[Q.tail] = x;
    Q.tail = (Q.tail + 1) % MAX_QUEUE;  // berputar
    Q.count++;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];
    Q.head = (Q.head + 1) % MAX_QUEUE; // berputar
    Q.count--;

    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << " - " << Q.tail << " | empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " | ";

    int i = Q.head;
    int n = 0;

    while (n < Q.count) {
        cout << Q.info[i] << " ";
        i = (i + 1) % MAX_QUEUE;
        n++;
    }

    cout << endl;
}

```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan8_Modul8/unguided3/imageun3.png)

penjelasan unguided 3
Implementasi ini mengatasi masalah pemborosan memori pada Alternatif 2 dengan menggunakan aritmatika modulo (\%MAX\_QUEUE) untuk memungkinkan head dan tail berputar (circular) dari akhir array kembali ke awal array jika tersedia ruang kosong.  Kedua pointer ini bergerak maju secara independen, dan queue hanya dianggap penuh ketika tidak ada ruang kosong tersisa di seluruh array, sehingga memaksimalkan penggunaan memori array yang dialokasikan.

## Kesimpulan
Ketiga alternatif implementasi Queue pada array menunjukkan perbedaan strategi dalam efisiensi memori dan waktu operasi.
Alternatif 1 (Shifting) menggunakan seluruh elemen array, tetapi operasi dequeue menjadi lambat karena harus menggeser elemen (O(n)).
Alternatif 2 (Linear Moving Head–Tail) membuat operasi enqueue dan dequeue lebih cepat (O(1)), namun ruang kosong di awal array tidak dapat dimanfaatkan kembali sehingga penggunaan memorinya kurang efisien.
Alternatif 3 (Circular Queue) menawarkan solusi paling optimal, karena tetap mempertahankan efisiensi waktu O(1) dan sekaligus memaksimalkan pemakaian array dengan memutar posisi head dan tail menggunakan operasi modulo.

## Referensi
[1] Dharmayanti, D. (2011). Queue.
<br>[2] Gunawan, R., Yuana, H., & Kirom, S. (2023). Implementasi Metode Queue Pada Sistem Antrian Online Berbasis Web Studi Kasus Uptd Puskesmas Sananwetan. JATI (Jurnal Mahasiswa Teknik Informatika), 7(3), 1538-1545.
<br>[3] Telkom University, “Queue: Pengertian, fungsi, dan jenisnya,” Jul. 28, 2025.