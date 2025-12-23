#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>

using namespace std;


typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;

};

struct listAnak{
    NodeChild first;
    NodeChild last;
};

struct NodeParent{
    string idGenre;
    string namaGenre;
    NodeChild next;
    NodeChild prev;

};

struct listInduk{
    NodeParent first;
    NodeParent last;
};

void createListParent(listInduk &LInduk);
void createListChild(listAnak &Anak);

NodeParent alokasiNodeParent(string idKAtegoriMakanan, string namaKategoriMakanan);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);
void dealokasiNodeChild(NodeChild &NodeAnak);

void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void hapusListChild(listAnak &LAnak, NodeChild nodePrev);

void searchFilmByratingRange(listInduk &LInduk, float minRating, float maxRating);
void printStrukturMLL(listInduk &LInduk);

#endif






