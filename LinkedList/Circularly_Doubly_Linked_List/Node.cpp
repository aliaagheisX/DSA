#include "Node.h"
#include <cstddef>
template <typename T>
Node<T>::Node() {
    next = NULL;
    prev = NULL;
}

template<typename T>
Node<T>::Node(const T& v) {
    value = v;
    next = NULL;
    prev = NULL;
}

template<typename T>
Node<T>::Node(const T& v,Node<T>* n, Node<T>* p) {
    value = v;
    next = n;
    prev = p;
}