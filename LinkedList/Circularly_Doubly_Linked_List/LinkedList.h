#ifndef H_LINKED_LIST
#define H_LINKED_LIST

#include "Node.cpp"

template<typename T>
class LinkedList {
    Node<T>* cursor;
    int size;
public:
    //initalizers
    LinkedList(); //default constructor

    LinkedList(const LinkedList<T>&); //copy constructor
    LinkedList<T>& operator=(const LinkedList <T> &); //assignment operator overloading
    void advance();

//adders
    void addFront(const T& val);
    void addBack(const T& val);
    bool Insert(const T& val, const int& index);

    //removers
    bool removeFront();
    bool removeBack();
    bool removeIndex(int index);
    bool removeValue(const T val);

    //getters
    T& getFront() const;
    T& getBack() const;
    T& operator[](int index) const;

    bool isEmpty() const;
    int getSize() const;

    void print() const;
    //destructor
    ~LinkedList();
};

#endif