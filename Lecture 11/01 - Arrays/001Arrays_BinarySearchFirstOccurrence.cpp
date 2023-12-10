#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 30, 30, 30, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 30;

	int s = 0;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {

		int m = s + (e - s) / 2;

		if (arr[m] == t) {

			ans = m;

			// reduce the search space from [s, e] to [s, m-1]

			e = m - 1;

		} else {

			if (t > arr[m]) {

				// go towards the right of the midPoint i.e. reduce the search space from [s, e] to [m+1, e]

				s = m + 1;

			} else {

				// go towards the left of the midPoint i.e. reduce the search space from [s, e] to [s, m-1]

				e = m - 1;

			}

		}

	}

	cout << ans << endl;

	return 0;
}