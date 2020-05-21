#include <iostream>
#include "LinkedList.h"

using namespace std;

#pragma once

// Template so that the BST doesn't apply for only ints and floats.
// For other non-number objects, a < and > override is needed in the class, to allow proper adding to the BST.
template <typename T>
class BST {

private:

    // node struct for node
    struct Node {
        T value; // Contains value
        Node* left = NULL; // Left and right nodes
        Node* right = NULL;

        Node() {} // Default constructor
        Node(T val) {value = val;} // Default value constructor
    };

    // Utility for printing recursively
    void printInOrderRecur(Node* currentNode) {
        if (currentNode->left != NULL)
            printInOrderRecur(currentNode->left);
        cout << currentNode->value << " ";
        if (currentNode->right != NULL)
            printInOrderRecur(currentNode->right);

        return;
    }

    // Utility to find a node before the targetNode
    Node* findBeforeRecur(Node* currentNode, Node* targetNode) {
        
        if (currentNode->right == targetNode || currentNode->left == targetNode)
            return currentNode;

        if (targetNode->value < currentNode->value) {
            return findBeforeRecur(currentNode->left, targetNode);
        }
        return findBeforeRecur(currentNode->right, targetNode);

    }

    // Utility to find a node that has x value
    Node* find(Node* currentNode, T value) {

        if (currentNode->value == value || currentNode == NULL)
            return currentNode;

        if (value < currentNode->value) {
            return find(currentNode->left, value);
        }
        return find(currentNode->right, value);

    }

    void returnInOrderUtil(Node* currentNode, LinkedList<T>* list) {

        if (currentNode->left != NULL) {
            returnInOrderUtil(currentNode->left, list);
        }
        list->add(currentNode->value);
        if (currentNode->right != NULL) {
            returnInOrderUtil(currentNode->right, list);
        }

        return;
    }

    // Main head variable
    Node* head = NULL;
    int size = 0;

public:

    BST() {} // Default Constructor
    ~BST() { delete head; } // Default Deconstructor

    void insert(T value) {
        // Create a newNode variable with new value
        Node* newNode = new Node(value);
        // If head is null, then set head as new node
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* currentNode = head;
        Node* beforeNode = head;

        while (currentNode != NULL) {
            beforeNode = currentNode;
            if (value < currentNode->value) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }

        if (value < beforeNode->value) {
            beforeNode->left = newNode;
        } else {
            beforeNode->right = newNode;
        }
        
        size++;
    }

    void del(T value) {
        Node* node = find(head, value);
        if (node == NULL)
            return;

        // Check if right tree exists
        if (node->right != NULL) {
            // Code to find the smallest value to the right of the node tree
            // These next 2 lines takes care of the right checking
            Node* smallestValue = node->right;
            Node* beforeSmallestValue = node;
            if (smallestValue->left != NULL) {
                // Go the leftmost tree from here
                while (smallestValue->left != NULL) {
                    beforeSmallestValue = smallestValue;
                    smallestValue = smallestValue->left;
                }
                node->value = smallestValue->value;
                beforeSmallestValue->left = NULL;
            } else if (smallestValue->right != NULL) {
                node->value = smallestValue->value;
                beforeSmallestValue->right = smallestValue->right;
            } else {
                node->value = smallestValue->value;
                node->right = NULL;
            }
        // If right tree doesn't exist but left tree exist
        } else if (node->left !=NULL) {
            node->value = node->left->value;
            // if left tree has left tree
            if (node->left->left !=NULL) {
                node->left = node->left->left;
            // if left tree doesn't have left tree
            } else {
                node->left = NULL;
            }
        } else {
            Node* tempNode = findBeforeRecur(head, node);
            if (tempNode->left == node) {
                tempNode->left = NULL;
            } else {
                tempNode->right = NULL;
            }
        }
        size--;
    }

    void printInOrder() {
        printInOrderRecur(head);
        cout << endl;
    }

    LinkedList<T> returnInOrder() {
        LinkedList<T>* list = new LinkedList<T>();
        
        returnInOrderUtil(head, list);
        T* arr = new T[list->size()];
        for (int i = 0; i < list->size(); i++) {
            arr[i] = list->get(i);
        }

        LinkedList<T> endList = *list;
        delete list;
        return endList;
    }

    int getSize() {
        return size;
    }

};