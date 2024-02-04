#include<iostream>

using namespace std;

// time : O(logn)

int binarySearch(int arr[], int s, int e, int t) {

	// base case

	if (s > e) {
		// search space is empty
		return -1;
	}

	// recursive case

	// find the 't' in arr[s...e]

	int m = s + (e - s) / 2;

	if (arr[m] == t) {
		// you've found the 't' at index 'm'
		return m;
	} else if (t > arr[m]) {
		// recursively, search for the 't' in arr[m+1...e]
		return binarySearch(arr, m + 1, e, t);
	}

	// t < arr[m]

	// recursively, search for the 't' in arr[s...m-1]
	return binarySearch(arr, s, m - 1, t);

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);
	int t = 100;

	cout << binarySearch(arr, 0, n - 1, t) << endl;

	return 0;
}