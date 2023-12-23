#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : O(n^2)
	// space: O(1)

	int total = 0;

	for (int i = 0; i < n; i++) {

		// compute the water trapped on top of the ith building i.e. w_i

		// 1. compute l_i : max(0 to i)

		int l_i = h[i]; // assume ith building is the tallest among all the building in the range 0 to i
		for (int j = i - 1; j >= 0; j--) {
			l_i = max(l_i, h[j]);
		}

		// 2. compute r_i : max(i to n-1)

		int r_i = h[i]; // assume ith building is the tallest among all the buildings in the range i to n-1
		for (int j = i + 1; j <= n - 1; j++) {
			r_i = max(r_i, h[j]);
		}

		int w_i = min(l_i, r_i) - h[i];
		total = total + w_i;

	}

	cout << total << endl;

	return 0;
}