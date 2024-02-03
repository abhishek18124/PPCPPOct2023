#include<iostream>

using namespace std;

int f(int n) {

	// base case

	// if(n == 0) {
	// 	// compute the 0th fib. no.
	// 	return 0;
	// }


	// if(n == 1) {
	// 	// compute the 1st fib. no.
	// 	return 1;
	// }

	if (n == 0 || n == 1) {
		// cout << n << " ";
		return n;
	}

	// recursive case

	// compute the nth fib. no.

	// 1. ask your friend to compute the n-1th fib. no
	int A = f(n - 1);

	// 2. ask your friend to compute the n-2th fib. no
	int B = f(n - 2);

	return A + B;

	// return f(n - 1) + f(n - 2);

}

int main() {

	int n = 4;

	cout << f(n) << endl;

	return 0;
}