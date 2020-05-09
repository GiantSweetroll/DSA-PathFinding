#include <iostream>
#include <memory>
#include "BST.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    // LinkedList<int> list;
    
    // BST<int> bst;

    // bst.insert(152);
    // bst.insert(213);
    // bst.insert(15);
    // bst.insert(613);
    // bst.insert(3);
    // bst.insert(125);
    // bst.insert(13);
    // bst.insert(64);
    // bst.insert(32);
    // bst.insert(2123);

    // bst.del(15);
    // bst.del(125);
    // bst.del(32);

    // bst.printInOrder();

    
    // LinkedList<int> yes = bst.returnInOrder();
    
    // for (int i = 0; i < yes.size(); i++) {
    //     cout << yes.get(i) << endl;
    // }
    
    LinkedList<int> ant;

    for (int i = 0; i < 5; i++) {
        ant.add(i);
    }

    cout << ant.size() << endl;
    ant.clearList();
    cout << ant.size() << endl;

    return 0;
}