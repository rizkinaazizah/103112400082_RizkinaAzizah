#include <iostream>
#include "bst.h"
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    cout << "Hello World!" << endl;

    auto start = high_resolution_clock::now();

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    inOrder(root);
    cout << "\n";

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << fixed << setprecision(3);
    cout << "Process returned 0 (0x0) execution time : " << elapsed.count() << " s" << endl;
    cout << "Press any key to continue." << endl;

    return 0;
}
