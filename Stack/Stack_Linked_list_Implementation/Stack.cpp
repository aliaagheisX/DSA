#include "Stack.h"
#include<exception>
using std::exception;
template<typename T>


Stack<T>::Stack(): head(nullptr), size(0) {}

template<typename T>
Stack<T>::~Stack() {
	while (size != 0) pop();
}

template<typename T>
Stack<T>::Stack(const Stack<T>& c) {
	*this = c;
}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& c) {
	if (this == &c) return *this;

	while (size != 0) pop();

	Node<T>* temp = c.head;
	Node<T>* curr = nullptr;
	Node<T>* prev = nullptr;

	if (temp == nullptr) { head = nullptr; size = 0; return *this; }

	head = new Node<T>(temp->val);
	prev = head;
	temp = temp->next;

	while (temp != nullptr) {
		curr = new Node<T>(temp->val);
		prev->next = curr;
		prev = curr;
		temp = temp->next;
	}
	size = c.size;
	return *this;
	
}



template<typename T>
const T& Stack<T>::getTop() const {
	if (head == nullptr) throw exception("Empty Stack");
	return head->val;
}

template<typename T>
int Stack<T>::getSize() const { return size; }

template<typename T>
bool Stack<T>::empty() const { return (size == 0); }

template<typename T>
T Stack<T>::pop(){
	if (head == nullptr) throw exception("Empty Stack");
	Node<T>* temp = head->next;
	delete head;
	head = temp;
	size--;
}

template<typename T>
void Stack<T>::push(const T& e){
	Node<T>* newNode = new Node<T>(e, head);
	head = newNode;
	size++;
}

/*+
	Stack(const Stack<T>&);
	Stack<T> & operator=(const Stack<T> &);
	
*/