# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (Bagian Kedua)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
Menurut pendapat (Sihombing et al., 2020) pendekatan Array dan Linked list adalah dua cara umum
untuk mengimplementasikan Stack. Berikut adalah perbandingan kinerja penggunaan Stack dengan
pendekatan Array dan Linked list dalam beberapa aspek: a. Alokasi memori: Array: membutuhkan
alokasi memori statis pada saat deklarasi. Ukuran Array harus ditentukan sebelumnya, dan perubahan
ukuran dapat memerlukan pembuatan Array baru dan pengalihan data. Linked list: memungkinkan
alokasi memori dinamis, yang berarti ukuran Stack dapat bertambah atau berkurang secara dinamis
tanpa harus menentukan ukuran sebelumnya. B. Penyisipan dan penghapusan elemen: Array:
penyisipan dan penghapusan elemen di tengah Array (bukan di ujung) dapat memerlukan pergeseran
elemen, yang dapat memakan waktu pada Stack yang besar. Linked list: penyisipan dan penghapusan
elemen di tengah Stack dilakukan dengan mengubah tautan antar simpul, yang lebih efisien daripada
pergeseran elemen pada Array. C. Akses ke elemen tertentu: Array: akses ke elemen tertentu dalam
Array dilakukan secara langsung melalui indeks. Proses ini memiliki kompleksitas waktu (1). Linked
list: akses ke elemen tertentu dalam Linked list memerlukan penelusuran dari awal hingga elemen yang
diinginkan, yang memiliki kompleksitas waktu o (n) [1]

### A. Guided<br/>
...
#### 1. Guided1
#### 2. Guided2

### B. Unguided<br/>
...
#### 1. Unguided 1
#### 2. Unguided 2

## Guided 

### 1. Guided1
#### listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

```
#### listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct buah{
    string nama; 
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias data buah struct buah
typedef struct node*address;

struct node{
    dataBuah isidata;
    address next;

};

struct linkedlist{
    address first;
};

//semua function dan prosedur yang akan dipakai
//Materi modul4

bool isEmpty(linkedlist List);
void createList(linkedlist List);
address alokasi(string nama, int jumlkah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist List, address nodeBaru);
void insertAfter(linkedlist List, address nodeBaru, address Prev);
void insertLast(linkedlist List, address nodeBaru);
void delFirst(linkedlist List);
void delLast(linkedlist List);
void delAfter(linkedlist List, address nodeHapus, address nodePrev);
void nbList(linkedList List)
void deleteList(linkedlist List);

//material modul 5 (part1-update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedList List, address prev);

#endif
```
#### main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi ("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"----ISI LIST SETELAH DILAKUKAN INSERT----"<< endl;
    printList(List);
    cout<<"jumlah node : "<< nbList (List)<<endl;
    cout<< endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List);

    cout << "---ISI LIST SETELAH DILAKUKAN UPDATE---"

}
```
Program ini merupakan implementasi Single Linked List dalam C++ untuk mengelola data buah yang terdiri dari nama, jumlah, dan harga. Program dapat menambah, menghapus, menampilkan, serta memperbarui data node menggunakan berbagai fungsi. Selain itu, program juga dapat menghitung jumlah node, menampilkan isi list, serta mengelola memori dengan fungsi alokasi dan dealokasi, sehingga seluruh data buah dapat diatur secara dinamis dan efisien di dalam struktur linked list.

### 2. Guided2
#### Binary
```C++
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};
void append(Node*&head, int value){
    Node*newNode= new Node{value, nullptr};
    if(!head)head=newNode;

    else{
        Node*temp=head;
        while (temp->next){
            temp=temp->next;
        }
        temp->next = newNode;

    }

};

Node*binarySearch(Node*head, int key){// Node* pointer kembalian / head = pointer ke node pertama/ key = data yang dicari
    int size = 0;
    for(Node*current=head; current; current=current->next)size++;

    Node *start=head;// start = pointer yang menunjuk ke node pertama
    Node* end=nullptr;

    while(size>0){
        int mid = size/2;
        Node*midNode=start;

        for(int i=0; i<mid; ++i)midNote=midNote->Next;

        if(midNote->data==key)return midNote;
        if(midNote->data<key){
            start=midNote->next;
        }
        else{
            end=midNode;
        }
        size-=mid;//kita mengurangi size dengan mid
    }
    return nullptr;
};

