#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	// iterating over the passes

	for (int i = 1; i <= n - 1; i++) {

		// insert the 1st element of the unsorted part of the arr[]
		// i.e. arr[i] to its correct position in the sorted part

		int key = arr[i];

		int j = i - 1;

		while (j >= 0 and key < arr[j]) {

			arr[j + 1] = arr[j];
			j--;

		}

		arr[j + 1] = key;

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}