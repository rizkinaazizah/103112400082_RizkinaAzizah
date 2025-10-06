# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
Struktur Data memberikan penjelasan tentang suatu koleksi atau kelompok data yang dapat dikarakteristikan oleh organisasi serta operasi yang didefinisikan terhadapnya. Pemakaian struktur data yang tepat didalam proses pemrograman,akan menghasilkan algoritma yang kebih jelas dan tepat sehingga menjadikan program secara keseluruhan lebih sederhana[1]

Array adalah Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama
Array dibagi menjadi:
1.Array satu dimensi
2.Array dua dimensi
3.Array tiga dimensi
4.Array banyak dimensi[1]

Pointer (penunjuk) adalah sebuah variabel yang digunakan sebagai penunjuk alamat dari variabel lain. Pointer disini   berfungsi menyimpan alamat  dari  sebuah variabel dan dapat mengakses  nilai  yang  ada  di  alamat tersebut, pointer dapat mengubah  nilai, menampilkan      nilai      atau menampilkan    alamat    dari    variabel yang disimpannya.[2]



### A. Guided<br/>
...
#### 1. Guided1
#### 2. Guided2-aritmatika
#### 3. Guided3-Percabangan
#### 4. Guided4-Perulangan 
#### 5. Guided5-Struct

### B. Unguided<br/>
...
#### 1. Unguided 1
#### 2. Unguided 2

## Guided 

### 1. Guided1

```C++
#include <iostream>
using namespace std;
//indeks ke3, elemen ke4

int main(){
    int arr[] = {10,20,30,40,50};
    int* ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; ++i){
        cout << "elemen array ke-"<< i+1 << " menggunakan pointer: " << *(ptr + i) << endl; 
    }

    //mengakses elemen array menggunakan indeks
    for(int i = 0; i < 5; ++i){
        cout << "elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}

```
penjelasan singkat guided 1
Program ini merupakan contoh sederhana penerapan array dan pointer


## Unguided 

### 1. Unguided 1 
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian 
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; 
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan 
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case 
seperti berikut ini : 
 --- Menu Program Matriks --- 
1. Penjumlahan matriks 
2. Pengurangan matriks 
3. Perkalian matriks 
4. Keluar
```C++
source code unguided 1
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
    for(int i = 0; i < 3; i++){             
        for(int j = 0; j < 3; j++){         
            C[i][j] = 0;                    
            for(int k = 0; k < 3; k++){    
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


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan_Modul2/Unguided/output-unguided1-modul2.png)

Program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3. Pada program menggunakan prosedur untuk melakukan operasi baik penjumlahan, perkalian, pengurangan ataupun menampilkan hasil. Pada program ini juga menggunakan percabangan yaitu switch case untuk pemilihan menu.

### 2. Unguided 2
Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan 
dan perubahan nilainya menggunakan pointer, seperti berikut: 
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan 
luas (beri nilai 0). 
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar 
yang menunjuk ke variabel lebar.  
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. 
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar. 
4) Cetak nilai luas ke layar. 
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui 
pointer ptrPanjang dan ptrLebar. 
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa 
nilainya telah berubah. 

```C++
source code unguided 2
#include <iostream>
using namespace std;

int main() {
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int keliling = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan_Modul2/Unguided/output-unguided2-modul2.png)

penjelasan unguided 2
Program ini digunakan untuk menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer.


## Kesimpulan
Struktur data merupakan salah satubahan dasar pembuatan program. Pemakaianstruktur data yang tepat di dalam  prosespemrograman, akan menghasilkan algoritmayang jelas dan tepat sehingga menjadikanprogram secara keseluruhan lebih sederhana[1]

## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.

[2] ARRAFFI, Adzriel. pointer.
