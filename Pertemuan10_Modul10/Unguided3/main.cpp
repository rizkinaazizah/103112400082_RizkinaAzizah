#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    cout << "Pre-order  : ";
    preOrder(root);
    cout << endl;

    cout << "Post-order : ";
    postOrder(root);
    cout << endl;

    return 0;
}
