#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	if (n == 0 || n == 1) {

		// n is either the 0th or the 1st fibo. no.

		cout << "true" << endl;

	} else {

		int a = 0; // to store the 0th fib. no.
		int b = 1; // to store the 1st fib. no.

		while (true) {

			// generate the next fibo. no.

			int c = a + b;

			if (c == n) {

				cout << "true" << endl;
				break;

			}

			if (c > n) {

				cout << "false" << endl;
				break;

			}

			// c < n

			a = b;
			b = c;


		}


	}

	return 0;
}