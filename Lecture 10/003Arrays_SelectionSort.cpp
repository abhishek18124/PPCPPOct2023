#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n - 1; i++) {

		// place the smallest element in the unsorted part of the arr[]
		// to its correct position i.e the ith index

		int minIdx = i; // assume the value the ith index is the smallest in the unsorted part of the arr[]

		for (int j = i + 1; j < n; j++) {

			if (arr[j] < arr[minIdx]) {

				minIdx = j;

			}

		}

		swap(arr[minIdx], arr[i]);


	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}