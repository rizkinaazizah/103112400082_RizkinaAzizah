#include "stackMahasiswa.h"
using namespace std;

bool isEmpty(Stack S) {
    return S.top == Nil;  
}

bool isFull(Stack S) {
    return S.top == Nil;
}

void CreateStack(Stack &S) {
    S.top = -1;  
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {  
        S.top++;  
        S.info[S.top] = x;  
        cout << "Stack Penuh!" << endl;  
    }
}

infotype pop(Stack &S) {
    infotype x = -999;  
    if (!isEmpty(S)) {  
        x = S.info[S.top]; 
        S.top--;  
    } else {
        cout << "Stack Kosong!" << endl; 
    }
    return x; 
}

void view(Stack S) {

}

void SearchNilaiAkhir(Stack S, float NilaiAkhirMin, float NilaiAkhirMax){
    
}


