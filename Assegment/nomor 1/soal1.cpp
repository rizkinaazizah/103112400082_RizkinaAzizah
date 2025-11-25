#include <iostream>
using namespace std;

string Node{
    string nama;
    Node*next;  
};

Node* head = NULL;

void insertAkhir(string nama){ 
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    if(head== NULL){
        head = baru;
    } else {
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void deleteNama(string nama){
    Node* temp = head;
    Node* prev = NULL;

    while(temp){
        if (temp->nama == nama){
            Node* temp = head;
            Node* prev = NULL;
            while(temp){
                if (temp->nama == nama){
                    if (prev == NULL){
                        head = temp->next;
                    }else{
                        prev->next = temp->next;
                    }
                    delete temp;
                    return;
                }  }
        }
    }
}

void viewList() {
    Node* temp = head;
    while (temp) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}



