# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Rizkina Azizah - 103112400082</p>

## Dasar Teori
 Pengertian Stack Menurut (Soffya Ranti, 2022) Stack adalah struktur data linier yang mengikuti
aturan tertentu untuk melakukan operasi. Menambah dan menghapus elemen dari tumpukan hanya
dapat terjadi di satu lokasi, yaitu ujung tumpukan. Stack bersifat LIFO (Last in First Out) dan objek
yang terakhir masuk ke dalam Stack akan menjadi benda pertama yang dikeluarkan dari Stack itu.
(Sihombing et al., 2020)[1]

Stack memiliki beberapa fungsi dan operasi antara lain: (Geeksforgeeks, 2024b) Operasi utama
pada Stack meliputi: 
1) Push, yaitu menambahkan elemen baru ke dalam Stack pada posisi teratas. 
2) Pop, yaitu menghapus elemen teratas dari Stack dan mengembalikan nilainya. 
3) Peek atau top, yaitu mengecek elemen teratas dari Stack tanpa menghapusnya. 
4) Isempty, yaitu memeriksa apakah Stack kosong atau tidak. 
5) Size, yaitu mengembalikan jumlah elemen dalam Stack. 
Fungsi pada Stack antara lain: Mengorganisasi data dan memudahkan penyimpanan komputer , Digunakan dalam berbagai
algoritma, seperti tower of hanoi, tree traversal, dan rekursi[1]

Struktur data stack bersifat linear, yang berjalan dengan prinsip LIFO (Last In, First Out). Artinya, elemen terakhir yang dimasukkan ke dalam stack adalah elemen pertama yang akan dikeluarkan, dan begitu juga sebaliknya.
Contoh penggunaan stack yang paling mudah dijumpai adalah fungsi undo dan redo.
Saat menggunakan aplikasi yang memiliki fungsi ini, setiap perubahan Anda akan disimpan dalam stack. Ketika mengklik undo, perubahan terakhir Anda akan dikeluarkan dari stack. Saat memilih redo, perubahan tersebut dimasukkan kembali ke stack.
- Kelebihan:
  Sederhana dan efisien untuk operasi LIFO, seperti undo-redo atau pemanggilan fungsi.
  Mudah diimplementasikan menggunakan array atau linked list.
  Penggunaan memori lebih terkontrol karena operasi hanya dilakukan di satu ujung (top).
- Kekurangan:
  Akses terbatas pada elemen teratas saja sehingga kurang fleksibel untuk keperluan lain.
  Mungkin terjadi overflow kalau jumlah data terlalu banyak.
  Tidak bisa mengakses atau modifikasi elemen secara acak.[2]

### A. Guided<br/>
...
#### 1. Guided1
#### 2. Guided2

### B. Unguided<br/>
...
#### 1. Unguided 1
#### 2. Unguided 2
#### 3. Unguided 3

## Guided 

### 1. Guided1
#### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL
#include<iostream>
using namespace std;

typedef struct node*address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}

```
Implementasi Guided1 ini menunjukkan pembuatan ADT Stack berbasis linked list di C++. Struktur data terdiri dari node yang menyimpan data dan pointer next, sedangkan stack hanya menyimpan pointer top. Fungsi dasar yang digunakan meliputi createStack, isEmpty, push, dan pop, lalu dilengkapi dengan fitur tambahan seperti update untuk mengubah data pada posisi tertentu, view untuk menampilkan isi stack dari atas ke bawah, serta searchData untuk mencari nilai tertentu dalam stack. Pada main.cpp, program melakukan serangkaian operasi push, pop, update, dan pencarian untuk memastikan seluruh fungsi berjalan sesuai dengan konsep stack berbasis linked list.

### 2. Guided2

#### Stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

//

```
#### Stack.h
```C++
#ifndefSTACK_H
#include<iostream>
#ifndefSTACK_H
#define MaxEl20
#define Nil-1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];//array untuk menyimpan elemen stack
    int top;
}

void CreateStack(Stack &S);
void isEmpty(Stack S);
void isFull(Stack S);
void push(Stack &S, infotype x);

infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif


```
#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
penjelasan guided2
Implementasi Guided2 memperlihatkan pembuatan ADT Stack berbasis array dengan kapasitas 20 dan penanda kosong top = -1. File Stack.h berisi struktur dan deklarasi fungsi, sedangkan Stack.cpp memuat logika seperti CreateStack, isEmpty, isFull, push, dan pop yang bekerja dengan prinsip LIFO. Terdapat juga prosedur balikStack yang memakai dua stack sementara untuk membalik urutan elemen. Pada main.cpp, program menguji operasi dasar tersebut dan menunjukkan bahwa balikStack berhasil mengubah urutan 9, 2, 4, 3 menjadi 3, 4, 2, 9.

