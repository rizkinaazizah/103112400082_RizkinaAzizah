#include <iostream>
using namespace std;

// Struktur buat node (kotak data)
struct Node {
    int data;      // isi data
    Node* next;    // penunjuk ke node berikutnya
};

// Fungsi buat nambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; // bikin kotak baru
    if (!head) head = newNode; // kalau belum ada kotak, maka bakal jadi kotak pertama
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; // cari ujung list
        temp->next = newNode; // sambungin ke kotak baru
    }
}

// Fungsi buat nampilin isi linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> "; // tampilkan isi kotak (data), terus kasih tanda panah biar keliatan nyambung
        temp = temp->next; // geser pointer ke kotak berikutnya
    }
    cout << "NULL" << endl;// tampilkan tulisan NULL buat nandain akhir dari rantai linked list
}


// Fungsi linear search di linked list
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";

    Node* current = head; // mulai dari node pertama
    int posisi = 1; // buat nandain urutan node

    while (current) {
        cout << "Memeriksa node " << posisi << ": " << current->data;
        if (current->data == key) { // kalau data di node sekarang sama kayak yang dicari
            cout << " (SAMA) - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            if (current->next) // cek apakah node berikutnya masih ada
                cout << "Node berikutnya: " << current->next->data << endl;
            else
                cout << "Node berikutnya: NULL\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next; // geser ke node berikutnya
        posisi++;//biar tahu lagi di urutan keberapa
    }

    // kalau data nggak ketemu
    cout << "Tidak ada node lagi yang tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    // bikin list-nya
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: ";
    printList(head);

    // cari nilai yang ada
    cout << "Mencari nilai: 30\n";
    linearSearch(head, 30);

    // cari nilai yang tidak ada
    cout << "\nMencari nilai: 25\n";
    linearSearch(head, 25);

    return 0;
}
