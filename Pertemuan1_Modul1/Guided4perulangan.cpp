#include <iostream>

using namespace std;

int main() //
{
    int angka1;
    cout << "masukan angka 1: "; // nampilin output 
    cin >> angka1; // nampilin input 
    for(int i = 0; i < angka1; i++){
        cout << i << " - ";
    }
    
    int j = 10; 
    while (j > angka1){
        cout << j << " - ";
        j--;
    }

    int k = 10;
    do{
        cout << k << " - ";

    } while (k < angka1 );
    
    return 0;
} 

// XOR kebalikan dari OR 
// unsign ngotak ngatik bil positif
//
