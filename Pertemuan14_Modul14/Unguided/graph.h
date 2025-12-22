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
