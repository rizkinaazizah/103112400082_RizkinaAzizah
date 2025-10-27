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

