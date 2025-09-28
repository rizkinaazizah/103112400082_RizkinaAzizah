#include <iostream>

using namespace std;

int main(){
    float angka1, angka2, penjumlahan, pengurangan, perkalian, pembagian;
    cout << "Masukkan Angka 1: ";
    cin >> angka1;
    cout << "Masukkan Angka 2: ";
    cin >> angka2;

    penjumlahan = angka1 + angka2;
    pengurangan = angka1 - angka2;
    perkalian = angka1*angka2;
    pembagian = angka1/angka2;

    cout<<"Penjumlahan: "<< penjumlahan <<endl;
    cout<<"Pengurangan: "<< pengurangan <<endl;
    cout<<"Perkalian: "<< perkalian <<endl;
    cout<<"Pembagian: "<< pembagian <<endl;

}