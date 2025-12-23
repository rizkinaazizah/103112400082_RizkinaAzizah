#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph g;
    initGraph(g);
    
    City* A = addCity(g, "A");
    City* B = addCity(g, "B");
    City* C = addCity(g, "C");
    City* D = addCity(g, "D");
    City* E = addCity(g, "E");
    
    addEdge(A, B); addEdge(B, A);
    addEdge(B, E); addEdge(E, B);
    addEdge(B, C); addEdge(C, B);
    addEdge(B, A); 
    addEdge(C, D); addEdge(D, C);
    addEdge(C, E); addEdge(E, C);
    
    cout << "Membangun Jaringan Distribusi Vaksin\n";
    printGraph(g);
    cout << endl;
    cout << "Analisis Kota Kritis (Single Point of Failure)\n";
    
    for (City* c = g.head; c != nullptr; c = c->next) {
        if (isCritical(g, c)) {
            cout << "[PERINGATAN] Kota " << c->name << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << c->name << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << c->name << " aman (redundansi oke)." << endl;
        }
    }
    return 0;
}
