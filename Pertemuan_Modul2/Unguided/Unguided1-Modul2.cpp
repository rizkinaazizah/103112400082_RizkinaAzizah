#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[3][3], int B[3][3], int C[3][3]) {
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void kurangMatriks(int A[3][3], int B[3][3], int C[3][3]) {
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void kaliMatriks(int A[3][3], int B[3][3], int C[3][3]) {
    for(int i = 0; i < 3; i++){             // perulangan baris
        for(int j = 0; j < 3; j++){         // perulangan kolom
            C[i][j] = 0;                    // pastikan awal 0
            for(int k = 0; k < 3; k++){     // perulangan perkalian
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int arrC[3][3] = {0};

    int pilihan;
    do {
        cout << "--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << endl;

        switch(pilihan) {
            case 1:
                jumlahMatriks(arrA, arrB, arrC);
                cout << "Hasil penjumlahan:" << endl;
                tampilkanHasil(arrC);
                cout << endl;
                break;

            case 2:
                kurangMatriks(arrA, arrB, arrC);
                cout << "Hasil pengurangan:" << endl;
                tampilkanHasil(arrC);
                cout << endl;
                break;

            case 3:
                kaliMatriks(arrA, arrB, arrC);
                cout << "Hasil perkalian:" << endl;
                tampilkanHasil(arrC);
                cout << endl;
                break;

            case 4:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl << endl;
                break;
        }
    } while(pilihan != 4);

    return 0;
}
