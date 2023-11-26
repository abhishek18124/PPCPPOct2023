#include<iostream>

using namespace std;

int main() {

	int n = 15;
	int m = 3;

	int res = n ^ m;

	// count the no. of set bits in 'res'

	int cnt = 0;

	while (res > 0) {

		cnt++;

		res = res & (res - 1);

	}

	cout << cnt << endl;

	return 0;
}