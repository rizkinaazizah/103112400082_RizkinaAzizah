#ifndefSTACK_H
#include<iostream>
#ifndefSTACK_H
#define MaxEl20
#define Nil-1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];//array untuk menyimpan elemen stack
    int top;
}

void CreateStack(Stack &S);
void isEmpty(Stack S);
void isFull(Stack S);
void push(Stack &S, infotype x);

infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
