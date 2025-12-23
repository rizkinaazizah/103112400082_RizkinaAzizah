#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

bool isEmpty(Node* root);
void createTree(Node*& root);
Node* newNode(string nama, float berat, string tier);
void insertNode(Node*& root, string nama, float berat, string tier);
Node* searchByBeratBadan(Node* root, float berat);
Node* mostLeft(Node* root);
Node* mostRight(Node* root);
void inOrder(Node*root);


#endif // BST_H
