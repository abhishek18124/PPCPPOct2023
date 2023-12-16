#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n);

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {

		// check if 'n' is prime or not

		if (isPrime(n)) {
			cout << n << " ";
		}

	}

	cout << endl;

}

bool isPrime(int n) {

	int rn = sqrt(n);

	for (int i = 2; i <= rn; i++) {

		if (n % i == 0) {

			// you've found a factor of 'n' in the range [2, rn] therefore n is not a prime number

			return false;

		}

	}

	// n is a prime number

	return true;

}


int main() {

	int m;
	cout << "Enter the value of m : ";
	cin >> m;

	printPrimes(m);

	return 0;
}