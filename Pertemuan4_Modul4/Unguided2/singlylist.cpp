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
