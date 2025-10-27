#include "SinglyList.h"

int main() {
    List L;
    address p;

    createList(L);

    p = alokasi(9);  insertLast(L, p);
    p = alokasi(12); insertLast(L, p);
    p = alokasi(8);  insertLast(L, p);
    p = alokasi(0);  insertLast(L, p);
    p = alokasi(2);  insertLast(L, p);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, 8); 
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
