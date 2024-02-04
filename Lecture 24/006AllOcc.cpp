#include<iostream>

using namespace std;

bool flag = false; // assume 't' is not found in X[]

void f(int X[], int n, int t, int i) {

	// base case

	if (i == n) {

		// find the idx of the 1st occ. of the 't' in X[n...n-1] = {}

		if (flag == false) {
			// 't' is not found the X[]
			cout << -1 << endl;
		}

		return;

	}

	// recursive case

	// find the idx of the 1st occ. of the 't' in X[i...n-1]

	if (X[i] == t) {
		flag = true;
		cout << i << endl;
	}

	// ask your friend find the idx of the 1st occ. of the 't' in X[i+1...n-1]

	f(X, n, t, i + 1);

}

int main() {

	int X[] = {10, 20, 30, 20, 30};
	int n = sizeof(X) / sizeof(int);
	int t = 40;

	f(X, n, t, 0);

	return 0;
}