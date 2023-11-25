#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if ((n & 1) == 0) {
		// 0th bit of n is not set
		cout << n << " is even" << endl;
	} else {
		// 0th bit of n is set
		cout << n << " is odd" << endl;
	}


	return 0;
}