#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	int p;
	cin >> p;

	float squareRoot = 0;

	int i = 1;
	float incFac = 1;

	while (i <= p + 1) {

		while (squareRoot * squareRoot <= n) {
			squareRoot = squareRoot + incFac;
		}

		squareRoot = squareRoot - incFac;
		incFac = incFac / 10;
		i = i + 1;
	}

	cout << squareRoot << endl;

	return 0;
}