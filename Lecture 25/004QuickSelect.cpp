#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int pivot = arr[e];

	int i = s - 1;
	int j = s;

	while (j < e) {

		if (arr[j] < pivot) {

			i++;
			swap(arr[i], arr[j]);

		}

		j++;

	}

	swap(arr[i + 1], arr[e]);

	return i + 1;

}

int quickSelect(int arr[], int s, int e, int k) {

	// base case

	if (s == e) {

		// search space has only one element

		return arr[s]; // arr[e] // arr[k]

	}

	// recursive case

	int pidx = partition(arr, s, e);

	if (pidx == k) {

		return arr[pidx];

	} else if (k < pidx) {

		// kth smallest element is < pivot so search for it in the left partition

		return quickSelect(arr, s, pidx - 1, k);

	}

	// kth smallest element is > pivot so search for it in the right partition

	return quickSelect(arr, pidx + 1, e, k);


}

int main() {

	int arr[] = {2, 7, 5, 3, 8, 4};
	int n = sizeof(arr) / sizeof(int);

	int k = 2;

	if (k < 0 || k > n - 1) {

		// k is not valid

		cout << -1 << endl;

	} else {

		cout << quickSelect(arr, 0, n - 1, k) << endl;

	}

	return 0;
}