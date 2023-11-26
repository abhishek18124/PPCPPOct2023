#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	// time : O(n)

	int i;

	for (i = 0; i < n; i++) {

		if (arr[i] == t) {

			// you've found the 't' at index 'i'

			cout << i << endl;

			break;

		}

	}

	if (i == n) {

		cout << -1 << endl;

	}

	return 0;
}