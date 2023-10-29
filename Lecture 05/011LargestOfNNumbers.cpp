#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	int x;
	cin >> x;

	int lsf = x; // to track the "largest so far"

	int i = 2;

	while (i <= n) {

		cin >> x;

		if (x > lsf) {
			lsf = x;
		}

		i = i + 1;

	}

	cout << lsf << endl;

	return 0;
}