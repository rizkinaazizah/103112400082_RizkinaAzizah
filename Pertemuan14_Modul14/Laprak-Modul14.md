# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH </h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
A. Definisi Graph
   Dalam bidang matematika dan ilmu komputer, teori graf mempelajari tentang graf yaitu struktur yang menggambarkan relasi antar objek dari sebuah koleksi objek.[2]

   Definisi dari suatu graf adalah himpunan benda benda yang disebut verteks (atau node) yang terhubung oleh sisi (atau edge atau arc). Biasanya graf digambarkan sebagai kumpulan titik-titik (melambangkan verteks) yang dihubungkan oleh garis-garis (melambangkan sisi).[1]

   Dalam bidang ilmu komputer, sebuah graf dapat dinyatakan sebagai sebuah struktur data, atau secara spesifik dinamakan sebagai ADT(abstract data type) yang terdiri dari kumpulan simpul dan sisi yang membangun hubungan antar simpul. Konsep ADT graf ini merupakan turunan konsep graf dari bidang kajian matematika.[2]

   Dalam matematika, graph adalah himpunan berpasangan dari (V,E) dimana V adalah himpunan vertex (titik) dan E adalah himpunan edge (garis) yang menghubungkan antar vertex. Setiap vertex dapat memiliki lebih dari satu hubungan dengan vertex yang lain (Ruohonen, 2013).[3]

B. Jenis Graph
Secara umum terdapat dua macam representasi dari struktur data graf yang dapat diimplementasi: 
- Pertama, disebut adjacency list, dan diimplementasi dengan menampilkan masing-masing simpul sebagai sebuah struktur data yang mengandung senarai dari semua simpul yang saling berhubungan
- Yang kedua adalah representasi berupa adjacency matrix dimana baris dan kolom dari matriks (jika dalam konteks implementasi berupa senarai dua dimensi) tersebut merepresentasikan simpul awal dan simpul tujuan dan sebuah entri di dalam senarai yang menyatakan apakah terdapat sisi di antara kedua simpul tersebut.[2]

Berdasarkan orientasi arah pada sisi, secara umum graf dapat dibedakan menjadi 2 jenis:
1. Graf tak berarah (undirected graph): Graf yang sisinya tidak mempunyai orientasi arah. Pada graf tak-berarah, urutan pasangan simpul yang dihubungkan oleh sisi tidak diperhatikan.
2. Graf Berarah (directed graph): Graf yang setiap sisinya memiliki orientasi arah. Sisi berarah dalam graf ini dapat dinamakan sebagai busur (arc).[1]


    
### A. Guided<br/>
...
#### 1. Guided

### B. Unguided<br/>
...
#### 1. Unguided 

## Guided 

### 1. Guided
#### graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}

```
#### graph_init.h
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}

```
#### graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}

```
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode nextNode;
};

struct elmGraph {
    adrNode first;
};

typedef struct elmGraph *Graph;

//Prototype
void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif

```
#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}

```
Guided ini mengimplementasikan graph tidak berarah menggunakan linked list untuk merepresentasikan node dan edge. Setiap node disimpan dalam list utama, sedangkan hubungan antar node (edge) disimpan dalam list terpisah pada setiap node. Program menyediakan operasi untuk membuat graph, menambahkan node, menghubungkan node, dan menampilkan seluruh struktur graph.

## Unguided 
### 1. Unguided 
1. Buatlah ADT Graph tidak berarah file “graph.h”:
Type infoGraph: char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
    info : infoGraph
    visited : integer
    firstEdge : adrEdge
    Next : adrNode
>
Type ElmEdge <
    Node : adrNode
    Next : adrEdge
>
Type Graph <
    first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph,
    input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)

Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT
pada file “main.cpp”.

2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.prosedur PrintDFS (Graph G, adrNode N);

3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);

#### graph.cpp
``` C++
#include "graph.h"
#include <iostream>
using namespace std;

//NOMOR 1 
void CreateGraph(Graph *G) {
    G->first = NULL;
}

