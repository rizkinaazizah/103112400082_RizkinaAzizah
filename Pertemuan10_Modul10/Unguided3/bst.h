#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
};

typedef Node* address;

Node* newNode(int x);
void insertNode(address &root, int x);

void preOrder(address root);
void postOrder(address root);

#endif
