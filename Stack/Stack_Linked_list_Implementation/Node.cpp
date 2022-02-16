#include "Node.h"
template<typename T>
Node<T>::Node() :next(nullptr){}

template<typename T>
Node<T>::Node(const T& v) :val(v), next(nullptr) {}

template<typename T>
Node<T>::Node(const T& v,Node<T>* n) : val(v), next(n) {}