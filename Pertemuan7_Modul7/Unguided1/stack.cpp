#include <iostream>
#include "stack.h"

using namespace std;

void CreateStack(Stack &S) {
    S.top = -1; 
}

bool IsEmpty(Stack S) {
    return S.top == -1;
}

bool IsFull(Stack S) {
    return S.top == MaxStack - 1;
}

void Push(Stack &S, infotype x) {
    if (IsFull(S)) {
        cout << "Stack Penuh, tidak bisa push elemen " << x << endl;
    } else {
        S.top++;
        S.Info[S.top] = x;
    }
}

infotype Pop(Stack &S) {
    infotype temp = -1; 
    if (IsEmpty(S)) {
        cout << "Stack Kosong, tidak bisa pop" << endl;
    } else {
        temp = S.Info[S.top];
        S.top--;
    }
    return temp;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << S.Info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (S.top <= 0) return; 

    Stack Temp;
    CreateStack(Temp);

    while (!IsEmpty(S)) {
        Push(Temp, Pop(S));
    }

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}