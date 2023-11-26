#include<iostream>

using namespace std;

int main() {

	int arr[100]; // n <= 100

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	// 1. read values into the array

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 2. print the values in the array

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 3. print the values in the array in reverse

	return 0;
}