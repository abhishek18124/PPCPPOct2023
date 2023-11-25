#include<iostream>

using namespace std;

int main() {

	int n = 57;
	int k = 3;

	int mask = (1 << k); // 2^k i.e. for the mask, only kth bit is set

	cout << (n | mask) << endl;

	return 0;
}