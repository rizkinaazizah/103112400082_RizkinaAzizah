#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout<<"Masukkan nama mahasiswa: ";
    cin>>m.nama;
    cout<<"masukkan nilai 1: ";
    cin>>m.nilai1;
    cout<<"masukkan nilai 2: ";
    cin>>m.nilai2
}