#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 210;
	int cnt = 0; // to track the no. of set bits in 'n'

	// for (int k = 0; k <= 31; k++) {

	// 	// check if kth bit of 'n' is set or not

	// 	int mask = (1 << k);
	// 	if ((n & mask) > 0) { // == (1<<k) i.e. 2^k
	// 		cnt++;
	// 	}


	// }

	for (int k = 0; k < ceil(log2(n + 1)); k++) {

		// check if kth bit of 'n' is set or not

		int mask = (1 << k);
		if ((n & mask) > 0) { // == (1<<k) i.e. 2^k
			cnt++;
		}


	}

	cout << cnt << endl;

	return 0;
}