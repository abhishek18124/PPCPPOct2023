#include<iostream>
#include<vector>

using namespace std;

vector<int> v; // to track indices of the 't' in X[]

void f(int X[], int n, int t, int i) {

	// base case

	if (i == n) {

		// find the idx of the 1st occ. of the 't' in X[n...n-1] = {}

		return; // mandatory

	}

	// recursive case

	// find the idx of the 1st occ. of the 't' in X[i...n-1]

	if (X[i] == t) {
		v.push_back(i);
	}

	// ask your friend find the idx of the 1st occ. of the 't' in X[i+1...n-1]

	f(X, n, t, i + 1);

	return; // optional

}

int main() {

	int X[] = {10, 20, 30, 20, 30};
	int n = sizeof(X) / sizeof(int);
	int t = 20;

	f(X, n, t, 0);

	if (v.size() == 0) {
		// 't' not found
		cout << -1 << endl;
	} else {

		for (int idx : v) {
			cout << idx << endl;
		}

	}

	return 0;
}