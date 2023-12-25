#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	cout << arr << " " << &arr[0] << endl;
	cout << arr + 1 << " " << &arr[1] << endl;
	cout << arr + 2 << " " << &arr[2] << endl;
	cout << arr + 3 << " " << &arr[3] << endl;
	cout << arr + 4 << " " << &arr[4] << endl;

	cout << *arr << " " << arr[0] << endl;
	cout << *(arr + 1) << " " << arr[1] << endl;
	cout << *(arr + 2) << " " << arr[2] << endl;
	cout << *(arr + 3) << " " << arr[3] << endl;
	cout << *(arr + 4) << " " << arr[4] << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << *(arr + i) << endl;
	}

	int* ptr = arr; // &arr[0]

	for (int i = 0; i < n; i++) {
		cout << ptr[i] << " " << *(ptr + i) << endl;
	}

	return 0;
}