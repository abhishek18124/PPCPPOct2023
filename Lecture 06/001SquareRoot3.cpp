#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	int p;
	cin >> p;

	float squareRoot = 0;

	while (squareRoot * squareRoot <= n) {
		squareRoot = squareRoot + 1;
	}

	squareRoot = squareRoot - 1;

	int i = 1;
	float incFac = 0.1;

	while (i <= p) {

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