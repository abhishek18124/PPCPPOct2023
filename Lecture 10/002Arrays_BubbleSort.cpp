#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// iterate over the passes

	int cnt = 0; // to track the no. of comparasions

	for (int i = 1; i <= n - 1; i++) {

		// in the ith pass, we will place the largest value in the
		// unsorted part of the arr[] to its correct position

		bool flag = false; // assume no swaps will be done in the ith pass

		for (int j = 0; j < n - i; j++) {

			cnt++;

			if (arr[j] > arr[j + 1]) {

				swap(arr[j], arr[j + 1]);
				flag = true;

			}

		}

		if (flag == false) {

			break;

		}

	}

	cout << cnt << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}