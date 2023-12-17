// constraints : n <= 100

#include<iostream>

using namespace std;

// time : O(n)
// space: O(n)

int kadanes(int arr[], int n) {

	int x[100]; // based on the constraints

	x[0] = arr[0];
	int maxSoFar = x[0];

	for (int i = 1; i < n; i++) {

		x[i] = max(x[i - 1] + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x[i]);

	}

	return maxSoFar;

}

// time : O(n)
// space: O(n)

int kadanesSpaceOptmised(int arr[], int n) {

	int x = arr[0]; // x denotes x[0]
	int maxSoFar = x;

	for (int i = 1; i < n; i++) {

		x = max(x + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x);

	}

	return maxSoFar;

}

int main() {

	int arr[] = { -3, 2, -1, 4, -5};
	int n = sizeof(arr) / sizeof(int);

	cout << kadanes(arr, n) << endl;
	cout << kadanesSpaceOptmised(arr, n) << endl;

	return 0;
}