int main(){
    Node*head = nullptr;
    append(head, 10);append(head, 20);append(head, 30); append (head, 40); append(head 50);

    Node*result=binarySearch(head, 40);
    cout<<(result?"Found":"Not Found")<<endl;

    return 0;
}
```

#### linear

```C++
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next
};
void append(Node*&head, int value){
    Node*newNode= new Node{value, nullptr};
    if(!head)head=newNode;

    else{
        Node*temp=head;
        while (temp->next){
            temp=temp->next;
        }
        temp->next = newNode;

    }

};

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong

    append(head, 10); //menambah node
    append(head, 20);
    append(head, 30);
    append(head, 40);

    Node* result = linearSearch(head, 20); // result ini pointer untuk mencari data 20

    cout << (result ? "Found" : "NotFound") << endl;

    return 0;
}
```
Program dibuat untuk menampilkan aritmatika ketika user memasukkan 2 angka program akan menampilkan output aritmatika dalm bentuk penjumlahan, pengurangan, perkalian, pembagian, dan sisa hasil bagi 

## Unguided 

### 1. Unguided 1
Implementasikan program C++ yang menggunakan algoritma Binary 
Search pada Linked List untuk mencari elemen tertentu. Program 
harus mampu: 
1. Membuat linked list dengan menambahkan node di akhir 
2. Mengimplementasikan binary search pada linked list 
3. Menampilkan detail proses pencarian dan hasil akhir 
```C++
source code unguided 1
#include <iostream>
using namespace std;

// Struktur buat nyimpen data dan nyambung ke node berikutnya
struct Node {
    int data;      // isinya angka
    Node* next;    // penunjuk ke kotak (node) setelahnya
};

// Fungsi buat nambahin data di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; // bikin kotak baru
    if (!head) head = newNode; // kalau belum ada kotak sama sekali, ini jadi kotak pertama
    else {
        Node* temp = head;
        // cari kotak terakhir
        while (temp->next) temp = temp->next;
        // sambungin kotak baru di belakangnya
        temp->next = newNode;
    }
}

// Fungsi buat ngitung berapa banyak kotak (node)
int getSize(Node* head) {
    int size = 0;
    for (Node* current = head; current; current = current->next)
        size++; // tiap ketemu kotak, tambah 1
    return size;
}

// Fungsi buat ngambil node di posisi ke-n
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++)
        head = head->next; // geser ke depan sampai posisi yang dimau
    return head;
}

// Fungsi binary search di linked list
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    int size = getSize(head);       // hitung dulu berapa banyak kotak
    int left = 0, right = size - 1; // batas kiri dan kanan
    int iter = 1;                   // buat nandain iterasi keberapa

    while (left <= right) {
        int mid = (left + right) / 2;          // cari posisi tengah
        Node* midNode = getNodeAt(head, mid);  // ambil node tengah

        cout << "Iterasi " << iter++ << ": Tengah = " << midNode->data;

        if (midNode->data == key) { // kalau isinya sama kayak yang dicari
            cout << " -> KETEMU!\n";
            cout << "\nNilai " << key << " ketemu di linked list!\n";
            cout << "Alamat node: " << midNode << endl;
            if (midNode->next)
                cout << "Node setelahnya: " << midNode->next->data << endl;
            else
                cout << "Node setelahnya: NULL (udah terakhir)\n";
            return midNode;
        }
        else if (midNode->data < key) { // kalau nilai tengah lebih kecil
            cout << " -> Cari di kanan\n";
            left = mid + 1; // geser batas kiri
        }
        else { // kalau nilai tengah lebih besar
            cout << " -> Cari di kiri\n";
            right = mid - 1; // geser batas kanan
        }
    }

    // kalau udah habis tapi belum ketemu
    cout << "\nNilai " << key << " nggak ketemu di linked list!\n";
    return nullptr;
}

// Fungsi buat nampilin isi linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "[" << temp->data << "]";
        if (temp->next)
            cout << " → "; // tanda panah ke node berikutnya
        temp = temp->next;
    }
    cout << " → NULL\n"; // tanda akhir list
}

int main() {
    Node* head = nullptr;

    // Bikin linked list-nya
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked list yang dibuat: ";
    printList(head);

    //cari data yang ada
    cout << "\nCari nilai 40:\n";
    binarySearch(head, 40);

    //cari data yang nggak ada
    cout << "\nCari nilai 25:\n";
    binarySearch(head, 25);

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan5_Modul5/Unguided1/output-unguided1.png)

