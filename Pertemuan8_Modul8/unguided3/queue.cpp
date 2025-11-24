#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0;
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE;
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    Q.info[Q.tail] = x;
    Q.tail = (Q.tail + 1) % MAX_QUEUE;  // berputar
    Q.count++;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];
    Q.head = (Q.head + 1) % MAX_QUEUE; // berputar
    Q.count--;

    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << " - " << Q.tail << " | empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " | ";

    int i = Q.head;
    int n = 0;

    while (n < Q.count) {
        cout << Q.info[i] << " ";
        i = (i + 1) % MAX_QUEUE;
        n++;
    }

    cout << endl;
}
