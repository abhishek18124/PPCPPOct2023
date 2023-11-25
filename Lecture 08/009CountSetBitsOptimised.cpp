#include<iostream>

using namespace std;

int main() {

	int n = 14;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) {

		int rightMostBit = n & 1;

		if (rightMostBit == 1) {

			cnt++;

		}

		n = n >> 1;

	}

	cout << cnt << endl;

	return 0;
}