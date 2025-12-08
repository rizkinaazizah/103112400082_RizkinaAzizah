#ifndef BST1_H
#define BST1_H

#include<iostream>
uisng namespace std;

typedef int infotype;
typedef struct Node*address;

struct Node{
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root); //function untuk membyat BSTnya root di set sebagai NULL

//alokasi&insert
address newNode(infotype x); //function untuk memasukkan data(infotype) kedalam node
address insertNode(address root, infotype x);

//traversal
void preOrder(address root);//tengah-kiri-kanan
void inOrder(address root);//kiri-tengah-kanan
void postOrder(address root);//kiri-kanan-tengah
//utilites
int countNodes(address root);//untuk menghitung ukuran atau jumlah dalam tree
int treeDepth(address root);

void searchByData(address root, infotype x);
address mostleft(address root);
address mostRight(address root);

bool deleteNode(address &root, infotype x);
void deleteTree(address &root);

#endif



