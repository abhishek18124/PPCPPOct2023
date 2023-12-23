// n <= 100

#include<iostream>

using namespace std;

int main() {

	// time : 2n ~ O(n)
	// space: n due r[] ~ O(n)

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	int r[100];
	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	int l_i = 0; // or INT_MIN

	for (int i = 0; i < n; i++) {

		// compute the water trapped on top of the ith building i.e. w_i
		l_i = max(l_i, h[i]);
		int w_i = min(l_i, r[i]) - h[i];
		total = total + w_i;

	}

	cout << total << endl;

	return 0;
}