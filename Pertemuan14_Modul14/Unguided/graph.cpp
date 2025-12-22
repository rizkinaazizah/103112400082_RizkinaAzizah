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