## Unguided 

### 1. Unguided 1
BUatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut
```C++
source code unguided 1
```
#### Stack.cpp
```C++
#include <iostream>
#include "stack.h"

using namespace std;

void CreateStack(Stack &S) {
    S.top = -1; 
}

bool IsEmpty(Stack S) {
    return S.top == -1;
}

bool IsFull(Stack S) {
    return S.top == MaxStack - 1;
}

void Push(Stack &S, infotype x) {
    if (IsFull(S)) {
        cout << "Stack Penuh, tidak bisa push elemen " << x << endl;
    } else {
        S.top++;
        S.Info[S.top] = x;
    }
}

infotype Pop(Stack &S) {
    infotype temp = -1; 
    if (IsEmpty(S)) {
        cout << "Stack Kosong, tidak bisa pop" << endl;
    } else {
        temp = S.Info[S.top];
        S.top--;
    }
    return temp;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << S.Info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (S.top <= 0) return; 

    Stack Temp;
    CreateStack(Temp);

    while (!IsEmpty(S)) {
        Push(Temp, Pop(S));
    }

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}
```
#### Stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

const int MaxStack = 20; 

struct Stack {
    infotype Info[MaxStack];
    int top;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S); 
void printInfo(Stack S);
void balikStack(Stack &S);

#endif 

```
#### main.cpp
```C++
#include <iostream>
#include "stack.h" 

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    Push(S, 3);
    Push(S, 4);
    Push(S, 8);

    Pop(S); 

    Push(S, 2); 
    Push(S, 3); 
    
    Pop(S); 
    
    Pop(S); 

    Push(S, 9); 

    printInfo(S); 
    cout << "balik stack" << endl;
    
    balikStack(S); 
    printInfo(S); 

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan7_Modul7/Unguided1/outputUn1.png)

implementasi Abstract Data Type (ADT Stack) menggunakan struktur data Array dalam bahasa C++. Tujuannya adalah menciptakan kerangka stack yang mematuhi prinsip LIFO (Last In, First Out). Implementasi ini mencakup prosedur penting seperti CreateStack untuk inisialisasi stack kosong, Push untuk menambahkan elemen ke puncak, dan Pop untuk mengambil/menghapus elemen dari puncak. Selain itu, terdapat prosedur tambahan balikStack yang berfungsi untuk membalik urutan semua elemen di dalam stack tersebut.

### 2. Unguided 2
TambahkanprosedurpushAscending(in/outS:Stack,inx:integer)

```C++
source code unguided 2
```
#### Stack.cpp
```C++
#include <iostream>
#include "stack.h"

using namespace std;

void CreateStack(Stack &S) {
    S.top = -1; 
}

bool IsEmpty(Stack S) {
    return S.top == -1;
}

bool IsFull(Stack S) {
    return S.top == MaxStack - 1;
}

void Push(Stack &S, infotype x) {
    if (IsFull(S)) {
        cout << "Stack Penuh, tidak bisa push elemen " << x << endl;
    } else {
        S.top++;
        S.Info[S.top] = x;
    }
}

infotype Pop(Stack &S) {
    infotype temp = -1; 
    if (IsEmpty(S)) {
        cout << "Stack Kosong, tidak bisa pop" << endl;
    } else {
        temp = S.Info[S.top];
        S.top--;
    }
    return temp;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << S.Info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (S.top <= 0) return; 

    Stack Temp;
    CreateStack(Temp);

    while (!IsEmpty(S)) {
        Push(Temp, Pop(S));
    }

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack Temp;
    CreateStack(Temp);
    
    while (!IsEmpty(S) && S.Info[S.top] > x) {
        Push(Temp, Pop(S));
    }
    
    Push(S, x);
    
    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}
```
#### Stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

const int MaxStack = 20; 

struct Stack {
    infotype Info[MaxStack];
    int top;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S); 
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x); 

#endif 
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h" 

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4); 
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    printInfo(S); 
    
    cout << "balik stack" << endl;
    
    balikStack(S); 
    printInfo(S); 

    return 0;
}

