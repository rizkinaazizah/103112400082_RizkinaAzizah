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