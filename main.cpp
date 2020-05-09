#include <iostream>
#include "BST.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    LinkedList<int> list;
    
    BST<int> bst;

    bst.insert(152);
    bst.insert(213);
    bst.insert(15);
    bst.insert(613);
    bst.insert(3);
    bst.insert(125);
    bst.insert(13);

    bst.printInOrder();

    
    LinkedList<int> yes = bst.returnInOrder();
    
    for (int i = 0; i < yes.size(); i++) {
        std::cout << yes.get(i) << std::endl;
    }
    


    return 0;
}