#include "LinkedList.h"
#include <cstddef>
#include <exception>
#include <iostream>
using namespace std;


template<typename T>//default constructor
LinkedList<T>::LinkedList() {
    cursor = NULL;
    size = 0;
}

template<typename T>//Copy constructor
LinkedList<T>::LinkedList(const LinkedList<T> & c) {
    Node<T>* copy = c.cursor->next;
    for (int i = 0; i < c.size; i++) {
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
        Node<T>* copy = c.cursor->next;
        for (int i = 0; i < c.size;i++) {
            addBack(copy->value);
            copy = copy->next;
        }
    }
    return *this;
}

template <typename T>
void LinkedList<T>::advance() {
    if(cursor != NULL)
        cursor = cursor->next;
}


/// <Adding>
/// -- Add Front
/// -- Add Back
/// -- Add By Index
template<typename T>
void LinkedList<T>::addFront(const T& val) {
    Node<T>* newNode = new Node<T>(val, cursor->next, cursor); // next -> point to head[next of cursor] | prev -> point to Cursor[last]
    if (size == 0){ //if empty
        cursor = newNode; //make cursor point to it
        newNode->next = newNode->prev = newNode; // make the next and prev point to it self
    }
    else {
        Node<T>* head = cursor->next; //store the head before adding
        cursor->next = newNode; // change the head
        head->prev =  newNode; // case size != 1

    }
    size++;
}


template<typename T>
void LinkedList<T>::addBack(const T& val) {


    if (size == 0) { //if empty
        Node<T>* newNode = new Node<T>(val);// next -> point to head || prev -> point to tail
        cursor = newNode; //make cursor point to it
        newNode->next = newNode->prev = newNode; // make the next and prev point to it self
    }
    else { 
        Node<T>* newNode = new Node<T>(val, cursor->next, cursor);// next -> point to head || prev -> point to tail

        Node<T>* head = cursor->next;
        cursor->next = newNode;
        cursor = newNode;
        head->prev = newNode;
    }
    size++;
}


template<typename T>
//insert at index
bool LinkedList<T>::Insert(const T& val, const int& index) {

    if (index > size) return false; // check if it's okay to insert



    if (index == 0) addFront(val);

    else if (index == size) addBack(val);
    else {
        Node<T>* newNode = new Node<T>(val);
        Node<T>* previous = cursor->next;
        for (int i = 0; i < index - 1; i++) previous = previous->next;

        //set the pointers of newNode
        newNode->next = previous->next; // let the nextptr of newNode Be The Same from it's Previous
        newNode->prev = previous;

        //change the pointers around
        previous->next = newNode; // make the nextPtr of previousNode = new 
        newNode->next->prev = newNode;

        size++;
    }
    return true;
}




template<typename T>
bool LinkedList<T>::removeFront() {
    if (size == 0) return false; // case: no elements to remove

    
    Node<T>* head = cursor->next;//element head (after cursor)
    Node<T>* temp = head->next;//store  element after head 

    cursor->next = temp; // make cursor point to next of head
        
    temp->prev = cursor;

    delete head; //delete head

    if (size == 1) cursor = NULL;//if there's only one item to delete

    size--;

    return true;
}

template<typename T>
bool LinkedList<T>::removeBack() {
    if (size == 0) return false; // case: no elements to remove

    Node<T>* prevTail = cursor->prev;

    prevTail->next = cursor->next; // make prevTail next pointer point to  head

    cursor->next->prev = prevTail; // make head prev pointer pointer to new tail

    delete cursor;

    if (size == 1) cursor = NULL;//if there's only one item to delete

    else cursor = prevTail;

    size--;

    return true;
}

template<typename T>
bool LinkedList<T>::removeIndex(int index) {
    if (index >= size) return false; // case: index doesn't exist
    if (index == 0) removeFront();
    else if (index == size - 1) removeBack();
    else {
        Node<T>* prevIndex = cursor->next;

        for (int i = 0; i < index - 1; i++)
            prevIndex = prevIndex->next;

        Node<T>* nodeIndex = prevIndex->next;//store what to delete

        prevIndex->next = nodeIndex->next; // make the previous pointing to the next of the deleted node

        nodeIndex->next->prev = prevIndex; // make the prev of after Index pointing to the prev of the deleted node

        delete nodeIndex;

        size--;
    }
    return true;
}


template<typename T>
bool LinkedList<T>::removeValue(const T val) {
    if (size == 0) return false;

    Node<T>* temp = cursor->next;

    int index = 0;

    for (; index < size && temp->value != val; index++)   
        temp = temp->next;

    if (index == size) return false;//if not exist

    //get the index to remove
    return removeIndex(index);
}


template<typename T>
T& LinkedList<T>::getFront() const {
    if(cursor != NULL)
        return cursor->next->value; 
    throw exception("No Head DUDE!");
}

template<typename T>
T& LinkedList<T>::getBack() const {
    if (cursor != NULL)
        return cursor->value;
    throw exception("No tail DUDE!");
}

template<typename T>
T& LinkedList<T>::operator[](int index) const {
    /// NOTE: the index may be larger than size as it will continue loop

    Node<T>* ptr = cursor->next;
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
    Node<T>* temp = cursor->next;
    for(int i = 0;i < size;i++) {
        cout << temp->value << ' ';
        temp = temp->next;
    }

}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (size != 0) 
        removeFront();
    
}


