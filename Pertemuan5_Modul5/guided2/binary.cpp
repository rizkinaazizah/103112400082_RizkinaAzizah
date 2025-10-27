#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
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

Node*binarySearch(Node*head, int key){// Node* pointer kembalian / head = pointer ke node pertama/ key = data yang dicari
    int size = 0;
    for(Node*current=head; current; current=current->next)size++;

    Node *start=head;// start = pointer yang menunjuk ke node pertama
    Node* end=nullptr;

    while(size>0){
        int mid = size/2;
        Node*midNode=start;

        for(int i=0; i<mid; ++i)midNote=midNote->Next;

        if(midNote->data==key)return midNote;
        if(midNote->data<key){
            start=midNote->next;
        }
        else{
            end=midNode;
        }
        size-=mid;//kita mengurangi size dengan mid
    }
    return nullptr;
};

int main(){
    Node*head = nullptr;
    append(head, 10);append(head, 20);append(head, 30); append (head, 40); append(head 50);

    Node*result=binarySearch(head, 40);
    cout<<(result?"Found":"Not Found")<<endl;

    return 0;
}