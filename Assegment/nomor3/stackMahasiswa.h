#ifndefSTACKMAHASISWA_H
#include<iostream>
#ifndefSTACKMAHASISWA_H
#define MaxEl6
#define Nil-1

typedef int infotype;
struct Mahasiswa{
    string nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct Stack{
    infotype info[MaxEl];//array untuk menyimpan elemen stack
    int top;
}

void CreateStack(Stack &S);
void isEmpty(Stack S);
void isFull(Stack S);
void push(Stack &S, infotype x);

infotype pop(Stack &S);
void update(Stack S);
void view(Stack &S);
void SearchNilaiAkhir(Stack S)
#endif
