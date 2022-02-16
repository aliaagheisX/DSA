#pragma once
#include"Node.cpp"

template<typename T>
class Stack
{
	Node<T>* head;
	int size;
public:
	Stack();
	~Stack();

	Stack(const Stack<T>&);
	Stack<T> & operator=(const Stack<T> &);

	const T& getTop() const;
	int getSize() const;
	bool empty() const;

	T pop();
	void push(const T&);

};

