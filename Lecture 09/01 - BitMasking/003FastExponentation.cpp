#include<iostream>

using namespace std;

int main() {

	int a = 3;
	int n = 13;

	int res = 1;
	int wgt = a;

	while (n > 0) {

		int rightMostBit = n & 1;
		if (rightMostBit == 1) {
			res = res * wgt;
		}

		n = n >> 1;
		wgt = wgt * wgt;

	}

	cout << res << endl;


	return 0;
}