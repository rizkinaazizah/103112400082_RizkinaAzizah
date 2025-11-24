#include<iostream>
#include"queue.h"

using namespace std;

int main(){
    cout << "Hello Word"<< endl;
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout<<"----------------------"<<endl;
    cout<<"H - T \t  | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5);//insert
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);
    dequeue(Q);printInfo(Q);
    enqueue(Q,4);printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}