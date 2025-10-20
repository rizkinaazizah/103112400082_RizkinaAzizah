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
