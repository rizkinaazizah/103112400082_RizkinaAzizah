# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
Abstract Data Type (ADT)
ADT adalah definisi TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi statik.

ADT biasanya diimplementasi menjadi dua buah modul, yaitu:
- Definisi/Spesifikasi Type dan primitif .
  • Spesifikasi type sesuai dengan bahasa yang bersangkutan.
  • Spesifikasi dari primitif sesuai dengan kaidah dalam konteks prosedural, yaitu:
     • Fungsi : nama, domain, range dan prekondisi jika ada
     • Prosedur : Initial State, Final State dan Proses yang dilakukan
- Body/realisasi dari primitif, berupa kode program dalam bahasa yang bersangkutan. Realisasi fungsi dan prosedur harus sedapat mungkin memanfaatkan selektor dan konstruktor.

Realisasi ADT dalam beberapa bahasa:
- BAHASA: Pascal (hanya dalam turbo pascal)
  SPESIFIKASI: Satu Unit interface
  BODY: Implementation
- BAHASA: C
  SPESIFIKASI: File header dengan ekstensi .h
  BODY: File kode dengan ekstensi .c
- BAHASA: Ada
  SPESIFIKASI: Paket dengan ekstensi .ads
  BODY: Paket body dengan ekstensi .adb

Dalam modul ADT tidak terkandung definisi variabel. Modul ADT biasanya dimanfaatkan oleh modul lain, yang akan mendeklarasikan variabel bertype ADT tsb dalam modulnya. Jadi ADT bertindak sebagai Supplier (penyedia type dan primitif), sedangkan modul pengguna berperan sebagai Client (pengguna) dari ADT tsb. Biasanya ada sebuah pengguna yang khusus yang disebut sebagai main program (program utama) yang memanfaatkan langsung type tsb.[1]

### A. Guided<br/>
...
#### 1. Guided1
#### 2. Guided2

### B. Unguided<br/>
...
#### 1. Unguided 

## Guided 

### 1. Guided1

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[10];
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah :" << rata2(mhs) << endl;

    system("read -p 'Press Enter to continue...' var");

    return 0;
}

```
penjelasan singkat guided1
Program ini merupakan program C++ sederhana yang menggunakan struct untuk merepresentasikan data mahasiswa yang terdiri dari NIM dan dua nilai. Program menyediakan fungsi untuk menginput data mahasiswa serta fungsi untuk menghitung nilai rata-rata dari dua nilai tersebut. Pada fungsi main, data mahasiswa dimasukkan oleh pengguna, kemudian program menghitung dan menampilkan rata-rata nilainya ke layar sebagai hasil akhir.

### 2. Guided2
#### mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m){
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2) / 2;
}
```
#### mahasiswa.h
```C++
#ifndef MAHASISWA_H
#define MAHASIWA_H

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;

};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif 
```
#### main.cpp
```C++
#include<iostream>
#include"mahasiswa.h"
#include<cstdlib>

using namespace std;
int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata rata nilai adalah: " << rata2(mhs) << endl;
    system("pause");
    
    return 0;

}
```
penjelasan singkat guided2
Program ini merupakan aplikasi C++ modular yang memisahkan deklarasi, implementasi, dan program utama ke dalam tiga file, yaitu mahasiswa.h, mahasiswa.cpp, dan main.cpp. File header digunakan untuk mendefinisikan struktur mahasiswa beserta prototipe fungsi, file .cpp berisi implementasi fungsi untuk menginput data mahasiswa dan menghitung nilai rata-rata, sedangkan main.cpp berfungsi sebagai pengendali utama program yang memanggil fungsi-fungsi tersebut.

## Unguided 

