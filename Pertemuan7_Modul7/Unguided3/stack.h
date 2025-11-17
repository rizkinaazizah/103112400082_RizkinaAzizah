#ifndef STACK_H
#define STACK_H

typedef int infotype;

const int MaxStack = 20; 

struct Stack {
    infotype Info[MaxStack];
    int top;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S); 
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x); 
void getInputStream(Stack &S);

#endif // STACK_H