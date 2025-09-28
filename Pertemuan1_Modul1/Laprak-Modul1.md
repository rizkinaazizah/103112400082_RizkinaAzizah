# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
Bahasa C++ dikembangkan oleh Bjarne Strostrup, sebagai pengembangan dari bahasa C. Bahasa C++ memberikan programmer kemampuan tinggi dalam mengendalikan sistem dan memori.Bahasa C++ telah diperbarui tiga kali yaitu pada tahun 2011, 2014 dan 2017 dengan nama C++11, C++14 dan C++17. Untuk memulai menggunakan C++, ada dua hal yang diperlukan yaitu
1. Sebuah teks editor (Editor) seperti notepad untuk menulis kode C++
2. Sebuah kompiler (Compiler) seperti GCC untuk menerjemahkan kode C++ ke bahasa yang dipahami oleh komputer (Bahasa Mesin)

Aturan Penamaan File C++
Dalam memberikan nama File C++ (dan file program yang lainnya)
terdapat beberapa aturan yang harus diperhatikan. Jika aturan ini dilanggar
maka akan terjadi kesalahan atau error program. Hal-Hal yang harus
diperhatikan adalah
1. Tidak boleh ada spasi pada nama File C++.
2. Tidak boleh ada simbol khusus seperti %, $, @, #, !. ?, >, <, koma
(,), titik (.) dan sebagainya.
3. Spasi dapat digantikan dengan simbol garis bawah atau underscore
(_).
4. Nama file tidak boleh dimulai dengan angka.
5. Setelah huruf, nama file boleh dikombinasikan dengan angka.
6. Sebaiknya nama file menggunakan huruf kecil semua.
7. Jika program merupakan file bahasa C++ maka diakhiri dengan
.cpp
8. Jika program merupakan file bahasa C maka diakhiri dengan .c [1]

### A. Guided<br/>
...
#### 1. Guided1-Hello
#### 2. Guided2-aritmatika
#### 3. Guided3-Percabangan
#### 4. Guided4-Perulangan 
#### 5. Guided5-Struct

### B. Unguided<br/>
...
#### 1. Unguided 1
#### 2. Unguided 2
#### 3. Unguided 3

## Guided 

### 1. Guided1-Hello

```C++
#include <iostream>

using namespace std;

int main()
{
    cout << "hello" << endl;
    return 0;
} 

```
Program dibuat untuk menampilkan kata hello

### 2. Guided2-aritmatika

```C++
#include <iostream>

using namespace std;

int main() 
{
    int angka1, angka2;
    cout << "masukan angka 1: "; // nampilin output 
    cin >> angka1; // nampilin input 
    cout << "masukan angka 2 ";
    cin >> angka2;
    
    
    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pegurangan: " << angka1 - angka2 << endl; // nampilin value
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 + angka2 << endl; 
    cout << "sisa bagi: " << angka1 % angka2 << endl; 
    return 0;
} 

```
Program dibuat untuk menampilkan aritmatika ketika user memasukkan 2 angka program akan menampilkan output aritmatika dalm bentuk penjumlahan, pengurangan, perkalian, pembagian, dan sisa hasil bagi 

### 3. Guided3-Percabangan

```C++
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

```
Program ini dibuat dengan sistem penerapan percabangan yaitu penggunaan if-else dan switch-case

### 4. Guided4-Perulangan 

```C++
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

```
Program dibuat untuk menampilkan urutan angka baik dari terkecil ke terbesar ataupun terbesar ke terkecil 
dengan menggunakan perulangan

### 5. Guided5-Struct

```C++
#include <iostream>

using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        char nama [3];
        float nilai;
    
    };
    rapot siswa [MAX];
    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
    }
    int j = 0;
    while(j< MAX ){
        cout << "nama siswa: " << siswa[j].nama << ", Nilai: " << siswa[j].nilai<<endl;
        j++;
    }
}
```
penjelasan singkat guided 5
Program ini digunakan inputan rapot dimana akan memunculkan output nama siswa beserta nilai yaitu dengan penerapan tipe data struktur. Tipe data ini biasanya digunakan untuk mengelompokkan beberapa informasi yang saling berkaitan[2]


## Unguided 

