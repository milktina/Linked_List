//
// Created by Christina Nguyen on 10/1/22.
//
#include <iostream>
#include <vector>
#pragma once
using namespace std;

#ifndef COP3503PROJECT1_LINKEDLIST_H
#define COP3503PROJECT1_LINKEDLIST_H

//struct Node {
//    size_t linkedListData;
//    struct Node *next;
//};

template<class T>
class LinkedList {
public:
    struct Node {
        T data;
        struct Node *next;
        struct Node *prev;
    };
private:
    unsigned int nodeCount;
    Node* head;
    Node* tail;
public:
    /* behaviors */
    void PrintForward() const; //iterates through all the nodes and prints out their values, one at a time
    void PrintReverse() const; // exactly the same at PrintForward, but backwards
    void PrintForwardRecursive(const Node* node) const; // takes in pointer to a node (starting node), and from that node,
    // recursively visits each node that follows, in forward order, and prints their values (must be implemented using recursion)
    void PrintReverseRecursive(const Node* node) const; //same as PrintForwardRecursive, but backwards

    /* accessors */
    unsigned int NodeCount() const; // how many things are stored in this list?
    void FindAll(vector<Node*>& outData, const T& value) const; // finds all nodes which match the passed in parameter value,
    // and store a pointer to that node in the passed in vector
    Node* Find(const T& data) const; // find the first node with a data value matching the passed in parameter, returning
    // a pointer to that node. returns nullptr if no matching node found
    Node* Find(const T& data); // non-const version of Find
    Node* GetNode(unsigned int index) const; // given an index, return a pointer to the node at that index. throws an exception of
    // type out_of_range if the index is out of range
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
    void InsertAfter(Node* node, const T& data); // given a pointer to a node, create a new node to store the passed in value,
    // after the indicated node
    void InsertBefore(Node* node, const T& data);  // same as InsertAfter, except inserting the new node before the indicated node
    void InsertAt(const T& data, unsigned int index); // insert a new Node to store the first parameter, at the index-th location.
    // throws an out_of_range exception if given an invalid index
`    /* removal */
    bool RemoveHead(); // deletes first node in list. returns whether or not node was removed
    bool RemoveTail(); // deletes last node in list, returns whether or not node was removed
    unsigned int Remove(const T&data); // remove ALL NODES containing values matching that of the passed in parameter. returns
    // how many instances were removed
    bool RemoveAt(unsigned int index); // deletes the index-th Node from the list, returning whether or not the operation was successful
    void Clear(); // deletes all Nodes. update node count

    /* operators */
    const T& operator[](unsigned int index) const; // overloaded subscript operator. takes an index, and returns data from the index-th node. throws
    // out_of_range exception for an invalid index
    T& operator[](unsigned int index);
    bool operator==(const LinkedList<T>& rhs) const; // overloaded equality operator
    LinkedList<T>& operator=(const LinkedList<T> & rhs); // assignment operator

    /* construction/destruction */
    LinkedList(); // default constructor; 0 nodes in an empty list; head and tail are pointing to nullptr
    LinkedList(const LinkedList<T>& list); // copy constructor sets "this" to a copy of the passed in LinkedList
    ~LinkedList(); // deletes all the nodes created by the list
};

/* behaviors */
template<typename T>
void LinkedList<T>::PrintForward() const {
    Node *temp;
    temp = head;

    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
template<typename T>
void LinkedList<T>::PrintReverse() const {
    Node *temp;
    temp = tail;

    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->prev;
    }
}
template<typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
    if(node != nullptr) {
        cout << node->data << endl;
        PrintForwardRecursive(node->next);
    }
}
template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
    if (node != nullptr) {
        cout << node->data << endl;
        PrintReverseRecursive(node->prev);
    }
}

/* accessors */
template<typename T>
unsigned int LinkedList<T>::NodeCount() const {
    return nodeCount;
}

template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
    Node *temp = head;

    while (temp != nullptr) {
        if ((temp->data == value)) {
            outData.push_back(temp);
        }
        temp = temp->next;
    }
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
    Node *temp = head;

    while (temp != nullptr) {
//    for (size_t i = 0; i < nodeCount; i++) {
//        temp = temp->next;
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
//     return nullptr;
    }
    return nullptr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
    Node *temp = head;

    while (temp != nullptr) {
//    for (size_t i = 0; i < nodeCount; i++) {
//        temp = temp->next;
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
//        return nullptr;
        }
    return nullptr;
//    return temp;
//    return 0;
    }

//    return nullptr;


template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const{
    Node *temp = head;

    if (index >= nodeCount) {
        throw out_of_range ("Index out of bounds");
    }

    for (size_t i = 0; i < index; i++) {
        temp = temp -> next;
    }

    return temp;

}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
    Node *temp = head;

    if (index >= nodeCount) {
        throw out_of_range ("Index out of bounds");
    }

    for (size_t i = 0; i < index; i++) {
        temp = temp -> next;
    }

    return temp;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
    return head;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() const{
    return head;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
    return tail;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() const{
    return tail;
}

/* insertion */
template<typename T>
void LinkedList<T>::AddHead(const T& data) {
    Node *temp = new Node();
    temp->data = data;

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
void LinkedList<T>::AddTail(const T& data) {
    Node *temp = new Node();
    temp->data = data;
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
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
    size_t j = count;

    for (size_t i = 0; i < count; i++) {
        Node *temp = new Node();
        j -= 1;
        temp->data = *(data+j);
        temp->next = head;
        head = temp;

        nodeCount++;
    }
}
template<typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
    Node *last;
    for (size_t i = 0; i < count; i++) {
        Node *temp = new Node();
        temp->data = *(data+i);
        last = head;

        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = temp;
        temp->next = nullptr;

        nodeCount++;
    }
}

template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
    if (node == tail) {
        AddTail(data);
    }

    else {
        Node *temp = new Node();
        temp->data = data;
        temp->next = node->next;
        node->next = temp;
    }
    nodeCount++;
}

template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
    Node *front = head;
    Node *back = tail;
    Node *temp;

    if (front == nullptr && back == nullptr) {
        AddHead(data);
        return;
    }

    if (node == nullptr) {
        return;
    }

    while (front <= back) {
        if (front == node) {
            temp = front;
            break;
        }
        else if (back == node) {
            temp = back;
            break;
        }

        front = front->next;
        back = back->prev;
    }

    Node *newNode = new Node();
    newNode->data = data;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev = newNode;
    nodeCount++;
}
template<typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
    if (index > nodeCount) {
        throw out_of_range("Index out of bounds");
    }

    if (index == 0) {
        AddHead(data);
    }

    else if (index == nodeCount) {
        AddTail(data);
    }

    else {
        Node *newNode;
        newNode = GetNode(index - 1);
        InsertAfter(newNode, data);
    }
}

/* removal */
template<typename T>
bool LinkedList<T>::RemoveHead() {
    if(head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
        nodeCount--;
        return true;
    }
    return false;
}
template<typename T>
bool LinkedList<T>::RemoveTail() {
    if (head == nullptr) {
        return false;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        nodeCount--;
        return true;
    }

    Node *current = head;
    while(current->next && current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    nodeCount--;
    return true;
}

template<typename T>
unsigned int LinkedList<T>::Remove(const T&data) {
    unsigned int numRemoved = 0;

    Node *current = head;
    Node *previous = nullptr;

    while (current) {
        while (current->data == data) {
            numRemoved++;
            Node *oldValue = current;
            current = current->next;

            if (previous) {
                previous->next = current;
            }

            delete oldValue;
            nodeCount--;
        }
        previous = current;
        current = current->next;
    }
    return numRemoved;
}


template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
    if (index > nodeCount) {
        return false;
    }
    Node *previous = nullptr;
    Node *current = head;

    unsigned int currentIndex = 0;

    while (current) {
        if (currentIndex == index) {
            break;
        }
        currentIndex++;
        previous = current;
        current = current->next;
    }

    if (previous) {
        previous->next = current->next;
        delete current;
        nodeCount--;
        return true;
    }
    else {
        head = current->next;
        delete current;
        nodeCount--;
        return true;
    }
}

template<typename T>
void LinkedList<T>::Clear() {
    Node *temp = head;
    Node *next;
    while (temp != nullptr) {
        next = temp->next;
        delete temp;
        temp = next;
    }

    delete head;

    head = nullptr;
    tail = nullptr;
    nodeCount = 0;
}

/* operators */
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
    Node *current = head;

    if (index >= nodeCount) {
        throw out_of_range ("Index out of bounds");
    }

    while (index--) {
        current = current->next;
    }

    return current->data;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
    Node *current = head;

    if (index >= nodeCount) {
        throw out_of_range ("Index out of bounds");
    }

    while (index--) {
        current = current->next;
    }

    return current->data;
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
    if(nodeCount != rhs.nodeCount) {
        return false;
    }

    if(head == nullptr && rhs.head == nullptr) {
        return true;
    }

    Node *list1Node = head;
    Node *list2Node = rhs.head;

    while (list1Node != nullptr) {
        if(list1Node->data != list2Node->data) {
            return false;
        }
        list1Node = list1Node->next;
        list2Node = list2Node->next;
    }
    return true;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & rhs) {
    LinkedList<T> temp(rhs);
    swap(temp.head, head);
    return *this;
}

/* construction/destruction */
template<typename T>
LinkedList<T>::LinkedList() {
    nodeCount = 0;
    head = nullptr;
    tail = nullptr;

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    if (list.head == nullptr) {
        head = nullptr;
    }
    else {
        Node *nodeNew = new Node();
        nodeNew->data = list.head->data;
        nodeNew->next = nullptr;
        head = nodeNew;

        Node *passed = list.head->next;
        Node *caller = head;

        while (passed != nullptr) {
            caller->next = new Node();
            caller->next->data = passed->data;
            caller->next->next = nullptr;
            caller = caller->next; // move to newly added node
            passed = passed->next; // move one node further
        }
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
//    delete[] linkedListdata;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}

#endif //COP3503PROJECT1_LINKEDLIST_H