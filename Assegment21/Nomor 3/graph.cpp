#include "graph.h"
#include <iostream>
using namespace std;

void initGraph(Graph& g) {
    g.head = nullptr;
}

City* addCity(Graph& g, const string& name) {
    City* city = new City;
    city->name = name;
    city->visited = false;
    city->lockdown = false;
    city->adjacency = nullptr;
    city->next = g.head;
    g.head = city;
    return city;
}

void addEdge(City* from, City* to) {
    Edge* edge = new Edge;
    edge->destination = to;
    edge->next = from->adjacency;
    from->adjacency = edge;
}

void resetVisited(Graph& g) {
    for (City* c = g.head; c != nullptr; c = c->next) {
        c->visited = false;
    }
}

void dfs(City* city, City* ignoreCity = nullptr) {
    if (!city || city->visited || city == ignoreCity) return;
    city->visited = true;
    for (Edge* e = city->adjacency; e != nullptr; e = e->next) {
        dfs(e->destination, ignoreCity);
    }
}

bool isConnected(Graph& g, City* ignoreCity) {
    resetVisited(g);
    City* start = nullptr;
    for (City* c = g.head; c != nullptr; c = c->next) {
        if (c != ignoreCity) {
            start = c;
            break;
        }
    }
    if (!start) return true;
    dfs(start, ignoreCity);
    for (City* c = g.head; c != nullptr; c = c->next) {
        if (c != ignoreCity && !c->visited) return false;
    }
    return true;
}

bool isCritical(Graph& g, City* city) {
    return !isConnected(g, city);
}

void printGraph(const Graph& g) {
    for (City* c = g.head; c != nullptr; c = c->next) {
        cout << "Node " << c->name << " terhubung ke: ";
        for (Edge* e = c->adjacency; e != nullptr; e = e->next) {
            cout << e->destination->name << " ";
        }
        cout << endl;
    }
}
