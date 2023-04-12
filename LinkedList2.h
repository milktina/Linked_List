//
// Created by Christina Nguyen on 10/1/22.
//
#include <iostream>
#pragma once
using namespace std;

#ifndef COP3503PROJECT1_LINKEDLIST2_H
#define COP3503PROJECT1_LINKEDLIST2_H

//struct Node {
//    size_t linkedListData;
//    struct Node *next;
//};

template<class T>
class LinkedList2 {
    struct Node {
        T linkedListData;
        struct Node *next;
        struct Node *prev;
    };

    unsigned int nodeCount;
    Node* head;
    Node* tail;


public:
    /* behaviors */
    void PrintForward() const; //iterates through all the nodes and prints out their values, one at a time
    void PrintReverse() const; // exactly the same at PrintForward, but backwards
//    void PrintForwardRecursive(const Node* node) const; // takes in pointer to a node (starting node), and from that node,
//    // recursively visits each node that follows, in forward order, and prints their values (must be implemented using recursion)
//    void PrintReversRecursive(const Node* node) const; //same as PrintForwardRecursive, but backwards

    /* accessors */
    unsigned int NodeCount() const; // how many things are stored in this list?
    void FindAll(vector<Node*>& outData, const T& value) const; // finds all nodes which match the passed in parameter value,
//    // and store a pointer to that node in the passed in vector
    Node* Find(const T& data) const; // find the first node with a data value matching the passed in parameter, returning
//    // a pointer to that node. returns nullptr if no matching node found
    Node* Find(const T& data); // non-const version of Find
    Node* GetNode(unsigned int index) const; // given an index, return a pointer to the node at that index. throws an exception of
//    // type out_of_range if the index is out of range
    Node* GetNode(unsigned int index); // non-const version of GetNode
    Node* Head(); // returns the head pointer
    Node* Head() const;
    Node* Tail(); // returns the tail pointer
    Node* Tail() const;

    /* insertion */
    void AddHead(const T& data); // creates a new node at the front of the list to store the passed in parameter
    void AddTail(const T& data); // creates a new node at the end of the list to store the passed in parameter
    void AddNodesHead(const T* data, unsigned int count); // given an array of values, insert a node for each of those at the beginning of
    // a list, maintaining the original order
    void AddNodesTail(const T* data, unsigned int count); // same as AddNodesHead, but adding to end of the list
//    void InsertAfter(Node* node, const T& data); // given a pointer to a node, create a new node to store the passed in value,
//    // after the indicated node
//    void InsertBefore(Node* node, const T& data); // same as InsertAfter, except inserting the new node before the indicated node
//    void InsertAt(const T& data, unsigned int index); // insert a new Node to store the first parameter, at the index-th location.
//    // throws an out_of_range exception if given an invalid index

    /* removal */
//    bool RemoveHead(); // deletes first node in list. returns whether or not node was removed
//    bool RemoveTail(); // deletes last node in list, returns whether or not node was removed
//    unsigned int Remove(const T&data); // remove ALL NODES containing values matching that of the passed in parameter. returns
//    // how many instances were removed
//    bool RemoveAt(unsigned int index); // deletes the index-th Node from the list, returning whether or not the operation was successful
//    void Clear(); // deletes all Nodes. update node count

    /* operators */
    const T& operator[](unsigned int index) const; // overloaded subscript operator. takes an index, and returns data from the index-th node. throws
//    // out_of_range exception for an invalid index
    T& operator[](unsigned int index);
//    bool operator==(const LinkedList<T>& rhs) const; // overloaded equality operator
//    LinkedList<T>& operator=(const LinkedList<T> & rhs); // assignment operator

    /* construction/destruction */
    LinkedList2(); // default constructor; 0 nodes in an empty list; head and tail are pointing to nullptr
    LinkedList2(const LinkedList2<T>& list); // copy constructor sets "this" to a copy of the passed in LinkedList
    ~LinkedList2(); // deletes all the nodes created by the list
};

/* behaviors */
template<typename T>
void LinkedList2<T>::PrintForward() const {
    Node *temp;
    temp = head;

    while (temp != nullptr) {
        cout << temp->linkedListData << endl;
        temp = temp->next;
    }
}

template<typename T>
void LinkedList2<T>::PrintReverse() const {
    Node *temp;
    temp = tail;

    while (temp != nullptr) {
        cout << temp->linkedListData << endl;
        temp = temp->prev;
    }
}
//template<typename T>
//void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
//
//}
//template<typename T>
//void LinkedList<T>::PrintReversRecursive(const Node* node) const {
//
//}

/* accessors */
template<typename T>
unsigned int LinkedList2<T>::NodeCount() const {
    return nodeCount;
}

template<typename T>
void LinkedList2<T>::FindAll(vector<Node*>& outData, const T& value) const {
    Node *temp;

    for (size_t i = 0; i < nodeCount; i++) {
        temp = temp->next;
        if ((temp->linkedListData = value)) {
            outData.push_back(temp);
        }
    }
}

