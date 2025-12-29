#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arrA[3][3], int arrB[3][3], int x, int y){
    int temp = arrA[x][y];
    arrA[x][y] = arrB[x][y];
    arrB[x][y] = temp;
}

void tukarPointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arrB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A:" << endl;
    tampilkanHasil(arrA);

    cout << "\nArray B:" << endl;
    tampilkanHasil(arrB);

    tukarArray(arrA, arrB, 1, 1);

    cout << "\nSetelah tukar A[1][1] dengan B[1][1]:" << endl;
    cout << "Array A:" << endl;
    tampilkanHasil(arrA);

    cout << "\nArray B:" << endl;
    tampilkanHasil(arrB);

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "Sesudah tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
