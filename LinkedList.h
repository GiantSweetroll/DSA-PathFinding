
#pragma once

// WARNING: ALL OF THE TYPE VALUES THAT WANTS TO BE PUT HERE MUST HAVE A DEFAULT CONSTRUCTOR.

// The template functions so that any type of values is accepted.
template <typename T>
class LinkedList {

    /* Each LinkedList class has only one variable, the node. the node is a Node struct that contains the value,
    and the pointer to the next node.

    When the pointer is NULL, then you have reached the end of the list.
    */

    struct Node {
        T value;    // Value containing the data
        Node* node = NULL;  // Pointer to next Node struct

        Node() {}  // Normal constructor
        Node(T val) { value = val; }  // Constructor to automatically assign a value
    };

    Node* getEndAddress() { 

        /* To make life easier, a getEndAddress method is implemented to 
        get the end of the LinkedList node address. */

        if (node != NULL) {
            Node* currentNode = node;
            while (currentNode->node != NULL) {
                currentNode = currentNode->node;
            }
            return currentNode;
        }
        return NULL;
    }
    
    Node* getNodeAtIndex(int index) {

        /* Another function to make life easier.
        Used to return a node at the specified index. */

        Node* currentNode = node;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->node;
        }
        return currentNode;
    }

    Node* node = NULL;  // Pointer to the first index of the List.

public:

    LinkedList() {}  // Normal Constructor
    ~LinkedList() { clearList(); delete node; }  // Normal Destructor

    /* This implementation of the Iterator can be used with:

    LinkedList::Iterator it;
    The iterator can be used just like normal C++ Iterators.
    The available operators are:

    it++ to increment the pointer
    it != LinkedList.end()
    it = LinkedList.begin()
    *LinkedList to get the value */

    class Iterator {
        Node* address;

    public:
        Iterator(Node* add) {address = add;}  // Easy access for assigning pointer
        Iterator() {}

    // Operator overloads
        void operator ++ (int) {
            address = address->node;
        }

        bool operator == (Iterator addr) {
            return (address == addr.address);
        }

        bool operator != (Iterator addr) {
            return (address != addr.address);
        }

        T operator * () {
            return address->value;
        }
    };

    // Iterator assignments
    Iterator begin() {
        return *(new Iterator(node));
    }

    Iterator end() {
        return NULL;
    }
    
    // Add a node to LinkedList at the end of the list with the value.
    void add(T value) {
        // If the first index's pointer is nil then
        Node* endNode = getEndAddress();
        if (endNode != NULL)
            endNode->node = new Node(value);
        else
            node = new Node(value);
    }

    // The Size method returns the size of the list.
    int size() {
        if (node != NULL) {
            int num = 1;
            Node* currentNode = node;
            while (currentNode->node != NULL) {
                num++;
                currentNode = currentNode->node;
            }
            return num;
        }
        return 0;
    }

    // This function gets the value in the specified index
    T get(int index) {
        return getNodeAtIndex(index)->value;
    }

    // Inserts a new value into the list by moving the node pointer into
    // the new Node object made, and set the pointer of the newly made object to
    // the next specified index.
    void insert(int index, T value) {
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->node = node;
            node = newNode;
        } else {
            Node* currentNode = getNodeAtIndex(index - 1);
            newNode->node = currentNode->node;
            currentNode->node = newNode;
        }
    }

    // Deletes the index at the specified index by
    // Moving the node pointer before the index to the next index.
    void del(int index) {
        if (index == 0 ) {
            node = getNodeAtIndex(1);
        } else {
            Node* leftNode = getNodeAtIndex(index - 1);
            Node* willDel = leftNode->node;
            leftNode->node = leftNode->node->node;
            delete willDel;
        }
    }

    // Deletes all the pointer.
    void clearList() {
        int count = size();
        for (int i = 0; i < count; i++) {
            del(0);
        }
    }

    // Exactly the same as the add method.
    void operator += (T value) {
        this->add(value);
    }

};