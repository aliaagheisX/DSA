#pragma once

const int MAX_SIZE_INITIAL = 100;


template<typename T>

class Stack
{
	int Top;
	const int size;
	T* arr;

public:
	Stack(int = MAX_SIZE_INITIAL);
	~Stack();

	Stack(const Stack <T> &); // copy constructor
	Stack<T>& operator=(const Stack<T>&); // assignement overloading


	/*Getters*/
	const T& getTop() const ;
	int getSize() const;
	int getMaxSize() const;
	bool empty() const;


	/*process*/
	T pop() ;
	void push(const T&) ;
};

