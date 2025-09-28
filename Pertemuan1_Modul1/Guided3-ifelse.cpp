#include <iostream>

using namespace std;

int main() //
{
    int angka1, angka2;
    cout << "masukan angka 1: "; // nampilin output 
    cin >> angka1; // nampilin input 
    cout << "masukan angka 2: ";
    cin >> angka2;

    if (angka1 < angka2 ){
        cout << angka1 << " kurang dari " << angka2 << endl;
        } else {
            cout << angka1 << " lebih dari " << angka2 <<endl;
        }

    if (angka1 == angka2){
        cout << angka1 << "sama dengan " << angka2 << endl;
        } else if (angka1 != angka2){
            cout << "angka berbeda" << endl;
        }
    
    int pilihan;
    cout << "MENU" << endl;
    cout << "penjumlahan" << endl;
    cout << "pengurangan" << endl;
    cout << "masukkan pilihan : " << endl;
    cin >> pilihan;

    switch(pilihan){
        case 1:
        cout << "penjumlahan: " << endl;
        cout << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pegurangan: " << angka1 - angka2 << endl;;
        cout << endl;
        break;
        default :
        cout << "pilihan salah" << endl;
    }
    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pegurangan: " << angka1 - angka2 << endl; // nampilin value
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 + angka2 << endl; 
    cout << "sisa bagi: " << angka1 % angka2 << endl; 
    return 0;
} 

// XOR kebalikan dari OR 
// unsign ngotak ngatik bil positif
// do while kondisi salah ttp tereksekusi walaupun satu
