#include <iostream>
#include "mahasiswa.h"
using namespace std;

//realisasi dari fungsi inputmhs
void inputMhs(mahasiswa &m){
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

//realisasi dari fungsi rata2
float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2) / 2;
}