Penjelasan unguided 1
Program ini merupakan implementasi algoritma Binary Search pada Linked List menggunakan bahasa C++. Program membuat linked list dengan menambahkan elemen di akhir melalui fungsi append(), lalu melakukan pencarian elemen menggunakan fungsi binarySearch(). Fungsi ini menentukan ukuran list, mencari elemen tengah (mid), dan membandingkan nilainya dengan data yang dicari. Jika cocok, program mengembalikan alamat node tersebut; jika tidak, pencarian dilanjutkan ke bagian kiri atau kanan list hingga data ditemukan atau seluruh node diperiksa.

### 2. Unguided 2
Tugas 2. 
Implementasikan program C++ yang menggunakan algoritma Linear 
Search pada Linked List untuk mencari elemen tertentu. Program 
harus mampu: 
1. Membuat linked list dengan menambahkan node di akhir 
2. Mengimplementasikan linear search pada linked list 
3. Menampilkan detail proses pencarian dan hasil akhir
```C++
source code unguided 2
#include <iostream>
using namespace std;

// Struktur buat node (kotak data)
struct Node {
    int data;      // isi data
    Node* next;    // penunjuk ke node berikutnya
};

// Fungsi buat nambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; // bikin kotak baru
    if (!head) head = newNode; // kalau belum ada kotak, maka bakal jadi kotak pertama
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; // cari ujung list
        temp->next = newNode; // sambungin ke kotak baru
    }
}

// Fungsi buat nampilin isi linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> "; // tampilkan isi kotak (data), terus kasih tanda panah biar keliatan nyambung
        temp = temp->next; // geser pointer ke kotak berikutnya
    }
    cout << "NULL" << endl;// tampilkan tulisan NULL buat nandain akhir dari rantai linked list
}


// Fungsi linear search di linked list
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";

    Node* current = head; // mulai dari node pertama
    int posisi = 1; // buat nandain urutan node

    while (current) {
        cout << "Memeriksa node " << posisi << ": " << current->data;
        if (current->data == key) { // kalau data di node sekarang sama kayak yang dicari
            cout << " (SAMA) - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            if (current->next) // cek apakah node berikutnya masih ada
                cout << "Node berikutnya: " << current->next->data << endl;
            else
                cout << "Node berikutnya: NULL\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next; // geser ke node berikutnya
        posisi++;//biar tahu lagi di urutan keberapa
    }

    // kalau data nggak ketemu
    cout << "Tidak ada node lagi yang tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    // bikin list-nya
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: ";
    printList(head);

    // cari nilai yang ada
    cout << "Mencari nilai: 30\n";
    linearSearch(head, 30);

    // cari nilai yang tidak ada
    cout << "\nMencari nilai: 25\n";
    linearSearch(head, 25);

    return 0;
}

```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan5_Modul5/Unguided2/output-unguided2.png)

penjelasan unguided 2
Program ini merupakan implementasi Linear Search pada Linked List menggunakan C++. Program ini membuat struktur Node untuk menyimpan data dan pointer ke node berikutnya. Fungsi append() digunakan untuk menambahkan node baru di akhir list, sedangkan printList() menampilkan isi list secara berurutan. Fungsi utama linearSearch() menelusuri setiap node dari awal hingga akhir untuk mencari nilai tertentu (key), sambil menampilkan proses pengecekan pada setiap langkah.

## Kesimpulan
Dari program program diatas dapat disimpulkan bahwa semua program menunjukkan cara kerja dasar struktur data Linked List dalam berbagai operasi penting, seperti menambah node (append/insert), menghapus dan memperbarui data, serta mencari elemen menggunakan Linear Search dan Binary Search.
Masing-masing program membantu memahami bagaimana node saling terhubung melalui pointer, bagaimana data diolah secara dinamis di memori, serta bagaimana algoritma pencarian dan manipulasi list dijalankan langkah demi langkah. Secara keseluruhan, program-program ini melatih logika dalam pengelolaan data terstruktur secara manual tanpa menggunakan array statis.

## Referensi
[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan struktur data stack dalam pemrograman C++ dengan pendekatan array dan linked list. Volume 5, Nomor 2, Desember 2024, 484. Fakultas Ilmu Komputer, Universitas Pamulang.
