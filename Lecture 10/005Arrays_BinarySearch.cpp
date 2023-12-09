#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 30;

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		// int m = (s + e) / 2;

		int m = s  + (e - s) / 2;

		if (t == arr[m]) {

			// you've found the target at index 'm'

			cout << m << endl;

			break;

		} else {

			if (t > arr[m]) {

				// go towards the right of the midPoint i.e. search space will reduce from [s, e] to [m+1, e]

				s = m + 1;

			} else { // t < arr[m]

				// go towards the left of the midPoint i.e. search space will reduce from [s, e] to [s, m-1]

				e = m - 1;
			}

		}

	}

	if (s > e) {

		// search space has become empty i.e. you did not find the target

		cout << -1 << endl;

	}

	return 0;
}