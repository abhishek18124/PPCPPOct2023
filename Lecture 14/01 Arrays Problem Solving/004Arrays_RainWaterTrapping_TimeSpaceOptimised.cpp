#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	int total = 0;
	int l = INT_MIN;
	int r = INT_MIN;

	int i = 0;
	int j = n - 1;

	while (i <= j) {

		l = max(l, h[i]); // max(0 to i)
		r = max(r, h[j]); // max(j to n-1)

		if (l < r) {

			// compute rainwater trapped on top of the ith building

			int w_i = l - h[i];
			total += w_i;
			i++;

		} else {

			// compute rainwater trapped on top of the jth building

			int w_j = r - h[j];
			total += w_j;
			j--;


		}

	}

	cout << total << endl;

	return 0;
}