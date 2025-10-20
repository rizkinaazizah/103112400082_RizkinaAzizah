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
