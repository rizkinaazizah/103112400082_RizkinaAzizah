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






