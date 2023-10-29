#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int sum = 0; // to track the sum of digits of 'n'
	// int d;

	while (n > 0) {

		// d = n % 10;
		sum = sum + n % 10;
		n = n / 10;

	}

	cout << sum << endl;

	return 0;
}