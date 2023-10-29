#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int i = 2;
	int squareRoot = sqrt(n);

	while (i <= squareRoot) {

		if (n % i == 0) {

			cout << n << " is not prime" << endl;

			break;

		}

		i = i + 1;

	}

	if (i > squareRoot) {

		cout << n << " is prime" << endl;

	}

	return 0;
}