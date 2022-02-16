#include "LinkedList.h"
#include <cstddef>
#include <exception>
#include <iostream>
using namespace std;


template<typename T>//default constructor
LinkedList<T>::LinkedList() {
    head = tail = NULL;
    size = 0;
}

template<typename T>//Copy constructor
LinkedList<T>::LinkedList(const LinkedList<T> & c) {
    Node<T>* copy = c.head;
    while (copy != NULL) {
        addBack(copy->value);
        copy = copy->next;
    }
} 


template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & c) {
    if (this != &c) {//check for not self assignement

        //Delete all Nodes
        while (size != 0) removeFront();

        //copy
        Node<T>* copy = c.head;
        while (copy != NULL) {
            addBack(copy->value);
            copy = copy->next;
        }
    }
    return *this;
}



/// <Adding>
/// -- Add Front
/// -- Add Back
/// -- Add By Index
template<typename T>//default constructor
void LinkedList<T>::addFront(const T& val) {
    Node<T>* newNode = new Node<T>(val, head);
    head = newNode;
    if (size == 0) tail = newNode;
    size++;
}


template<typename T>//default constructor
void LinkedList<T>::addBack(const T& val) {

    Node<T>* newNode = new Node<T>(val);

    if (size == 0) head = tail = newNode; // if empty head and tail point to newNode
    else tail->next = newNode, tail = newNode; // if  not the prev last element point to it and it become the tail

    size++;
}


template<typename T>
bool LinkedList<T>::Insert(const T& val, const int& index) {

    if (index > size) return false; // check if it's okay to insert



    if (index == 0) addFront(val);

    else if (index == size) addBack(val);
    else {
        Node<T>* newNode = new Node<T>(val);
        Node<T>* temp = head;
        for (int i = 0; i < index - 1; i++) temp = temp->next;
        newNode->next = temp->next; // let the nextptr of newNode Be The Same from it's Previous
        temp->next = newNode; // make the nextPtr of previousNode = new 
        size++;
    }
    return true;
}




template<typename T>
bool LinkedList<T>::removeFront() {
    if (size == 0) return false; // case: no elements to remove
    
    Node<T>* temp = head->next;//store  element after head

    delete head; //delete head

    head = temp; //newHead = temp

    size--;

    return true;
}

template<typename T>
bool LinkedList<T>::removeBack() {
    if (size == 0) return false; // case: no elements to remove

    Node<T>* prevTail = head;

    while (prevTail->next != tail && prevTail != NULL) prevTail = prevTail->next;//loop till next == tail or not the end

    delete tail;

    tail = prevTail;

    if(tail != NULL)
        tail->next = NULL;

    size--;
    return true;
}

template<typename T>
bool LinkedList<T>::removeIndex(int index) {
    if (index >= size) return false; // case: index doesn't exist
    if (index == 0) removeFront();
    else if (index == size - 1) removeBack();
    else {
        Node<T>* prevIndex = head;

        for (int i = 0; i < index - 1; i++)
            prevIndex = prevIndex->next;

        Node<T>* nodeIndex = prevIndex->next;//store what to delete

        prevIndex->next = prevIndex->next->next; // make the previous pointing to the next of the deleted node

        delete nodeIndex;

        size--;
    }
    return true;
}


template<typename T>
bool LinkedList<T>::removeValue(const T val) {
    if (size == 0) return false;

    Node<T>* temp = head;

    int index = 0;

    while (temp != NULL && temp->value != val) temp = temp->next, index++;

    if (temp == NULL) return false;//if not exist

    //get the index to remove
    return removeIndex(index);
}


template<typename T>
T& LinkedList<T>::getFront() const {
    if(head!= NULL)
        return head->value; 
    throw exception("No Head DUDE!");
}

template<typename T>
T& LinkedList<T>::getBack() const {
    if (tail != NULL)
        return tail->value;
    throw exception("No tail DUDE!");
}

template<typename T>
T& LinkedList<T>::operator[](int index) const {
    if (index >= size) throw exception("OUT OF RANGE");

    Node<T>* ptr = head;
    for (int i = 0; i < index; i++)
        ptr = ptr->next;
    return ptr->value;
}




template<typename T>
bool LinkedList<T>::isEmpty() const { return size; }


template<typename T>
int LinkedList<T>::getSize() const { return size; }


template<typename T>
void LinkedList<T>::print() const {
    Node<T>* temp = head;
    while (temp != NULL) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }

}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (size != 0) removeFront();
}


