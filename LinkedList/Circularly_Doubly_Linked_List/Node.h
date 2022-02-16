#ifndef H_NODE
#define H_NODE


template<typename T>
class Node {
public:
    T value;
    Node* next;
    Node* prev;
    ///Constructors
    Node();
    Node(const T&);
    Node(const T&,Node<T>*,Node<T>*);
};

#endif