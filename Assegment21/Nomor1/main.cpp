#include "bst.h"
#include <iostream>
using namespace std;

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->beratBadan << " ";
        inOrder(root->right);
    }
}

Node* mostLeft(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* mostRight(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}

int main() {
    Node* root;
    createTree(root);
    insertNode(root, "Rizkina Azizah", 60, "Basic");
    insertNode(root, "Hakan Ismail", 50, "Basic");
    insertNode(root, "Yusuf Rizki", 47, "Basic");
    insertNode(root, "Mutiara Fauziah", 52, "Basic");
    insertNode(root, "Rizal Akbar", 56, "Basic");
    insertNode(root, "Hanif Al Faiz", 70, "Basic");
    insertNode(root, "Aulia Rahman", 65, "Basic");
    insertNode(root, "Dewi Lestari", 68, "Basic");
    insertNode(root, "Fahmi Ramadhan", 81, "Basic");

    cout << "=== Traversal InOrder ===\n";
    inOrder(root);
    cout << endl;

    Node* left = mostLeft(root);
    Node* right = mostRight(root);
    if (left) cout << "Node MostLeft : " << left->beratBadan << endl;
    if (right) cout << "Node MostRight : " << right->beratBadan << endl;

    float cari = 70;
    Node* hasil = searchByBeratBadan(root, cari);
    if (hasil) {
        cout << "Data ditemukan didalam BST!\n--- Data Node Yang Dicari ---\n";
        cout << "Nama Member : " << hasil->namaMember << endl;
        cout << "Berat Badan : " << hasil->beratBadan << endl;
        cout << "Tier Member : " << hasil->tierMember << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }













    
    return 0;
}