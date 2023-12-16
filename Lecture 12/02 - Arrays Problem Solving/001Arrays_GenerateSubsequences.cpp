#include<iostream>

using namespace std;

void generateSubsequences(int arr[], int n) {

	for (int num = 0; num < (1 << n); num++) {

		// iterate over the 'n' bit binary repr. of 'num'

		for (int i = 0; i < n; i++) { // ceil(log2(num + 1))

			// is the ith bit of 'num' set or not

			if (((num >> i) & 1) == 1) {

				// ith bit of 'num' is set

				cout << arr[i] << " ";

			}

		}

		cout << endl;

	}

}

int main() {

	int arr[] = {10, 20, 30};
	int n = sizeof(arr) / sizeof(int);

	generateSubsequences(arr, n);

	return 0;
}
