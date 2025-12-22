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
