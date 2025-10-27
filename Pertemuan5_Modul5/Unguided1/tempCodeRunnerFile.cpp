#include <iostream>
using namespace std;

// Struktur buat nyimpen data dan nyambung ke node berikutnya
struct Node {
    int data;      // isinya angka
    Node* next;    // penunjuk ke kotak (node) setelahnya
};

// Fungsi buat nambahin data di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; // bikin kotak baru
    if (!head) head = newNode; // kalau belum ada kotak sama sekali, ini jadi kotak pertama
    else {
        Node* temp = head;
        // cari kotak terakhir
        while (temp->next) temp = temp->next;
        // sambungin kotak baru di belakangnya
        temp->next = newNode;
    }
}

// Fungsi buat ngitung berapa banyak kotak (node)
int getSize(Node* head) {
    int size = 0;
    for (Node* current = head; current; current = current->next)
        size++; // tiap ketemu kotak, tambah 1
    return size;
}

// Fungsi buat ngambil node di posisi ke-n
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++)
        head = head->next; // geser ke depan sampai posisi yang dimau
    return head;
}

// Fungsi binary search di linked list
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    int size = getSize(head);       // hitung dulu berapa banyak kotak
    int left = 0, right = size - 1; // batas kiri dan kanan
    int iter = 1;                   // buat nandain iterasi keberapa

    while (left <= right) {
        int mid = (left + right) / 2;          // cari posisi tengah
        Node* midNode = getNodeAt(head, mid);  // ambil node tengah

        cout << "Iterasi " << iter++ << ": Tengah = " << midNode->data;

        if (midNode->data == key) { // kalau isinya sama kayak yang dicari
            cout << " -> KETEMU!\n";
            cout << "\nNilai " << key << " ketemu di linked list!\n";
            cout << "Alamat node: " << midNode << endl;
            if (midNode->next)
                cout << "Node setelahnya: " << midNode->next->data << endl;
            else
                cout << "Node setelahnya: NULL (udah terakhir)\n";
            return midNode;
        }
        else if (midNode->data < key) { // kalau nilai tengah lebih kecil
            cout << " -> Cari di kanan\n";
            left = mid + 1; // geser batas kiri
        }
        else { // kalau nilai tengah lebih besar
            cout << " -> Cari di kiri\n";
            right = mid - 1; // geser batas kanan
        }
    }

    // kalau udah habis tapi belum ketemu
    cout << "\nNilai " << key << " nggak ketemu di linked list!\n";
    return nullptr;
}

// Fungsi buat nampilin isi linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "[" << temp->data << "]";
        if (temp->next)
            cout << " → "; // tanda panah ke node berikutnya
        temp = temp->next;
    }
    cout << " → NULL\n"; // tanda akhir list
}

int main() {
    Node* head = nullptr;

    // Bikin linked list-nya
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked list yang dibuat: ";
    printList(head);

    //cari data yang ada
    cout << "\nCari nilai 40:\n";
    binarySearch(head, 40);

    //cari data yang nggak ada
    cout << "\nCari nilai 25:\n";
    binarySearch(head, 25);

    return 0;
}
