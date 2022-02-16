#include<iostream>
#include<string>
using namespace std;


void ReverseString(string& s, int i, int j) {
	if (i > j) return;

	swap(s[i], s[j]);

	ReverseString(s, i + 1, j - 1);
}

bool isPalindrome(string& s, int i, int j) {
	if (i > j) return true;

	return (s[i] == s[j]) && isPalindrome(s, i + 1, j - 1);	
}

int toBinary(int num) {
	if (num == 0 || num == 1) return num;

	return num % 2 + 10* toBinary(num / 2);
	 
}

int sumAllNaturalNumbers(int num) {
	if (num == 1 || num == 0) return num;
	return num + sumAllNaturalNumbers(num - 1);
}

template<typename T>
int BinarySearch(T arr[],T k, int i, int j) {
	if (i > j) return -1;

	int mid = (i + j) / 2;

	if (k < arr[mid]) return BinarySearch(arr, k, i, mid - 1);

	if (k > arr[mid]) return BinarySearch(arr, k, mid + 1, j);

	return mid;

}

template<typename T>
void merge(T arr[], int start, int mid, int end) {
	T *temp = new T [end - start + 1];
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (int i = start; i <= end; i++) arr[i] = temp[i - start];
	delete[] temp;
}

template<typename T>
void mergeSort(T arr[], int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);
	merge(arr, start, mid, end);

}

int main() {
	int arr[5] = { -25, -75, 100, 0, 50 };

	mergeSort(arr, 0, 4);

	for (int i = 0; i < 5; i++) cout << arr[i] << ' ';
}
