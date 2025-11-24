#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5 //isi  mkasimal array

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;//melihat isi que

};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x); //tambah
int dequeue(Queue &Q);//hapus
void printInfo(Queue Q);
#endif