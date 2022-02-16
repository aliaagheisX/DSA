#include"Stack.cpp"
#include<iostream>
using std::cout;

int main() {
	try{
		Stack<int> arr;
		arr.push(5);
		arr.push(4);
		arr.push(3);
		cout << arr.getTop() << '\n';
		Stack<int> arr1 = arr;
		cout << arr1.getTop();
	}
	catch (exception e) {
		cout << "\n\033[1;31m Error:" << e.what() << "\033[0m\n";
	}
	return 0;
}