template<typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::Find(const T& data) const{
    Node *temp;

    for (size_t i = 0; i < nodeCount; i++) {
        temp = temp->next;
        if ((temp->linkedListData = data)) {
            return temp;
        }
    }

    return nullptr;

} // figure out template!!!!

template<typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::Find(const T& data) {
    Node *temp;

    for (size_t i = 0; i < nodeCount; i++) {
        temp = temp->next;
        if ((temp->linkedListData = data)) {
            return temp;
        }
    }

    return nullptr;
}

template<typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::GetNode(unsigned int index) const{
    Node *temp = new Node();

    if (index > nodeCount) {
        throw out_of_range ("Out of range");
    }

    for (size_t i = 0; i < index; i++) {
        temp = temp -> next;
    }

    return temp;

} // figure out template!!!!

template <typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::GetNode(unsigned int index) {
    Node *temp = new Node();

    if (index > nodeCount) {
        throw out_of_range ("Out of range");
    }

    for (size_t i = 0; i < index; i++) {
        temp = temp -> next;
    }

    return temp;
}

template<typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::Head() {
    return *head;
}
template<typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::Head() const{
    return *head;
} // figure out template!!!!

template<typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::Tail() {
    return *tail;
}

template<typename T>
typename LinkedList2<T>::Node* LinkedList2<T>::Tail() const{
    return *tail;
} // figure out template!!!

/* insertion */
template<typename T>
void LinkedList2<T>::AddHead(const T& data) {
    Node *temp = new Node();
    temp->linkedListData = data;

    if (head == nullptr) {
        head = temp;
        head->prev = nullptr;
        tail = temp;
        tail->next = nullptr;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = nullptr;
    }

    nodeCount++;
}

template<typename T>
void LinkedList2<T>::AddTail(const T& data) {
    Node *temp = new Node();
    temp->linkedListData = data;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        head->prev = nullptr;
        tail = temp;
        tail->next = nullptr;
    }

    else {
        Node *last = head;

        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = temp;
        tail = temp;
        tail->prev = last;
    }

    nodeCount++;
}

template<typename T>
void LinkedList2<T>::AddNodesHead(const T* data, unsigned int count) {
    size_t j = count;

    for (size_t i = 0; i < count; i++) {
        Node *temp = new Node();
        j -= 1;
        temp->linkedListData = *(data+j);
        temp->next = head;
        head = temp;

        nodeCount++;
    }
}

template<typename T>
void LinkedList2<T>::AddNodesTail(const T* data, unsigned int count) {
    Node *last;
    for (size_t i = 0; i < count; i++) {
        Node *temp = new Node();
        temp->linkedListData = *(data+i);
        last = head;

        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = temp;
        temp->next = nullptr;

        nodeCount++;
    }
}
//template<typename T>
//void LinkedList<T>::InsertAfter(Node* node, const T& data) {
//
//}
//template<typename T>
//void LinkedList<T>::InsertBefore(Node* node, const T& data) {
//
//}
//template<typename T>
//void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
//
//}

/* removal */
//template<typename T>
//bool LinkedList<T>::RemoveHead() {
//
//}
//template<typename T>
//bool LinkedList<T>::RemoveTail() {
//
//}
//template<typename T>
//unsigned int LinkedList<T>::Remove(const T&data) {
//
//}
//template<typename T>
//bool LinkedList<T>::RemoveAt(unsigned int index) {
//
//}
//template<typename T>
//void LinkedList<T>::Clear() {
//
//}

/* operators */
template <typename T>
const T& LinkedList2<T>::operator[](unsigned int index) const {
    Node *current = head;

    while (index--) {
        current = current->next;
    }

    return current->linkedListData;
}

template <typename T>
T& LinkedList2<T>::operator[](unsigned int index) {
    Node *current = head;

    while (index--) {
        current = current->next;
    }

    return current->linkedListData;
}
//bool operator==(const LinkedList<T>& rhs) const;
//LinkedList<T>& operator=(const LinkedList<T> & rhs);

/* construction/destruction */
template<typename T>
LinkedList2<T>::LinkedList2() {
    nodeCount = 0;
    head = nullptr;
    tail = nullptr;

}

template<typename T>
LinkedList2<T>::LinkedList2(const LinkedList2<T> &list) {
    if (list.head == nullptr) {
        head = nullptr;
    }
    else {
        Node *nodeNew = new Node();
        nodeNew->linkedListData = list.head->linkedListData;
        nodeNew->next = nullptr;
        head = nodeNew;

        Node *passed = list.head->next;
        Node *caller = head;

        while (passed != nullptr) {
            caller->next = new Node();
            caller->next->linkedListData = passed->linkedListData;
            caller->next->next = nullptr;
            caller = caller->next; // move to newly added node
            passed = passed->next; // move one node further
        }
    }
}

template<typename T>
LinkedList2<T>::~LinkedList2() {
//    delete[] linkedListdata;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}

#endif //COP3503PROJECT1_LINKEDLIST2_H

