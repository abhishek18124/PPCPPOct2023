#include<iostream>

using namespace std;

void generateSubarrays(int arr[], int n) {

	// iterate over all the starting indices of the subarrays

	for (int i = 0; i < n; i++) {

		// for the given 'i', iterate over all the possible ending indices

		for (int j = i; j < n; j++) {

			// generate the subarray that starts at the ith index and ends at the jth index

			// cout << i << j << endl;

			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}

			cout << endl;


		}

		cout << endl;

	}

	cout << endl;

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	generateSubarrays(arr, n);

	return 0;
}