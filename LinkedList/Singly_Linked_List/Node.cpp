#include "Node.h"
#include <cstddef>
template <typename T>
Node<T>::Node() {
    next = NULL;
}

template<typename T>
Node<T>::Node(const T& v) {
    value = v;
    next = NULL;
}

template<typename T>
Node<T>::Node(const T& v,Node<T>* n) {
    value = v;
    next = n;
}