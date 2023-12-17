// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// total steps = n (for csum[]) + n^2 ~ O(n^2)
	// space = n+1 ~ O(n)

	int csum[101];
	csum[0] = 0;

	for (int i = 1; i <= n; i++) {
		csum[i] = csum[i - 1] + arr[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << csum[i] << " ";
	// }

	// cout << endl;

	int maxSoFar = INT_MIN;

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// compute the sum of the subarray that starts at the ith index and ends at the jth index

			int sum = csum[j + 1] - csum[i];
			maxSoFar = max(maxSoFar, sum);

		}

	}

	cout << maxSoFar << endl;

	return 0;
}