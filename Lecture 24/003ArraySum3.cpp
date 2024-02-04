#include<iostream>

using namespace std;

int f(int X[], int i) {

	// base case

	if (i == -1) {
		// compute the sum X[0...-1] = sum({})
		return 0;
	}

	// if (i == 0) {
	// 	// compute the sum X[0...0] = sum({X[0]})
	// 	return X[0];
	// }

	// recursive case

	// compute the sum X[0....i]

	// 1. ask your friend to compute the sum of X[0...i-1]

	int A = f(X, i - 1);

	return X[i] + A;

}

int main() {

	int X[] = {1, 2, 3, 4, 5};
	int n = sizeof(X) / sizeof(int);

	cout << f(X, n - 1) << endl;

	return 0;
}