### 1. Unguided 1 
```C++
source code unguided 1
#include <iostream>

using namespace std;

const int MAX = 10;
    struct rapot{
        string nama, nim;
        float uts, uas, tugas, nilaiAkhir;
    
    };

    float hitungnilaiAkhir(float uts, float uas, float tugas){
        return 0.3*uts+0.4*uas+0.3*tugas;
    }
    
int main(){
    
    rapot siswa [MAX];

    cout<<"==============DATA MAHASISWA=================="<<endl;

    for(int i = 0; i < MAX; i++){
        
        cout << "NAMA: ";
        cin >> siswa[i].nama;
        cout << "NIM: ";
        cin >> siswa[i].nim;
        cout << "Nilai UTS: ";
        cin >> siswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> siswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> siswa[i].tugas;

        siswa[i].nilaiAkhir = hitungnilaiAkhir(siswa[i].uts, siswa[i].uas, siswa[i].tugas);

        cout << "Hasil Nilai Akhir: " << siswa[i].nilaiAkhir << endl;
        cout << endl;
    }
    
    int j = 0;
    while(j< MAX ){
        cout << "NAMA: " << siswa[j].nama << ", NIM: " << siswa[j].nim<< ", Nilai UTS: " << siswa[j].uts << ", Nilai UAS: " << siswa[j].uas<< ", Nilai Tugas: " << siswa[j].tugas<<", Hasil Nilai Akhir: " << siswa[j].nilaiAkhir<<endl;
        j++;
    }
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan3_Modul3/Unguided/nomor1/un1.png)

Program ini digunakan untuk mengelola data nilai mahasiswa menggunakan array of struct. Program menyimpan data hingga 10 mahasiswa, yang meliputi nama, NIM, nilai UTS, nilai UAS, nilai tugas, serta nilai akhir. Nilai akhir dihitung menggunakan fungsi hitungnilaiAkhir dengan bobot tertentu, kemudian hasilnya ditampilkan setelah proses input dan juga dicetak ulang menggunakan perulangan while. Program ini menunjukkan penggunaan struct, array, fungsi, serta perulangan for dan while dalam pengolahan data mahasiswa.

### 2. Unguided 2
#### pelajaran.cpp
```C++
source code unguided 2
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaPel = namaPel;
    p.kodePel = kodePel;
    return p;
}

void tampil_pelajaran(const pelajaran& p) {
    cout << "nama pelajaran : " << p.namaPel << endl;
    cout << "nilai : " << p.kodePel << endl;
}
```
#### pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaPel;
    string kodePel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(const pelajaran& p);

#endif
```
#### main.cpp
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";
    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);
    return 0;
}
```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan3_Modul3/Unguided/nomor2/un2.png)

penjelasan unguided 2
Program ini merupakan program C++ sederhana yang menerapkan pemrograman modular dengan pemisahan kode ke dalam file header dan file implementasi. Struktur pelajaran digunakan untuk merepresentasikan data mata pelajaran yang terdiri dari nama pelajaran dan kode pelajaran. Fungsi create_pelajaran berfungsi untuk membuat dan menginisialisasi data pelajaran, sedangkan fungsi tampil_pelajaran digunakan untuk menampilkan informasi pelajaran ke layar. Pada main.cpp, program membuat satu objek pelajaran lalu menampilkannya, sehingga menunjukkan konsep struct, fungsi, dan modularisasi program.

### 3. Unguided 3
```C++
source code unguided 3
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

```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan3_Modul3/Unguided/nomor3/un3.png)

Program ini merupakan program C++ yang mendemonstrasikan penggunaan array dua dimensi dan pointer. Program menampilkan dua array 3×3, kemudian menukar elemen tertentu antara kedua array menggunakan fungsi tukarArray. Selain itu, program juga menunjukkan konsep pointer dengan menukar nilai dua variabel integer melalui fungsi tukarPointer. Melalui program ini, ditunjukkan cara pengiriman array dan pointer ke fungsi, serta bagaimana manipulasi data dapat dilakukan baik secara langsung melalui indeks array maupun secara tidak langsung melalui pointer.

## Kesimpulan
Ketiga program tersebut menunjukkan penerapan konsep dasar pemrograman C++ yang penting, yaitu penggunaan struct, pemrograman modular, array, fungsi, dan pointer. Program mahasiswa dan pelajaran menekankan pemisahan kode ke dalam file header dan implementasi untuk membuat program lebih terstruktur dan mudah dikembangkan, sedangkan program array dan pointer menunjukkan bagaimana data dapat dimanipulasi melalui indeks array maupun alamat memori.

## Referensi
[1] Rachman, D. A. Perkenalan Abstrak Data Type.