```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan7_Modul7/Unguided2/outputUn2.png)

penjelasan unguided 2
menambahkan prosedur baru, pushAscending(S, x), untuk menjaga agar stack utama (S) selalu terurut secara menaik (ascending) dari dasar ke puncak. Logika prosedur ini adalah sebelum elemen baru x dimasukkan, semua elemen di puncak S yang nilainya lebih besar dari x dipindahkan sementara ke stack bantuan. Setelah x berhasil dimasukkan ke posisi yang benar (di bawah elemen yang lebih besar), semua elemen yang dipindahkan dari stack bantuan dikembalikan, sehingga urutan tetap menaik.

### 3. Unguided 3
Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan
menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan
tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

```C++
source code unguided 3
```
#### Stack.cpp
```C++
#include <iostream>
#include <limits> 
#include "stack.h"

using namespace std;

void CreateStack(Stack &S) {
    S.top = -1; 
}

bool IsEmpty(Stack S) {
    return S.top == -1;
}

bool IsFull(Stack S) {
    return S.top == MaxStack - 1;
}

void Push(Stack &S, infotype x) {
    if (IsFull(S)) {
        cout << "Stack Penuh, tidak bisa push elemen " << x << endl;
    } else {
        S.top++;
        S.Info[S.top] = x;
    }
}

infotype Pop(Stack &S) {
    infotype temp = -1; 
    if (IsEmpty(S)) {
        cout << "Stack Kosong, tidak bisa pop" << endl;
    } else {
        temp = S.Info[S.top];
        S.top--;
    }
    return temp;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << S.Info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (S.top <= 0) return; 

    Stack Temp;
    CreateStack(Temp);

    while (!IsEmpty(S)) {
        Push(Temp, Pop(S));
    }

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack Temp;
    CreateStack(Temp);
    
    while (!IsEmpty(S) && S.Info[S.top] > x) {
        Push(Temp, Pop(S));
    }
    
    Push(S, x);
    
    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}

void getInputStream(Stack &S) {
    char ch;
    
    cout << "Masukkan input stream (angka, akhiri dengan Enter): "; 
    
    while (cin.get(ch) && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            infotype x = ch - '0'; 
            Push(S, x);
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
```
#### Stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

const int MaxStack = 20; 

struct Stack {
    infotype Info[MaxStack];
    int top;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S); 
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x); 
void getInputStream(Stack &S);

#endif // STACK_H
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h" 

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    getInputStream(S);

    printInfo(S); 
    
    cout << "balik stack" << endl;
    
    balikStack(S); 
    printInfo(S); 

    return 0;
}

```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/rizkinaazizah/103112400082_RizkinaAzizah/blob/main/Pertemuan7_Modul7/Unguided3/outputUn3.png)

penjelasan unguided 3
penambahan prosedur getInputStream(S) yang bertugas menerima dan memproses input data dari pengguna sebagai sebuah stream. Prosedur ini menggunakan fungsi cin.get(ch) untuk membaca setiap karakter yang diketik pengguna, melanjutkan pembacaan hingga pengguna menekan tombol Enter. Setiap karakter yang teridentifikasi sebagai angka kemudian akan dikonversi dari karakter (char) menjadi nilai integer (infotype) yang sesuai, lalu dimasukkan (Push) ke dalam stack S.

## Kesimpulan
Dari program program diatas dapat disimpulkan bahwa bahasa C++ dalam tipe data hampir sama saja dengan bahasa pemrograman lainnya, baik dari segi struktur maupun logika. Misalnya, penggunaan variabel, operator, serta struktur kontrol seperti if-else, switch case, dan perulangan (for, while, do-while). Hal ini membuat C++ relatif mudah dipahami oleh pemula yang sudah mengenal bahasa lain, karena konsep dasarnya tetap sama yaitu menerima input, mengolah data, dan menampilkan output sesuai kebutuhan.

## Referensi
[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindu, R. (2024). Penggunaan struktur data stack dalam pemrograman C++ dengan pendekatan array dan linked list. JUTECH: Journal Education and Technology, 5(2), Desember 2024.
https://jurnal.stkipperasada.ac.id/jurnal/index.php/jutech/index
[2] Faradilla, A. (2025). Apa Itu Struktur Data? Pahami arti, jenis, dan fungsinya dalam pemrograman. Diakses dari
https://www.hostinger.com/id/tutorial/apa-itu-struktur-data
