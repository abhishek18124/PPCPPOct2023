#include<iostream>

using namespace std;

int main() {

	int n = 247;

	int cnt = 0;
	int maxSoFar = 0;

	while (n > 0) {

		int rightMostBit = n & 1;

		if (rightMostBit == 1) {

			cnt++;

			// maxSoFar = max(maxSoFar, cnt);

			if (cnt > maxSoFar) {
				maxSoFar = cnt;
			}

		} else {

			cnt = 0;

		}

		n = n >> 1;

	}

	cout << maxSoFar << endl;

	return 0;
}