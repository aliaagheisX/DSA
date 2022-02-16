#pragma once
template<typename T>
class Node
{
public:
	T val;
	Node* next;

	Node();
	Node(const T&);
	Node(const T&,Node<T> *);
};

