#include<iostream>
#include<cmath>

using namespace std;

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

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	isPrime(n) ? cout << "prime" << endl : cout << "not prime" << endl;

	return 0;
}