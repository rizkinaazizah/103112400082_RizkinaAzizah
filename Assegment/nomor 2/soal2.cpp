#include <iostream>
using namespace std;

string Node{
    string nama;
    Node*prev;
    Node*next;
    
};

Node* head = NULL;
Node* tail = NULL;

void insertAkhir(int nilai){ 
    Node* baru = new Node;
    baru->nilai = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if(head== NULL){
        head = tail= baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void deleteAkhir() {
    if (tail == NULL) {
        cout << "List kosong.\n";
        return;
    }
    Node* hapus = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete hapus;
    cout << "Nilai terakhir dihapus.\n";
}

void viewDepan() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void viewBelakang() {
    Node* temp = tail;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

