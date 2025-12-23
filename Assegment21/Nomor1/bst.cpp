#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(Node* root) {
    return root == nullptr;
}

void createTree(Node*& root) {
    root = nullptr;
}

Node* newNode(string nama, float berat, string tier) {
    Node* node = new Node;
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void insertNode(Node*& root, string nama, float berat, string tier) {
    if (root == nullptr) {
        root = newNode(nama, berat, tier);
    } else if (berat < root->beratBadan) {
        insertNode(root->left, nama, berat, tier);
    } else {
        insertNode(root->right, nama, berat, tier);
    }
}

Node* searchByBeratBadan(Node* root, float berat) {
    if (root == nullptr) {
        return nullptr;
    } else if (berat == root->beratBadan) {
        return root;
    } else if (berat < root->beratBadan) {
        return searchByBeratBadan(root->left, berat);
    } else {
        return searchByBeratBadan(root->right, berat);
    }
}

Node* mostLeft(Node* root) { 
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* mostRight(Node* root) { 
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

void inOrder(Node* root) { 
    if (root != NULL) {
        inOrder(root->left);
        cout << root->namaMember << " ";
        inOrder(root->right);
    }
}



