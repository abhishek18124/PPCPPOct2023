// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int pivot = arr[e];

	int i = s - 1;
	int j = s;

	while (j < e) {

		// if (arr[j] > pivot) {

		// 	// arr[j] should go in the right partition

		// 	j++;

		// } else {

		// 	// arr[j] should go in the left partition

		// 	i++;
		// 	swap(arr[i], arr[j]);
		// 	j++;

		// }

		if (arr[j] < pivot) {

			i++;
			swap(arr[i], arr[j]);

		}

		j++;

	}

	swap(arr[i + 1], arr[e]);

	return i + 1;

}

void quickSort(int arr[], int s, int e) {

	// base case

	// if(s == e) {
	// 	return;
	// }

	// if(s > e) {
	// 	return;
	// }

	if (s >= e) {
		return;
	}

	// recursive case

	// sort the arr[s...e] using the quickSort algorithm

	int pidx = partition(arr, s, e);
	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}