#ifndef GRAPH_H
#define GRAPH_H
#include <string>
using namespace std;

struct City;
struct Edge {
    City* destination;
    Edge* next;
};

struct City {
    string name;
    bool visited;
    bool lockdown;
    Edge* adjacency;
    City* next;
};

struct Graph {
    City* head;
};

void initGraph(Graph& g);
City* addCity(Graph& g, const string& name);
void addEdge(City* from, City* to);
void printGraph(const Graph& g);
bool isConnected(Graph& g, City* ignoreCity = nullptr);
bool isCritical(Graph& g, City* city);

#endif // GRAPH_H
