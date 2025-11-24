#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
    Q.count++;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];

    // Head maju
    if (Q.head == Q.tail) {
        // Jika elemen tinggal satu → reset ke empty state
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }

    Q.count--;
    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "-1 - -1 | empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }

    cout << endl;
}
