#include "Stack.h"
#include <exception>
template<typename T>
Stack<T>::Stack(int s) :size(s){
	arr = new T[size];
	Top = -1;
}
template<typename T>
Stack<T>::~Stack() {
	delete[] arr;
}

template<typename T>
Stack<T>::Stack(const Stack <T>& c){ 
	size = c.size;
	arr = new T[size];
	Top = c.Top;
	for (int i = 0; i <= Top; i++) arr[i] = c.arr[i];
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>&){ // assignement overloading
	delete[] arr;
	size = c.size;
	arr = new T[size];
	Top = c.Top;
	for (int i = 0; i <= Top; i++) arr[i] = c.arr[i];
}


template<typename T>
const T& Stack<T>::getTop() const {
	if (Top < 0) throw std::exception("Stack Empty");
	return arr[Top];
}

template<typename T>
int Stack<T>::getSize() const { return Top + 1; }

template<typename T>
int Stack<T>::getMaxSize() const { return size; }

template<typename T>
bool Stack<T>::empty() const { return (Top == -1); }

template<typename T>
T Stack<T>::pop() {
	if (Top < 0) throw std::exception("Stack Empty");
	T temp = arr[Top];
	Top--;
	return temp;
}

template<typename T>
void Stack<T>::push(const T& e) {
	if (Top == size - 1) {
		size *= 2;
		T* temp = new T[size];
		for (int i = 0; i <= T; i++) temp[i] = arr[i];
		delete[] arr;
		arr = temp;
	}

	arr[++Top] = e;
}
