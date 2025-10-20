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
