# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
Pohon atau tree adalah salah satu bentuk konsep struktur data yang terdiri sari akar dan simpul-simpul yang berada dibawah akar.[1]

Pohon biner adalah pohon yang setiap simpulnya memiliki simpul turunan maksimal dua[1]

Operasi pada Pohon Biner
 1. PreeOrder
    Urutannya dimulai dari root-subpohon kiri-subpohon kanan
 2. InOrder
    Urutannya dimulai dari turunan subpohon kiri-root-subpohon kanan
 3. PostOrder
    Urutannya dimulai dari turunan subpohon kiri-subpohon kanan-root
 4. LevelOrder
    Urutannya dimulai dari simpul tingkat 1 dilanjut ke simpul tingkat 2 dan seterusnya dimulai dari simpul kiri ke kanan
 5. Menyalin dan Membandingkan Pohon Biner
 6. Implementasi Biner
    baisanya menggunakan pointer dan mengalokasikannya simpul di memori[1]
    
### A. Guided<br/>
...
#### 1. Guided2
#### 2. Guided3

### B. Unguided<br/>
...
#### 1. Unguided 1
#### 2. Unguided 2
#### 3. Unguided 3

## Guided 

### 1. Guided2
#### bst.cpp
```C++
    #include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
#### bst.h
```C++
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

#endif
```
#### main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}

```
Guided1 menerapkan struktur Binary Search Tree (BST), di mana setiap data dimasukkan ke posisi kiri atau kanan sesuai besar-kecilnya nilai. Dari tree ini kita bisa menampilkan data lewat beberapa cara seperti pre-order, in-order, dan post-order. Program juga punya fitur untuk menghitung berapa banyak node yang ada dan seberapa dalam tree tersebut. Intinya, BST ini dibuat supaya proses pencarian dan pengelolaan data bisa berjalan lebih terstruktur dan efisien.
### 2. Guided2

#### bst.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

```
#### bst.h
```C++
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

```
#### main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
penjelasan guided3
dilengkapi dengan fitur pencarian data yang memberikan informasi detail, seperti parent, sibling, dan child dari node tersebut. Program juga menyediakan fungsi untuk mendapatkan nilai minimum dan maksimum melalui pencarian ke subtree paling kiri dan paling kanan. Selain itu, proses penghapusan node telah menangani berbagai kondisi sehingga operasi pada tree dapat dilakukan secara lebih menyeluruh dan terstruktur.

## Unguided 
### 1. Unguided 
 Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
“bstree.h”:
Type infotype: integer
Type address : pointer to Node
Type Node: <
   info : infotype
   left, right : address
>
   function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address,
   input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )

Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil
implementasi ADT pada file “main.cpp”
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
cout << "Hello World" << endl;
   address root = Nil;
   insertNode(root,1);
   insertNode(root,2);
   insertNode(root,6);
   insertNode(root,4);
   insertNode(root,5);
   insertNode(root,3);
   insertNode(root,6);
   insertNode(root,7);
   InOrder(root);

return 0;
}

#### bst.cpp
``` C++
#include "bst.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL) return NULL;
    if (root->info == x) return root;
    if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

void inOrder(address root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}
```
#### bst.h
```C++
#ifndef BST_H
#define BST_H

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void inOrder(address root);

#endif

```
#### main.cpp
```C++
#include <iostream>
#include "bst.h"
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    cout << "Hello World!" << endl;

    auto start = high_resolution_clock::now();

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    inOrder(root);
    cout << "\n";

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << fixed << setprecision(3);
    cout << "Process returned 0 (0x0) execution time : " << elapsed.count() << " s" << endl;
    cout << "Press any key to continue." << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan10_Modul10/Unguided1/un1.png)

Program ini adalah implementasi dasar dari Binary Search Tree (BST) menggunakan bahasa C++.
Tujuannya supaya kita bisa menyimpan data angka, lalu melakukan operasi seperti menambah node, mencari data, dan melakukan traversal (penelusuran tree).

### 2. Unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer
/* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

int main() {
   cout << "Hello World" << endl;
   address root = Nil;
   insertNode(root,1);
   insertNode(root,2);
   insertNode(root,6);
   insertNode(root,4);
   insertNode(root,5);
   insertNode(root,3);
   insertNode(root,6);
   insertNode(root,7);
   InOrder(root);
   cout<<"\n";
   cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
   cout<<"jumlah Node : "<<hitungNode(root)<<endl;
   cout<<"total : "<<hitungTotal(root)<<endl;
   return 0;
}
```C++
source code unguided 2
```
#### bst.cpp
```C++
#include "bst.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL) return NULL;
    if (root->info == x) return root;
    if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

void inOrder(address root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info +
           hitungTotalInfo(root->left) +
           hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) return start;
    int left = hitungKedalaman(root->left, start + 1);
    int right = hitungKedalaman(root->right, start + 1);
    return (left > right ? left : right);
}
```
#### bst.h
```C++
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
```
#### main.cpp
```C++
#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    inOrder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}
```


### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan10_Modul10/Unguided2/un2.png)

penjelasan unguided 2
Program ini membangun Binary Search Tree (BST) dengan fitur menambah data, mencari data, menampilkan isi tree secara in-order, serta menghitung jumlah node, total nilai, dan kedalaman tree. Struktur BST membuat data otomatis terurut dan mudah dicari.

### 3. Unguided 3
Print tree secara pre-order dan post-order.
```C++
source code unguided 3
```
#### bst.cpp
```C++
#include <iostream>
#include "bst.h"
using namespace std;

Node* newNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(address &root, int x) {
    if (root == NULL) {
        root = newNode(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else {
        insertNode(root->right, x);
    }
}

void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

```
#### bst,h
```C++
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
```
#### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    cout << "Pre-order  : ";
    preOrder(root);
    cout << endl;

    cout << "Post-order : ";
    postOrder(root);
    cout << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan10_Modul10/unguided3/imageun3.png)

penjelasan unguided 3
Program ini membuat Binary Search Tree (BST) yang bisa memasukkan data dan menampilkannya lewat dua jenis traversal: pre-order dan post-order. Setiap data baru akan ditempatkan otomatis ke kiri atau kanan sesuai aturan BST, sehingga struktur tree tetap rapi dan mudah dibaca. Traversal digunakan untuk menunjukkan urutan kunjungan node sesuai jenis yang dipilih.

## Kesimpulan
Semua program tersebut sama-sama menerapkan konsep Binary Search Tree (BST) untuk menyimpan data secara terstruktur. Proses seperti insert, pencarian node, perhitungan jumlah node, sampai traversal (pre-order, in-order, post-order) dibuat untuk menunjukkan bagaimana BST bekerja dalam mengatur dan membaca data. Intinya, ketiga program ini membantu memahami cara tree dibangun, cara data dilacak, dan bagaimana isi tree bisa ditampilkan dengan berbagai urutan.

## Referensi
[1] Rosa A. S. M. Sholahuddin(2010). Modul Pembelajaran Sruktur Data. Penerbit Modula
