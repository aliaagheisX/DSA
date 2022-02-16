#include "Stack.cpp"

#include<iostream>
#include<exception>
using std::cout;
using std::exception;

int main() {
	try {
		Stack<int> arr(10);
		arr.push(5);
		arr.push(4);
		arr.push(3);
		cout << arr.getTop() << '\n';
		arr.push(2);

		cout << arr.pop() << '\n';
		cout << arr.getTop() << '\n';
	} 
	catch(exception e) {
		cout << "\n\033[1;31m Error:" << e.what() << "\033[0m\n";
	}
}