### 1. Unguided 1
BUatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut
```C++
source code unguided 1
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

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan1_Modul1/Unguided11_Modul1.png)

Jadi, program ini adalah program yang menerima inputan angka bertipe float kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut

### 2. Unguided 2
Buatlah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan diinputkan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
source code unguided 2
#include <iostream>
using namespace std;

int main() {
    string huruf[101] = {
        "nol", "hurufsatu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas",
        "dua puluh", "dua puluh satu", "dua puluh dua", "dua puluh tiga", "dua puluh empat", "dua puluh lima", "dua puluh enam", "dua puluh tujuh", "dua puluh delapan", "dua puluh sembilan",
        "tiga puluh", "tiga puluh satu", "tiga puluh dua", "tiga puluh tiga", "tiga puluh empat", "tiga puluh lima", "tiga puluh enam", "tiga puluh tujuh", "tiga puluh delapan", "tiga puluh sembilan",
        "empat puluh", "empat puluh satu", "empat puluh dua", "empat puluh tiga", "empat puluh empat", "empat puluh lima", "empat puluh enam", "empat puluh tujuh", "empat puluh delapan", "empat puluh sembilan",
        "lima puluh", "lima puluh satu", "lima puluh dua", "lima puluh tiga", "lima puluh empat", "lima puluh lima", "lima puluh enam", "lima puluh tujuh", "lima puluh delapan", "lima puluh sembilan",
        "enam puluh", "enam puluh satu", "enam puluh dua", "enam puluh tiga", "enam puluh empat", "enam puluh lima", "enam puluh enam", "enam puluh tujuh", "enam puluh delapan", "enam puluh sembilan",
        "tujuh puluh", "tujuh puluh satu", "tujuh puluh dua", "tujuh puluh tiga", "tujuh puluh empat", "tujuh puluh lima", "tujuh puluh enam", "tujuh puluh tujuh", "tujuh puluh delapan", "tujuh puluh sembilan",
        "delapan puluh", "delapan puluh satu", "delapan puluh dua", "delapan puluh tiga", "delapan puluh empat", "delapan puluh lima", "delapan puluh enam", "delapan puluh tujuh", "delapan puluh delapan", "delapan puluh sembilan",
        "sembilan puluh", "sembilan puluh satu", "sembilan puluh dua", "sembilan puluh tiga", "sembilan puluh empat", "sembilan puluh lima", "sembilan puluh enam", "sembilan puluh tujuh", "sembilan puluh delapan", "sembilan puluh sembilan", "seratus"
    };

    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    cout << angka << ":" << huruf[angka] << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan1_Modul1/Unguided21_Modul1.png)

penjelasan unguided 2
Program adalah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Program diatas dibuat dengan menggunakan array.

### 3. Unguided 3
Berikan program yang dapat memberikan input dan output sbb
321*123
 21*12
  1*1
   *

```C++
source code unguided 3
#include <iostream>

using namespace std;

int main(){
	int tinggi = 3;
	
	for (int i = tinggi; i >=0; i--){
		for (int j = 0; j < tinggi-i; j++) {
			cout <<" ";
		}
		for(int s=i;s>=1;s--){
			cout<<s;
		}
		cout << "*";

		for(int s=1; s<=i; s++){
			cout<<s;
			}
		cout<< endl;
			
	}
	}
	

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan1_Modul1/Unguided31_Modul1.png)

penjelasan unguided 3
Program diatas adalah program yang ketika dijalankan langsung mengeluarkan output. Program menggunakan peneran perulangan for

## Kesimpulan
Dari program program diatas dapat disimpulkan bahwa bahasa C++ dalam tipe data hampir sama saja dengan bahasa pemrograman lainnya, baik dari segi struktur maupun logika. Misalnya, penggunaan variabel, operator, serta struktur kontrol seperti if-else, switch case, dan perulangan (for, while, do-while). Hal ini membuat C++ relatif mudah dipahami oleh pemula yang sudah mengenal bahasa lain, karena konsep dasarnya tetap sama yaitu menerima input, mengolah data, dan menampilkan output sesuai kebutuhan.

## Referensi
[1] Ma’arif, A. (2022). Dasar Pemrograman Bahasa C++. Yogyakarta: Universitas Ahmad Dahlan.

<br>[2] Institut Teknologi Telkom Purwokerto. (n.d.). Modul 1: Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama). Purwokerto: Institut Teknologi Telkom Purwokerto.
