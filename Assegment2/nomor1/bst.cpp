#include "BST1.h"
#include <iostream>

using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

// Mengecek apakah BST kosong
bool isEmpty(Node* root) {
    return root == nullptr;
}

// Membuat BST (root di-set NULL)
void createTree(Node*& root) {
    root = nullptr;
}

address newNode(infotype x) { 
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Memasukkan node ke dalam BST
void insertNode(Node*& root, string nama, float berat, string tier) {
    if (root == nullptr) {
        root = newNode(nama, berat, tier);
    } else if (berat < root->beratBadan) {
        insertNode(root->left, nama, berat, tier);
    } else {
        insertNode(root->right, nama, berat, tier);
    }
}

// Mencari member berdasarkan berat badan
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

// Contoh penggunaan
int main() {
    Node* root;
    createTree(root);
    insertNode(root, "Andi", 70.5, "Gold");
    insertNode(root, "Budi", 65.2, "Silver");
    insertNode(root, "Cici", 80.0, "Platinum");
    float cariBerat = 65.2;
    Node* hasil = searchByBeratBadan(root, cariBerat);
    if (hasil != nullptr) {
        cout << "Member ditemukan: " << hasil->namaMember << ", Berat: " << hasil->beratBadan << ", Tier: " << hasil->tierMember << endl;
    } else {
        cout << "Member dengan berat badan " << cariBerat << " tidak ditemukan." << endl;
    }
    return 0;
}