void InsertNode(Graph *G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G->first == NULL)
        G->first = P;
    else {
        adrNode Q = G->first;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->Node = N2;
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->Node = N1;
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

// NOMOR 2 
void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->Node);
        E = E->Next;
    }
}

//NOMOR 3
void PrintBFS(Graph G, adrNode N) {
    adrNode Q[20];
    int front = 0, rear = 0;

    N->visited = 1;
    Q[rear++] = N;

    while (front < rear) {
        adrNode P = Q[front++];
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q[rear++] = E->Node;
            }
            E = E->Next;
        }
    }
}

```
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
typedef struct ElmEdge {
    adrNode Node;      
    adrEdge Next;    
} ElmEdge;

typedef struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
} ElmNode;

typedef struct {
    adrNode first;
} Graph;

void CreateGraph(Graph *G);
void InsertNode(Graph *G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

//NOMOR 2 
void PrintDFS(Graph G, adrNode N);

//NOMOR 3
void PrintBFS(Graph G, adrNode N);

#endif

```
#### main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->Next;
    }
    return NULL;
}

int main() {
    Graph G;
    CreateGraph(&G);

    InsertNode(&G, 'A');
    InsertNode(&G, 'B');
    InsertNode(&G, 'C');
    InsertNode(&G, 'D');
    InsertNode(&G, 'E');
    InsertNode(&G, 'F');
    InsertNode(&G, 'G');
    InsertNode(&G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(Gg, H);
    ConnectNode(F, H);
    ConnectNode(E, H);
    ConnectNode(D, H);

    ConnectNode(C, Gg);
    ConnectNode(C, F);

    ConnectNode(B, E);
    ConnectNode(B, D);

    ConnectNode(A, C);
    ConnectNode(A, B);

    cout << "Graph:" << endl;
    PrintInfoGraph(G);

    cout << endl << "DFS dari A:" << endl;
    PrintDFS(G, A);

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << endl << endl << "BFS dari A:" << endl;
    PrintBFS(G, A);

    return 0;
}

```

### Output Unguided  :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan14_Modul14/Unguided/outputUn.png)

Nomor 1: Program membuat graph kosong, menambahkan node, dan menghubungkan dua node menggunakan operasi CreateGraph, InsertNode, dan ConnectNode. Setiap node menyimpan informasi, status visited, dan daftar edge yang menghubungkannya dengan node lain.

Nomor 2: Program mengimplementasikan Depth First Search (DFS) untuk menelusuri graph secara mendalam. DFS dimulai dari node tertentu dan menelusuri seluruh node yang terhubung secara rekursif, memastikan setiap node dikunjungi satu kali sesuai urutan adjacency list.

Nomor 3: Program juga mengimplementasikan Breadth First Search (BFS) menggunakan queue (bisa manual atau STL) untuk menelusuri graph secara melebar. BFS menelusuri node berdasarkan tingkat kedalaman dari node awal, memastikan urutan kunjungan sesuai struktur graph.

## Kesimpulan
 Program ini berhasil menerapkan ADT Graph tidak berarah menggunakan linked list untuk menyimpan node dan hubungannya. Dengan operasi penambahan node dan penghubungan node, graph dapat merepresentasikan hubungan antar node secara fleksibel tanpa mengganggu node lain. Selain itu, implementasi DFS dan BFS memungkinkan penelusuran graph secara mendalam maupun melebar sesuai urutan yang diinginkan. Secara keseluruhan, struktur graph ini efektif untuk memodelkan data yang saling berhubungan dan memudahkan proses penelusuran serta pemrosesan informasi antar node.

## Referensi
[1] Siregar, A. A. N. (2018). Pengertian dari graph. Universitas Mitra: Fakultas Ilmu Komputer.
<br>[2] Anggara, F. D. (2009). Studi dan Implementasi Struktur Data Graf. Jurnal Sekolah Teknik Elektro dan Informatika Institut Teknologi Bandung, Bandung.
<br>[3] Setialana, P., Adji, T. B., & Ardiyanto, I. (2017). Perbandingan Performa Relational, Document-Oriented dan Graph Database Pada Struktur Data Directed Acyclic Graph. Jurnal Buana Informatika, 8(2).
