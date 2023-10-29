#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int i = 2;

	while (i <= n - 1) {

		if (n % i == 0) {

			cout << n << " is not prime" << endl;

			break;

		}

		i = i + 1;

	}

	if (i == n) {

		cout << n << " is prime" << endl;

	}

	return 0;
}